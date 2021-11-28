#include "chessserverobj.h"
#include <sstream>
#include <iostream>
#include <QThread>
ChessServerObj::ChessServerObj(QObject *parent) : QObject(parent)
 {
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any, 1214))
       {
        qDebug() << "Server didn't start - check port number";
    }
    else
    {
        qDebug() << "Server started";
    }
}

void ChessServerObj::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();

    //Add it to the currently connected sockets list.
    connectionlist.push_back(socket);
    //Add disconnecting and receiving slots
    connect(socket,SIGNAL(disconnected()),this,SLOT(onDisconnect()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReceive()));

    //Debug purposes
    qDebug() << " " << socket->peerAddress().toString() << " "<< socket->peerPort();

    //Send connected message
    //send("Connection ok \n", socket);
    sendInfo(socket);
    //socket->close();
}

void ChessServerObj::onDisconnect()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(QObject::sender());
    qDebug() << "the ip " << socket->localAddress().toString() << " is disconnected";
    connectionlist.remove(socket);
    //remove(connectionlist.begin(), connectionlist.end(),socket);
    //Remove every player from that ip address connected to the game    
    vector<string> playerNums;
    for(unsigned long i = 0; i < playerList.size(); ++i)
    {
        if(playerList[i].socket == socket)
        {
            playerNums.push_back(playerList[i].player);
            playerList.erase(playerList.begin()+i);
            --i;
        }
    }
    socket->deleteLater();

    //Inform every player
    for_each(playerNums.begin(), playerNums.end(), [&](string s){broadcastRemoval(s);});
}

void ChessServerObj::onReceive()
{

    QTcpSocket *socket = qobject_cast<QTcpSocket *>(QObject::sender());
    qDebug() <<"HERE2";
    while(socket->canReadLine())
    {
    QString input = socket->readLine();
    //qDebug() << input;

    string s = input.toStdString();
    std::cout << "DEBUG"<< s << std::endl;
    //send("ok", socket)




    std::stringstream ss(input.toStdString());
    string command = "";
    ss >> command;
    std::cout<< command <<std::endl;
    //qDebug() << command;
    if(command == "reg")
    {
        string player ="";
        string isBot = "";
        ss >> player;
        ss >> isBot;
        registerPlayer(QString::fromStdString(player), socket, (isBot == "true") ? true : false);
        if(playerList.size() == 4)
        {
            qDebug() << "SIZE == 4";
            broadcast("START");
        }
    }
    if(command == "move" || command == "deactive")
    {
        std::cout << "here"<<std::endl;
        QThread::msleep(1000);
        broadcast(input);
        //send("ok\t\n", socket);
    }
    if(command  == "getinfo")
    {
        sendInfo(socket);
    }
    if(command == "num")
    {
        qDebug() << input;
        send(QString::fromStdString(to_string(playerList.size())), socket);
    }
    //qDebug() << input;
    }
}

void ChessServerObj::sendInfo(QTcpSocket *socket)
{
    string msg = "info ";
    for_each(playerList.begin(), playerList.end(), [&](player p){
        if(p.isBot)
            msg.append(p.player + " ");
    });
    msg.append("count " + to_string(playerList.size()));

    send(QString::fromStdString(msg), socket);

}
void ChessServerObj::broadcast(QString str)
{
    for_each(connectionlist.begin(), connectionlist.end(), [&](QTcpSocket *socket){
        str.append("\n");
        socket->write(str.toUtf8());
        socket->flush();
        socket->waitForBytesWritten(1000);
        });
}
void ChessServerObj::broadcastExcept(QString str, QTcpSocket *except)
{
    for_each(connectionlist.begin(), connectionlist.end(), [&](QTcpSocket *socket){
       if(socket->peerAddress() != except->peerAddress() && socket->peerPort() != socket->peerPort()) send(str, socket);});
}
void ChessServerObj::registerPlayer(QString playerind, QTcpSocket *socket, bool isBot)
{
    if(playerList.size()!= 4)
    {
        qDebug() << "REGISTER " << playerind << socket->peerAddress() << isBot;
        player p{socket, playerind.toStdString(), isBot};
        playerList.push_back(p);
    }
    else
    {
        send("full", socket);
    }

}
void ChessServerObj::send(QString msg, QTcpSocket *socket)
{
    qDebug() << msg;
    msg.append("\t\n");
    socket->write(msg.toUtf8());
    socket->flush();
    socket->waitForBytesWritten(1000);

}
void ChessServerObj::broadcastRemoval(string s)
{
    QString str = "dead " + QString::fromStdString(s) + "\n";
    broadcast(str);
}

