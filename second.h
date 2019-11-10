#ifndef SECOND_H
#define SECOND_H

#include <QMainWindow>
#include "make.h"
#include "access.h"

namespace Ui {
class second;
}

class second : public QMainWindow
{
    Q_OBJECT

public:
    explicit second(QWidget *parent = nullptr);
    ~second();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::second *ui;
    Make * makeWindow;
    Access * accessWindow;
};

#endif // SECOND_H
