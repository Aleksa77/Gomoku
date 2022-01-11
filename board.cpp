#include "board.h"

Board::Board(int size, int winLine): _size(size), _winLine(winLine)
{
    allocate();
    _inGame = true;
}

void Board::allocate()
{
    _field.resize(_size);
    for (int i = 0; i < _size; ++i)
        _field[i].resize(_size, CELL_TYPE::NOTHING);
}

int Board::setCell(int i, int j)
{
    if(_inGame){
        CELL_TYPE tmp;
        if (_count % 2)
            tmp = CELL_TYPE::ZERO;
        else tmp = CELL_TYPE::CROSS;
        if(_field[i][j] == CELL_TYPE::NOTHING){
            _field[i][j] = tmp;
            ++_count;
        }
        checkWin();
        if(_inGame)
            return 0;
    }
    return 1;
}

void Board::checkWin()
{
    for(int i = 0; i < _size; ++i)
        for(int j = 0; j < _size; ++j){
            if (_field[i][j] == CELL_TYPE::NOTHING)
                continue;
            for(int m = 0; m < _winLine; ++m){
                if(i+m < _size){
                    if(!(_field[i+m][j] == _field[i][j]))
                        break;
                    if(m == _winLine - 1){
                        _winner = static_cast <PLAYER>(_field[i][j]);
                        _inGame = false;
                    }

                }
                else break;
            }
            for(int n = 0; n < _winLine; ++n){
                if(j+n < _size){
                    if(!(_field[i][j+n] == _field[i][j]))
                        break;
                    if(n == _winLine - 1){
                        _winner = static_cast <PLAYER>(_field[i][j]);
                        _inGame = false;
                    }
                }
                else break;
            }
            for(int k = 0; k < _winLine; ++k){
                if((i+k < _size)&&(j+k < _size)){
                    if(!(_field[i+k][j+k] == _field[i][j]))
                        break;
                    if(k == _winLine -1){
                        _winner = static_cast <PLAYER>(_field[i][j]);
                        _inGame = false;
                    }
                }
                else break;
            }
            for(int l = 0; l < _winLine; ++l){
                if((i+l < _size)&&(j-l >= 0)){
                    if(!(_field[i+l][j-l] == _field[i][j]))
                        break;
                    if(l == _winLine -1){
                        _winner = static_cast<PLAYER>(_field[i][j]);
                        _inGame = false;
                    }
                }
                else break;
            }
        }
}

PLAYER Board::getWinner()
{
    return _winner;
}

CELL_TYPE Board::getCell(int i, int j)
{
    return _field[i][j];
}

void Board::restart()
{
   for(int i = 0; i < _size; ++i){
       for(int j = 0; j < _size; ++j){
           _field[i][j] = CELL_TYPE::NOTHING;
       }
   }
   _inGame = true;
   _count = 0;
}
