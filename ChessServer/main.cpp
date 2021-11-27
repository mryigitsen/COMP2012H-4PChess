#include <QCoreApplication>
#include "chessserverobj.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ChessServerObj server;
    return a.exec();
}
