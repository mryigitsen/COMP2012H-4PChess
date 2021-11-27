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
    std::vector <Piece::Coordinates> current_piece_vec;
    Game *game;

    int heightForWidth(int) const;

    bool offline;
    QPushButton *button_arr[14][14];

    void initMap(QGridLayout *, QSignalMapper *, Game *);

    void handle_valid_moves(Piece::Coordinates) const;

    bool check_piece(Piece::Coordinates);

    void resetColors(bool);

private
    slots:
            void handleButtonClick(int);

    signals:


};

#endif // CHESSWIDGET_H
