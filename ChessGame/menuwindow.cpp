#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "mainwindow.h"
#include <iostream>
#include "qinputdialog.h"
#include "qmessagebox.h"
MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    connect = new ChessClientObj();

}

MenuWindow::~MenuWindow()
{
    delete ui;
    delete connect;
}

void MenuWindow::on_start_game_clicked()
{
    std::cout<<"Button Clicked" <<std::endl;

    std::cout<<ui->player_count->currentText().toInt()<<std::endl;
    MainWindow *m = new MainWindow(nullptr, 4-ui->player_count->currentText().toInt(), ui->is_online->isChecked(), true );
    m->setAttribute(Qt::WA_DeleteOnClose);
    m->show();
    close();
}

void MenuWindow::on_join_game_clicked()
{
    std::cout<< "JG Clicked" <<std::endl;
    QInputDialog* inputDialog = new QInputDialog(this);
    QString ip = "";
    int port = -1;
    ip = inputDialog->getText(this, "Setup Server", "Please enter the IP address of the server");
    if(ip != "")
    {
        port = inputDialog->getInt(this, "Server Setup", "Please enter the port number of the server");
    }
    delete inputDialog;
    if(ip != "" && port > 0)
    {
        //TEST CONNECTION HERE
        bool test = connect->setupSocket(ip, port);
        if(!test)
        {
            QMessageBox box(QMessageBox::Warning, "ERROR", "The server connection does not work. Are you sure you are putting in the correct address?" );
            box.exec();
        }
        else
        {
            //connect->wait();
            //connect->send("getinfo");
            //connect->getNum();


            MainWindow *m = new MainWindow(connect, connect->numPlayers, true, false );
            m->setAttribute(Qt::WA_DeleteOnClose);
            m->show();
            close();
        }
    }
}

void MenuWindow::on_create_game_clicked()
{
    std::cout<< "CG Clicked" <<std::endl;
    QInputDialog* inputDialog = new QInputDialog(this);
    QString ip = "";
    int port = -1;
    ip = inputDialog->getText(this, "Setup Server", "Please enter the IP address of the server");
    if(ip != "")
    {
        port = inputDialog->getInt(this, "Server Setup", "Please enter the port number of the server");
    }
    if(ip != "" && port > 0)
    {
        //TEST CONNECTION HERE
        bool test = connect->setupSocket(ip, port);
        if(!test)
        {
            QMessageBox box(QMessageBox::Warning, "ERROR", "The server connection does not work. Are you sure you are putting in the correct address?" );
            box.exec();
            delete inputDialog;

        }
        else
        {
            delete inputDialog;
            int bot = inputDialog->getInt(this, "Server Setup", "How many bots?");
            MainWindow *m = new MainWindow(connect,bot, true, true );
            m->setAttribute(Qt::WA_DeleteOnClose);
            m->show();
            close();
        }
    }
}
