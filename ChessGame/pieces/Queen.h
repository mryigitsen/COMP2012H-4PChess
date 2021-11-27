//
// Created by Yigit Sen on 13/11/2021.
//

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

    std::string get_img() const;

};


#endif //INC_4PCHESS_QUEEN_H
