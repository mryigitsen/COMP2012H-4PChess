
#include "Game.h"
#include "Player.h"
#include "pieces/Piece.h"
#include <iostream>
#include <cmath>
#include <random>
#include <ctime>

namespace Random_Generator{
std::mt19937 mersenne{static_cast<std::mt19937::result_type>(std::time(nullptr))};
}

int Game::get_random_number(int min, int max) {
    std::uniform_int_distribution<int> uniform_dist(min, max);
    return uniform_dist(Random_Generator::mersenne);
}

Game::Game(int botCount) {
    turn_number = 0;

    for (int i = 0; i < 4; ++i) {
        players[i] = new Player(*this);
        players[i]->set_index(i);
    }

    for(int i = 0; i < botCount; ++i)
    {
        int index = get_random_number(1, 3);
        if(players[index]->get_is_bot())
        {
            --i;
            continue;
        }
        players[index]->set_is_bot();
    }
    for (int y = 0; y < 14; ++y) {
        for (int x = 0; x < 14; ++x) {
            board[x][y].piece = nullptr;

            if ((y < 3 && x < 3) || (y > 10 && x < 3) || (y > 10 && x > 10) || (y < 3 && x > 10)) {
                board[x][y].is_activated = false;
            } else if (y < 2) {
                if (y == 1)
                    board[x][y].piece = new Pawn(*players[1], *this, x, y);

                else {
                    if (x == 3 || x == 10)
                        board[x][y].piece = new Rook(*players[1], *this, x, y);
                    else if (x == 4 || x == 9)
                        board[x][y].piece = new Knight(*players[1], *this, x, y);
                    else if (x == 5 || x == 8)
                        board[x][y].piece = new Bishop(*players[1], *this, x, y);
                    else if (x == 7)
                        board[x][y].piece = new Queen(*players[1], *this, x, y);
                    else if (x == 6)
                        board[x][y].piece = new King(*players[1], *this, x, y);
                }
            } else if (x < 2) {
                if (x == 1)
                    board[x][y].piece = new Pawn(*players[2], *this, x, y);
                else {
                    if (y == 3 || y == 10)
                        board[x][y].piece = new Rook(*players[2], *this, x, y);
                    else if (y == 4 || y == 9)
                        board[x][y].piece = new Knight(*players[2], *this, x, y);
                    else if (y == 5 || y == 8)
                        board[x][y].piece = new Bishop(*players[2], *this, x, y);
                    else if (y == 7)
                        board[x][y].piece = new Queen(*players[2], *this, x, y);
                    else if (y == 6)
                        board[x][y].piece = new King(*players[2], *this, x, y);
                }
            } else if (y > 11) {
                if (y == 12)
                    board[x][y].piece = new Pawn(*players[3], *this, x, y);
                else {
                    if (x == 3 || x == 10)
                        board[x][y].piece = new Rook(*players[3], *this, x, y);
                    else if (x == 4 || x == 9)
                        board[x][y].piece = new Knight(*players[3], *this, x, y);
                    else if (x == 5 || x == 8)
                        board[x][y].piece = new Bishop(*players[3], *this, x, y);
                    else if (x == 7)
                        board[x][y].piece = new King(*players[3], *this, x, y);
                    else if (x == 6)
                        board[x][y].piece = new Queen(*players[3], *this, x, y);
                }
            } else if (x > 11) {
                if (x == 12)
                    board[x][y].piece = new Pawn(*players[0], *this, x, y);
                else {
                    if (y == 3 || y == 10)
                        board[x][y].piece = new Rook(*players[0], *this, x, y);
                    else if (y == 4 || y == 9)
                        board[x][y].piece = new Knight(*players[0], *this, x, y);
                    else if (y == 5 || y == 8)
                        board[x][y].piece = new Bishop(*players[0], *this, x, y);
                    else if (y == 7)
                        board[x][y].piece = new King(*players[0], *this, x, y);
                    else if (y == 6)
                        board[x][y].piece = new Queen(*players[0], *this, x, y);
                }
            }
        }
    }

    for (int row = 0; row < 14; ++row) {
        for (int col = 0; col < 14; ++col) {
            if (board[row][col].piece != nullptr) {
                board[row][col].piece->list_possible_moves();
            }
        }
    }
}

Game::~Game() {
    for (int i = 0; i < 4; ++i) {
        delete players[i];
    }
}

void Game::print_board() {
    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 14; ++j) {
            if (!board[i][j].is_activated) {
                std::cout << "XX ";
            } else if (board[i][j].piece == nullptr) {
                std::cout << "   ";
            } else {
                switch (board[i][j].piece->get_type()) {
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
                switch (board[i][j].piece->which_player()) {
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

Piece *Game::get_piece(int x, int y) {
    if (in_boundaries(x, y) && board[x][y].piece != nullptr) {
        return board[x][y].piece;
    }
    return nullptr;
}

bool Game::in_boundaries(int x, int y) {
    if (x < 14 && x > -1 && y < 14 && y > -1 && board[x][y].is_activated == true) {
        return true;
    }
    return false;
}

void Game::movePiece(int initX, int initY, int destX, int destY) //This needs to be changes 21/11/21
{
    if ((initX == destX) && (initY == destY)) {
        return;
    }
    int player_num = board[initX][initY].piece->which_player();

    //Capturing
    if (board[destX][destY].piece != nullptr) {
        players[player_num]->increase_score(board[destX][destY].piece->get_point());
        board[destX][destY].piece->set_is_captured(true);
    }

    //PAWN PROMOTION
    Piece* piece_to_move = board[initX][initY].piece;
    if (piece_to_move->get_type() == Piece::Type::PAWN &&
        ((destX == 7 && player_num == 2) || (destX == 6 && player_num == 0) || (destY == 7 && player_num == 1) ||
         (destY == 6 && player_num == 3))) {
        for (int i = 0; i < 16; ++i) {
            if (piece_to_move == players[player_num]->pieces[i]) {
                delete players[player_num]->pieces[i];
                players[player_num]->pieces[i] = new Queen(*players[player_num], *this, initX, initY, i);
                board[initX][initY].piece = nullptr;
                board[destX][destY].piece = players[player_num]->pieces[i];
                board[destX][destY].piece->setCoordinates(destX, destY);
                players[player_num]->pieces[i]->set_points(1);
            }
        }
    }

    //CASTLING
    else if(piece_to_move->get_type() == Piece::Type::KING)
    {
        //Check if the move is a castle
        if(std::abs(destX - initX) == 3 || std::abs(destX - initX) == 2 || std::abs(destY - initY) == 3 || std::abs(destY - initY) == 2) {

            //Check if it hasn't moved
            if(!piece_to_move->get_has_moved())
            {
                int player = piece_to_move->which_player() ;
                //Check the rook next to the movement spot
                if(player == 0)
                {
                    //Player 1:
                    if((destY - initY) == 2 && board[destX][destY+1].piece != nullptr &&board[destX][destY+1].piece->get_type() == Piece::Type::ROOK && !board[destX][destY+1].piece->get_has_moved())
                    {
                        board[destX][destY].piece = board[initX][initY].piece;
                        board[initX][initY].piece = nullptr;
                        board[destX][destY].piece->setCoordinates(destX, destY);
                        board[destX][destY].piece->set_has_moved(true);
                        board[destX][destY-1].piece = board[destX][destY+1].piece;
                        board[destX][destY+1].piece = nullptr;
                        board[destX][destY-1].piece->setCoordinates(destX, destY-1);
                        board[destX][destY-1].piece->set_has_moved(true);
                    }
                    else if((destY - initY) == -2 && board[destX][destY-2].piece != nullptr && board[destX][destY-2].piece->get_type() == Piece::Type::ROOK && !board[destX][destY-2].piece->get_has_moved())
                    {

                        board[destX][destY].piece = board[initX][initY].piece;
                        board[initX][initY].piece = nullptr;
                        board[destX][destY].piece->setCoordinates(destX, destY);
                        board[destX][destY].piece->set_has_moved(true);
                        board[destX][destY+1].piece = board[destX][destY-2].piece;
                        board[destX][destY-2].piece = nullptr;
                        board[destX][destY+1].piece->setCoordinates(destX, destY+1);
                        board[destX][destY+1].piece->set_has_moved(true);
                    }
                }
                else if(player == 1)
                {
                    //Player 2:
                    if((destX - initX) == -2 && board[destX-1][destY].piece->get_type() == Piece::Type::ROOK && !board[destX-1][destY].piece->get_has_moved())
                    {

                        board[destX][destY].piece = board[initX][initY].piece;
                        board[initX][initY].piece = nullptr;
                        board[destX][destY].piece->setCoordinates(destX, destY);
                        board[destX][destY].piece->set_has_moved(true);
                        board[destX+1][destY].piece = board[destX-1][destY].piece;
                        board[destX-1][destY].piece = nullptr;
                        board[destX+1][destY].piece->setCoordinates(destX+1, destY);
                        board[destX+1][destY].piece->set_has_moved(true);

                    }
                    else if((destX - initX) == 2 && board[destX+2][destY].piece != nullptr && board[destX+2][destY].piece->get_type() == Piece::Type::ROOK && !board[destX+2][destY].piece->get_has_moved())
                    {
                        board[destX][destY].piece = board[initX][initY].piece;
                        board[initX][initY].piece = nullptr;
                        board[destX][destY].piece->setCoordinates(destX, destY);
                        board[destX][destY].piece->set_has_moved(true);
                        board[destX-1][destY].piece = board[destX+2][destY].piece;
                        board[destX+2][destY].piece = nullptr;
                        board[destX-1][destY].piece->setCoordinates(destX-1, destY);
                        board[destX-1][destY].piece->set_has_moved(true);
                    }
                }
                //Player 3:
                else if(player == 2)
                {
                    if((destY - initY) == -2 && board[destX][destY-1].piece != nullptr && board[destX][destY-1].piece->get_type() == Piece::Type::ROOK && !board[destX][destY-1].piece->get_has_moved())
                    {
                        board[destX][destY].piece = board[initX][initY].piece;
                        board[initX][initY].piece = nullptr;
                        board[destX][destY].piece->setCoordinates(destX, destY);
                        board[destX][destY].piece->set_has_moved(true);
                        board[destX][destY+1].piece = board[destX][destY-1].piece;
                        board[destX][destY-1].piece = nullptr;
                        board[destX][destY+1].piece->setCoordinates(destX, destY+1);
                        board[destX][destY+1].piece->set_has_moved(true);

                    }
                    else if((destY - initY) == 2 && board[destX][destY+2].piece != nullptr && board[destX][destY+2].piece->get_type() == Piece::Type::ROOK && !board[destX][destY+2].piece->get_has_moved())
                    {
                        board[destX][destY].piece = board[initX][initY].piece;
                        board[initX][initY].piece = nullptr;
                        board[destX][destY].piece->setCoordinates(destX, destY);
                        board[destX][destY].piece->set_has_moved(true);
                        board[destX][destY-1].piece = board[destX][destY+2].piece;
                        board[destX][destY+2].piece = nullptr;
                        board[destX][destY-1].piece->setCoordinates(destX, destY-1);
                        board[destX][destY-1].piece->set_has_moved(true);
                    }
                }
                //Player 4:
                else if(player == 3)
                {
                    if((destX - initX) == 2 && board[destX+1][destY].piece->get_type() == Piece::Type::ROOK && !board[destX+1][destY].piece->get_has_moved())
                    {
                        board[destX][destY].piece = board[initX][initY].piece;
                        board[initX][initY].piece = nullptr;
                        board[destX][destY].piece->setCoordinates(destX, destY);
                        board[destX][destY].piece->set_has_moved(true);
                        board[destX-1][destY].piece = board[destX+1][destY].piece;
                        board[destX+1][destY].piece = nullptr;
                        board[destX-1][destY].piece->setCoordinates(destX-1, destY);
                        board[destX-1][destY].piece->set_has_moved(true);
                    }
                    else if((destX - initX) == -2 && board[destX-2][destY].piece != nullptr && board[destX-2][destY].piece->get_type() == Piece::Type::ROOK && !board[destX-2][destY].piece->get_has_moved())
                    {
                        board[destX][destY].piece = board[initX][initY].piece;
                        board[initX][initY].piece = nullptr;
                        board[destX][destY].piece->setCoordinates(destX, destY);
                        board[destX][destY].piece->set_has_moved(true);
                        board[destX+1][destY].piece = board[destX-2][destY].piece;
                        board[destX-2][destY].piece = nullptr;
                        board[destX+1][destY].piece->setCoordinates(destX+1, destY);
                        board[destX+1][destY].piece->set_has_moved(true);
                    }
                }

            }
        }
        else {
            board[destX][destY].piece = board[initX][initY].piece;
            board[initX][initY].piece = nullptr;
            board[destX][destY].piece->setCoordinates(destX, destY);
            board[destX][destY].piece->set_has_moved(true);
        }
    }


    //Ordinary move method for all other pieces that don't require special moves.
    else {
        board[destX][destY].piece = board[initX][initY].piece;
        board[initX][initY].piece = nullptr;
        board[destX][destY].piece->setCoordinates(destX, destY);
        board[destX][destY].piece->set_has_moved(true);
    }
    make_turn();
    print_board();
}

void Game::bot_move_piece() {
    int index;
    int player_num = turn_number % 4;
    std::vector<std::vector<int>> possible_move_list;

    //To get a random move out of a player's possible moves list
    do{
        index = get_random_number(0, 15);
        if(!players[player_num]->pieces[index]->get_is_captured()){
            for(int i = 0; i < 14; ++i) {
                for(int j = 0; j < 14; ++j) {
                    if(players[player_num]->pieces[index]->get_possible_move_at(i, j) == 2){
                        possible_move_list.push_back(std::vector<int>());
                        possible_move_list[possible_move_list.size() - 1].push_back(i);
                        possible_move_list[possible_move_list.size() - 1].push_back(j);
                    }
                }   // Check for moves, if no moves, repeat, if moves, randomly select one
            }
        }
    } while (possible_move_list.size() == 0);

    int move_index = get_random_number(0, possible_move_list.size() - 1);

    movePiece(players[player_num]->pieces[index]->getX(), players[player_num]->pieces[index]->getY(), possible_move_list[move_index][0], possible_move_list[move_index][1]);

    return;
}

void Game::create_board_copy(int current_turn, int (&board_copy)[14][14]) {
    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 14; ++j) {
            Piece* piece = board[i][j].piece;
            if (piece == nullptr)
                board_copy[i][j] = 0;
            else if (piece->which_player() == current_turn) {
                if (piece->get_type() == Piece::Type::KING) {
                    board_copy[i][j] = 1;
                } else
                    board_copy[i][j] = 2;
            } else {
                if (piece->get_type() == Piece::Type::QUEEN)
                    board_copy[i][j] = 3;
                if (piece->get_type() == Piece::Type::ROOK)
                    board_copy[i][j] = 4;
                if (piece->get_type() == Piece::Type::BISHOP)
                    board_copy[i][j] = 5;
                if (piece->get_type() == Piece::Type::KNIGHT)
                    board_copy[i][j] = 6;
                if (piece->get_type() == Piece::Type::KING)
                    board_copy[i][j] = 7;
                if (piece->get_type() == Piece::Type::PAWN) {
                    board_copy[i][j] = 8 + piece->which_player();
                }

            }
        }
    }
}

void Game::make_turn() {


    int current_turn;
    Player *current_player;
    do
    {
        ++turn_number;
        player_turn = (player_turn + 1) % 4;
        current_turn = turn_number % 4;
        current_player = players[current_turn];
    }
    while(!current_player->is_in_game());


    int num_moves = 0;
    for (int k = 0; k < 16; ++k) {
        Piece* current_piece = current_player->pieces[k];
        if(!current_piece->get_is_captured())
        {
            num_moves += current_piece->list_possible_moves();
            for (int i = 0; i < 14; ++i) {
                for (int j = 0; j < 14; ++j) {
                    if (current_piece->get_possible_move_at(i,j) == 2) {
                        int board_copy[14][14];
                        create_board_copy(current_turn, board_copy);

                        int tempX = current_piece->getX(), tempY = current_piece->getY();
                        board_copy[i][j] = board_copy[tempX][tempY];
                        board_copy[tempX][tempY] = 0;

                        if (is_checked(current_turn, board_copy)) {
                            current_piece->set_possible_move_at(i, j, 0);
                            --num_moves;
                        }
                    }
                }
            }
        }
    }
    int board_copy[14][14];
    create_board_copy(current_turn, board_copy);
    std::cout << "\n\n\n\n\n\n" << current_turn << '\n' << num_moves << "\n\n\n\n\n\n";
    if (num_moves == 0) {
        if (is_checked(current_turn, board_copy)) {
            std::cout << is_checked_player(current_turn, board_copy) << "\n\n\n\n";
            players[is_checked_player(current_turn, board_copy)]->increase_score(20);
            std::cout << "deactivating player" << current_player->get_index() << std::endl;
            current_player->deactivate();
        } else {
            current_player->deactivate();
            for (int i = 0; i < 4; ++i) {
                if (players[i]->is_in_game())
                    players[i]->increase_score(10);
            }
        }
        //make_turn();
//        do
//        {
//            ++turn_number;
//            player_turn = (player_turn + 1) % 4;
//            current_turn = turn_number % 4;
//            current_player = players[current_turn];
//        }
//        while(!current_player->is_in_game());


        int num_active_players=0;
        for(int i = 0; i < 4; ++i) {
            if(players[i]->is_in_game())
                num_active_players++;
        }
        if(num_active_players == 1) {
            is_ended = true;
        }

        make_turn();
        return;

    }

    for(int i = 0; i < 4; ++i) {
        std::cout << players[i]->get_score() << '\n';
    }
    //if (num_moves == 0 && check_moves(original map))

    if(is_ended) {
        std::cout << "\n\n\n\n\n\n\nGAME HAS ENDED!!!!!\n\n\n\n\n\n\n";
    }

}

bool Game::is_checked(int index, const int (&board_copy)[14][14]) {


    // Save player to be checked
    int kingX, kingY;


    // Pull king from player and save index to kingX, kingY
//    for (int i = 0; i < 16; ++i) {
//        if (current_player->pieces[i]->get_type() == Piece::Type::KING) {
//            kingX = current_player->pieces[i]->x;
//            kingY = current_player->pieces[i]->y;
//        }

//    }
    for(int i = 0; i < 14; ++i) {
        for(int j = 0; j < 14; ++j) {
            if(board_copy[i][j] == 1) {
                kingX = i;
                kingY = j;
            }
        }
    }

    int xpos = kingX;
    int ypos = kingY;

//    for(int i = 0; i <14; i++)
//    {
//        for(int j = 0; j < 14; j++)
//        {
//            if(i==xpos && j == ypos)
//            {
//                std::cout << "* ";
//            }
//            else
//            std::cout<<board_copy[i][j] << " ";
//        }
//        std::cout<<std::endl;
//    }
    //std::cout<<std::endl;
//    std::cout << xpos << " " << ypos <<std::endl;

    while (in_boundaries(xpos, ypos)) {
//        for(int i = 0; i <14; i++)
//        {
//            for(int j = 0; j < 14; j++)
//            {
//                if(i==xpos && j == ypos)
//                {
//                    std::cout << "* ";
//                }
//                else
//                std::cout<<board_copy[i][j] << " ";
//            }
//            std::cout<<std::endl;
//        }
//        std::cout<<std::endl;


        if (board_copy[xpos][ypos] == 2) break;
        else if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 4) {
            std::cout << "true1" << std::endl;
            return true;
        } else if (board_copy[xpos][ypos] != 0 && board_copy[xpos][ypos] != 1) {
            break;
        }
        ++xpos;

    }

    xpos = kingX;
    ypos = kingY;
    while (in_boundaries(xpos, ypos)) {
//        for(int i = 0; i <14; i++)
//        {
//            for(int j = 0; j < 14; j++)
//            {
//                if(i==xpos && j == ypos)
//                {
//                    std::cout << "* ";
//                }
//                else
//                std::cout<<board_copy[i][j] << " ";
//            }
//            std::cout<<std::endl;
//        }
//        std::cout<<std::endl;

        if (board_copy[xpos][ypos] == 2) break;
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 4) {
            std::cout << "true2" << std::endl;
            return true;
        } else if (board_copy[xpos][ypos] != 0 && board_copy[xpos][ypos] != 1) {
            break;
        }
        --xpos;
    }
//    std::cout<<"HERE"<<std::endl;

    xpos = kingX;
    ypos = kingY;
    while (in_boundaries(xpos, ypos)) {
//        for(int i = 0; i <14; i++)
//        {
//            for(int j = 0; j < 14; j++)
//            {
//                if(i==xpos && j == ypos)
//                {
//                    std::cout << "* ";
//                }
//                else
//                std::cout<<board_copy[i][j] << " ";
//            }
//            std::cout<<std::endl;
//        }
//        std::cout<<std::endl;

        if (board_copy[xpos][ypos] == 2) break;
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 4) {
            std::cout << "true3" << std::endl;
            return true;
        } else if (board_copy[xpos][ypos] != 0 && board_copy[xpos][ypos] != 1) {
            break;
        }
        ++ypos;
    }

    xpos = kingX;
    ypos = kingY;
    while (in_boundaries(xpos, ypos)) {
//        for(int i = 0; i <14; i++)
//        {
//            for(int j = 0; j < 14; j++)
//            {
//                if(i==xpos && j == ypos)
//                {
//                    std::cout << "* ";
//                }
//                else
//                std::cout<<board_copy[i][j] << " ";
//            }
//            std::cout<<std::endl;
//        }
//        std::cout<<std::endl;

        if (board_copy[xpos][ypos] == 2) break;
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 4) {
            std::cout << "true4" << std::endl;
            return true;
        } else if (board_copy[xpos][ypos] != 0 && board_copy[xpos][ypos] != 1) {
            break;
        }
        --ypos;
    }

    xpos = kingX;
    ypos = kingY;
//    std::cout << xpos << " " << ypos <<std::endl;
    while (in_boundaries(xpos, ypos)) {
//        for(int i = 0; i <14; i++)
//        {
//            for(int j = 0; j < 14; j++)
//            {
//                if(i==xpos && j == ypos)
//                {
//                    std::cout << "* ";
//                }
//                else
//                std::cout<<board_copy[i][j] << " ";
//            }
//            std::cout<<std::endl;
//        }
//        std::cout<<std::endl;
//        std::cout<<std::endl;


        if (board_copy[xpos][ypos] == 2) break;
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 5) {
            std::cout << "true5" << std::endl;
            return true;
        } else if (board_copy[xpos][ypos] != 0 && board_copy[xpos][ypos] != 1) {
            break;
        }
        ++xpos;
        ++ypos;
    }

    xpos = kingX;
    ypos = kingY;
    while (in_boundaries(xpos, ypos)) {
//        for(int i = 0; i <14; i++)
//        {
//            for(int j = 0; j < 14; j++)
//            {
//                if(i==xpos && j == ypos)
//                {
//                    std::cout << "* ";
//                }
//                else
//                std::cout<<board_copy[i][j] << " ";
//            }
//            std::cout<<std::endl;
//        }
//        std::cout<<std::endl;
        if (board_copy[xpos][ypos] == 2) break;
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 5) {
            std::cout << "true6" << std::endl;
            return true;
        } else if (board_copy[xpos][ypos] != 0 && board_copy[xpos][ypos] != 1) {
            break;
        }
        --xpos;
        ++ypos;
    }

    xpos = kingX;
    ypos = kingY;
    while (in_boundaries(xpos, ypos)) {
//        for(int i = 0; i <14; i++)
//        {
//            for(int j = 0; j < 14; j++)
//            {
//                if(i==xpos && j == ypos)
//                {
//                    std::cout << "* ";
//                }
//                else
//                std::cout<<board_copy[i][j] << " ";
//            }
//            std::cout<<std::endl;
//        }
//        std::cout<<std::endl;
        if (board_copy[xpos][ypos] == 2) break;
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 5) {
            std::cout << "true7" << std::endl;
            return true;
        } else if (board_copy[xpos][ypos] != 0 && board_copy[xpos][ypos] != 1) {
            break;
        }
        ++xpos;
        --ypos;
    }

    xpos = kingX;
    ypos = kingY;
    while (in_boundaries(xpos, ypos)) {
//        for(int i = 0; i <14; i++)
//        {
//            for(int j = 0; j < 14; j++)
//            {
//                if(i==xpos && j == ypos)
//                {
//                    std::cout << "* ";
//                }
//                else
//                std::cout<<board_copy[i][j] << " ";
//            }
//            std::cout<<std::endl;
//        }
//        std::cout<<std::endl;
        if (board_copy[xpos][ypos] == 2) break;
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 5) {
            std::cout << "true8" << std::endl;
            return true;
        } else if (board_copy[xpos][ypos] != 0 && board_copy[xpos][ypos] != 1) {
            break;
        }
        --xpos;
        --ypos;
    }

    for (int i = kingX - 1; i < kingX + 2; ++i) {
//        for(int i = 0; i <14; i++)
//        {
//            for(int j = 0; j < 14; j++)
//            {
//                if(i==xpos && j == ypos)
//                {
//                    std::cout << "* ";
//                }
//                else
//                std::cout<<board_copy[i][j] << " ";
//            }
//            std::cout<<std::endl;
//        }
//        std::cout<<std::endl;
        for (int j = kingY - 1; j < kingY + 2; ++j) {
            if (in_boundaries(i, j)) {
                if (board_copy[i][j] == 7) {
                    std::cout << "true9" << std::endl;
                    return true;
                }
            }
        }
    }

    if (index != 0) {
        if (in_boundaries(kingX + 1, kingY + 1) && board_copy[kingX + 1][kingY + 1] - 8 == 0) {
            std::cout << "true10" << std::endl;
            return true;
        }
        if (in_boundaries(kingX + 1, kingY - 1) && board_copy[kingX + 1][kingY - 1] - 8 == 0) {
            std::cout << "true11" << std::endl;
            return true;
        }
    }

    if (index != 1) {
        if (in_boundaries(kingX + 1, kingY - 1) && board_copy[kingX + 1][kingY - 1] - 8 == 1) {
            std::cout << "true12" << std::endl;
            return true;
        }
        if (in_boundaries(kingX - 1, kingY - 1) && board_copy[kingX - 1][kingY - 1] - 8 == 1) {
            std::cout << "true13" << std::endl;
            return true;
        }
    }

    if (index != 2) {
        if (in_boundaries(kingX - 1, kingY - 1) && board_copy[kingX - 1][kingY - 1] - 8 == 2) {
            std::cout << "true14" << std::endl;
            return true;
        }
        if (in_boundaries(kingX - 1, kingY + 1) && board_copy[kingX - 1][kingY + 1] - 8 == 2) {
            std::cout << "true15" << std::endl;
            return true;
        }
    }

    if (index != 3) {
        if (in_boundaries(kingX - 1, kingY + 1) && board_copy[kingX - 1][kingY + 1] - 8 == 3) {
            std::cout << "true16" << std::endl;
            return true;
        }
        if (in_boundaries(kingX + 1, kingY + 1) && board_copy[kingX + 1][kingY + 1] - 8 == 3) {
            std::cout << "true17" << std::endl;
            return true;
        }
    }

    if (in_boundaries(kingX + 2, kingY + 1) && board_copy[kingX + 2][kingY + 1] == 6) {
        std::cout << "true18" << std::endl;
        return true;
    }
    if (in_boundaries(kingX + 2, kingY - 1) && board_copy[kingX + 2][kingY - 1] == 6) {
        std::cout << "true19" << std::endl;
        return true;
    }
    if (in_boundaries(kingX - 2, kingY + 1) && board_copy[kingX - 2][kingY + 1] == 6) {
        std::cout << "true20" << std::endl;
        return true;
    }
    if (in_boundaries(kingX - 2, kingY - 1) && board_copy[kingX - 2][kingY - 1] == 6) {
        std::cout << "true21" << std::endl;
        return true;
    }

    if (in_boundaries(kingX + 1, kingY + 2) && board_copy[kingX + 1][kingY + 2] == 6) {
        std::cout << "true22" << std::endl;
        return true;
    }
    if (in_boundaries(kingX + 1, kingY - 2) && board_copy[kingX + 1][kingY - 2] == 6) {
        std::cout << "true23" << std::endl;
        return true;
    }
    if (in_boundaries(kingX - 1, kingY + 2) && board_copy[kingX - 1][kingY + 2] == 6) {
        std::cout << "true24" << std::endl;
        return true;
    }
    if (in_boundaries(kingX - 1, kingY - 2) && board_copy[kingX - 1][kingY - 2] == 6) {
        std::cout << "true25" << std::endl;
        return true;
    }
//    std::cout<< "END is_checked" <<std::endl;

    return false;
}

int Game::get_cur_player() {
    return player_turn;
}

Player* Game::get_cur_player_pointer() const {
    return players[player_turn];
}

int Game::is_checked_player(int index, const int (&board_copy)[14][14]) {
    int checkmater_index = 50;

    int kingX, kingY;
//    if (current_player->pieces[11]->get_type() == Piece::Type::KING) {
//        kingX = current_player->pieces[11]->x;
//        kingY = current_player->pieces[11]->y;
//    } else {
//        kingX = current_player->pieces[12]->x;
//        kingY = current_player->pieces[12]->y;
//    }
    for(int i = 0; i < 14; ++i) {
        for(int j = 0; j < 14; ++j) {
            if(board_copy[i][j] == 1) {
                kingX = i;
                kingY = j;
            }
        }
    }

    int xpos = kingX + 1;
    int ypos = kingY;
    while (in_boundaries(xpos, ypos)) {
        if (board_copy[xpos][ypos] == 2) break;
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 4) {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        else if (board_copy[xpos][ypos] != 0 && board_copy[xpos][ypos] != 1) {
                    break;
                }
        ++xpos;
    }

    xpos = kingX - 1;
    ypos = kingY;
    while (in_boundaries(xpos, ypos)) {
        if (board_copy[xpos][ypos] == 2) break;
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 4) {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        else if (board_copy[xpos][ypos] != 0 && board_copy[xpos][ypos] != 1) {
                    break;
                }
        --xpos;
    }

    xpos = kingX;
    ypos = kingY + 1;
    while (in_boundaries(xpos, ypos)) {
        if (board_copy[xpos][ypos] == 2) break;
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 4) {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        else if (board_copy[xpos][ypos] != 0 && board_copy[xpos][ypos] != 1) {
                    break;
                }
        ++ypos;
    }

    xpos = kingX;
    ypos = kingY - 1;
    while (in_boundaries(xpos, ypos)) {
        if (board_copy[xpos][ypos] == 2) break;
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 4) {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        else if (board_copy[xpos][ypos] != 0 && board_copy[xpos][ypos] != 1) {
                    break;
                }
        --ypos;
    }

    xpos = kingX + 1;
    ypos = kingY + 1;
    while (in_boundaries(xpos, ypos)) {
        if (board_copy[xpos][ypos] == 2) break;
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 5) {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        else if (board_copy[xpos][ypos] != 0 && board_copy[xpos][ypos] != 1) {
                    break;
                }
        ++xpos;
        ++ypos;
    }

    xpos = kingX - 1;
    ypos = kingY + 1;
    while (in_boundaries(xpos, ypos)) {
        if (board_copy[xpos][ypos] == 2) break;
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 5) {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        else if (board_copy[xpos][ypos] != 0 && board_copy[xpos][ypos] != 1) {
                    break;
                }
        --xpos;
        ++ypos;
    }

    xpos = kingX + 1;
    ypos = kingY - 1;
    while (in_boundaries(xpos, ypos)) {
        if (board_copy[xpos][ypos] == 2) break;
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 5) {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        else if (board_copy[xpos][ypos] != 0 && board_copy[xpos][ypos] != 1) {
                    break;
                }
        ++xpos;
        --ypos;
    }

    xpos = kingX - 1;
    ypos = kingY - 1;
    while (in_boundaries(xpos, ypos)) {
        if (board_copy[xpos][ypos] == 2) break;
        if (board_copy[xpos][ypos] == 3 || board_copy[xpos][ypos] == 5) {
            int this_check_index = board[xpos][ypos].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        else if (board_copy[xpos][ypos] != 0 && board_copy[xpos][ypos] != 1) {
                    break;
                }
        --xpos;
        --ypos;
    }

    for (int i = kingX - 1; i < kingX + 2; ++i) {
        for (int j = kingY - 1; j < kingY + 2; ++j) {
            if (in_boundaries(i, j)) {
                if (board_copy[i][j] == 7) {
                    int this_check_index = board[i][j].piece->which_player();
                    this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
                    checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
                }
            }
        }
    }

    if (index != 0) {
        if (in_boundaries(kingX + 1, kingY + 1) && board_copy[kingX + 1][kingY + 1] - 8 == 0) {
            int this_check_index = board[kingX + 1][kingY + 1].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        if (in_boundaries(kingX + 1, kingY - 1) && board_copy[kingX + 1][kingY - 1] - 8 == 0) {
            int this_check_index = board[kingX + 1][kingY - 1].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
    }

    if (index != 1) {
        if (in_boundaries(kingX + 1, kingY - 1) && board_copy[kingX + 1][kingY - 1] - 8 == 1) {
            int this_check_index = board[kingX + 1][kingY - 1].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        if (in_boundaries(kingX - 1, kingY - 1) && board_copy[kingX - 1][kingY - 1] - 8 == 1) {
            int this_check_index = board[kingX - 1][kingY - 1].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
    }

    if (index != 2) {
        if (in_boundaries(kingX - 1, kingY - 1) && board_copy[kingX - 1][kingY - 1] - 8 == 2) {
            int this_check_index = board[kingX - 1][kingY - 1].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        if (in_boundaries(kingX - 1, kingY + 1) && board_copy[kingX - 1][kingY + 1] - 8 == 2) {
            int this_check_index = board[kingX - 1][kingY + 1].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
    }

    if (index != 3) {
        if (in_boundaries(kingX - 1, kingY + 1) && board_copy[kingX - 1][kingY + 1] - 8 == 3) {
            int this_check_index = board[kingX - 1][kingY + 1].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
        if (in_boundaries(kingX + 1, kingY + 1) && board_copy[kingX + 1][kingY + 1] - 8 == 3) {
            int this_check_index = board[kingX + 1][kingY + 1].piece->which_player();
            this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
            checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
        }
    }

    if (in_boundaries(kingX + 2, kingY + 1) && board_copy[kingX + 2][kingY + 1] == 6) {
        int this_check_index = board[kingX + 2][kingY + 1].piece->which_player();
        this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
        checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
    }
    if (in_boundaries(kingX + 2, kingY - 1) && board_copy[kingX + 2][kingY - 1] == 6) {
        int this_check_index = board[kingX + 2][kingY - 1].piece->which_player();
        this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
        checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
    }
    if (in_boundaries(kingX - 2, kingY + 1) && board_copy[kingX - 2][kingY + 1] == 6) {
        int this_check_index = board[kingX - 2][kingY + 1].piece->which_player();
        this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
        checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
    }
    if (in_boundaries(kingX - 2, kingY - 1) && board_copy[kingX - 2][kingY - 1] == 6) {
        int this_check_index = board[kingX - 2][kingY - 1].piece->which_player();
        this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
        checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
    }

    if (in_boundaries(kingX + 1, kingY + 2) && board_copy[kingX + 1][kingY + 2] == 6) {
        int this_check_index = board[kingX + 1][kingY + 2].piece->which_player();
        this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
        checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
    }
    if (in_boundaries(kingX + 1, kingY - 2) && board_copy[kingX + 1][kingY - 2] == 6) {
        int this_check_index = board[kingX + 1][kingY - 2].piece->which_player();
        this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
        checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
    }
    if (in_boundaries(kingX - 1, kingY + 2) && board_copy[kingX - 1][kingY + 2] == 6) {
        int this_check_index = board[kingX - 1][kingY + 2].piece->which_player();
        this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
        checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
    }
    if (in_boundaries(kingX - 1, kingY - 2) && board_copy[kingX - 1][kingY - 2] == 6) {
        int this_check_index = board[kingX - 1][kingY - 2].piece->which_player();
        this_check_index = (this_check_index < index) ? this_check_index + 4 : this_check_index;
        checkmater_index = (checkmater_index > this_check_index) ? this_check_index : checkmater_index;
    }

    return ((checkmater_index > 3) ? checkmater_index - 4 : checkmater_index);
}
