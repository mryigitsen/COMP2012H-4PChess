//
// Created by Yigit Sen on 13/11/2021.
//

#include "Knight.h"
Knight::Knight(Player& player, Game& game): Piece(player, game) {}

Piece::Type Knight::get_type() const{
    return Piece::Type::KNIGHT;
}

int Knight::get_point() const{
    return 3;
}

void Knight::list_possible_moves(){
    //Do nothing
}