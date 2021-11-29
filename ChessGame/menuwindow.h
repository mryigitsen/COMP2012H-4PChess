#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include "chessclientobj.h"
namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

private:
    Ui::MenuWindow *ui;
    ChessClientObj *connect;
private slots:
    void on_start_game_clicked();
    void on_create_game_clicked();
};

#endif // MENUWINDOW_H
