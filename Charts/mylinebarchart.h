#ifndef MYLINEBARCHART_H
#define MYLINEBARCHART_H

#include "mybarchart.h"
#include "mylinechart.h"

class MyLineBarChart : public MyBarChart, public MyLineChart
{
public:
    MyLineBarChart(const Matrix* m, const QString& f);
    virtual ~MyLineBarChart() =default;
    virtual QChart* createChart() const;
};

#endif // MYLINEBARCHART_H
