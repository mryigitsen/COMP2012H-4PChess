//
// Created by Yigit Sen on 13/11/2021.
//

#ifndef INC_4PCHESS_PIECE_H
#define INC_4PCHESS_PIECE_H
#include <string>
#include "../Player.h"
class Game;
class Player;


class Piece {
protected:
    explicit Piece(Player &player, Game &game, int x, int y);

    Player &player;
    Game &game;

    public:
        enum class Type {
            BISHOP = 1,
            KING = 2,
            KNIGHT = 3,
            PAWN = 4,
            QUEEN = 5,
            ROOK = 6
        };
        int x;
        int y;
        int which_player();
        void setCoordinates(int x, int y);
        virtual ~Piece() = default;

        virtual Piece::Type get_type() const = 0;

        virtual int get_point() const = 0;

        virtual void list_possible_moves() = 0;

};


#endif //INC_4PCHESS_PIECE_H
