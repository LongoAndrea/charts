#ifndef MYBARCHART_H
#define MYBARCHART_H
#include "myabstractchart.h"

class MyBarChart: virtual public MyAbstractChart
{
public:
    MyBarChart() =default;
    MyBarChart(Matrix& mat): MyAbstractChart(mat){}
    virtual ~MyBarChart() = default;
    virtual QChart* createChart() const;

};

#endif // MYBARCHART_H
