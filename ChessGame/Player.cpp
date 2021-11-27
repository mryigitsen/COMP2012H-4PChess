//
// Created by Yigit Sen on 13/11/2021.
//

#include "Player.h"
#include "Game.h"

Player::Player(Game &game) :  is_active{true}, game{game}, is_bot{false} {}

Player::~Player() {
    for (int i = 0; i < 16; ++i) {
        delete pieces[i];
    }
}

void Player::set_index(int index) {
    indexNum = index;
}

int Player::get_index() {
    return indexNum;
}

void Player::generate_threat_map() {
    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 14; ++j) {
            if (game.in_boundaries(i, j)) {

            }
        }
    }
}

bool Player::is_in_game() {
    return is_active;
}

bool Player::check_move() {
    return true;
}

void Player::increase_score(int score) {
    this->score += score;
}

int Player::get_score() {
    return score;
}

void Player::deactivate() {
    std::cout << "DEACTIVATING" << std::endl;
    for (int i = 0; i < 16; ++i) {
        pieces[i]->set_points(0);
    }
    is_active = false;
}

bool Player::get_is_bot() const {
    return is_bot;
}
void Player::set_is_bot() {
    is_bot = true;
}
