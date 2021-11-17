//
// Created by Yigit Sen on 13/11/2021.
//

#include "Queen.h"
Queen::Queen(Player& player, Game& game, int x, int y): Piece(player, game, x, y) {}


Piece::Type Queen::get_type() const{
    return Piece::Type::QUEEN;
}

int Queen::get_point() const{
    if(converted)
        return 1;
    else
        return 9;
}

void Queen::list_possible_moves(){
    //Do nothing
}
void Queen::convert() {
    converted = true;
}
