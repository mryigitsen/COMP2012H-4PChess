#include "chessserverobj.h"
#include <sstream>
#include <iostream>
#include <QThread>
#include "algorithm"
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
    connectionlist.insert({socket, 0});
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
    qDebug() <<"DISCONNECT";
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(QObject::sender());
    qDebug() << "the ip " << socket->localAddress().toString() << " is disconnected";
    int count = connectionlist.find(socket)->second;
    connectionlist.erase(socket);
    qDebug() << "LATEST COUNT " << count;
    //remove(connectionlist.begin(), connectionlist.end(),socket);
    //Remove every player from that ip address connected to the game
    vector<string> playerNums;
    for(unsigned long i = 0; i < playerList.size(); ++i)
    {
        if(playerList[i].socket == socket)
        {
            qDebug() << "SOCKET MATCH";
            playerNums.push_back(playerList[i].player);
            playerList.erase(playerList.begin()+i);
            --i;
        }
    }
    count_players-= count;
    qDebug() << count_players << " COUNT";
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
    if(command == "prereg")
    {
        qDebug() << input;

        int newCount = 0;
        ss >> newCount;
        connectionlist.erase(socket);
        connectionlist.insert({socket, newCount});
        count_players += newCount;
        qDebug() << count_players;

        if(count_players == 4)
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
    if(command == "deregister")
    {
        deregister(socket);

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
    msg.append("other ");
    for_each(playerList.begin(), playerList.end(), [&](player p){
        if(!p.isBot)
            msg.append(p.player + " ");
    });
    msg.append("count " + to_string(playerList.size()));

    send(QString::fromStdString(msg), socket);

}

void ChessServerObj::deregister(QTcpSocket *socket)
{
    int count = connectionlist.find(socket)->second;

    //Find the player on the playerList and delete those

    for(unsigned long i = 0; i < playerList.size(); ++i)
    {
        if(playerList[i].socket == socket)
        {
            qDebug() << "SOCKET MATCH";
            playerList.erase(playerList.begin()+i);
            --i;
        }
    }

    //Re-set the player count to 0 in connection map
    connectionlist.erase(socket);
    connectionlist.insert({socket, 0});

    count_players -= count;

}

void ChessServerObj::broadcast(QString str)
{

    for ( const auto &p : connectionlist ) {
        QTcpSocket *socket = p.first;
        str.append("\n");
        socket->write(str.toUtf8());
        socket->flush();
        socket->waitForBytesWritten(1000);
}
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
    qDebug() << "SENDING";
    socket->write(msg.toUtf8());
    socket->flush();
    socket->waitForBytesWritten(1000);

}
void ChessServerObj::broadcastRemoval(string s)
{
    QString str = "dead " + QString::fromStdString(s) + "\n";
    broadcast(str);
}

