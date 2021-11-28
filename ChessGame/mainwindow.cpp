#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QGridLayout>
#include "chesswidget.h"
#include "chessclientobj.h"
#include <unistd.h>

MainWindow::MainWindow(ChessClientObj *client, int count, bool online, bool firstOnline, QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ChessWidget *cw = new ChessWidget(client, count, online, firstOnline, this, this);
    ui->horizontalLayout->addWidget(cw);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::update_scores(int player_1_score, int player_2_score, int player_3_score, int player_4_score) {
    ui->Player_1_Score->setText(QString::number(player_1_score));
    ui->Player_2_Score->setText(QString::number(player_2_score));
    ui->Player_3_Score->setText(QString::number(player_3_score));
    ui->Player_4_Score->setText(QString::number(player_4_score));
}
