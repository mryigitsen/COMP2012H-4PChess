//
// Created by Yigit Sen on 13/11/2021.
//

#include "Player.h"
#include "Game.h"

//Player::Player(Game& game) : game{game} {}

void Player::set_index(int index)
{
    indexNum = index;
}
int Player::get_index()
{
    return indexNum;
}

// void Player::generate_threat_map() {
//     for(int i = 0; i < 14; ++i) {
//         for(int j = 0; j < 14; ++j) {
//             if(!game.in_boundaries(i, j))
//                 continue;
//         }
//     }
// }