
#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "mainwindow.h"
#include <iostream>

MenuWindow::MenuWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::on_start_game_clicked()
{
    std::cout<<"Button Clicked" <<std::endl;

    std::cout<<ui->player_count->currentText().toInt()<<std::endl;
    MainWindow *m = new MainWindow(4-ui->player_count->currentText().toInt());
    m->setAttribute(Qt::WA_DeleteOnClose);
    m->setStyleSheet("QWidget{font:Arial}");
    m->show();
    close();
}
