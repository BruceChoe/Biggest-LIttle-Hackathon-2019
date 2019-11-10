#ifndef ACCESS_H
#define ACCESS_H

#include <QMainWindow>

namespace Ui {
class Access;
}

class Access : public QMainWindow
{
    Q_OBJECT

public:
    explicit Access(QWidget *parent = nullptr);
    ~Access();

private:
    Ui::Access *ui;
};

#endif // ACCESS_H
