//
// Created by Yigit Sen on 13/11/2021.
//
#include <iostream>
#include "Game.h"
int main()
{
    Game* temp = new Game();
    temp->print_board();
    std::cout<<std::endl;
    //temp->delete_piece(12, 10);
    temp->print_board();
    std::cout<<std::endl;

    temp->get_piece(13,10)->list_possible_moves();
    std::cout<<std::endl;

    temp->movePiece(13, 10, 1, 10);
    temp->movePiece(1, 10, 7, 7);
    temp->print_board();
    std::cout<<std::endl;

    temp->get_piece(7,7)->list_possible_moves();

    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;

    temp->movePiece(12, 4, 0, 5);
    temp->print_board();
    temp->get_piece(0,5)->list_possible_moves();

    temp->movePiece(0, 5, 4, 7);
    temp->print_board();
    temp->get_piece(4,7)->list_possible_moves();

    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;


    Game* temp2 = new Game();
    temp2->print_board();
    std::cout<<std::endl;

    // temp2->delete_piece(12, 6);
    // temp2->delete_piece(12, 7);
    // temp2->delete_piece(12, 8);

    temp2->print_board();
    std::cout<<std::endl;

    temp2->get_piece(13,7)->list_possible_moves();
    std::cout<<std::endl;




    temp2->movePiece(13, 7, 7, 7);
    temp2->print_board();
    std::cout<<std::endl;

    temp2->get_piece(7,7)->list_possible_moves();
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;

    Game* temp3 = new Game();
    temp3->print_board();
    std::cout<<std::endl;

    temp3->get_piece(13,9)->list_possible_moves();
    std::cout<<std::endl;

    temp3->movePiece(13, 9, 7, 7);
    temp3->print_board();
    std::cout<<std::endl;

    temp3->get_piece(7,7)->list_possible_moves();


    Game* temp4 = new Game();
    temp4->print_board();
    std::cout<<std::endl;

    // temp4->delete_piece(12, 9);
    // temp4->delete_piece(12, 7);
    // temp4->delete_piece(12, 8);

    temp4->print_board();
    std::cout<<std::endl;

    temp4->get_piece(13,8)->list_possible_moves();
    std::cout<<std::endl;




    temp4->movePiece(13, 8, 7, 7);
    temp4->print_board();
    std::cout<<std::endl;

    temp4->get_piece(7,7)->list_possible_moves();


    Game* temp5 = new Game();
    temp5->print_board();
    std::cout<<std::endl;
    temp5->get_piece(12,3)->list_possible_moves();
    std::cout<<std::endl;
    temp5->get_piece(12,4)->list_possible_moves();
    std::cout<<std::endl;
    temp5->get_piece(10,1)->list_possible_moves();
    std::cout<<std::endl;
    temp5->get_piece(9,1)->list_possible_moves();
    std::cout<<std::endl;
    temp5->get_piece(1,3)->list_possible_moves();
    std::cout<<std::endl;
    temp5->get_piece(1,4)->list_possible_moves();
    std::cout<<std::endl;
    temp5->get_piece(4,12)->list_possible_moves();
    std::cout<<std::endl;
    temp5->get_piece(5,12)->list_possible_moves();
    std::cout<<std::endl;

    temp->print_board();
    //temp->make_turn();
}
