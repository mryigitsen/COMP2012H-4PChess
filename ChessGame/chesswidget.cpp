#include "chesswidget.h"
#include <QGridLayout>
#include <QLayout>
#include <QVBoxLayout>
#include "Game.h"
#include <QIcon>
#include <iostream>
#include <QSignalMapper>
#include "pieces/Piece.h"
#include <algorithm>
#include <vector>
#include "menuwindow.h"
#include <QApplication>
#include <QThread>
#include "unistd.h"
ChessWidget::ChessWidget(ChessClientObj *client, int botCount, bool online , bool firstOnline, MainWindow *mw, QWidget *parent) : QWidget(parent), mw(mw) {
    game = new Game(client, botCount, online, firstOnline);
    if(client != nullptr)
    {
    client->registerWidget(this);
    }
    QGridLayout *gridLayout = new QGridLayout(this);
    QSignalMapper *mapper = new QSignalMapper(this);

    initMap(gridLayout, mapper, game);

    QSizePolicy p = this->sizePolicy();
    p.setHeightForWidth(true);
    this->setSizePolicy(p);
    mw->update_scores(0, 0, 0, 0);
}

int ChessWidget::heightForWidth(int width) const {
    return width;
}

void ChessWidget::initMap(QGridLayout *gridLayout, QSignalMapper *mapper, Game *game) {
    gridLayout->setHorizontalSpacing(0);
    gridLayout->setVerticalSpacing(0);
    for (int row = 0; row < 14; ++row) {
        for (int col = 0; col < 14; ++col) {
            QPushButton *button = new QPushButton(" ");
            mapper->setMapping(button, row * 14 + col);
            connect(button, SIGNAL(clicked()), mapper, SLOT(map()));
            button->setFixedHeight(57);
            button->setFixedWidth(57);
            if ((row + col) % 2 == 0) {
                button->setStyleSheet("background-color: rgb(183, 192, 216); text-align:right");
            } else {
                button->setStyleSheet("background-color: rgb(232, 237, 249); text-align:right");
            }
            if ((row < 3 && col < 3) || (row < 3 && col > 10) || (row > 10 && col < 3) || (row > 10 && col > 10)) {
                button->setEnabled(false);
                button->setStyleSheet("background-color: silver; text-align: right");
            }
            if (game->get_piece(row, col) != nullptr) {
                button->setIcon(QIcon(QString::fromStdString(game->get_piece(row, col)->get_img())));
                button->setIconSize(QSize(45, 45));
            }
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
           //gridLayout->addWidget(button, row, col);
            button_arr[row][col] = button;
            int player = game->get_local_player();
                        qDebug() << player;
                        if(player == 0)
                        {
                            gridLayout->addWidget(button, row, col);
                        }
                        else if(player == 1)
                        {
                            gridLayout->addWidget(button, 14-col, row);
                        }
                        else if(player == 2)
                        {
                            gridLayout->addWidget(button, 14-row, 14-col);
                        }
                        else if(player == 3)
                        {
                            gridLayout->addWidget(button, col, 14-row);
                        }





        }


    }

    connect(mapper, SIGNAL(mapped(int)),
            this, SLOT(handleButtonClick(int)));

}


void ChessWidget::handleButtonClick(int index) {

    if (chosenx == index / 14 && choseny == index % 14) {
        //do nothing
        return;
    }

    //If the piece is the own piece
    if (game->get_piece(index / 14, index % 14) != nullptr &&
        ((!game->get_is_online()  && game->get_piece(index / 14, index % 14)->which_player() == game->get_cur_player()) || (game->get_is_online()  && game->get_piece(index / 14, index % 14)->which_player() == game->get_cur_player()  && game->get_piece(index / 14, index % 14)->which_player() == game->get_online_player()))) {
        //Assume you're choosing a piece of yourself
        resetColors(false);
        button_arr[index / 14][index % 14]->setStyleSheet("background-color: rgb(123, 97, 255); text-align: right");
        current_piece_vec = game->get_piece(index / 14, index % 14)->get_moves_vec();
        for_each(current_piece_vec.begin(), current_piece_vec.end(),
                 [&](Piece::Coordinates p) { handle_valid_moves(p); });
        chosenx = index / 14;
        choseny = index % 14;

        //DO
        return;
    }
    bool isarequest = false;

    for (unsigned long i = 0; i < current_piece_vec.size(); ++i) {
        if (current_piece_vec.at(i).x == index / 14 && current_piece_vec.at(i).y == index % 14) {
            isarequest = true;
        }

    }
    if (isarequest) {

        game->movePiece(chosenx, choseny, index / 14, index % 14);
        mw->update_scores(game->get_player_at(0)->get_score(), game->get_player_at(1)->get_score(), game->get_player_at(2)->get_score(), game->get_player_at(3)->get_score());
        chosenx = 0;
        choseny = 0;
        current_piece_vec.resize(0);
        resetColors(true);
        QApplication::processEvents();
        while(game->get_cur_player_pointer()->get_is_bot() && !game->get_cur_player_pointer()->get_is_online()){
            //resetColors(true);
            game->bot_move_piece();
            mw->update_scores(game->get_player_at(0)->get_score(), game->get_player_at(1)->get_score(), game->get_player_at(2)->get_score(), game->get_player_at(3)->get_score());
            resetColors(true);
            QApplication::processEvents();
            sleep(1);
        }

    } else {
    }

}

void ChessWidget::processPossibleBots()
{
    while(game->get_cur_player_pointer()->get_is_bot() && !game->get_cur_player_pointer()->get_is_online()){
        //resetColors(true);
        game->bot_move_piece();
        resetColors(true);
        QApplication::processEvents();
        //QThread::msleep(500);
    }
}

void ChessWidget::resetColors(bool icon) {
    for (int row = 0; row < 14; ++row) {
        for (int col = 0; col < 14; ++col) {
            QPushButton *button = button_arr[row][col];
            if ((row + col) % 2 == 0) {
                button->setStyleSheet("background-color: rgb(183, 192, 216); text-align: right");
            } else {
                button->setStyleSheet("background-color: rgb(232, 237, 249) ; text-align: right");
            }
            if ((row < 3 && col < 3) || (row < 3 && col > 10) || (row > 10 && col < 3) || (row > 10 && col > 10)) {
                button->setEnabled(false);
                button->setStyleSheet("background-color: silver; text-align: right");
            }

            if (icon && game->get_piece(row, col) != nullptr) {
                button->setIcon(QIcon(QString::fromStdString(game->get_piece(row, col)->get_img())));
                button->setIconSize(QSize(45, 45));
            } else if (icon && game->get_piece(row, col) == nullptr) {
                button->setIcon(QIcon());
            }
        }
    }
}

void ChessWidget::handle_valid_moves(Piece::Coordinates p) const {
    button_arr[p.x][p.y]->setStyleSheet("background-color: rgb(178, 167, 252); text-align: right");
}

bool ChessWidget::check_piece(Piece::Coordinates p) {
    if (p.x == chosenx && p.y == choseny) {
        return true;
    }
    return false;
}
