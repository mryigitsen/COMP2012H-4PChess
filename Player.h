//
// Created by Yigit Sen on 13/11/2021.
//

#ifndef INC_4PCHESS_PLAYER_H
#define INC_4PCHESS_PLAYER_H


class Player {
private:
    bool is_active;
    int score;
    int indexNum;

public:
        enum class Direction{
            UP,
            DOWN,
            LEFT,
            RIGHT,

            DIRECTION
        };
    void set_index(int index);
    int get_index();

};


#endif //INC_4PCHESS_PLAYER_H
