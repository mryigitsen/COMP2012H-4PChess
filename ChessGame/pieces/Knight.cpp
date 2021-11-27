//
// Created by Yigit Sen on 13/11/2021.
//

#include "Knight.h"
#include "iostream"
#include "../Game.h"

Knight::Knight(Player &player, Game &game, int x, int y) : Piece(player, game, x, y) {
    points = 3;
    player.pieces[player.num_pieces++] = this;

}

Piece::Type Knight::get_type() const {
    return Piece::Type::KNIGHT;
}

int Knight::get_point() const {
    return points;
}

int Knight::list_possible_moves() {
//    std::cout<<"knight"<<std::endl;

    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 14; ++j) {
            possible_moves[i][j] = 0;
        }
    }
    possible_moves[x][y] = 1;
    int num_moves = 0;

    if (game.in_boundaries(x + 2, y + 1)) {
        if (game.get_piece(x + 2, y + 1) != nullptr) {
            if (game.get_piece(x + 2, y + 1)->which_player() != player.get_index()) {
                possible_moves[x + 2][y + 1] = 2;
                num_moves++;
            }
        } else {
            possible_moves[x + 2][y + 1] = 2;
            num_moves++;
        }
    }

    if (game.in_boundaries(x + 2, y - 1)) {
        if (game.get_piece(x + 2, y - 1) != nullptr) {
            if (game.get_piece(x + 2, y - 1)->which_player() != player.get_index()) {
                possible_moves[x + 2][y - 1] = 2;
                num_moves++;
            }
        } else {
            possible_moves[x + 2][y - 1] = 2;
            num_moves++;
        }
    }

    if (game.in_boundaries(x - 2, y + 1)) {
        if (game.get_piece(x - 2, y + 1) != nullptr) {
            if (game.get_piece(x - 2, y + 1)->which_player() != player.get_index()){
                possible_moves[x - 2][y + 1] = 2;
                num_moves++;
            }
        } else {
            possible_moves[x - 2][y + 1] = 2;
            num_moves++;


        }
    }
    if (game.in_boundaries(x - 2, y - 1)) {
        if (game.get_piece(x - 2, y - 1) != nullptr) {
            if (game.get_piece(x - 2, y - 1)->which_player() != player.get_index()){
                possible_moves[x - 2][y - 1] = 2;
                num_moves++;
            }
        } else {
            possible_moves[x - 2][y - 1] = 2;
            num_moves++;
        }
    }

    if (game.in_boundaries(x + 1, y + 2)) {
        if (game.get_piece(x + 1, y + 2) != nullptr) {
            if (game.get_piece(x + 1, y + 2)->which_player() != player.get_index()){
                possible_moves[x + 1][y + 2] = 2;
                num_moves++;
            }
        } else {
            possible_moves[x + 1][y + 2] = 2;
            num_moves++;
        }
    }
    if (game.in_boundaries(x - 1, y + 2)) {
        if (game.get_piece(x - 1, y + 2) != nullptr) {
            if (game.get_piece(x - 1, y + 2)->which_player() != player.get_index()){
                possible_moves[x - 1][y + 2] = 2;
                num_moves++;
            }
        } else {
            possible_moves[x - 1][y + 2] = 2;
            num_moves++;

        }
    }
    if (game.in_boundaries(x + 1, y - 2)) {
        if (game.get_piece(x + 1, y - 2) != nullptr) {
            if (game.get_piece(x + 1, y - 2)->which_player() != player.get_index()){
                possible_moves[x + 1][y - 2] = 2;
                num_moves++;
            }
        } else {
            possible_moves[x + 1][y - 2] = 2;
            num_moves++;
        }
    }
    if (game.in_boundaries(x - 1, y - 2)) {
        if (game.get_piece(x - 1, y - 2) != nullptr) {
            if (game.get_piece(x - 1, y - 2)->which_player() != player.get_index()){
                possible_moves[x - 1][y - 2] = 2;
                num_moves++;
            }
        } else {
            possible_moves[x - 1][y - 2] = 2;
            num_moves++;

        }
    }

//    for (int i = 0; i < 14; ++i) {
//        for (int j = 0; j < 14; ++j) {
//            std::cout<<possible_moves[i][j] << " ";
//        }
//        std::cout<<std::endl;

//    }

    return num_moves;
}

std::string Knight::get_img() const {
    return ":/img/Player" + std::to_string(player.get_index()) + "/knight.png";

}
