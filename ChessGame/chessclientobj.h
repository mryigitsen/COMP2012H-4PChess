#ifndef CHESSCLIENTOBJ_H
#define CHESSCLIENTOBJ_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include "Game.h"
#include "chesswidget.h"
#include "mainwindow.h"
#include "menuwindow.h"
#include "QMessageBox"
using namespace std;

class ChessWidget;
class MenuWindow;
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
    void deregister();
    void getNum();
    void flush();
    vector<int> botList;
    vector<int> phyList;

    bool wait();
    void preRegister(int count);
    void registerMainWindow(MainWindow *mw);
    void registerGamePtr(Game *g);
    void registerWidget(ChessWidget *cw);
    void registerMenuWindow(MenuWindow *mw);
    void registerWaitingPopup(QMessageBox *bx);
    QString signature = "";
    int getCount();


    void close();

signals:

public slots:
    void receive();
private:
    int numPlayers = 0;

    MainWindow *main;
    MenuWindow *menu;
    ChessWidget *widget;
    Game *game;
    QTcpSocket *socket;
    QMessageBox *box;
    bool started = false;
    bool first = true;
};


#endif // CHESSCLIENTOBJ_H
