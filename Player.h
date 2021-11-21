//
// Created by Yigit Sen on 13/11/2021.
//

#ifndef INC_4PCHESS_PLAYER_H
#define INC_4PCHESS_PLAYER_H
#include "./Game.h"

class Game;

class Player {
private:
    bool is_active;
    int score;
    int indexNum;
    bool opp_threat_map[14][14];
    //Game& game;
    //Game game;

public:
        enum class Direction{
            UP,
            DOWN,
            LEFT,
            RIGHT,

            DIRECTION
        };
    //Player(Game& game);
    
    void set_index(int index);
    int get_index();
    void generate_threat_map();
};


#endif //INC_4PCHESS_PLAYER_H
