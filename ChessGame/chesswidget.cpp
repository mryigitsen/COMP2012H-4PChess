#include "chesswidget.h"
#include <QGridLayout>
#include <QLayout>
#include <QVBoxLayout>
#include <QApplication>
#include "Game.h"
#include <QIcon>
#include <iostream>
#include <QSignalMapper>
#include "pieces/Piece.h"
#include <algorithm>
#include <vector>
#include <unistd.h>
#include "menuwindow.h"

ChessWidget::ChessWidget(int botCount, QWidget *parent) : QWidget(parent) {
    std::cout<<"BOT" << botCount <<std::endl;
    game = new Game(botCount);

    QGridLayout *gridLayout = new QGridLayout(this);
    QSignalMapper *mapper = new QSignalMapper(this);

    initMap(gridLayout, mapper, game);

    QSizePolicy p = this->sizePolicy();
    p.setHeightForWidth(true);
    this->setSizePolicy(p);
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

            if ((row + col) % 2 == 0) {
                button->setStyleSheet("background-color: rgb(183, 192, 216)");
            } else {
                button->setStyleSheet("background-color: rgb(232, 237, 249)");
            }
            if ((row < 3 && col < 3) || (row < 3 && col > 10) || (row > 10 && col < 3) || (row > 10 && col > 10)) {
                button->setEnabled(false);
                button->setStyleSheet("background-color: silver");
            }
            if (game->get_piece(row, col) != nullptr) {
                button->setIcon(QIcon(QString::fromStdString(game->get_piece(row, col)->get_img())));
                button->setIconSize(QSize(50, 50));
            }
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            gridLayout->addWidget(button, row, col);
            button_arr[row][col] = button;
        }
    }

    connect(mapper, SIGNAL(mapped(int)),
            this, SLOT(handleButtonClick(int)));

}


void ChessWidget::handleButtonClick(int index) {
//   std::cout << "clicked row" << index/14 << " col " << index % 14 <<std::endl;
//    std::cout<<"chosen "<< chosenx << " " <<choseny <<std::endl;
    if (game->get_piece(index / 14, index % 14) != nullptr) {
//            std::cout<<"player "<< game->get_piece(index/14, index %14)->which_player() <<std::endl;
//            std::cout << "current player" << game->get_cur_player() <<std::endl;
    }
    if (chosenx == index / 14 && choseny == index % 14) {
        //do nothing
        return;
    }

    //If the piece is the own piece
    if (game->get_piece(index / 14, index % 14) != nullptr &&
        game->get_piece(index / 14, index % 14)->which_player() == game->get_cur_player()) {
        //Assume you're choosing a piece of yourself
        resetColors(false);
        button_arr[index / 14][index % 14]->setStyleSheet("background-color: rgb(123, 97, 255)");
        current_piece_vec = game->get_piece(index / 14, index % 14)->get_moves_vec();
        for_each(current_piece_vec.begin(), current_piece_vec.end(),
                 [&](Piece::Coordinates p) { handle_valid_moves(p); });
        chosenx = index / 14;
        choseny = index % 14;

        //DO
        return;

    }
    bool isarequest = false;

    for (int i = 0; i < current_piece_vec.size(); ++i) {
//       std::cout<< current_piece_vec.at(i).x << " " <<current_piece_vec.at(i).y <<std::endl;
        if (current_piece_vec.at(i).x == index / 14 && current_piece_vec.at(i).y == index % 14) {
            isarequest = true;
        }

    }
    if (isarequest) {

        game->movePiece(chosenx, choseny, index / 14, index % 14);
        chosenx = 0;
        choseny = 0;
        current_piece_vec.resize(0);
        //game->make_turn();
        resetColors(true);
        std::cout<<"RESETTED"<<std::endl;
        QApplication::processEvents();
        while(game->get_cur_player_pointer()->get_is_bot()){
              game->bot_move_piece();
              resetColors(true);
              QApplication::processEvents();
              sleep(1);
        }

//       std::cout<< "MOVE" << std::endl;
    } else {
//       std::cout<< "empty" <<std::endl;
    }

}


void ChessWidget::resetColors(bool icon) {
//    std::cout << "in resetColors " <<std::endl;
    for (int row = 0; row < 14; ++row) {
        for (int col = 0; col < 14; ++col) {
            QPushButton *button = button_arr[row][col];
            if ((row + col) % 2 == 0) {
                button->setStyleSheet("background-color: rgb(183, 192, 216)");
            } else {
                button->setStyleSheet("background-color: rgb(232, 237, 249)");
            }
            if ((row < 3 && col < 3) || (row < 3 && col > 10) || (row > 10 && col < 3) || (row > 10 && col > 10)) {
                button->setEnabled(false);
                button->setStyleSheet("background-color: silver");
            }

            if (icon && game->get_piece(row, col) != nullptr) {
//                std::cout<<row << " " << col<<std::endl;

//                std::cout<<game->get_piece(row,col)->get_img() <<std::endl;
                button->setIcon(QIcon(QString::fromStdString(game->get_piece(row, col)->get_img())));
                button->setIconSize(QSize(50, 50));
            } else if (icon && game->get_piece(row, col) == nullptr) {
                button->setIcon(QIcon());
            }
        }
    }
//    std::cout << "end resetColors " <<std::endl;

}

void ChessWidget::handle_valid_moves(Piece::Coordinates p) const {
    button_arr[p.x][p.y]->setStyleSheet("background-color: rgb(178, 167, 252)");
}

bool ChessWidget::check_piece(Piece::Coordinates p) {
    if (p.x == chosenx && p.y == choseny) {
        return true;
    }
    return false;
}
