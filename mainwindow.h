#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "second.h"
#include "PasswordManager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void loginPress();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    second * secondWindow;
    PasswordManager * pmg;
};
#endif // MAINWINDOW_H
