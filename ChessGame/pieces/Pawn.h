//

#ifndef INC_4PCHESS_PAWN_H
#define INC_4PCHESS_PAWN_H

#include "Piece.h"


class Pawn : public Piece {

    private:
        bool is_2_move_opening = false;

    public:
        Pawn(Player &player, Game &game, int x, int y);

        virtual Piece::Type get_type() const override;

        virtual int get_point() const override;

        virtual int list_possible_moves() override;

        std::string get_img() const override;
};


#endif //INC_4PCHESS_PAWN_H
