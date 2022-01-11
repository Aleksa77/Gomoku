#include "prepare.h"
#include "ui_prepare.h"

Prepare::Prepare(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Prepare)
{
    ui->setupUi(this);
    connect(ui->buttonBox,&QDialogButtonBox::accepted,this,&Prepare::startGame);
    connect(ui->spinBox,&QSpinBox::valueChanged,this,&Prepare::maxWinValue);
    connect(ui->spinBox_2,&QSpinBox::valueChanged,this,&Prepare::maxWinValue);
}

Prepare::~Prepare()
{
    delete ui;
}

void Prepare::startGame()
{
    int size = ui->spinBox_2->value();
    int winLine = ui->spinBox->value();
    _gomoku = new Gomoku(size,winLine);
    connect(_gomoku,&Gomoku::gameEnd,this,&Prepare::restartGame);
    this->hide();
    _gomoku->show();
}

void Prepare::maxWinValue()
{
    if(ui->spinBox->value() > ui->spinBox_2->value())
        ui->spinBox->setValue(ui->spinBox_2->value());
}

void Prepare::restartGame()
{
    _needRestart = true;
    _gomoku->deleteLater();
    this->show();
}
