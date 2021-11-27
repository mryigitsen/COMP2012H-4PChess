#ifndef CHESSSERVEROBJ_H
#define CHESSSERVEROBJ_H

#include <QObject>

#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
using namespace std;
class ChessServerObj : public QObject
{
    Q_OBJECT
public:
    explicit ChessServerObj(QObject *parent = 0);
signals:

public slots:
    void newConnection();
    void onDisconnect();
    void onReceive();
private:
    struct player
    {
        QTcpSocket *socket;
        string player;
        bool isBot;
    };
    QTcpServer *server;
    vector<QTcpSocket *> connectionlist;
    //index identifies which player # it is.
    vector<player> playerList;
    void broadcast(QString str = "");

    void getPrevPlayersInfo(QTcpSocket *socket);
    void registerPlayer(QString player, QTcpSocket *socket, bool isBot);
    void broadcastExcept(QString str, QTcpSocket *except);
    void send(QString msg, QTcpSocket *socket);


};

#endif // CHESSSERVEROBJ_H
