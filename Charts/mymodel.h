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
    MyModel() : m() {}
    void modifyValue(int r, int c, const QString& value);
    const QString& getValue(int r, int c) const;
    void addRow();
    void addColumn();
    void deleteRow();
    void deleteColumn();
    void createMatrix(const QString& title, int r, int c);
};

#endif // MYMODEL_H
