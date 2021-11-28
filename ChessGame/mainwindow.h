#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include "chessclientobj.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class ChessClientObj;
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(ChessClientObj *client = nullptr, int count = 0, bool online = false, bool firstOnline= true, QWidget *parent = nullptr);

    ~MainWindow();

    void update_scores(int player_1_score, int player_2_score, int player_3_score, int player_4_score);

private:
    Ui::MainWindow *ui;

    void initGrid();

};

#endif // MAINWINDOW_H
