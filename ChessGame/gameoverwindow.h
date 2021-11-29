#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H

#include <QDialog>

class Game;

namespace Ui {
class GameOverWindow;
}

class GameOverWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameOverWindow(bool end_to_disconnect, int winner_index, int winner_index_2, int winner_index_3, int winner_index_4, QWidget *parent = nullptr);
    ~GameOverWindow();

private:
    Ui::GameOverWindow *ui;

private slots:
    void on_main_menu_button_clicked();
    void on_quit_game_button_clicked();
};

#endif // GAMEOVERWINDOW_H
