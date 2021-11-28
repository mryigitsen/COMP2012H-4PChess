//

#ifndef INC_4PCHESS_PLAYER_H
#define INC_4PCHESS_PLAYER_H

class Game;

class Piece;

class Player {

    private:
        bool is_active;
        int score = 0;
        int indexNum;
        Game &game;
        bool is_bot;

    public:
        enum class Direction {
            UP,
            DOWN,
            LEFT,
            RIGHT,

            DIRECTION
        };

        Player(Game &game);
        ~Player();

        void set_index(int index);

        int get_index();

        bool is_in_game();

        bool check_move();

        int get_score();

        void increase_score(int);

        void deactivate();

        bool get_is_bot() const;
        void set_is_bot();

        int num_pieces = 0;
        Piece *pieces[16];
};


#endif //INC_4PCHESS_PLAYER_H
