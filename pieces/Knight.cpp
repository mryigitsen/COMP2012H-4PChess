//
// Created by Yigit Sen on 13/11/2021.
//

#include "Knight.h"
#include "iostream"
#include "../Game.h"
Knight::Knight(Player& player, Game& game, int x, int y): Piece(player, game, x, y) {}

Piece::Type Knight::get_type() const{
    return Piece::Type::KNIGHT;
}

int Knight::get_point() const{
    return 3;
}

void Knight::list_possible_moves(){
    //Do nothing
    int temp[14][14] = {0};
    temp[x][y] = 1;

    if(game.in_boundaries(x + 2, y + 1)) {
        if(game.get_piece(x + 2, y + 1) != nullptr) {
            if(game.get_piece(x + 2, y + 1)->which_player() != player.get_index())
                temp[x+2][y+1] = 2;
        }
        else
        {
            temp[x+2][y+1] = 2;
        }
    }

    if(game.in_boundaries(x + 2, y - 1)) {
        if(game.get_piece(x + 2, y - 1) != nullptr) {
            if(game.get_piece(x + 2, y - 1)->which_player() != player.get_index())
                temp[x+2][y-1] = 2;
        }
        else
        {
            temp[x+2][y-1] = 2;
        }
    }

    if(game.in_boundaries(x - 2, y + 1)) {
        if(game.get_piece(x - 2, y + 1) != nullptr) {
            if(game.get_piece(x - 2, y + 1)->which_player() != player.get_index())
                temp[x-2][y+1] = 2;
        }
        else
        {
            temp[x-2][y+1] = 2;


        }
    }
    if(game.in_boundaries(x - 2, y - 1)) {
        if(game.get_piece(x - 2, y - 1) != nullptr) {
            if(game.get_piece(x - 2, y - 1)->which_player() != player.get_index())
                temp[x-2][y-1] = 2;
        }
        else{
            temp[x-2][y-1] = 2;
        }
    }

    if(game.in_boundaries(x + 1, y + 2)) {
        if(game.get_piece(x + 1, y + 2) != nullptr) {
            if(game.get_piece(x + 1, y + 2)->which_player() != player.get_index())
                temp[x+1][y+2] = 2;
        }
        else{
            temp[x+1][y+2] = 2;
        }
    }
    if(game.in_boundaries(x - 1, y + 2)) {
        if(game.get_piece(x - 1, y + 2) != nullptr) {
            if(game.get_piece(x - 1, y + 2)->which_player() != player.get_index())
                temp[x-1][y+2] = 2;
        }
        else{
            temp[x-1][y+2] = 2;

        }
    }
    if(game.in_boundaries(x + 1, y - 2)) {
        if(game.get_piece(x + 1, y - 2) != nullptr) {
            if(game.get_piece(x + 1, y - 2)->which_player() != player.get_index())
                temp[x+1][y-2] = 2;
        }
        else{
            temp[x+1][y-2] = 2;
        }
    }
    if(game.in_boundaries(x - 1, y - 2)) {
        if(game.get_piece(x - 1, y - 2) != nullptr) {
            if(game.get_piece(x - 1, y - 2)->which_player() != player.get_index())
                temp[x-1][y-2] = 2;
        }
        else{
            temp[x-1][y-2] = 2;

        }
    }

    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 14; ++j) {
            std::cout<<temp[i][j] << " ";
        }
        std::cout<<std::endl;

    }
}