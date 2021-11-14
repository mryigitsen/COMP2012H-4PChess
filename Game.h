//
// Created by Yigit Sen on 13/11/2021.
//

#ifndef INC_4PCHESS_GAME_H
#define INC_4PCHESS_GAME_H

#include "./Pieces/Piece.h"
#include "Player.h"

class Game {
    public:
        struct Tile{
            Piece* piece;
            bool is_activated;
        };

        Game();
        int get_current_turn() const;
        void next_turn(); 

    private:
        Tile board[14][14];
        Player players[4];
        int player_turn;
        
        struct Coordinates{
            int x_coordinate;
            int y_coordinate;
        };
};


#endif //INC_4PCHESS_GAME_H
