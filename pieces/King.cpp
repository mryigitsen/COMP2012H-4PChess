//
// Created by Yigit Sen on 13/11/2021.
//

#include "Piece.h"
#include <iostream>
#include "../Game.h"
King::King(Player &player, Game &game, int x, int y) : Piece(player, game, x, y)
{
    points = 20;
    player.pieces[player.num_pieces++] = this;
}

Piece::Type King::get_type() const
{
    return Piece::Type::KING;
}

int King::get_point() const
{
    return points;
}

int King::list_possible_moves()
{
    for (int i = 0; i < 14; ++i)
    {
        for (int j = 0; j < 14; ++j)
        {
            possible_moves[i][j] = 0;
        }
    }
    possible_moves[x][y] = 1;
    int num_moves = 0;

    for (int i = x - 1; i < x + 2; ++i)
    {
        for (int j = y - 1; j < y + 2; ++j)
        {
            if (game.in_boundaries(i, j) == false)
                continue;

            if (game.get_piece(i, j) != nullptr)
            {
                if (game.get_piece(i, j)->which_player() != player.get_index())
                {
                    possible_moves[i][j] = 2;
                    num_moves++;
                }
            }
            else
            {
                possible_moves[i][j] = 2;
                num_moves++;
            }
        }
    }

    int board_copy[14][14];
    game.create_board_copy(which_player(), board_copy);
    int index = which_player();

    if (!has_moved)
    {
        if (!game.is_checked(index, board_copy))
        {
            if (index == 0)
            {
                if (!game.get_piece(x, y + 3)->get_has_moved())
                {
                    if (game.get_piece(x, y + 1) == nullptr && game.get_piece(x, y + 2) == nullptr)
                        possible_moves[x][y + 2] = 2;
                }
                if (!game.get_piece(x, y - 4)->get_has_moved())
                {
                    if (game.get_piece(x, y - 1) == nullptr && game.get_piece(x, y - 2) == nullptr && game.get_piece(x, y - 3) == nullptr)
                        possible_moves[x][y - 3] = 2;
                }
            }
            else if (index == 1)
            {
                if (!game.get_piece(x - 3, y)->get_has_moved())
                {
                    if (game.get_piece(x - 1, y) == nullptr && game.get_piece(x - 2, y) == nullptr)
                        possible_moves[x - 2][y] = 2;
                }
                if (!game.get_piece(x + 4, y)->get_has_moved())
                {
                    if (game.get_piece(x + 1, y) == nullptr && game.get_piece(x + 2, y) == nullptr && game.get_piece(x + 3, y) == nullptr)
                        possible_moves[x + 3][y] = 2;
                }
            }
            else if (index == 2)
            {
                if (!game.get_piece(x, y - 3)->get_has_moved())
                {
                    if (game.get_piece(x, y - 1) == nullptr && game.get_piece(x, y - 2) == nullptr)
                        possible_moves[x][y - 2] = 2;
                }
                if (!game.get_piece(x, y + 4)->get_has_moved())
                {
                    if (game.get_piece(x, y + 1) == nullptr && game.get_piece(x, y + 2) == nullptr && game.get_piece(x, y + 3) == nullptr)
                        possible_moves[x][y + 3] = 2;
                }
            }
            else
            {
                if (!game.get_piece(x + 3, y)->get_has_moved())
                {
                    if (game.get_piece(x + 1, y) == nullptr && game.get_piece(x + 2, y) == nullptr)
                        possible_moves[x + 2][y] = 2;
                }
                if (!game.get_piece(x - 4, y)->get_has_moved())
                {
                    if (game.get_piece(x - 1, y) == nullptr && game.get_piece(x - 2, y) == nullptr && game.get_piece(x - 3, y) == nullptr)
                        possible_moves[x - 3][y] = 2;
                }
            }
        }
    }

    possible_moves[x][y] = 1;

    for (int i = 0; i < 14; ++i)
    {
        for (int j = 0; j < 14; ++j)
        {
            std::cout << possible_moves[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return num_moves;
}
