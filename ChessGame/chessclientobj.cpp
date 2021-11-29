
#include "chessclientobj.h"
#include "sstream"
#include "vector"
#include <QThread>
ChessClientObj::ChessClientObj(QObject *parent) : QObject(parent)
{
}

bool ChessClientObj::setupSocket(QString address, int port)
{
    if(!first)
    {
        deregister();
    }
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
                bool flag = false;
                while(!ss.eof())
                {
                    string x = "";
                    ss >> x;
                    std::cout<< x<<std::endl;
                    if(x == "other")
                    {
                        flag = true;
                    }
                    else if(x == "count")
                    {
                        ss >> numPlayers;
                    }
                    else
                    {
                        if(!flag)
                        {
                            botList.push_back(stoi(x));
                        }
                        else
                        {
                            phyList.push_back(stoi(x));
                        }
                    }

                }
            }
        }


        signature = address + (QString::number(socket->localPort()));
        //signature.append(socket->localAddress().toString());
        //signature.append(socket->localPort());
        connect(socket, SIGNAL(readyRead()), this, SLOT(receive()));
        first = false;
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
        if(command == "START")
        {
            if(!started)
            {
            if(box != nullptr)
            {   qDebug() << "NOTNULL";
                box->accept();
            }
            menu->close();
            main->show();
            started = true;
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
                        game->end_game(true);
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

void ChessClientObj::deregister()
{
    send("deregister");
}

void ChessClientObj::flush()
{
    socket->flush();
}
void ChessClientObj::preRegister(int count)
{
    send("prereg "+ QString::fromStdString(to_string(count)));

}

void ChessClientObj::registerMainWindow(MainWindow *mw)
{
    main = mw;
}

void ChessClientObj::registerGamePtr(Game *g)
{
    game = g;
}
void ChessClientObj::registerWidget(ChessWidget *cw)
{
    widget = cw;
}

void ChessClientObj::registerMenuWindow(MenuWindow *mw)
{
    menu = mw;
}

void ChessClientObj::registerWaitingPopup(QMessageBox *bx)
{
    qDebug() << "here";
    box = bx;
}
void ChessClientObj::close()
{
    qDebug() << "here";
    socket->disconnect();
}

int ChessClientObj::getCount()
{
    return numPlayers;
}
