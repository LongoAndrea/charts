#ifndef MYMODEL_H
#define MYMODEL_H

#include "matrix.h"
#include <QString>

class MyModel
{
private:
    Matrix* m;
    static QString defaultValue;
public:
    MyModel() : m(new Matrix());
    void modifyValue(int r, int c, const QString& value);
    const QString& getValue(int r, int c) const;
    void addRow();
    void addColumn();
    void deleteRow();
    void deleteColumn();
};

#endif // MYMODEL_H
