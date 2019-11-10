#ifndef MAKE_H
#define MAKE_H

#include <QMainWindow>

namespace Ui {
class Make;
}

class Make : public QMainWindow
{
    Q_OBJECT

public:
    explicit Make(QWidget *parent = nullptr);
    ~Make();

private slots:
    void on_submitbutton_clicked();

private:
    Ui::Make *ui;
};

#endif // MAKE_H
