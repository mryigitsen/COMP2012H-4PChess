//
// Created by Yigit Sen on 13/11/2021.
//

#ifndef INC_4PCHESS_PIECE_H
#define INC_4PCHESS_PIECE_H
#include <string>
#include "../Player.h"
//#include "../Game.h"
class Game;
class Player;


class Piece {
protected:
    explicit Piece(Player &player, Game &game, int x, int y);

    Player &player;
    Game &game;
    bool is_captured;
    int points;
    bool has_moved;

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

        virtual int list_possible_moves() = 0;
        void set_is_captured(bool);

        int possible_moves[14][14];

        bool get_has_moved();

        void set_points(int);
        void set_has_moved(bool);

        // bool operator==(const Piece& piece) {
        //     return ((x == piece.x) && (y == piece.y));
        // }

};


#endif //INC_4PCHESS_PIECE_H
