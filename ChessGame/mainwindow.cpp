
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
    if(player_1_status == "Disconnected" || player_1_status == "Checkmated" || player_1_status == "Stalemated") {
        ui->Player_1_Box->setStyleSheet("background-color: rgb(149, 149, 149)");
    }
    ui->Player_2_Status->setText("Status: " + QString::fromStdString(player_2_status));
    if(player_2_status == "Disconnected" || player_2_status == "Checkmated" || player_2_status == "Stalemated") {
        ui->Player_2_Box->setStyleSheet("background-color: rgb(149, 149, 149)");
    }
    ui->Player_3_Status->setText("Status: " + QString::fromStdString(player_3_status));
    if(player_3_status == "Disconnected" || player_3_status == "Checkmated" || player_3_status == "Stalemated") {
        ui->Player_3_Box->setStyleSheet("background-color:rgb(149, 149, 149)");
    }
    ui->Player_4_Status->setText("Status: " + QString::fromStdString(player_4_status));
    if(player_4_status == "Disconnected" || player_4_status == "Checkmated" || player_4_status == "Stalemated") {
        ui->Player_4_Box->setStyleSheet("background-color: rgb(149, 149, 149)");
    }
}

void MainWindow::set_bot_notif(bool player_2_bot, bool player_3_bot, bool player_4_bot) {
    std::string font = "font: 24pt \"Arial\"; font-weight: bold";

    std::string player_1_label = "Player 1";
    ui->Player_1_Label->setText(QString::fromStdString(player_1_label));
    ui->Player_1_Label->setStyleSheet(QString::fromStdString(font));

    std::string player_2_label = "Player 2";
    player_2_label += (player_2_bot ? " (Bot)" : "");
    ui->Player_2_Label->setText(QString::fromStdString(player_2_label));
    ui->Player_2_Label->setStyleSheet(QString::fromStdString(font));

    std::string player_3_label = "Player 3";
    player_3_label += (player_3_bot ? " (Bot)" : "");
    ui->Player_3_Label->setText(QString::fromStdString(player_3_label));
    ui->Player_3_Label->setStyleSheet(QString::fromStdString(font));

    std::string player_4_label = "Player 4";
    player_4_label += (player_4_bot ? " (Bot)" : "");
    ui->Player_4_Label->setText(QString::fromStdString(player_4_label));
    ui->Player_4_Label->setStyleSheet(QString::fromStdString(font));
}
