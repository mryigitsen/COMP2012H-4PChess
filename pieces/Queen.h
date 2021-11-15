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
Queen(Player& player, Game& game);
    virtual Piece::Type get_type() const ;
    virtual int get_point() const;
    virtual void list_possible_moves();
    void convert();
};


#endif //INC_4PCHESS_QUEEN_H
