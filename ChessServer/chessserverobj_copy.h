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
private:
    QTcpServer *server;
    vector<QTcpSocket *> connectionlist;
};

#endif // CHESSSERVEROBJ_H
