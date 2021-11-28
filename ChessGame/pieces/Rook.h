//

#ifndef INC_4PCHESS_ROOK_H
#define INC_4PCHESS_ROOK_H

#include "Piece.h"


class Rook : public Piece {

    public:
        Rook(Player &player, Game &game, int x, int y);

        virtual Piece::Type get_type() const override;

        virtual int get_point() const override;

        virtual int list_possible_moves() override;

        std::string get_img() const override;
};


#endif //INC_4PCHESS_ROOK_H
