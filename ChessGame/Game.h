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
#include "chessclientobj.h"
#include "mainwindow.h"
class Player;
class ChessClientObj;
class MainWindow;
class Game {
public:
    struct Tile {
        Piece *piece;
        bool is_activated = true;

        // void operator=(const Tile& tile) {
        //     *(this->piece) = *(tile.piece);
        //     this->is_activated = tile.is_activated;
        // }
    };
    int get_local_player();

    Game(ChessClientObj *client = nullptr, int botCount = 0, bool online = false, bool firstOnline = true, MainWindow *mw = nullptr);

    int get_current_turn() const;

    void next_turn();

    void print_board();
    void end_game(bool end_to_disconnect);
    int active_players();


    void delete_piece(int x, int y);

    Tile board[14][14];

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

    bool get_is_online();

    int get_online_player();

    Player* get_player_at(int index);

    void deactivate_player(int index, std::string status);

private:
    //local player is only being used IF THIS IS AN ONLINE GAME
    int local_player;
    Player *players[4];
    int player_turn = 0;
    int turn_number;
    bool is_ended = false;
    bool is_online = false;
    ChessClientObj *client = nullptr;
    MainWindow *mw;

    ~Game();

    struct Coordinates {
        int x_coordinate;
        int y_coordinate;
    };
};


#endif //INC_4PCHESS_GAME_H
