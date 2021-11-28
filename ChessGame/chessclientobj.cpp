
#include "chessclientobj.h"

ChessClientObj::ChessClientObj(QString address, int port, QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    socket->connectToHost(address, port);
    if(socket->ConnectionRefusedError)
    {
     qDebug() << "Not a valid address";
    }
    connect(socket, SIGNAL(readyRead()), this, SLOT(receive()));
    socket->waitForConnected();

}

void ChessClientObj::send(QString msg)
{
    socket->write(msg.toUtf8());
    socket->flush();
    socket->waitForReadyRead(100);
}

void ChessClientObj::receive() const
{
    QString input = socket->readLine();
    qDebug() << input;
}

void ChessClientObj::isConnected() const
{
    if(socket->isOpen())
    {
        qDebug() << "Connected";
    }
    else qDebug() << "Disconnected";
}
