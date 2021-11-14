//
// Created by Yigit Sen on 13/11/2021.
//

#include "Game.h"
#include <iostream>

Game::Game() {
    for(int y = 0; y < 14; ++y) {
        for(int x = 0; x < 14; ++x) {
            board[x][y].piece = nullptr;

            if((y < 3 && x < 3 ) || (y > 10 && x < 3) || (y > 10 && x > 10) || (y < 3 && x > 10)) {
                board[x][y].is_activated = false;
            }

            else if (y < 2) {
                if (y == 1)
                    board[x][y].piece = new Pawn(players[0], *this);
        
                else {
                    if(x == 3 || x == 10) 
                        board[x][y].piece = new Rook(players[0], *this);
                    else if(x == 4 || x == 9)
                        board[x][y].piece = new Knight(players[0], *this);
                    else if(x == 5 || x == 8)
                        board[x][y].piece = new Bishop(players[0], *this);
                    else if(x == 6)
                        board[x][y].piece = new Queen(players[0], *this);
                    else if(x == 7)
                        board[x][y].piece = new King(players[0], *this);
                }
            }

            else if (x < 2) {
                if (x == 1)
                    board[x][y].piece = new Pawn(players[1], *this); 
                else {
                    if(y == 3 || y == 10) 
                        board[x][y].piece = new Rook(players[1], *this);
                    else if(y == 4 || y == 9)
                        board[x][y].piece = new Knight(players[1], *this);
                    else if(y == 5 || y == 8)
                        board[x][y].piece = new Bishop(players[1], *this);
                    else if(y == 6)
                        board[x][y].piece = new Queen(players[1], *this);
                    else if(y == 7)
                        board[x][y].piece = new King(players[1], *this);
                }
            }

            else if (y > 11) {
                if (y == 12)
                    board[x][y].piece = new Pawn(players[2], *this); 
                else {
                    if(x == 3 || x == 10) 
                        board[x][y].piece = new Rook(players[2], *this);
                    else if(x == 4 || x == 9)
                        board[x][y].piece = new Knight(players[2], *this);
                    else if(x == 5 || x == 8)
                        board[x][y].piece = new Bishop(players[2], *this);
                    else if(x == 6)
                        board[x][y].piece = new King(players[2], *this);
                    else if(x == 7)
                        board[x][y].piece = new Queen(players[2], *this);
                }
            }

            else if (x > 11) {
                if (x == 12)
                    board[x][y].piece = new Pawn(players[3], *this); 
                else {
                    if(y == 3 || y == 10) 
                        board[x][y].piece = new Rook(players[3], *this);
                    else if(y == 4 || y == 9)
                        board[x][y].piece = new Knight(players[3], *this);
                    else if(y == 5 || y == 8)
                        board[x][y].piece = new Bishop(players[3], *this);
                    else if(y == 6)
                        board[x][y].piece = new King(players[3], *this);
                    else if(y == 7)
                        board[x][y].piece = new Queen(players[3], *this);
                }
            }
        }
    }
}