#include "gomoku.h"
#include "ui_gomoku.h"

Gomoku::Gomoku(int size, int winLine, QWidget *parent)
    : QMainWindow(parent)
    , _size(size)
    , ui(new Ui::Gomoku)
{
    ui->setupUi(this);
    _board = new Board(_size, winLine);
    draw();
}

Gomoku::~Gomoku()
{
    delete ui;
}

void Gomoku::draw()
{
    for (int i = 0; i < _size; ++i)
        for (int j = 0; j < _size; ++j) {
            QPushButton* btn = new QPushButton("");
            btn->setFixedSize(40,40);
            ui->field->addWidget(btn, i, j);
            connect(btn, &QPushButton::clicked,this,&Gomoku::setCell);
        }
    this->adjustSize();
}

void Gomoku::setCell()
{
    QObject* obj = sender();
    QWidget* widget = qobject_cast<QWidget*>(obj);
    QPushButton* btn = qobject_cast<QPushButton*>(widget);

    long long index = ui->field->indexOf(widget);
    int j = index % _size;
    int i = (index - index % _size) / _size;
    int result = _board->setCell(i,j);
    CELL_TYPE cell = _board->getCell(i,j);
    if(cell == CELL_TYPE::CROSS)
        btn->setText("X");
    else if(cell == CELL_TYPE::ZERO)
        btn->setText("O");
    if(result) {
        showWinner(static_cast<int>(_board->getWinner()));
        emit gameEnd();
    }
}

void Gomoku::restart()
{
    for (int i = 0; i < _size * _size; ++i){
        QWidget* widget = ui->field->itemAt(i)->widget();
        QPushButton* btn = qobject_cast<QPushButton*>(widget);
        btn->setText("");
    }
    _board->restart();
}

void Gomoku::showWinner(int winner)
{
    QMessageBox msg;
    msg.setText("***Игрок " + QString::number(winner) + " победил!***");
    msg.exec();
}

