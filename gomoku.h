#ifndef GOMOKU_H
#define GOMOKU_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include "board.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Gomoku; }
QT_END_NAMESPACE

class Gomoku : public QMainWindow
{
    Q_OBJECT

public:
    Gomoku( int, int, QWidget *parent = nullptr);
    ~Gomoku();
    void draw();
    void setCell();
    void restart();
    void showWinner(int);

signals:
    void gameEnd();

private:
    int _size = 3;
    Board* _board;
    Ui::Gomoku *ui;
};
#endif // GOMOKU_H
