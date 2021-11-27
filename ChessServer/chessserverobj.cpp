#include "chessserverobj.h"
#include <sstream>

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
    qDebug() << " " << socket->localAddress().toString();

    //Send connected message
    send("Connection ok \n", socket);
    //socket->close();
}

void ChessServerObj::onDisconnect()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(QObject::sender());
    qDebug() << "the ip " << socket->localAddress().toString() << " is disconnected";
    remove(connectionlist.begin(), connectionlist.end(),socket);

    //Remove every player from that ip address connected to the game

    //Inform every player
    socket->deleteLater();
}

void ChessServerObj::onReceive()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(QObject::sender());
    QString input = socket->readLine();
    std::stringstream ss(input.toStdString());
    string command = "";
    ss >> command;
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
        broadcastExcept(input, socket);
    }
    if(command  == "getinfo")
    {

    }
    qDebug() << input;
}


void ChessServerObj::broadcast(QString str)
{
    for_each(connectionlist.begin(), connectionlist.end(), [&](QTcpSocket *socket){
        socket->write(str.toUtf8());
        socket->flush();
        socket->waitForBytesWritten();
        });
}
void ChessServerObj::broadcastExcept(QString str, QTcpSocket *except)
{
    for_each(connectionlist.begin(), connectionlist.end(), [&](QTcpSocket *socket){
       if(socket != except) send(str, socket);});
}
void ChessServerObj::registerPlayer(QString playerind, QTcpSocket *socket, bool isBot)
{
   qDebug() << "REGISTER " << playerind << socket->localAddress() << isBot;
   player p{ socket,playerind.toStdString(), isBot};
   playerList.push_back(p);
}
void ChessServerObj::send(QString msg, QTcpSocket *socket)
{
    socket->write(msg.toUtf8());
    socket->flush();
    socket->waitForReadyRead(100);
}
