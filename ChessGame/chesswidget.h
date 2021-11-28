//

#ifndef CHESSWIDGET_H
#define CHESSWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QSignalMapper>
#include "Game.h"

class ChessWidget : public QWidget {

    Q_OBJECT
    public:
        explicit ChessWidget(int botCount = 0, QWidget *parent = nullptr);

    private:
        int chosenx = 0;
        int choseny = 0;
        Game *game;
        std::vector <Piece::Coordinates> current_piece_vec;
        QPushButton *button_arr[14][14];

        int heightForWidth(int) const;

        bool offline;

        void initMap(QGridLayout *, QSignalMapper *, Game *);

        void handle_valid_moves(Piece::Coordinates) const;

        bool check_piece(Piece::Coordinates);

        void resetColors(bool);

    private slots:
        void handleButtonClick(int);
};

#endif // CHESSWIDGET_H
