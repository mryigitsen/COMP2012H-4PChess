//
// Created by Yigit Sen on 13/11/2021.
//

#include "Pawn.h"
Pawn::Pawn(Player& player, Game& game, int x, int y): Piece(player, game, x, y) {}


Piece::Type Pawn::get_type() const {
    return Piece::Type::PAWN;
}

int Pawn::get_point() const{
    return 1;
}
void Pawn::list_possible_moves(){
    //Do nothing
}
