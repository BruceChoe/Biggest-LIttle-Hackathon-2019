#ifndef MAKE_H
#define MAKE_H

#include <QMainWindow>
#include "PasswordManager.h"
#include "BlockChain.h"

namespace Ui {
class Make;
}

class Make : public QMainWindow
{
    Q_OBJECT

public:
    explicit Make(Blockchain * b, PasswordManager * p, std::string u, QWidget *parent = nullptr);
    ~Make();

private slots:
    void on_submitbutton_clicked();

private:
    Ui::Make *ui;
    PasswordManager * pmg;
    std::string user;
    Blockchain * bc;
};

#endif // MAKE_H
