//
// Created by Yigit Sen on 13/11/2021.
//

#ifndef INC_4PCHESS_GAME_H
#define INC_4PCHESS_GAME_H

#include "pieces/Piece.h"
#include "pieces/Bishop.h"
#include "pieces/King.h"
#include "pieces/Knight.h"
#include "pieces/Pawn.h"
#include "pieces/Queen.h"
#include "pieces/Rook.h"
#include "Player.h"

class Player;

class Game {
    public:
        struct Tile{
            Piece* piece;
            bool is_activated = true;
        };

        Game();
        int get_current_turn() const;
        void next_turn(); 
        void print_board();
        void delete_piece(int x, int y);
    Tile board[14][14];
    bool in_boundaries( int x, int y);
    Piece* get_piece(int x, int y);
    void movePiece(int initX, int initY, int destX, int destY);
    void make_turn(int initX, int initY, int destX, int destY);


private:
        //Player* players[4] {nullptr, nullptr, nullptr, nullptr};
        Player players[4];
        int player_turn;
        ~Game();
        
        struct Coordinates{
            int x_coordinate;
            int y_coordinate;
        };
};


#endif //INC_4PCHESS_GAME_H
