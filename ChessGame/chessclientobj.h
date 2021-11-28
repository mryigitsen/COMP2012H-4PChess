//

#ifndef CHESSCLIENTOBJ_H
#define CHESSCLIENTOBJ_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

using namespace std;

class ChessClientObj : public QObject
{
    Q_OBJECT
    private:
        QTcpSocket *socket;

    public:
        explicit ChessClientObj(QString address, int port, QObject *parent = 0);
        void send(QString msg);
        void isConnected() const;

    public slots:
        void receive() const;
};


#endif // CHESSCLIENTOBJ_H
