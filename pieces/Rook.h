//
// Created by Yigit Sen on 13/11/2021.
//

#ifndef INC_4PCHESS_ROOK_H
#define INC_4PCHESS_ROOK_H
#include "Piece.h"


class Rook : public Piece {
public:
    Rook(Player& player, Game& game);
    virtual Piece::Type get_type() const override;
    virtual int get_point() const override;
    virtual void list_possible_moves();

};


#endif //INC_4PCHESS_ROOK_H
