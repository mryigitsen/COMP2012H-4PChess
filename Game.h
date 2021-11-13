//
// Created by Yigit Sen on 13/11/2021.
//

#ifndef INC_4PCHESS_GAME_H
#define INC_4PCHESS_GAME_H

#include "./Pieces/Piece.h"
#include "Player.h"

class Game {
    private:
        Piece ***board;
        Player players[4];

    public:
        Game() {};
};


#endif //INC_4PCHESS_GAME_H
