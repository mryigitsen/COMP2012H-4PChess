//
// Created by Yigit Sen on 13/11/2021.
//

#include "Piece.h"
#include "../Game.h"
Piece::Piece(Player& player, Game& game, int x, int y): player{player}, game{game}, x(x), y(y), is_captured(false), has_moved(false) {}

int Piece::which_player() {return player.get_index();}

void Piece::setCoordinates(int x, int y){
    this->x = x;
    this->y = y;
}

void Piece::set_is_captured(bool status) {
    is_captured = status;
}

void Piece::set_points(int points) {
    this->points = points;
}

void Piece::set_has_moved(bool moved) {
    has_moved = moved;
}

bool Piece::get_has_moved() {
    return has_moved;
}