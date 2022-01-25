#ifndef MYMODEL_H
#define MYMODEL_H

#include "matrix.h"
#include "loader.h"
#include "xmlloader.h"
#include <QString>

class MyModel
{
private:
    Matrix* m;
    static QString defaultValue;
    Loader* l;
public:
    MyModel() : m(), l() {}
    void modifyValue(int r, int c, const QString& value);
    const QString& getValue(int r, int c) const;
    void addRow();
    void addColumn();
    void deleteRow();
    void deleteColumn();
    void createMatrix(const QString& title, int r, int c);
    const Matrix* getMatrix() const;
    void openChartFile(QString& p, QString& typechart, QString&,bool&);
    void saveChartFile(QString& p, QString& typechart,QString&);
};

#endif // MYMODEL_H
