//
// Created by Yigit Sen on 13/11/2021.
//

#include "Pawn.h"
#include "../Game.h"
#include "iostream"
Pawn::Pawn(Player& player, Game& game, int x, int y): Piece(player, game, x, y) {}


Piece::Type Pawn::get_type() const {
    return Piece::Type::PAWN;
}

int Pawn::get_point() const{
    return 1;
}
void Pawn::list_possible_moves(){
    int temp[14][14] = {0};
    temp[x][y] = 1;

    //if P1 - decrease x
    if(which_player() == 0)
    {
        if(x == 12)
        {
            //Can move up 2
            if(game.in_boundaries(x-1,y) && game.get_piece((x-1), y) == nullptr)
            {
                //add it to arr
                temp[x-1][y] = 2;
                if(game.in_boundaries(x-2,y) &&game.get_piece((x-2), y) == nullptr)
                {
                    //add it to arr
                    temp[x-2][y] = 2;
                }
            }
            if(game.in_boundaries(x-1,y+1) && game.get_piece((x-1), y+1) != nullptr && game.get_piece(x-1, y+1)->which_player() != which_player())
            {
                //add it to arr
                temp[x-1][y+1] = 2;

            }
            if(game.in_boundaries(x-1,y-1) && game.get_piece((x-1), y-1) != nullptr && game.get_piece(x-1, y-1)->which_player() != which_player()) {
                //add it to arr
                temp[x - 1][y - 1] = 2;

            }
        }
        else
        {
            //Can only move up one
            if(game.in_boundaries(x-1,y) && game.get_piece((x-1), y) == nullptr)
            {
                //add it to arr
                temp[x-1][y] = 2;

            }
            if(game.in_boundaries(x-1,y+1) && game.get_piece((x-1), y+1) != nullptr && game.get_piece(x-1, y+1)->which_player() != which_player())
            {
                //add it to arr
                temp[x-1][y+1] = 2;

            }
            if(game.in_boundaries(x-1,y-1) && game.get_piece((x-1), y-1) != nullptr && game.get_piece(x-1, y-1)->which_player() != which_player())
            {
                //add it to arr
                temp[x - 1][y - 1] = 2;

            }
        }
    }
    //if P2 - increase Y
    if(which_player() == 1)
    {
        if(y == 1)
        {
            //Can move up 2
            if(game.in_boundaries(x,y+1) &&game.get_piece((x), y+1) == nullptr)
            {
                //add it to arr
                temp[x][y+1] = 2;
                if(game.in_boundaries(x,y+2) &&game.get_piece((x), y+2) == nullptr)
                {
                    //add it to arr
                    temp[x][y+2] = 2;
                }
            }
            if(game.in_boundaries(x+1,y+1) &&game.get_piece((x+1), y+1) != nullptr && game.get_piece(x+1, y+1)->which_player() != which_player())
            {
                //add it to arr
                temp[x+1][y+1] = 2;

            }
            if(game.in_boundaries(x-1,y+1) &&game.get_piece((x-1), y+1) != nullptr && game.get_piece(x-1, y+1)->which_player() != which_player()) {
                //add it to arr
                temp[x - 1][y + 1] = 2;

            }
        }
        else
        {
            //Can only move up one
            if(game.in_boundaries(x,y+1) &&game.get_piece((x), y+1) == nullptr)
            {
                //add it to arr
                temp[x][y+1] = 2;

            }
            if(game.in_boundaries(x+1,y+1) &&game.get_piece((x+1), y+1) != nullptr && game.get_piece(x+1, y+1)->which_player() != which_player())
            {
                //add it to arr
                temp[x+1][y+1] = 2;

            }
            if(game.in_boundaries(x-1,y+1) &&game.get_piece((x-1), y+1) != nullptr && game.get_piece(x-1, y+1)->which_player() != which_player()) {
                //add it to arr
                temp[x - 1][y + 1] = 2;

            }
        }
    }

    //if P3 - increase X
    if(which_player() == 2)
    {
        if(x == 1)
        {
            //Can move up 2
            if(game.in_boundaries(x+1,y) &&game.get_piece((x+1), y) == nullptr)
            {
                //add it to arr
                temp[x+1][y] = 2;
                if(game.in_boundaries(x+2,y) &&game.get_piece((x+2), y) == nullptr)
                {
                    //add it to arr
                    temp[x+2][y] = 2;
                }
            }
            if(game.in_boundaries(x+1,y+1) &&game.get_piece((x+1), y+1) != nullptr && game.get_piece(x+1, y+1)->which_player() != which_player())
            {
                //add it to arr
                temp[x+1][y+1] = 2;

            }
            if(game.in_boundaries(x+1,y-1) &&game.get_piece((x+1), y-1) != nullptr && game.get_piece(x+1, y-1)->which_player() != which_player()) {
                //add it to arr
                temp[x + 1][y - 1] = 2;

            }
        }
        else
        {
            //Can only move up one
            if(game.in_boundaries(x+1,y) &&game.get_piece((x+1), y) == nullptr)
            {
                //add it to arr
                temp[x+1][y] = 2;

            }
            if(game.in_boundaries(x+1,y+1) &&game.get_piece((x+1), y+1) != nullptr && game.get_piece(x+1, y+1)->which_player() != which_player())
            {
                //add it to arr
                temp[x+1][y+1] = 2;

            }
            if(game.in_boundaries(x+1,y-1) &&game.get_piece((x+1), y-1) != nullptr && game.get_piece(x+1, y-1)->which_player() != which_player())
            {
                //add it to arr
                temp[x + 1][y - 1] = 2;

            }
        }
    }

    //if P4 - decrease Y
    if(which_player() == 3)
    {
        if(y == 12)
        {
            //Can move up 2
            if(game.in_boundaries(x,y-1) &&game.get_piece((x), y-1) == nullptr)
            {
                //add it to arr
                temp[x][y-1] = 2;
                if(game.in_boundaries(x,y-2) &&game.get_piece((x), y-2) == nullptr)
                {
                    //add it to arr
                    temp[x][y-2] = 2;
                }
            }
            if(game.in_boundaries(x+1,y-1) &&game.get_piece((x+1), y-1) != nullptr && game.get_piece(x+1, y-1)->which_player() != which_player())
            {
                //add it to arr
                temp[x+1][y-1] = 2;

            }
            if(game.in_boundaries(x-1,y-1) &&game.get_piece((x-1), y-1) != nullptr && game.get_piece(x-1, y-1)->which_player() != which_player()) {
                //add it to arr
                temp[x - 1][y - 1] = 2;

            }
        }
        else
        {
            //Can only move up one
            if(game.in_boundaries(x,y-1) &&game.get_piece((x), y-1) == nullptr)
            {
                //add it to arr
                temp[x][y-1] = 2;

            }
            if(game.in_boundaries(x+1,y-1) &&game.get_piece((x+1), y-1) != nullptr && game.get_piece(x+1, y-1)->which_player() != which_player())
            {
                //add it to arr
                temp[x+1][y-1] = 2;

            }
            if(game.in_boundaries(x-1,y-1) &&game.get_piece((x-1), y-1) != nullptr && game.get_piece(x-1, y-1)->which_player() != which_player())
            {
                //add it to arr
                temp[x - 1][y - 1] = 2;

            }
        }
    }

    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 14; ++j) {
            std::cout<<temp[i][j] << " ";
        }
        std::cout<<std::endl;

    }


    //Do nothing
}
