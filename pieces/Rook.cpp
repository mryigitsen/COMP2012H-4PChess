//
// Created by Yigit Sen on 13/11/2021.
//

#include "Rook.h"
#include "../Game.h"
#include "iostream"
Rook::Rook(Player& player, Game& game, int x, int y): Piece(player, game, x, y) {}


Piece::Type Rook::get_type() const {
    return Piece::Type::ROOK;
}

int Rook::get_point() const{
    return 5;
}

void Rook::list_possible_moves(){

    //Check for +Y (up)
    int temp[14][14] = {0};
    temp[x][y] = 1;
    int xpos = x;
    int ypos = y-1;
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
    }
     xpos = x;
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
    }
     xpos = x+1;
     ypos = y;
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
        xpos++;
    }

     xpos = x-1;
     ypos = y;
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
        xpos--;
    }

    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 14; ++j) {
            std::cout<<temp[i][j] << " ";
        }
        std::cout<<std::endl;

    }
}
