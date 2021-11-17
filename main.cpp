//
// Created by Yigit Sen on 13/11/2021.
//
#include <iostream>
#include "Game.h"
int main()
{
    Game* temp = new Game();
    temp->print_board();
    temp->delete_piece(12, 10);
    temp->print_board();
    temp->get_piece(13,10)->list_possible_moves();
    temp->movePiece(13, 10, 7, 7);
    temp->print_board();
    temp->get_piece(7,7)->list_possible_moves();

}