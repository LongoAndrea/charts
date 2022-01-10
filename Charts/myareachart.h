#ifndef MYAREACHART_H
#define MYAREACHART_H

#include "myabstractdatechart.h"
#include "matrix.h"

#include <QString>
#include <QChart>

class MyAreaChart : public MyAbstractDateChart
{
public:
    MyAreaChart(Matrix& m, const QString& f) : MyAbstractDateChart(m, f) {}
    virtual QChart* createChart() const;
};

#endif // MYAREACHART_H
