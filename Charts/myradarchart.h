#ifndef MYRADARCHART_H
#define MYRADARCHART_H

#include "myabstractchart.h"

class MyRadarChart : virtual public MyAbstractChart
{
public:
    MyRadarChart() =default;
    MyRadarChart(Matrix& mat): MyAbstractChart(mat){}
    virtual ~MyRadarChart() = default;
    virtual QChart* createChart() const;
};

#endif // MYRADARCHART_H
