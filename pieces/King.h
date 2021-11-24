//
// Created by Yigit Sen on 13/11/2021.
//

#ifndef INC_4PCHESS_KING_H
#define INC_4PCHESS_KING_H
#include "Piece.h"
#include <iostream>
#include "../Game.h"

class King : public Piece {
public:
    King(Player& player, Game& game, int x, int y);
    virtual Piece::Type get_type() const override;
    virtual int get_point() const override;
    virtual int list_possible_moves() override;

};


#endif //INC_4PCHESS_KING_H
