#ifndef MYLINEBARCHART_H
#define MYLINEBARCHART_H

#include "mybarchart.h"
#include "mylinechart.h"

class MyLineBarChart : public MyBarChart, public MyLineChart
{
public:
    MyLineBarChart(const QString& f, const Matrix* m = 0);
    virtual ~MyLineBarChart() =default;
    virtual QChart* createChart() const;
};

#endif // MYLINEBARCHART_H
