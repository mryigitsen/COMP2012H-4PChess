//
// Created by Yigit Sen on 13/11/2021.
//

#include "Game.h"
#include "Player.h"
#include "pieces/Piece.h"
#include <iostream>

Game::Game() {
    for (int i = 0; i < 4; ++i) {
        players[i].set_index(i);
    }

    for(int y = 0; y < 14; ++y) {
        for(int x = 0; x < 14; ++x) {
            board[x][y].piece = nullptr;

            if((y < 3 && x < 3 ) || (y > 10 && x < 3) || (y > 10 && x > 10) || (y < 3 && x > 10)) {
                board[x][y].is_activated = false;
            }

            else if (y < 2) {
                if (y == 1)
                    board[x][y].piece = new Pawn(players[1], *this, x, y);

                else {
                    if(x == 3 || x == 10)
                        board[x][y].piece = new Rook(players[1], *this, x, y);
                    else if(x == 4 || x == 9)
                        board[x][y].piece = new Knight(players[1], *this, x, y);
                    else if(x == 5 || x == 8)
                        board[x][y].piece = new Bishop(players[1], *this, x, y);
                    else if(x == 6)
                        board[x][y].piece = new Queen(players[1], *this, x, y);
                    else if(x == 7)
                        board[x][y].piece = new King(players[1], *this, x, y);
                }
            }

            else if (x < 2) {
                if (x == 1)
                    board[x][y].piece = new Pawn(players[2], *this, x, y);
                else {
                    if(y == 3 || y == 10)
                        board[x][y].piece = new Rook(players[2], *this, x, y);
                    else if(y == 4 || y == 9)
                        board[x][y].piece = new Knight(players[2], *this, x, y);
                    else if(y == 5 || y == 8)
                        board[x][y].piece = new Bishop(players[2], *this, x, y);
                    else if(y == 6)
                        board[x][y].piece = new Queen(players[2], *this, x, y);
                    else if(y == 7)
                        board[x][y].piece = new King(players[2], *this, x, y);
                }
            }

            else if (y > 11) {
                if (y == 12)
                    board[x][y].piece = new Pawn(players[3], *this, x, y);
                else {
                    if(x == 3 || x == 10)
                        board[x][y].piece = new Rook(players[3], *this, x, y);
                    else if(x == 4 || x == 9)
                        board[x][y].piece = new Knight(players[3], *this, x, y);
                    else if(x == 5 || x == 8)
                        board[x][y].piece = new Bishop(players[3], *this, x, y);
                    else if(x == 6)
                        board[x][y].piece = new King(players[3], *this, x, y);
                    else if(x == 7)
                        board[x][y].piece = new Queen(players[3], *this, x, y);
                }
            }

            else if (x > 11) {
                if (x == 12)
                    board[x][y].piece = new Pawn(players[0], *this, x, y);
                else {
                    if(y == 3 || y == 10)
                        board[x][y].piece = new Rook(players[0], *this, x, y);
                    else if(y == 4 || y == 9)
                        board[x][y].piece = new Knight(players[0], *this, x, y);
                    else if(y == 5 || y == 8)
                        board[x][y].piece = new Bishop(players[0], *this, x, y);
                    else if(y == 6)
                        board[x][y].piece = new King(players[0], *this, x, y);
                    else if(y == 7)
                        board[x][y].piece = new Queen(players[0], *this, x, y);
                }
            }
        }
    }
}
Game::~Game()
{
    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 14; ++j) {
            if(board[i][j].piece != nullptr)
            {
                delete board[i][j].piece;
                board[i][j].piece = nullptr;
            }
        }
    }
}
void Game::print_board() {
    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 14; ++j) {
            if(!board[i][j].is_activated)
            {
                std::cout<<"XX ";
            }
            else if(board[i][j].piece == nullptr)
            {
                std::cout << "   ";
            }
            else
            {
                switch (board[i][j].piece->get_type()) {
                    case Piece::Type::BISHOP:
                        std::cout <<"B";
                        break;
                    case Piece::Type::KING:
                        std::cout <<"K";
                        break;
                    case Piece::Type::KNIGHT:
                        std::cout <<"N";
                        break;
                    case Piece::Type::PAWN:
                        std::cout <<"P";
                        break;
                    case Piece::Type::QUEEN:
                        std::cout <<"Q";
                        break;
                    case Piece::Type::ROOK:
                        std::cout <<"R";
                        break;
                    default:
                        std::cout << " ";

                }
                switch (board[i][j].piece->which_player()) {
                    case 0:
                        std::cout <<"1 ";
                        break;
                    case 1:
                        std::cout <<"2 ";
                        break;
                    case 2:
                        std::cout <<"3 ";
                        break;
                    case 3:
                        std::cout <<"4 ";
                        break;
                    default:
                        std::cout << "  ";

                }
            }
        }
        std::cout<<std::endl;
    }

}
void Game::delete_piece(int x, int y)
{
    delete board[x][y].piece;
    board[x][y].piece= nullptr;
}
Piece* Game::get_piece(int x, int y)
{
    if(in_boundaries(x, y) && board[x][y].piece != nullptr)
    {
        return board[x][y].piece;
    }
    return nullptr;
}
bool Game::in_boundaries(int x, int y)
{
    if(x < 14 && x > -1 && y < 14 && y > -1 && board[x][y].is_activated == true)
    {
        return true;
    }
    return false;
}
void Game::movePiece(int initX, int initY, int destX, int destY)
    {
    board[destX][destY].piece = board[initX][initY].piece;
    board[initX][initY].piece = nullptr;
    board[destX][destY].piece->setCoordinates(destX, destY);
    }