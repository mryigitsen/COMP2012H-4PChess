
#include "Piece.h"
#include <iostream>
#include "../Game.h"

King::King(Player &player, Game &game, int x, int y) : Piece(player, game, x, y) {
    points = 20;
    player.pieces[player.num_pieces++] = this;

}

Piece::Type King::get_type() const {
    return Piece::Type::KING;
}

int King::get_point() const {
    return points;
}

int King::list_possible_moves() {
//    std::cout<<"king"<<std::endl;
    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 14; ++j) {
            possible_moves[i][j] = 0;
        }
    }
    possible_moves[x][y] = 1;
    int num_moves = 0;

    for (int i = x - 1; i < x + 2; ++i) {
        for (int j = y - 1; j < y + 2; ++j) {
            if (game.in_boundaries(i, j) == false)
                continue;

            if (game.get_piece(i, j) != nullptr) {
                if (game.get_piece(i, j)->which_player() != player.get_index()) {
                    possible_moves[i][j] = 2;
                    num_moves++;
                }
            } else {
                possible_moves[i][j] = 2;
                num_moves++;
            }
        }
    }


    //CASTLING
    int board_copy[14][14];
    game.create_board_copy(which_player(), board_copy);
    int index = which_player();
    if (!has_moved) {

        if (!game.is_checked(index, board_copy)) {

            if (index == 0) {
                if (game.get_piece(x, y + 3) != nullptr && !game.get_piece(x, y + 3)->get_has_moved()) {
                    int board_copy_castle[14][14];
                    game.create_board_copy(which_player(), board_copy_castle);
                    board_copy_castle[x][y+1] = board_copy_castle[x][y];
                    board_copy_castle[x][y] = 0;
                    if(!game.is_checked(index, board_copy_castle)){
                        if (game.get_piece(x, y + 1) == nullptr && game.get_piece(x, y + 2) == nullptr) {
                            possible_moves[x][y + 2] = 2;
                            num_moves++;
                        }
                    }
                }
                if (game.get_piece(x, y - 4) != nullptr && !game.get_piece(x, y - 4)->get_has_moved()) {
                    int board_copy_castle[14][14];
                    game.create_board_copy(which_player(), board_copy_castle);
                    board_copy_castle[x][y-1] = board_copy_castle[x][y];
                    board_copy_castle[x][y] = 0;
                    if(!game.is_checked(index, board_copy_castle)){
                        if (game.get_piece(x, y - 1) == nullptr && game.get_piece(x, y - 2) == nullptr &&
                                game.get_piece(x, y - 3) == nullptr){
                            possible_moves[x][y - 2] = 2;
                            num_moves++;
                        }
                    }
                }
            } else if (index == 1) {
                if (game.get_piece(x - 3, y) != nullptr && !game.get_piece(x - 3, y)->get_has_moved()) {
                    int board_copy_castle[14][14];
                    game.create_board_copy(which_player(), board_copy_castle);
                    board_copy_castle[x-1][y] = board_copy_castle[x][y];
                    board_copy_castle[x][y] = 0;
                    if(!game.is_checked(index, board_copy_castle)){
                        if (game.get_piece(x - 1, y) == nullptr && game.get_piece(x - 2, y) == nullptr){
                            possible_moves[x - 2][y] = 2;
                            num_moves++;
                        }
                    }
                }
                if (game.get_piece(x + 4, y) != nullptr && !game.get_piece(x + 4, y)->get_has_moved()) {
                    int board_copy_castle[14][14];
                    game.create_board_copy(which_player(), board_copy_castle);
                    board_copy_castle[x+1][y] = board_copy_castle[x][y];
                    board_copy_castle[x][y] = 0;
                    if(!game.is_checked(index, board_copy_castle)){
                        if (game.get_piece(x + 1, y) == nullptr && game.get_piece(x + 2, y) == nullptr &&
                                game.get_piece(x + 3, y) == nullptr){
                            possible_moves[x + 2][y] = 2;
                            num_moves++;
                        }
                    }
                }
            } else if (index == 2) {
                if (game.get_piece(x, y - 3) != nullptr && !game.get_piece(x, y - 3)->get_has_moved()) {
                    int board_copy_castle[14][14];
                    game.create_board_copy(which_player(), board_copy_castle);
                    board_copy_castle[x][y-1] = board_copy_castle[x][y];
                    board_copy_castle[x][y] = 0;
                    if(!game.is_checked(index, board_copy_castle)){
                        if (game.get_piece(x, y - 1) == nullptr && game.get_piece(x, y - 2) == nullptr){
                            possible_moves[x][y - 2] = 2;
                            num_moves++;
                        }
                    }
                }
                if (game.get_piece(x, y + 4) != nullptr && !game.get_piece(x, y + 4)->get_has_moved()) {
                    int board_copy_castle[14][14];
                    game.create_board_copy(which_player(), board_copy_castle);
                    board_copy_castle[x][y+1] = board_copy_castle[x][y];
                    board_copy_castle[x][y] = 0;
                    if(!game.is_checked(index, board_copy_castle)){
                        if (game.get_piece(x, y + 1) == nullptr && game.get_piece(x, y + 2) == nullptr &&
                                game.get_piece(x, y + 3) == nullptr){
                            possible_moves[x][y + 2] = 2;
                            num_moves++;
                        }
                    }
                }
            } else {
                if (game.get_piece(x + 3, y) != nullptr && !game.get_piece(x + 3, y)->get_has_moved()) {
                    int board_copy_castle[14][14];
                    game.create_board_copy(which_player(), board_copy_castle);
                    board_copy_castle[x+1][y] = board_copy_castle[x][y];
                    board_copy_castle[x][y] = 0;
                    if(!game.is_checked(index, board_copy_castle)){
                        if (game.get_piece(x + 1, y) == nullptr && game.get_piece(x + 2, y) == nullptr){
                            possible_moves[x + 2][y] = 2;
                            num_moves++;
                        }
                    }
                }
                if (game.get_piece(x - 4, y) != nullptr && !game.get_piece(x - 4, y)->get_has_moved()) {
                    int board_copy_castle[14][14];
                    game.create_board_copy(which_player(), board_copy_castle);
                    board_copy_castle[x-1][y] = board_copy_castle[x][y];
                    board_copy_castle[x][y] = 0;
                    if(!game.is_checked(index, board_copy_castle)){
                        if (game.get_piece(x - 1, y) == nullptr && game.get_piece(x - 2, y) == nullptr &&
                                game.get_piece(x - 3, y) == nullptr){
                            possible_moves[x - 2][y] = 2;
                            num_moves++;
                        }
                    }
                }
            }
        }
    }

    possible_moves[x][y] = 1;

//    for (int i = 0; i < 14; ++i)
//    {
//        for (int j = 0; j < 14; ++j)
//        {
//            std::cout << possible_moves[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }

    return num_moves;
}

std::string King::get_img() const {
    if(!player.is_in_game())
        return ":/img/DeactivatedPlayer/king.png";
    return ":/img/Player" + std::to_string(player.get_index()) + "/king.png";
}

