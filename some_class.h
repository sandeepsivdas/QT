#ifndef SOME_CLASS_H
#define SOME_CLASS_H

#include <QObject>

extern double arr[];

class some_class : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<qreal> floatarray READ getfloatarray WRITE setfloatarray NOTIFY floatarrayChanged)

public:
//    int line_flag;
    int myint1;

    explicit some_class(QObject *parent = 0);
    ~some_class();
    Q_INVOKABLE int callMe();
    Q_INVOKABLE void readtext();
    QList<qreal> getfloatarray()
    {
        return m_floatarray;
    }
    Q_INVOKABLE void setfloatarray(QList<qreal>)
    {
        emit floatarrayChanged(m_floatarray);
    }



signals:
        void floatarrayChanged(QList<qreal>);

public slots:

private:

    QList<qreal> m_floatarray={1.1000,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.01,
                               1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.01,
                               1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.01,
                               1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.01,
                               1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.01
                                };

};

#endif // SOME_CLASS_H
