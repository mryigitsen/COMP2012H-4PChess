//
// Created by Yigit Sen on 13/11/2021.
//

#include "Game.h"
#include "Player.h"
#include "pieces/Piece.h"
#include <iostream>
#include <cmath>

Game::Game()
{
    turn_number = 0;

    for (int i = 0; i < 4; ++i)
    {
        players[i] = new Player(*this);
        players[i]->set_index(i);
    }

    for (int y = 0; y < 14; ++y)
    {
        for (int x = 0; x < 14; ++x)
        {
            board[x][y].piece = nullptr;

            if ((y < 3 && x < 3) || (y > 10 && x < 3) || (y > 10 && x > 10) || (y < 3 && x > 10))
            {
                board[x][y].is_activated = false;
            }

            else if (y < 2)
            {
                if (y == 1)
                    board[x][y].piece = new Pawn(*players[1], *this, x, y);

                else
                {
                    if (x == 3 || x == 10)
                        board[x][y].piece = new Rook(*players[1], *this, x, y);
                    else if (x == 4 || x == 9)
                        board[x][y].piece = new Knight(*players[1], *this, x, y);
                    else if (x == 5 || x == 8)
                        board[x][y].piece = new Bishop(*players[1], *this, x, y);
                    else if (x == 6)
                        board[x][y].piece = new Queen(*players[1], *this, x, y);
                    else if (x == 7)
                        board[x][y].piece = new King(*players[1], *this, x, y);
                }
            }

            else if (x < 2)
            {
                if (x == 1)
                    board[x][y].piece = new Pawn(*players[2], *this, x, y);
                else
                {
                    if (y == 3 || y == 10)
                        board[x][y].piece = new Rook(*players[2], *this, x, y);
                    else if (y == 4 || y == 9)
                        board[x][y].piece = new Knight(*players[2], *this, x, y);
                    else if (y == 5 || y == 8)
                        board[x][y].piece = new Bishop(*players[2], *this, x, y);
                    else if (y == 6)
                        board[x][y].piece = new Queen(*players[2], *this, x, y);
                    else if (y == 7)
                        board[x][y].piece = new King(*players[2], *this, x, y);
                }
            }

            else if (y > 11)
            {
                if (y == 12)
                    board[x][y].piece = new Pawn(*players[3], *this, x, y);
                else
                {
                    if (x == 3 || x == 10)
                        board[x][y].piece = new Rook(*players[3], *this, x, y);
                    else if (x == 4 || x == 9)
                        board[x][y].piece = new Knight(*players[3], *this, x, y);
                    else if (x == 5 || x == 8)
                        board[x][y].piece = new Bishop(*players[3], *this, x, y);
                    else if (x == 6)
                        board[x][y].piece = new King(*players[3], *this, x, y);
                    else if (x == 7)
                        board[x][y].piece = new Queen(*players[3], *this, x, y);
                }
            }

            else if (x > 11)
            {
                if (x == 12)
                    board[x][y].piece = new Pawn(*players[0], *this, x, y);
                else
                {
                    if (y == 3 || y == 10)
                        board[x][y].piece = new Rook(*players[0], *this, x, y);
                    else if (y == 4 || y == 9)
                        board[x][y].piece = new Knight(*players[0], *this, x, y);
                    else if (y == 5 || y == 8)
                        board[x][y].piece = new Bishop(*players[0], *this, x, y);
                    else if (y == 6)
                        board[x][y].piece = new King(*players[0], *this, x, y);
                    else if (y == 7)
                        board[x][y].piece = new Queen(*players[0], *this, x, y);
                }
            }
        }
    }
}
Game::~Game()
{
    for (int i = 0; i < 14; ++i)
    {
        for (int j = 0; j < 14; ++j)
        {
            if (board[i][j].piece != nullptr)
            {
                delete board[i][j].piece;
                board[i][j].piece = nullptr;
            }
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        delete players[i];
    }
}
void Game::print_board()
{
    for (int i = 0; i < 14; ++i)
    {
        for (int j = 0; j < 14; ++j)
        {
            if (!board[i][j].is_activated)
            {
                std::cout << "XX ";
            }
            else if (board[i][j].piece == nullptr)
            {
                std::cout << "   ";
            }
            else
            {
                switch (board[i][j].piece->get_type())
                {
                case Piece::Type::BISHOP:
                    std::cout << "B";
                    break;
                case Piece::Type::KING:
                    std::cout << "K";
                    break;
                case Piece::Type::KNIGHT:
                    std::cout << "N";
                    break;
                case Piece::Type::PAWN:
                    std::cout << "P";
                    break;
                case Piece::Type::QUEEN:
                    std::cout << "Q";
                    break;
                case Piece::Type::ROOK:
                    std::cout << "R";
                    break;
                default:
                    std::cout << " ";
                }
                switch (board[i][j].piece->which_player())
                {
                case 0:
                    std::cout << "1 ";
                    break;
                case 1:
                    std::cout << "2 ";
                    break;
                case 2:
                    std::cout << "3 ";
                    break;
                case 3:
                    std::cout << "4 ";
                    break;
                default:
                    std::cout << "  ";
                }
            }
        }
        std::cout << std::endl;
    }
}
// void Game::delete_piece(int x, int y)
// {
//     delete board[x][y].piece;
//     board[x][y].piece= nullptr;
// }

Piece *Game::get_piece(int x, int y)
{
    if (in_boundaries(x, y) && board[x][y].piece != nullptr)
    {
        return board[x][y].piece;
    }
    return nullptr;
}
bool Game::in_boundaries(int x, int y)
{
    if (x < 14 && x > -1 && y < 14 && y > -1 && board[x][y].is_activated == true)
    {
        return true;
    }
    return false;
}
void Game::movePiece(int initX, int initY, int destX, int destY) //This needs to be changes 21/11/21
{
    if ((initX == destX) && (initY == destY))
    {
        return;
    }
    int player_num = board[initX][initY].piece->which_player();
    if (board[destX][destY].piece != nullptr)
    {
        players[player_num]->increase_score(board[destX][destY].piece->get_point());
        board[destX][destY].piece->set_is_captured(true);
    }

    if (board[initX][initY].piece->get_type() == Piece::Type::PAWN)
    {
        if ((destX == 7 && player_num == 2) || (destX == 6 && player_num == 0) || (destY == 7 && player_num == 1) || (destY == 6 && player_num == 3))
        {
            for (int i = 0; i < 8; ++i)
            {
                if (board[initX][initY].piece == players[player_num]->pieces[i])
                {
                    delete players[player_num]->pieces[i];
                    players[player_num]->pieces[i] = new Queen(*players[player_num], *this, destX, destY);
                    players[player_num]->pieces[i]->set_points(1);
                }
            }
        }
    }


    board[destX][destY].piece = board[initX][initY].piece;
    board[initX][initY].piece = nullptr;
    board[destX][destY].piece->setCoordinates(destX, destY);
    board[destX][destY].piece->set_has_moved(true);

    if (board[initX][initY].piece->get_type() == Piece::Type::KING)
    {
        if(!board[initX][initY].piece->get_has_moved()) {
            int rookX, rookY;
            int dispX, dispY;
            if(std::abs(destY - initY) == 3 || std::abs(destY - initY) == 2 || std::abs(initX - destX) == 3  || std::abs(initX - destX) == 2){ 
                if(destY - initY != 0)
                    rookY = (destY - initY) > 0 ? destY - initY + 1 : destY - initY - 1;
                else   
                    rookY = 0;
                if(destX - initX != 0)
                    rookX = (destX - initX) > 0 ? destX - initX + 1 : destX - initX - 1;
                else
                    rookX = 0;
                
                if(rookY != 0)
                    dispY = rookY > 0 ? destY - 1 : destY + 1;
                else   
                    dispY = initY + rookY;
                if(rookX != 0)
                    dispX = rookX > 0 ? destX - 1 : destX + 1;
                else
                    dispX = rookX + initX;
                movePiece(initX + rookX, initY + rookY, dispX, dispY);
            }
            
        }
    }
}

void Game::create_board_copy(int current_turn, int (&board_copy)[14][14]) {
    for (int i = 0; i < 14; ++i)
    {
        for (int j = 0; j < 14; ++j)
        {
            if (board[i][j].piece == nullptr)
                board_copy[i][j] = 0;
            else if (board[i][j].piece->which_player() == current_turn)
            {
                if (board[i][j].piece->get_type() == Piece::Type::KING)
                {
                    board_copy[i][j] = 1;
                }
                else
                    board_copy[i][j] = 2;
            }
            else
            {
                if (board[i][j].piece->get_type() == Piece::Type::QUEEN)
                    board_copy[i][j] = 3;
                if (board[i][j].piece->get_type() == Piece::Type::ROOK)
                    board_copy[i][j] = 4;
                if (board[i][j].piece->get_type() == Piece::Type::BISHOP)
                    board_copy[i][j] = 5;
                if (board[i][j].piece->get_type() == Piece::Type::KNIGHT)
                    board_copy[i][j] = 6;
                if (board[i][j].piece->get_type() == Piece::Type::KING)
                    board_copy[i][j] = 7;
                if (board[i][j].piece->get_type() == Piece::Type::PAWN)
                {
                }
                board_copy[i][j] = 8 + board[i][j].piece->which_player();
            }
        }
    }
}

void Game::make_turn()
{
    int current_turn = turn_number % 4;
    Player *current_player = players[current_turn];
    ++turn_number;

    if (!(current_player->is_in_game()))
        return;

    int num_moves = 0;
    for (int k = 0; k < 16; ++k)
    {
        num_moves += current_player->pieces[k]->list_possible_moves();
        for (int i = 0; i < 14; ++i)
        {
            for (int j = 0; j < 14; ++j)
            {
                if (current_player->pieces[k]->possible_moves[i][j] == 2)
                {
                    int board_copy[14][14];
                    create_board_copy(current_turn, board_copy);

                    int tempX = current_player->pieces[k]->x, tempY = current_player->pieces[k]->y;
                    board_copy[i][j] = board_copy[tempX][tempY];
                    board_copy[tempX][tempY] = 0;

                    if (is_checked(current_turn, board_copy))
                    {
                        current_player->pieces[k]->possible_moves[i][j] = 0;
                        --num_moves;
                    }
                }
            }
        }
    }

    int board_copy[14][14];
    create_board_copy(current_turn, board_copy);

    if (num_moves == 0)
    {
        if (is_checked(current_turn, board_copy))
        {
            players[is_checked_player(current_turn, board_copy)]->increase_score(20);
            current_player->deactivate();
        }
        else
        {
            for (int i = 0; i < 4; ++i)
            {
                if (players[i]->is_in_game())
                    players[i]->increase_score(10);
            }
        }
    }
    //if (num_moves == 0 && check_moves(original map))
}

bool Game::is_checked(int index, const int (&board_copy)[14][14])
{
    Player *current_player = players[index];

    int kingX, kingY;
    if (current_player->pieces[11]->get_type() == Piece::Type::KING)
    {
        kingX = current_player->pieces[11]->x;
        kingY = current_player->pieces[11]->y;
    }
    else
    {
        kingX = current_player->pieces[12]->x;
        kingY = current_player->pieces[12]->y;
    }

    int xpos = kingX + 1;
    int ypos = kingY;
    while (in_boundaries(xpos, ypos))
    {
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 4)
        {
            return true;
        }
        ++xpos;
    }

    xpos = kingX - 1;
    ypos = kingY;
    while (in_boundaries(xpos, ypos))
    {
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 4)
        {
            return true;
        }
        --xpos;
    }

    xpos = kingX;
    ypos = kingY + 1;
    while (in_boundaries(xpos, ypos))
    {
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 4)
        {
            return true;
        }
        ++ypos;
    }

    xpos = kingX;
    ypos = kingY - 1;
    while (in_boundaries(xpos, ypos))
    {
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 4)
        {
            return true;
        }
        --ypos;
    }

    xpos = kingX + 1;
    ypos = kingY + 1;
    while (in_boundaries(xpos, ypos))
    {
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 5)
        {
            return true;
        }
        ++xpos;
        ++ypos;
    }

    xpos = kingX - 1;
    ypos = kingY + 1;
    while (in_boundaries(xpos, ypos))
    {
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 5)
        {
            return true;
        }
        --xpos;
        ++ypos;
    }

    xpos = kingX + 1;
    ypos = kingY - 1;
    while (in_boundaries(xpos, ypos))
    {
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 5)
        {
            return true;
        }
        ++xpos;
        --ypos;
    }

    xpos = kingX - 1;
    ypos = kingY - 1;
    while (in_boundaries(xpos, ypos))
    {
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 5)
        {
            return true;
        }
        --xpos;
        --ypos;
    }

    for (int i = kingX - 1; i < kingX + 2; ++i)
    {
        for (int j = kingY - 1; j < kingY + 2; ++j)
        {
            if (in_boundaries(i, j))
            {
                if (board_copy[i][j] == 7)
                {
                    return true;
                }
            }
        }
    }

    if (index != 0)
    {
        if (in_boundaries(kingX + 1, kingY + 1) && board_copy[kingX + 1][kingY + 1] - 8 == 0)
            return true;
        if (in_boundaries(kingX + 1, kingY - 1) && board_copy[kingX + 1][kingY - 1] - 8 == 0)
            return true;
    }

    if (index != 1)
    {
        if (in_boundaries(kingX + 1, kingY - 1) && board_copy[kingX + 1][kingY - 1] - 8 == 1)
            return true;
        if (in_boundaries(kingX - 1, kingY - 1) && board_copy[kingX - 1][kingY - 1] - 8 == 1)
            return true;
    }

    if (index != 2)
    {
        if (in_boundaries(kingX - 1, kingY - 1) && board_copy[kingX - 1][kingY - 1] - 8 == 2)
            return true;
        if (in_boundaries(kingX - 1, kingY + 1) && board_copy[kingX - 1][kingY + 1] - 8 == 2)
            return true;
    }

    if (index != 3)
    {
        if (in_boundaries(kingX - 1, kingY + 1) && board_copy[kingX - 1][kingY + 1] - 8 == 3)
            return true;
        if (in_boundaries(kingX + 1, kingY + 1) && board_copy[kingX + 1][kingY + 1] - 8 == 3)
            return true;
    }

    if (in_boundaries(kingX + 2, kingY + 1) && board_copy[kingX + 2][kingY + 1] == 6)
        return true;
    if (in_boundaries(kingX + 2, kingY - 1) && board_copy[kingX + 2][kingY - 1] == 6)
        return true;
    if (in_boundaries(kingX - 2, kingY + 1) && board_copy[kingX - 2][kingY + 1] == 6)
        return true;
    if (in_boundaries(kingX - 2, kingY - 1) && board_copy[kingX - 2][kingY - 1] == 6)
        return true;

    if (in_boundaries(kingX + 1, kingY + 2) && board_copy[kingX + 1][kingY + 2] == 6)
        return true;
    if (in_boundaries(kingX + 1, kingY - 2) && board_copy[kingX + 1][kingY - 2] == 6)
        return true;
    if (in_boundaries(kingX - 1, kingY + 2) && board_copy[kingX - 1][kingY + 2] == 6)
        return true;
    if (in_boundaries(kingX - 1, kingY - 2) && board_copy[kingX - 1][kingY - 2] == 6)
        return true;

    return false;
}

int Game::is_checked_player(int index, const int (&board_copy)[14][14])
{
    Player *current_player = players[index];
    int checkmater_index;

    int kingX, kingY;
    if (current_player->pieces[11]->get_type() == Piece::Type::KING)
    {
        kingX = current_player->pieces[11]->x;
        kingY = current_player->pieces[11]->y;
    }
    else
    {
        kingX = current_player->pieces[12]->x;
        kingY = current_player->pieces[12]->y;
    }

    int xpos = kingX + 1;
    int ypos = kingY;
    while (in_boundaries(xpos, ypos))
    {
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 4)
        {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        ++xpos;
    }

    xpos = kingX - 1;
    ypos = kingY;
    while (in_boundaries(xpos, ypos))
    {
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 4)
        {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        --xpos;
    }

    xpos = kingX;
    ypos = kingY + 1;
    while (in_boundaries(xpos, ypos))
    {
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 4)
        {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        ++ypos;
    }

    xpos = kingX;
    ypos = kingY - 1;
    while (in_boundaries(xpos, ypos))
    {
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 4)
        {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        --ypos;
    }

    xpos = kingX + 1;
    ypos = kingY + 1;
    while (in_boundaries(xpos, ypos))
    {
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 5)
        {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        ++xpos;
        ++ypos;
    }

    xpos = kingX - 1;
    ypos = kingY + 1;
    while (in_boundaries(xpos, ypos))
    {
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 5)
        {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        --xpos;
        ++ypos;
    }

    xpos = kingX + 1;
    ypos = kingY - 1;
    while (in_boundaries(xpos, ypos))
    {
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 5)
        {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        ++xpos;
        --ypos;
    }

    xpos = kingX - 1;
    ypos = kingY - 1;
    while (in_boundaries(xpos, ypos))
    {
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 5)
        {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        --xpos;
        --ypos;
    }

    for (int i = kingX - 1; i < kingX + 2; ++i)
    {
        for (int j = kingY - 1; j < kingY + 2; ++j)
        {
            if (in_boundaries(i, j))
            {
                if (board_copy[i][j] == 7)
                {
                    int this_check_index = board[xpos][ypos].piece->which_player();
                    this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
                    checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
                }
            }
        }
    }

    if (index != 0)
    {
        if (in_boundaries(kingX + 1, kingY + 1) && board_copy[kingX + 1][kingY + 1] - 8 == 0)
        {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        if (in_boundaries(kingX + 1, kingY - 1) && board_copy[kingX + 1][kingY - 1] - 8 == 0)
        {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
    }

    if (index != 1)
    {
        if (in_boundaries(kingX + 1, kingY - 1) && board_copy[kingX + 1][kingY - 1] - 8 == 1)
        {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        if (in_boundaries(kingX - 1, kingY - 1) && board_copy[kingX - 1][kingY - 1] - 8 == 1)
        {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
    }

    if (index != 2)
    {
        if (in_boundaries(kingX - 1, kingY - 1) && board_copy[kingX - 1][kingY - 1] - 8 == 2)
        {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        if (in_boundaries(kingX - 1, kingY + 1) && board_copy[kingX - 1][kingY + 1] - 8 == 2)
        {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
    }

    if (index != 3)
    {
        if (in_boundaries(kingX - 1, kingY + 1) && board_copy[kingX - 1][kingY + 1] - 8 == 3)
        {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        if (in_boundaries(kingX + 1, kingY + 1) && board_copy[kingX + 1][kingY + 1] - 8 == 3)
        {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
    }

    if (in_boundaries(kingX + 2, kingY + 1) && board_copy[kingX + 2][kingY + 1] == 6)
    {
        int this_check_index = board[xpos][ypos].piece->which_player();
        this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
        checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
    }
    if (in_boundaries(kingX + 2, kingY - 1) && board_copy[kingX + 2][kingY - 1] == 6)
    {
        int this_check_index = board[xpos][ypos].piece->which_player();
        this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
        checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
    }
    if (in_boundaries(kingX - 2, kingY + 1) && board_copy[kingX - 2][kingY + 1] == 6)
    {
        int this_check_index = board[xpos][ypos].piece->which_player();
        this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
        checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
    }
    if (in_boundaries(kingX - 2, kingY - 1) && board_copy[kingX - 2][kingY - 1] == 6)
    {
        int this_check_index = board[xpos][ypos].piece->which_player();
        this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
        checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
    }

    if (in_boundaries(kingX + 1, kingY + 2) && board_copy[kingX + 1][kingY + 2] == 6)
    {
        int this_check_index = board[xpos][ypos].piece->which_player();
        this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
        checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
    }
    if (in_boundaries(kingX + 1, kingY - 2) && board_copy[kingX + 1][kingY - 2] == 6)
    {
        int this_check_index = board[xpos][ypos].piece->which_player();
        this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
        checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
    }
    if (in_boundaries(kingX - 1, kingY + 2) && board_copy[kingX - 1][kingY + 2] == 6)
    {
        int this_check_index = board[xpos][ypos].piece->which_player();
        this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
        checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
    }
    if (in_boundaries(kingX - 1, kingY - 2) && board_copy[kingX - 1][kingY - 2] == 6)
    {
        int this_check_index = board[xpos][ypos].piece->which_player();
        this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
        checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
    }

    return ((checkmater_index > 3) ? checkmater_index - 4 : checkmater_index);
}