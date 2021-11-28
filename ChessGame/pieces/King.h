//


#ifndef INC_4PCHESS_KING_H
#define INC_4PCHESS_KING_H

#include "Piece.h"
#include <iostream>
#include "../Game.h"

class King : public Piece {

    public:
        King(Player &player, Game &game, int x, int y);

        virtual Piece::Type get_type() const override;

        virtual int get_point() const override;

        virtual int list_possible_moves() override;

        std::string get_img() const;
};


#endif //INC_4PCHESS_KING_H
