#ifndef MYLINECHART_H
#define MYLINECHART_H

#include "myabstractdatechart.h"
#include "matrix.h"

#include <QString>
#include <QChart>

class MyLineChart : public MyAbstractDateChart
{
public:
    MyLineChart() =default;
    MyLineChart(Matrix& m, const QString& f) : MyAbstractDateChart(m, f) {}
    virtual ~MyLineChart() =default;
    virtual QChart* createChart() const;
};

#endif // MYLINECHART_H
