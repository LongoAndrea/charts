#ifndef MYRADARCHART_H
#define MYRADARCHART_H

#include "myabstractchart.h"

class MyRadarChart : public MyAbstractChart
{
public:
    MyRadarChart() =default;
    MyRadarChart(const Matrix* mat): MyAbstractChart(mat){}
    virtual ~MyRadarChart() = default;
    virtual QChart* createChart() const;
};

#endif // MYRADARCHART_H
