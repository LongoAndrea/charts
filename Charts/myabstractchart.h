#ifndef MYABSTRACTCHART_H
#define MYABSTRACTCHART_H
#include "matrix.h"
#include <QtCharts>

class MyAbstractChart
{
protected://per accedere alla matrice anche dalle classi figlie
    Matrix* m;
public:
    MyAbstractChart() =default;
    MyAbstractChart(Matrix& mat): m(&mat){}
    virtual ~MyAbstractChart() = default;
    virtual QChart* createChart() const =0;

};

#endif // MYABSTRACTCHART_H
