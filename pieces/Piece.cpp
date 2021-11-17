//
// Created by Yigit Sen on 13/11/2021.
//

#include "Piece.h"

Piece::Piece(Player& player, Game& game, int x, int y): player{player}, game{game}, x(x), y(y) {}

int Piece::which_player() {return player.get_index();}

void Piece::setCoordinates(int x, int y){
    this->x = x;
    this->y = y;
}
