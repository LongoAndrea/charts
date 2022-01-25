#ifndef MYPIECHART_H
#define MYPIECHART_H
#include "myabstractchart.h"
#include "drilldownchart.h"
#include "drilldownslice.h"

class MyPieChart : public MyAbstractChart
{
    /* se le faccio annidate
private:
    class DrilldownChart;
    class DrilldownSlice;*/
public:
    MyPieChart(const Matrix* mat): MyAbstractChart(mat){}
    virtual ~MyPieChart() =default;
    virtual QChart* createChart() const;
};

#endif // MYPIECHART_H
