#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

enum class CELL_TYPE{
    NOTHING,
    CROSS,
    ZERO
};

enum class PLAYER{
    NOTHING,
    PLAYER1,
    PLAYER2
};

class Board
{
public:
    Board(int,int);
    void allocate();
    int setCell(int, int);
    void checkWin();
    PLAYER getWinner();
    CELL_TYPE getCell(int,int);
    void restart();

private:
    int _count = 0;
    std::vector<std::vector<CELL_TYPE>> _field;
    int _size;
    PLAYER _winner = PLAYER::NOTHING;
    bool _inGame = false;
    int _winLine = 3;
};

#endif // BOARD_H
