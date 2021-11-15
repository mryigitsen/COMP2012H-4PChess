//
// Created by Yigit Sen on 13/11/2021.
//

#include "King.h"
King::King(Player& player, Game& game): Piece(player, game) {}

Piece::Type King::get_type() const{
    return Piece::Type::KING;
}

int King::get_point() const{
    return 20;
}

void King::list_possible_moves(){
    //Do nothing
}
