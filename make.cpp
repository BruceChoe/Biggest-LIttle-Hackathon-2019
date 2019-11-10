#include "make.h"
#include "ui_make.h"
#include "BlockChain.h"

Make::Make(Blockchain * b, PasswordManager * p, std::string u, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Make),
    pmg(p),
    user(u),
    bc(b)
{
    ui->setupUi(this);
}

Make::~Make()
{
    delete ui;
}

void Make::on_submitbutton_clicked()
{
    std::string d_tp_id = ui->tp_name->text().toStdString();
    int d_fi_id = std::stoi(ui->fi_id->text().toStdString());
    int d_thirdparty_id = std::stoi(ui->thirdparty_id->text().toStdString());
    std::string d_reportdate = ui->reportdate->text().toStdString();
    std::string d_duediligencedate = ui->duediligencedate->text().toStdString();
    std::string d_duediligencetype = ui->dueddiligencetype->text().toStdString();

    FI temp(user, d_fi_id);
    Report r(d_fi_id, d_thirdparty_id, d_duediligencedate, d_reportdate, d_duediligencetype);
    ThirdParty tempTP(d_thirdparty_id, d_tp_id, d_duediligencetype);

    Blockchain bChain = Blockchain();
    bChain.AddBlock(Block(0, temp, tempTP, r));
    //This function returns a report - In this case a report is just made - needs to be saved later...

    hide();
}
