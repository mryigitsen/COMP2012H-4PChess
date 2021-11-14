//
// Created by Yigit Sen on 13/11/2021.
//

#ifndef INC_4PCHESS_PLAYER_H
#define INC_4PCHESS_PLAYER_H


class Player {
    public:
        enum class Direction{
            UP,
            DOWN,
            LEFT,
            RIGHT,

            DIRECTION
        };

    private:
        bool is_active;
        int score;
        Direction direction;
};


#endif //INC_4PCHESS_PLAYER_H
