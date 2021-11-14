//
// Created by Yigit Sen on 13/11/2021.
//

#include "Bishop.h"
#include "Piece.h"


Bishop::Bishop(Player& player, Game& game): Piece(player, game) {}

Piece::Type Bishop::get_type() {
    return Piece::Type::BISHOP;
}

int Bishop::get_point(){
    return 3;
}

//void Bishop::list_possible_moves(){
    //if (*this)
//}

