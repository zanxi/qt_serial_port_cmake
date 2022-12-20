#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QObject>
#include <QAbstractItemModel>
#include <QStringList>

#include "ceSerial.h"  // библиотека работы с COM портами
using namespace ce;

// Модель данных  - работа с Com портом

class DataModel : public QAbstractItemModel
{
   Q_OBJECT

    QStringList m_data;

public:
    DataModel(QObject *parent);

    // Model interface implementation

    virtual int columnCount(const QModelIndex &parent) const;
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QModelIndex index(int row, int column, const QModelIndex &parent) const;
    virtual QModelIndex parent(const QModelIndex &index) const;

    ceSerial com; // создаем инстанс для работы с COM портом
    void InitComPort();
    void OpenComPort();
    //ceSerial com("/dev/ttyS0",9600,8,'N',1);


public slots:
    void addValue(const QString &value);
    void Open();



};

#endif // DATAMODEL_H
