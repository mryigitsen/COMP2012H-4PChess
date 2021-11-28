//
// Created by Yigit Sen on 13/11/2021.
//

#ifndef INC_4PCHESS_PLAYER_H
#define INC_4PCHESS_PLAYER_H
//#include "Game.h"

class Game;

class Piece;

class Player {
private:
    bool is_active = false;
    int score = 0;
    int indexNum = 0;
    Game &game;
    bool is_bot = false;
    bool is_online = false;

public:
    enum class Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT,

        DIRECTION
    };

    ~Player();

    void set_index(int index);

    int get_index();

    Player(Game &game);

    bool is_in_game();

    bool check_move();

    int get_score();

    void increase_score(int);

    void deactivate();

    void generate_threat_map();

    bool get_is_bot() const;
    void set_is_bot();
    bool get_is_online() const;
    void set_is_online();
    int num_pieces = 0;
    Piece *pieces[16];
};


#endif //INC_4PCHESS_PLAYER_H
