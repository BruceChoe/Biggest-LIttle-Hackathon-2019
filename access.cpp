#include "access.h"
#include "ui_access.h"
#include "PasswordManager.h"

Access::Access(Blockchain * b, PasswordManager * p, std::string u, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Access),
    pmg(p),
    user(u),
    bc(b)
{
    ui->setupUi(this);


    DataTable * table = new DataTable(this);
    //table->populate(vec);

    ui->dataTable->setModel(table);
    ui->dataTable->horizontalHeader()->setVisible(true);
    ui->dataTable->show();
}

Access::~Access()
{
    delete ui;
}

DataTable::DataTable(QObject * parent)
    : QAbstractTableModel(parent)
{
}

void DataTable::populate(std::vector<DataItems> & data)
{
    tableData = data;
}

int DataTable::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return static_cast<int>(tableData.size());
}

int DataTable::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 8;
}

QVariant DataTable::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }
    switch(index.column())
    {
    case 0:
        return QString::number(tableData[index.row()].fi_id);
    case 1:
        return QString::number(tableData[index.row()].thirdparty_id);
    case 2:
        return QString::fromStdString(tableData[index.row()].duediligencedate);
    case 3:
        return QString::fromStdString(tableData[index.row()].duediligencetype);
    case 4:
        return QString::fromStdString(tableData[index.row()].reportdate);
    case 5:
        return QString::fromStdString(tableData[index.row()].hash);
    case 6:
        return QString::number(tableData[index.row()].nonce);
    case 7:
        return QString::number(tableData[index.row()].public_key);
    }

    return QVariant();
}

QVariant DataTable::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
            switch(section)
            {
            case 0:
                return QString("Financial Institution ID");
            case 1:
                return QString("Third party ID");
            case 2:
                return QString("Due diligence date");
            case 3:
                return QString("Due diligence type");
            case 4:
                return QString("Report date");
            case 5:
                return QString("Hash");
            case 6:
                return QString("Nonce");
            case 7:
                return QString("Public key");
            }
        }
    return QVariant();
}
