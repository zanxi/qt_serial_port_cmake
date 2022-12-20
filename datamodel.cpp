#include "datamodel.h"


void DataModel::InitComPort(){


}

// инициализация и открытие Com порта
void DataModel::OpenComPort(){

    com.SetPort("/dev/ttyS0");
    com.SetBaudRate(9600);
    com.SetDataSize(8);
    com.SetParity('N');
    com.SetStopBits(1);

    com.SetRTS(true);
    com.SetDTR(false);

    //ceSerial com("/dev/ttyS0",9600,8,'N',1);


    if (com.Open() == 0) {
            addValue("Device ready!!!!!!.\n");
        }
        else {
            addValue("Device NOT ready ??????????.\n");
        }

}

void DataModel::Open()
{
    InitComPort();
    OpenComPort();
    emit layoutChanged();


}



DataModel::DataModel(QObject *parent) : QAbstractItemModel(parent)
{

}

int DataModel::columnCount(const QModelIndex &) const
{
    return 1;
}

int DataModel::rowCount(const QModelIndex &) const
{
    return m_data.size();
}

QVariant DataModel::data(const QModelIndex &index, int role) const
{
    if( role == Qt::DisplayRole )
    {
        return m_data.at(index.row());
    }
    return QVariant();
}

QModelIndex DataModel::index(int row, int column, const QModelIndex &) const
{
    return createIndex(row, column, (void*)&m_data[row]);
}

QModelIndex DataModel::parent(const QModelIndex &) const
{
    return QModelIndex();
}
// посылка прочитанных значений
void DataModel::addValue(const QString &value)
{    
    m_data.append(value);
    emit layoutChanged();
}
