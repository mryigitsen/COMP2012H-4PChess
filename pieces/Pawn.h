//
// Created by Yigit Sen on 13/11/2021.
//

#ifndef INC_4PCHESS_PAWN_H
#define INC_4PCHESS_PAWN_H
#include "Piece.h"

class Pawn : public Piece{
public:
    Pawn(Player& player, Game& game, int x, int y);
    virtual Piece::Type get_type() const;
    virtual int get_point() const;
    virtual void list_possible_moves();

};


#endif //INC_4PCHESS_PAWN_H
