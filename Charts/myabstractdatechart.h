#ifndef MYABSTRACTDATECHART_H
#define MYABSTRACTDATECHART_H

#include "myabstractchart.h"
#include "matrix.h"

#include <QString>

class MyAbstractDateChart : virtual public MyAbstractChart {
protected:
    QString format;
public:
    MyAbstractDateChart(const Matrix* m, const QString& f) : MyAbstractChart(m), format(f) {}
    const QString& getFormat() const { return format; }
    virtual ~MyAbstractDateChart() =default;
    virtual QChart* createChart() const =0;

};

#endif
