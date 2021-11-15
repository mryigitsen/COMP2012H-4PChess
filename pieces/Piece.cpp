//
// Created by Yigit Sen on 13/11/2021.
//

#include "Piece.h"

Piece::Piece(Player& player, Game& game): player{player}, game{game} {}

int Piece::which_player() {return player.get_index();}