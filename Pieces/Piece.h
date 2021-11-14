//
// Created by Yigit Sen on 13/11/2021.
//

#ifndef INC_4PCHESS_PIECE_H
#define INC_4PCHESS_PIECE_H
#include <string>
//class Player;
//class Game;
#include "../Game.h"
#include "../Player.h"
#include "./Bishop.h"
#include "./King.h"
#include "./Knight.h"
#include "./Pawn.h"
#include "./Queen.h"
#include "./Rook.h"

class Piece {
    public:
        enum class Type {
            BISHOP = 1,
            KING = 2,
            KNIGHT = 3,
            PAWN = 4,
            QUEEN = 5,
            ROOK = 6
        };

        virtual ~Piece() = default;

        virtual Piece::Type get_type() const = 0;

        virtual int get_point() const = 0;

        virtual void list_possible_moves() = 0;

    protected:
        explicit Piece(Player &player, Game &game, Game::Coordinates coordinates);

        Player &player;
        Game &game;

        Game::Coordinates coordinates;
};


#endif //INC_4PCHESS_PIECE_H
