#include "mydatamodel.h"
#include <QDebug>
#include <iostream>
#include <list>
#include <QSize>


MyDataModel::MyDataModel(): m_data(), m_xMin(0), m_xMax(0) {}



int MyDataModel::rowCount(const QModelIndex &parent) const
{

    return m_data.size();
}

int MyDataModel::columnCount(const QModelIndex &parent) const
{

    return 2;
}


QVariant MyDataModel::headerData(int /* section */, Qt::Orientation /* orientation */, int role) const
{
    if (role == Qt::SizeHintRole)
        return QSize(1, 1);
    return QVariant();
}

QVariant MyDataModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    const QPointF p = m_data[index.row()];

    if (index.column() == 0)
        return p.x();

    return p.y();
}


QHash<int, QByteArray> MyDataModel::roleNames() const
{
    static QHash<int, QByteArray> roleNames{{ValueRole, "value"}};
    return roleNames;
}

void MyDataModel::addData(const QPointF &point)
{
    if (m_data.size() == 500) {
        beginRemoveRows(QModelIndex(), 0, 0);
        m_data.pop_front();
        endRemoveRows();
        emit xMinChanged();
    }

    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_data.push_back(point);
    endInsertRows();
    emit xMaxChanged();
}


