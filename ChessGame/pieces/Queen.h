// Queen class publicly inherits the Piece class which has all the base attributes that chess pieces should contain
// The Queen class has its own member functions that only apply to all Queen pieces on the board


#ifndef INC_4PCHESS_QUEEN_H
#define INC_4PCHESS_QUEEN_H

#include "Piece.h"


class Queen : public Piece {

    private:
        bool converted = false;

    public:
        Queen(Player &player, Game &game, int x, int y);

        Queen(Player &player, Game &game, int x, int y, int pos);

        virtual Piece::Type get_type() const override;

        virtual int get_point() const override;

        virtual int list_possible_moves() override;

        void convert();

        std::string get_img() const override;
};


#endif //INC_4PCHESS_QUEEN_H
