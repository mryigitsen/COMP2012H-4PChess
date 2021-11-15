//
// Created by Yigit Sen on 13/11/2021.
//

#include "Bishop.h"
#include "Piece.h"



Bishop::Bishop(Player& player, Game& game): Piece(player, game) {}

Piece::Type Bishop::get_type() const{
    return Piece::Type::BISHOP;
}

int Bishop::get_point() const{
    return 5;
}

void Bishop::list_possible_moves(){
    //Do nothing
}

