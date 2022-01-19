#ifndef MYABSTRACTCHART_H
#define MYABSTRACTCHART_H
#include "matrix.h"
#include <QtCharts>

class MyAbstractChart
{
protected://per accedere alla matrice anche dalle classi figlie
    const Matrix* m;
public:
    MyAbstractChart(): m(new Matrix()) {}
    MyAbstractChart(const Matrix* mat): m(mat){}
    virtual ~MyAbstractChart() = default;
    virtual QChart* createChart() const =0;
    void setMatrix(const Matrix* mat) {m = mat;}

};

#endif // MYABSTRACTCHART_H
