#ifndef PREPARE_H
#define PREPARE_H

#include <QDialog>
#include <QDialogButtonBox>
#include "gomoku.h"

namespace Ui {
class Prepare;
}

class Prepare : public QDialog
{
    Q_OBJECT

public:
    explicit Prepare(QWidget *parent = nullptr);
    ~Prepare();

    void startGame();
    void maxWinValue();
    void restartGame();

private:
    Ui::Prepare *ui;
    Gomoku* _gomoku;
    bool _needRestart = false;
};

#endif // PREPARE_H
