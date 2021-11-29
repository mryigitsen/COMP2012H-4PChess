#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "mainwindow.h"
#include <iostream>
#include "qinputdialog.h"
#include "qmessagebox.h"
#include "unistd.h"

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
    QInputDialog* inputDialog = new QInputDialog(this);
    QStringList items({"0","1","2","3"});
    int bots = inputDialog->getItem(this, "Multiplayer Setup", "How many bots do you want to have?", items ).toInt();
    MainWindow *m = new MainWindow(nullptr, bots, false, true );
    m->setAttribute(Qt::WA_DeleteOnClose);
    m->show();
    close();
    delete inputDialog;

}


void MenuWindow::on_create_game_clicked()
{
    std::cout<< "CG Clicked" <<std::endl;
    QInputDialog* inputDialog = new QInputDialog(this);
    QString ip = "";
    int port = -1;
    ip = inputDialog->getText(this, "Multiplayer Server", "Please enter the IP address of the server");
    if(ip != "")
    {
        port = inputDialog->getInt(this, "Multiplayer Setup", "Please enter the port number of the server");
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
            int playerCount = connect->getCount();
            qDebug() << playerCount;
            MainWindow *m = nullptr;
            int reg = 1;
            if(playerCount == 0)
            {
                inputDialog->setIntMaximum(3);
                inputDialog->setIntMinimum(0);
                QStringList items({"0","1","2"});
                int bot = inputDialog->getItem(this, "Multiplayer Setup", "How many bots do you want to have?", items ).toInt();
                m = new MainWindow(connect,bot, true, true );
                connect->registerMainWindow(m);
                connect->registerMenuWindow(this);
                reg = bot +1;
            }

            else
            {
                m = new MainWindow(connect, connect->getCount(), true, false );
                connect->registerMainWindow(m);
                connect->registerMenuWindow(this);

            }
            QMessageBox box(QMessageBox::Information, "Waiting", "Waiting for everyone to join the server. Please wait patiently. If you have to exit, please use cmd-alt-delete on Windows or force-quit on Mac");
            box.setStandardButtons(QMessageBox::Cancel);

            //box.setStandardButtons(0);
            connect->registerWaitingPopup(&box);

            sleep(1);
            connect->preRegister(reg);


            box.exec();


            m->setAttribute(Qt::WA_DeleteOnClose);
            //m->show();
            //close();
        }
    }
}
