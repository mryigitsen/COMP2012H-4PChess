//
// Created by Yigit Sen on 13/11/2021.
//

#ifndef INC_4PCHESS_BISHOP_H
#define INC_4PCHESS_BISHOP_H
#include "Piece.h"
class Bishop : public Piece {
    public:
        Bishop(Player& player, Game& game);
        virtual Piece::Type get_type() const;
        virtual int get_point() const;
        virtual void list_possible_moves();
};


#endif //INC_4PCHESS_BISHOP_H
