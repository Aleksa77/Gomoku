#include "prepare.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Prepare p;
    p.show();
    return a.exec();
}
