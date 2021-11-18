//
// Created by Yigit Sen on 13/11/2021.
//
#include <iostream>
#include "King.h"
#include "../Game.h"
King::King(Player& player, Game& game, int x, int y): Piece(player, game, x, y) {}

Piece::Type King::get_type() const{
    return Piece::Type::KING;
}

int King::get_point() const{
    return 20;
}

void King::list_possible_moves(){
    //Do nothing
    int temp[14][14] = {0};
    for(int i = x-1; i < x + 2; ++i) {
        for(int j = y-1; j < y + 2; ++j) {
            if(game.in_boundaries(i, j) == false)
                continue;

            if(game.get_piece(i,j) != nullptr){ 
                if(game.get_piece(i,j)->which_player() != player.get_index()) {
                    temp[i][j] = 2;
                }
            }
            else {
                temp[i][j] = 2;
            }

        }
    }

    temp[x][y] = 1;

    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 14; ++j) {
            std::cout<<temp[i][j] << " ";
        }
        std::cout<<std::endl;

    }
}
