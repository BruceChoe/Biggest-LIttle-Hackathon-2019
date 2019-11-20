#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <iostream>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pmg = new PasswordManager();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pmg;
    std::cout << "dtor called mainwindow" << std::endl;
}

void MainWindow::on_pushButton_clicked()
{
    std::string usernameStr = ui->username->text().toStdString();
    std::string passwordStr = ui->password->text().toStdString();

    if(pmg->login(usernameStr, passwordStr))
    {
        hide();
        secondWindow = new second(pmg, usernameStr, this);
        secondWindow->show();
    }
    else {
        QMessageBox::warning(this,"Login", "Incorrect login information.");
    }
}
