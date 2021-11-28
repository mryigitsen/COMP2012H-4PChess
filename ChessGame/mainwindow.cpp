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
    ui->Player_1_Score->setText("Score: " + QString::number(player_1_score));
    ui->Player_2_Score->setText("Score: " + QString::number(player_2_score));
    ui->Player_3_Score->setText("Score: " + QString::number(player_3_score));
    ui->Player_4_Score->setText("Score: " + QString::number(player_4_score));
}

void MainWindow::update_status(std::string player_1_status, std::string player_2_status, std::string player_3_status, std::string player_4_status) {
    ui->Player_1_Status->setText("Status: " + QString::fromStdString(player_1_status));
    ui->Player_2_Status->setText("Status: " + QString::fromStdString(player_2_status));
    ui->Player_3_Status->setText("Status: " + QString::fromStdString(player_3_status));
    ui->Player_4_Status->setText("Status: " + QString::fromStdString(player_4_status));
}
