#ifndef CHESSCLIENTOBJ_H
#define CHESSCLIENTOBJ_H

#include <QObject>


#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include "Game.h"
#include "chesswidget.h"
using namespace std;
class ChessWidget;
class ChessClientObj : public QObject
{
    Q_OBJECT
public:
    explicit ChessClientObj(QObject *parent = 0);
    bool setupSocket(QString address, int port);
    void send(QString msg);
    void isConnected() const;
    void Register(QString index, bool isBot);
    void move(int initX, int initY, int destX, int destY);
    void moveBot(int initX, int initY, int destX, int destY);

    void getNum();
    void flush();
    int numPlayers = 0;
    vector<int> botList;
    bool wait();

    void registerGamePtr(Game *g);
    void registerWidget(ChessWidget *cw);


signals:

public slots:
    void receive();
private:
    ChessWidget *widget;
    Game *game;
    QTcpSocket *socket;
    QString signature = "";
};


#endif // CHESSCLIENTOBJ_H
