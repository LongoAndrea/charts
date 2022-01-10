#include "myradarchart.h"
#include "matrix.h"
#include <QtCharts>
#include <QPolarChart>

QChart* MyRadarChart::createChart() const {
    QPolarChart *chart = new QPolarChart();
    chart->setTitle(m->getValue(0,0));
    QCategoryAxis *angularAxis = new QCategoryAxis();
    angularAxis->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);
    angularAxis->setRange(0, m->getColumns() - 1);
    for(int j = 1; j < m->getColumns(); j++) {
        angularAxis->append(m->getValue(0,j), j-1);
    }
    QValueAxis *radialAxis = new QValueAxis();
    chart->addAxis(angularAxis, QPolarChart::PolarOrientationAngular);
    chart->addAxis(radialAxis, QPolarChart::PolarOrientationRadial);
    QLineSeries *series;
    double max = 0;
    for(int i = 1; i < m->getRows(); i++) {
        series = new QLineSeries();
        series->setName(m->getValue(i,0));
        int j = 1;
        for(; j < m->getColumns(); j++) {
            double tmp = m->getValue(i,j).toInt();
            if(max < tmp)
                max = tmp;
            series->append(j-1, tmp);
        }
        series->append(j-1, m->getValue(i,1).toInt());
        chart->addSeries(series);
        series->attachAxis(angularAxis);
        series->attachAxis(radialAxis);
    }
    radialAxis->setRange(0,max);
    return chart;
}
