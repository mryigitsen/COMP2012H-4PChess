
#include "mainwindow.h"
#include "menuwindow.h"
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //a.setStyle(QStyleFactory::create("Fusion"));
    MenuWindow w;
    w.show();
    return a.exec();
}
