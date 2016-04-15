//-------------------------------------------------
//
// Project created by Mandar Shinde 2016-04-15T12:02:30
//
//-------------------------------------------------

#ifndef PASSWORDGENERATORWIN_H
#define PASSWORDGENERATORWIN_H

#include <QMainWindow>

namespace Ui {
class PasswordGeneratorWin;
}

class PasswordGeneratorWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit PasswordGeneratorWin(QWidget *parent = 0);
    ~PasswordGeneratorWin();

private slots:
    void on_GeneratePassword_clicked();

private:
    Ui::PasswordGeneratorWin *ui;
};

#endif // PASSWORDGENERATORWIN_H
