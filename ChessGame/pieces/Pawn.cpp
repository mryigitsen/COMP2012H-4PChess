//
// Created by Yigit Sen on 13/11/2021.
//

#include "Pawn.h"
#include "../Game.h"
#include "iostream"

Pawn::Pawn(Player &player, Game &game, int x, int y) : Piece(player, game, x, y) {
    points = 1;
    player.pieces[player.num_pieces++] = this;

}


Piece::Type Pawn::get_type() const {
    return Piece::Type::PAWN;
}

int Pawn::get_point() const {
    return points;
}


int Pawn::list_possible_moves() {
//    std::cout<<"pawn"<<std::endl;

    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 14; ++j) {
            possible_moves[i][j] = 0;
        }
    }
    possible_moves[x][y] = 1;
    int num_moves = 0;

    //if P1 - decrease x
    if (which_player() == 0) {
        if (!get_has_moved()) {
            //Can move up 2
            if (game.in_boundaries(x - 1, y) && game.get_piece((x - 1), y) == nullptr) {
                //add it to arr
                possible_moves[x - 1][y] = 2;
                num_moves++;
                if (game.in_boundaries(x - 2, y) && game.get_piece((x - 2), y) == nullptr) {
                    //add it to arr
                    possible_moves[x - 2][y] = 2;
                    num_moves++;
                }
            }
            if (game.in_boundaries(x - 1, y + 1) && game.get_piece((x - 1), y + 1) != nullptr &&
                game.get_piece(x - 1, y + 1)->which_player() != which_player()) {
                //add it to arr
                possible_moves[x - 1][y + 1] = 2;
                num_moves++;

            }
            if (game.in_boundaries(x - 1, y - 1) && game.get_piece((x - 1), y - 1) != nullptr &&
                game.get_piece(x - 1, y - 1)->which_player() != which_player()) {
                //add it to arr
                possible_moves[x - 1][y - 1] = 2;
                num_moves++;
            }

        } else {
            //Can only move up one
            if (game.in_boundaries(x - 1, y) && game.get_piece((x - 1), y) == nullptr) {
                //add it to arr
                possible_moves[x - 1][y] = 2;
                num_moves++;

            }
            if (game.in_boundaries(x - 1, y + 1) && game.get_piece((x - 1), y + 1) != nullptr &&
                game.get_piece(x - 1, y + 1)->which_player() != which_player()) {
                //add it to arr
                possible_moves[x - 1][y + 1] = 2;
                num_moves++;

            }
            if (game.in_boundaries(x - 1, y - 1) && game.get_piece((x - 1), y - 1) != nullptr &&
                game.get_piece(x - 1, y - 1)->which_player() != which_player()) {
                //add it to arr
                possible_moves[x - 1][y - 1] = 2;
                num_moves++;
            }


        }
    }
    //if P2 - increase Y
    if (which_player() == 1) {
        if (!get_has_moved()) {
            //Can move up 2
            if (game.in_boundaries(x, y + 1) && game.get_piece((x), y + 1) == nullptr) {
                //add it to arr
                possible_moves[x][y + 1] = 2;
                num_moves++;
                if (game.in_boundaries(x, y + 2) && game.get_piece((x), y + 2) == nullptr) {
                    //add it to arr
                    possible_moves[x][y + 2] = 2;
                    num_moves++;
                }
            }
            if (game.in_boundaries(x + 1, y + 1) && game.get_piece((x + 1), y + 1) != nullptr &&
                game.get_piece(x + 1, y + 1)->which_player() != which_player()) {
                //add it to arr
                possible_moves[x + 1][y + 1] = 2;
                num_moves++;

            }
            if (game.in_boundaries(x - 1, y + 1) && game.get_piece((x - 1), y + 1) != nullptr &&
                game.get_piece(x - 1, y + 1)->which_player() != which_player()) {
                //add it to arr
                possible_moves[x - 1][y + 1] = 2;
                num_moves++;

            }

        } else {
            //Can only move up one
            if (game.in_boundaries(x, y + 1) && game.get_piece((x), y + 1) == nullptr) {
                //add it to arr
                possible_moves[x][y + 1] = 2;
                num_moves++;

            }
            if (game.in_boundaries(x + 1, y + 1) && game.get_piece((x + 1), y + 1) != nullptr &&
                game.get_piece(x + 1, y + 1)->which_player() != which_player()) {
                //add it to arr
                possible_moves[x + 1][y + 1] = 2;
                num_moves++;

            }
            if (game.in_boundaries(x - 1, y + 1) && game.get_piece((x - 1), y + 1) != nullptr &&
                game.get_piece(x - 1, y + 1)->which_player() != which_player()) {
                //add it to arr
                possible_moves[x - 1][y + 1] = 2;
                num_moves++;

            }

        }
    }

    //if P3 - increase X
    if (which_player() == 2) {
        if (!get_has_moved()) {
            //Can move up 2
            if (game.in_boundaries(x + 1, y) && game.get_piece((x + 1), y) == nullptr) {
                //add it to arr
                possible_moves[x + 1][y] = 2;
                num_moves++;
                if (game.in_boundaries(x + 2, y) && game.get_piece((x + 2), y) == nullptr) {
                    //add it to arr
                    possible_moves[x + 2][y] = 2;
                    num_moves++;
                }
            }
            if (game.in_boundaries(x + 1, y + 1) && game.get_piece((x + 1), y + 1) != nullptr &&
                game.get_piece(x + 1, y + 1)->which_player() != which_player()) {
                //add it to arr
                possible_moves[x + 1][y + 1] = 2;
                num_moves++;

            }
            if (game.in_boundaries(x + 1, y - 1) && game.get_piece((x + 1), y - 1) != nullptr &&
                game.get_piece(x + 1, y - 1)->which_player() != which_player()) {
                //add it to arr
                possible_moves[x + 1][y - 1] = 2;
                num_moves++;

            }


        } else {
            //Can only move up one
            if (game.in_boundaries(x + 1, y) && game.get_piece((x + 1), y) == nullptr) {
                //add it to arr
                possible_moves[x + 1][y] = 2;
                num_moves++;

            }
            if (game.in_boundaries(x + 1, y + 1) && game.get_piece((x + 1), y + 1) != nullptr &&
                game.get_piece(x + 1, y + 1)->which_player() != which_player()) {
                //add it to arr
                possible_moves[x + 1][y + 1] = 2;
                num_moves++;

            }
            if (game.in_boundaries(x + 1, y - 1) && game.get_piece((x + 1), y - 1) != nullptr &&
                game.get_piece(x + 1, y - 1)->which_player() != which_player()) {
                //add it to arr
                possible_moves[x + 1][y - 1] = 2;
                num_moves++;

            }


        }
    }

    //if P4 - decrease Y
    if (which_player() == 3) {
        if (!get_has_moved()) {
            //Can move up 2
            if (game.in_boundaries(x, y - 1) && game.get_piece((x), y - 1) == nullptr) {
                //add it to arr
                possible_moves[x][y - 1] = 2;
                num_moves++;
                if (game.in_boundaries(x, y - 2) && game.get_piece((x), y - 2) == nullptr) {
                    //add it to arr
                    possible_moves[x][y - 2] = 2;
                    num_moves++;
                }
            }
            if (game.in_boundaries(x + 1, y - 1) && game.get_piece((x + 1), y - 1) != nullptr &&
                game.get_piece(x + 1, y - 1)->which_player() != which_player()) {
                //add it to arr
                possible_moves[x + 1][y - 1] = 2;
                num_moves++;

            }
            if (game.in_boundaries(x - 1, y - 1) && game.get_piece((x - 1), y - 1) != nullptr &&
                game.get_piece(x - 1, y - 1)->which_player() != which_player()) {
                //add it to arr
                possible_moves[x - 1][y - 1] = 2;
                num_moves++;

            }

        } else {
            //Can only move up one
            if (game.in_boundaries(x, y - 1) && game.get_piece((x), y - 1) == nullptr) {
                //add it to arr
                possible_moves[x][y - 1] = 2;
                num_moves++;
            }
            if (game.in_boundaries(x + 1, y - 1) && game.get_piece((x + 1), y - 1) != nullptr &&
                game.get_piece(x + 1, y - 1)->which_player() != which_player()) {
                //add it to arr
                possible_moves[x + 1][y - 1] = 2;
                num_moves++;

            }
            if (game.in_boundaries(x - 1, y - 1) && game.get_piece((x - 1), y - 1) != nullptr &&
                game.get_piece(x - 1, y - 1)->which_player() != which_player()) {
                //add it to arr
                possible_moves[x - 1][y - 1] = 2;
                num_moves++;

            }

        }
    }

    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 14; ++j) {
            std::cout<<possible_moves[i][j] << " ";
        }
        std::cout<<std::endl;
    }

    return num_moves;
    //Do nothing
}

std::string Pawn::get_img() const {
    if(!player.is_in_game())
        return ":/img/DeactivatedPlayer/pawn.png";
    return ":/img/Player" + std::to_string(player.get_index()) + "/pawn.png";
}
