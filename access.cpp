#include "access.h"
#include "ui_access.h"

Access::Access(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Access)
{
    ui->setupUi(this);
}

Access::~Access()
{
    delete ui;
}
