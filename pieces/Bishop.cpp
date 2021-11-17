//
// Created by Yigit Sen on 13/11/2021.
//

#include "Bishop.h"
#include "Piece.h"



Bishop::Bishop(Player& player, Game& game, int x, int y): Piece(player, game, x, y) {}

Piece::Type Bishop::get_type() const{
    return Piece::Type::BISHOP;
}

int Bishop::get_point() const{
    return 3;
}

void Bishop::list_possible_moves(){
    //Check for +Y-dir
    int xpos = 0;
    while(true)
    {


    }
    //Do nothing
}

