#include "passwordgeneratorwin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PasswordGeneratorWin w;
    w.show();

    return a.exec();
}
