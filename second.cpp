#include "second.h"
#include "ui_second.h"

second::second(PasswordManager * p, std::string u, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::second),
    pmg(p),
    user(u)
{
    ui->setupUi(this);
    bc = new Blockchain();
}

second::~second()
{
    delete ui;
}

void second::on_pushButton_2_clicked()
{
    //hide();
    makeWindow = new Make(bc, pmg, user, this);
    makeWindow->show();
}

void second::on_pushButton_clicked()
{
    accessWindow = new Access(bc, pmg, user, this);
    accessWindow->show();
}
