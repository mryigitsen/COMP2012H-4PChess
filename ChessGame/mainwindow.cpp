#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QGridLayout>
#include "chesswidget.h"
#include "chessclientobj.h"
#include <unistd.h>

MainWindow::MainWindow(int count, QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ChessWidget *cw = new ChessWidget(count);
    ui->horizontalLayout->addWidget(cw);
    ChessClientObj *client = new ChessClientObj("127.0.0.1", 1214, this);
    client->isConnected();
    client->send("Hello server\n");
    client->send("reg 0 true\n");
    client->send("reg 1 true\n");
    client->send("reg 2 false\n");
    client->send("reg 3 true\n");

}

MainWindow::~MainWindow() {
    delete ui;
}

