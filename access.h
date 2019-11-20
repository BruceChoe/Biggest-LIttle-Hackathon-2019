#ifndef ACCESS_H
#define ACCESS_H

#include <QMainWindow>
#include <QTableView>
#include "PasswordManager.h"
#include "BlockChain.h"

namespace Ui {
class Access;
}

class Access : public QMainWindow
{
    Q_OBJECT

public:
    explicit Access(Blockchain * b, PasswordManager * p, std::string u, QWidget *parent = nullptr);
    ~Access();

private:
    Ui::Access *ui;
    PasswordManager * pmg;
    std::string user;
    Blockchain * bc;
};

struct DataItems
{
    int fi_id;
    int thirdparty_id;
    std::string duediligencedate;
    std::string duediligencetype;
    std::string reportdate;

    std::string hash;
    int nonce;
    long public_key;
};

class DataTable : public QAbstractTableModel
{
public:
    DataTable(QObject * parent = nullptr);
    void populate(std::vector<DataItems> & data);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

private:
    std::vector<DataItems> tableData;
};

#endif // ACCESS_H
