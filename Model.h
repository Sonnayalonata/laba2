#ifndef MODEL_H
#define MODEL_H

#include <QDate>
#include <QAbstractTableModel>
#include <QItemSelectionModel>

// Модель
/*class MyModel : public QAbstractTableModel
{
public:
    MyModel(QObject *parent = nullptr) : QAbstractTableModel( parent )
        {}

        int columnCount(const QModelIndex &parent = QModelIndex()) const override
        {
            return 3;
            Q_UNUSED( parent )
        }

        /*QVariant headerData(int section, Qt::Orientation orientation, int role) const
        {
            if ((orientation != Qt::Horizontal) | (role != Qt::DisplayRole))
                return QVariant();

            if (section == 0)
                return QString( "Название" );

            if (section == 1)
                return QString( "Описание" );

            return QString( "Время" );

        }*/

       /* bool setData( const QModelIndex &index, const QVariant &value, int role = Qt::EditRole, override
            {
                Q_UNUSED( role )

                if (index.column() == 1)
                {
                    lst2[ index.row() ] = value.toString();
                }

                return true;
            }

};*/


#endif // MODEL_H
