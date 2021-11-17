//
// Created by Yigit Sen on 13/11/2021.
//

#include "Bishop.h"
#include "Piece.h"
#include "iostream"
#include "../Game.h"

Bishop::Bishop(Player& player, Game& game, int x, int y): Piece(player, game, x, y) {}

Piece::Type Bishop::get_type() const{
    return Piece::Type::BISHOP;
}

int Bishop::get_point() const{
    return 5;
}

void Bishop::list_possible_moves(){

    //Check for +Y (up)
    int temp[14][14] = {0};
    temp[x][y] = 1;

    int xpos = x+1;
    int ypos = y+1;
    while(true)
    {
        if(game.in_boundaries(xpos, ypos))
        {
            if(game.get_piece(xpos, ypos) == nullptr)
            {
                temp[xpos][ypos] = 2;
            }
            else
            {
                if(game.get_piece(xpos, ypos)->which_player() != this->which_player())
                {
                    temp[xpos][ypos] = 2;
                }
                break;
            }
        }
        else
        {
            break;
        }
        ypos++;
        xpos++;
    }

    xpos = x-1;
    ypos = y+1;
    while(true)
    {
        if(game.in_boundaries(xpos, ypos))
        {
            if(game.get_piece(xpos, ypos) == nullptr)
            {
                temp[xpos][ypos] = 2;
            }
            else
            {
                if(game.get_piece(xpos, ypos)->which_player() != this->which_player())
                {
                    temp[xpos][ypos] = 2;
                }
                break;
            }
        }
        else
        {
            break;
        }
        ypos++;
        xpos--;
    }
    xpos = x-1;
    ypos = y-1;
    while(true)
    {
        if(game.in_boundaries(xpos, ypos))
        {
            if(game.get_piece(xpos, ypos) == nullptr)
            {
                temp[xpos][ypos] = 2;
            }
            else
            {
                if(game.get_piece(xpos, ypos)->which_player() != this->which_player())
                {
                    temp[xpos][ypos] = 2;
                }
                break;
            }
        }
        else
        {
            break;
        }
        ypos--;
        xpos--;
    }

    xpos = x+1;
    ypos = y-1;
    while(true)
    {
        if(game.in_boundaries(xpos, ypos))
        {
            if(game.get_piece(xpos, ypos) == nullptr)
            {
                temp[xpos][ypos] = 2;
            }
            else
            {
                if(game.get_piece(xpos, ypos)->which_player() != this->which_player())
                {
                    temp[xpos][ypos] = 2;
                }
                break;
            }
        }
        else
        {
            break;
        }
        ypos--;
        xpos++;
    }




    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 14; ++j) {
            std::cout<<temp[i][j] << " ";
        }
        std::cout<<std::endl;

    }
}

