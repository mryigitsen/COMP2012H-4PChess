//
// Created by Yigit Sen on 13/11/2021.
//

#include "Bishop.h"
#include "iostream"
#include "../Game.h"
#include "Piece.h"

Bishop::Bishop(Player &player, Game &game, int x, int y) : Piece(player, game, x, y) {
    points = 5;
    player.pieces[player.num_pieces++] = this;
}

Piece::Type Bishop::get_type() const {
    return Piece::Type::BISHOP;
}

int Bishop::get_point() const {
    return points;
}

int Bishop::list_possible_moves() {
//    std::cout<<"bishop " << player.get_index() <<std::endl;

    //Check for +Y (up)

    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 14; ++j) {
            possible_moves[i][j] = 0;
        }
    }
    possible_moves[x][y] = 1;
    int num_moves = 0;

    int xpos = x + 1;
    int ypos = y + 1;
    while (true) {
        if (game.in_boundaries(xpos, ypos)) {
            if (game.get_piece(xpos, ypos) == nullptr) {
                possible_moves[xpos][ypos] = 2;
                num_moves++;
            } else {
                if (game.get_piece(xpos, ypos)->which_player() != this->which_player()) {
                    possible_moves[xpos][ypos] = 2;
                    num_moves++;
                }
                break;
            }
        } else {
            break;
        }
        ypos++;
        xpos++;
    }

    xpos = x - 1;
    ypos = y + 1;
    while (true) {
        if (game.in_boundaries(xpos, ypos)) {
            if (game.get_piece(xpos, ypos) == nullptr) {
                possible_moves[xpos][ypos] = 2;
                num_moves++;
            } else {
                if (game.get_piece(xpos, ypos)->which_player() != this->which_player()) {
                    possible_moves[xpos][ypos] = 2;
                    num_moves++;
                }
                break;
            }
        } else {
            break;
        }
        ypos++;
        xpos--;
    }
    xpos = x - 1;
    ypos = y - 1;
    while (true) {
        if (game.in_boundaries(xpos, ypos)) {
            if (game.get_piece(xpos, ypos) == nullptr) {
                possible_moves[xpos][ypos] = 2;
                num_moves++;
            } else {
                if (game.get_piece(xpos, ypos)->which_player() != this->which_player()) {
                    possible_moves[xpos][ypos] = 2;
                    num_moves++;
                }
                break;
            }
        } else {
            break;
        }
        ypos--;
        xpos--;
    }

    xpos = x + 1;
    ypos = y - 1;
    while (true) {
        if (game.in_boundaries(xpos, ypos)) {
            if (game.get_piece(xpos, ypos) == nullptr) {
                possible_moves[xpos][ypos] = 2;
                num_moves++;
            } else {
                if (game.get_piece(xpos, ypos)->which_player() != this->which_player()) {
                    possible_moves[xpos][ypos] = 2;
                    num_moves++;
                }
                break;
            }
        } else {
            break;
        }
        ypos--;
        xpos++;
    }




//    for (int i = 0; i < 14; ++i) {
//        for (int j = 0; j < 14; ++j) {
//            std::cout<<possible_moves[i][j] << " ";
//        }
//        std::cout<<std::endl;

//    }

    return num_moves;
}

std::string Bishop::get_img() const {
    return ":/img/Player" + std::to_string(player.get_index()) + "/bishop.png";

}
