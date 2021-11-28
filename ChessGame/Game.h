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

    private:
        Player *players[4];
        int player_turn = 0;
        int turn_number;
        bool is_ended = false;

        ~Game();

    public:
        struct Tile {
            Piece *piece;
            bool is_activated = true;
        };

        Tile board[14][14];

        Game(int botCount = 0);

        void print_board();

        bool in_boundaries(int x, int y);

        Piece *get_piece(int x, int y);

        void movePiece(int initX, int initY, int destX, int destY);

        bool is_checked(int index, const int (&board_copy)[14][14]);

        int is_checked_player(int index, const int (&board_copy)[14][14]);

        void create_board_copy(int current_turn, int (&board_copy)[14][14]);

        void make_turn();

        int get_cur_player();

        Player* get_cur_player_pointer() const;

        void bot_move_piece();

        int get_random_number(int min, int max);
};


#endif //INC_4PCHESS_GAME_H
