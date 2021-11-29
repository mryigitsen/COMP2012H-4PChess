// Bishop class publicly inherits the Piece class which has all the base attributes that chess pieces should contain
// The Bishop class has its own member functions that only apply to all Bishop pieces on the board

#ifndef INC_4PCHESS_BISHOP_H
#define INC_4PCHESS_BISHOP_H

#include "Piece.h"

class Bishop : public Piece {

    public:
        Bishop(Player &player, Game &game, int x, int y);

        virtual Piece::Type get_type() const override;

        virtual int get_point() const override;

        virtual int list_possible_moves() override;

        std::string get_img() const override;
};


#endif //INC_4PCHESS_BISHOP_H
