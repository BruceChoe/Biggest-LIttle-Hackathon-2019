#ifndef SECOND_H
#define SECOND_H

#include <QMainWindow>
#include "make.h"
#include "access.h"
#include "PasswordManager.h"
#include "BlockChain.h"

namespace Ui {
class second;
}

class second : public QMainWindow
{
    Q_OBJECT

public:
    explicit second(PasswordManager * p, std::string u, QWidget *parent = nullptr);
    ~second();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::second *ui;
    Make * makeWindow;
    Access * accessWindow;
    PasswordManager * pmg;
    std::string user;
    Blockchain * bc;
};

#endif // SECOND_H
