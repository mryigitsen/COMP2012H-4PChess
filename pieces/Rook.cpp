//
// Created by Yigit Sen on 13/11/2021.
//

#include "Rook.h"
Rook::Rook(Player& player, Game& game): Piece(player, game) {}

Piece::Type Rook::get_type() const {
    return Piece::Type::ROOK;
}

int Rook::get_point() const{
    return 5;
}

void Rook::list_possible_moves(){
    //Do nothing
}
