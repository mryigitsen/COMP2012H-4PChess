#include "chessclientobj.h"
#include "sstream"
#include "vector"
#include <QThread>
ChessClientObj::ChessClientObj(QObject *parent) : QObject(parent)
{
}

bool ChessClientObj::setupSocket(QString address, int port)
{
    qDebug() << "in SetupSocket";
    socket = new QTcpSocket(this);
    socket->connectToHost(address, port);
    if(socket->waitForConnected())
    {
        qDebug() << socket->localAddress() << " " <<socket->localPort();
        if(socket->waitForReadyRead())
        {
            QString line = socket->readLine().trimmed();

            stringstream ss(line.toStdString());
            string command = "";
            ss >> command;

            if(command == "info")
            {
                while(!ss.eof())
                {
                    string x = "";
                    ss >> x;
                    if(x != "count")
                    {
                        botList.push_back(stoi(x));
                    }
                    if(x == "count")
                    {
                        ss >> numPlayers;
                    }
                }
            }
        }


        signature = socket->localAddress().toString() + (QString::number(socket->localPort()));
        //signature.append(socket->localAddress().toString());
        //signature.append(socket->localPort());
        connect(socket, SIGNAL(readyRead()), this, SLOT(receive()));

        return true;
    }
    else
    {
        qDebug() << "Not a valid address";
        return false;
    }

}

void ChessClientObj::send(QString msg)
{
    msg.append(" ");
    msg.append(signature);
    msg.append("\t\n");
    qDebug() << msg;


    socket->write(msg.toUtf8());
    socket->flush();
    socket->waitForBytesWritten();
    socket->flush();
    socket->waitForBytesWritten(1000);
}

void ChessClientObj::receive()
{
    qDebug() << "HERE";
    while(socket->canReadLine())
    {
        QString input = socket->readLine().trimmed();
        input.remove("\t\n");
          qDebug() << input;
        stringstream ss(input.toStdString());
        string command = "";
        ss >> command;
        if(command == "info")
        {
            while(!ss.eof())
            {
                string x = "";
                ss >> x;
                if(x != "count")
                {
                    botList.push_back(stoi(x));
                }
                if(x == "count")
                {
                    ss >> numPlayers;
                }
            }
        }

        if(command == "move")
        {

                int initX, initY, destX, destY;
                 string sign;
                ss >> initX;
                ss >> initY;
                ss >> destX;
                ss >> destY;
                ss >> sign;
                if(QString::fromStdString(sign) != signature)
                {
                game->movePiece(initX, initY, destX, destY);
                widget->resetColors(true);
                widget->processPossibleBots();
                }
        }

        if(command == "dead")
                {
                    int player;
                    ss >> player;
                    game->deactivate_player(player, "Disconnected");
                    widget->resetColors(true);
                    int active = game->active_players();
                    qDebug() << active;
                    if(game->active_players() == 1)
                    {
                        game->end_game();
                    }
                }

    }
}

void ChessClientObj::isConnected() const
{
    if(socket->isOpen())
    {
        qDebug() << "Connected";
    }
    else qDebug() << "Disconnected";
}

void ChessClientObj::Register(QString index, bool isBot)
{

    if(isBot)
    {
        QString msg = "reg " + index + " true";
        send(msg);

    }
    else
    {
        QString msg = "reg " + index + " false";
        send(msg);
    }
}

void ChessClientObj::move(int initX, int initY, int destX, int destY)
{
    //QThread::sleep(1);
    QString msg = "move "+ QString::fromStdString(to_string(initX)) + " " + QString::fromStdString(to_string(initY)) + " " + QString::fromStdString(to_string(destX)) + " " + QString::fromStdString(to_string(destY));
    send(msg);

}

void ChessClientObj::moveBot(int initX, int initY, int destX, int destY)
{
   // QThread::sleep(1);
    QString msg = "move "+ QString::fromStdString(to_string(initX)) + " " + QString::fromStdString(to_string(initY)) + " " + QString::fromStdString(to_string(destX)) + " " + QString::fromStdString(to_string(destY));
    send(msg);
}


void ChessClientObj::getNum()
{
    send("num");
}

void ChessClientObj::flush()
{
    socket->flush();
}

void ChessClientObj::registerGamePtr(Game *g)
{
    game = g;
}
void ChessClientObj::registerWidget(ChessWidget *cw)
{
    widget = cw;
}
