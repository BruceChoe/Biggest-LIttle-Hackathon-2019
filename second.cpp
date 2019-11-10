#include "second.h"
#include "ui_second.h"

second::second(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::second)
{
    ui->setupUi(this);
}

second::~second()
{
    delete ui;
}

void second::on_pushButton_2_clicked()
{
    //hide();
    makeWindow = new Make(this);
    makeWindow->show();
}

void second::on_pushButton_clicked()
{
    accessWindow = new Access(this);
    accessWindow->show();
}
