#include "make.h"
#include "ui_make.h"

Make::Make(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Make)
{
    ui->setupUi(this);
}

Make::~Make()
{
    delete ui;
}

void Make::on_submitbutton_clicked()
{
    int d_fi_id = std::stoi(ui->fi_id->text().toStdString());
    int d_thirdparty_id = std::stoi(ui->thirdparty_id->text().toStdString());
    std::string d_reportdate = ui->reportdate->text().toStdString();
    std::string d_duediligencedate = ui->duediligencedate->text().toStdString();
    std::string d_duediligencetype = ui->dueddiligencetype->text().toStdString();

    //doSomething(d_fi_id, d_thirdparty_id, d_reportdate, d_duediligencedate, d_duediligencetype);
}
