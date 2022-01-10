#include "mylinechart.h"

#include <QChart>
#include <QDateTimeAxis>
#include <QLineSeries>

QChart* MyLineChart::createChart() const{
    QChart *chart = new QChart();
    chart->setTitle(m->getValue(0,0));
    QDateTimeAxis *axisX = new QDateTimeAxis();
    axisX->setTickCount(m->getColumns()-1);
    axisX->setMin(QDateTime::fromString(m->getValue(0,1), format));
    axisX->setMax(QDateTime::fromString(m->getValue(0,m->getColumns()-1), format));
    axisX->setFormat(format);
    QLineSeries *series;
    for(int i = 1; i < m->getRows(); i++) {
        series = new QLineSeries();
        series->setName(m->getValue(i,0));
        for(int j = 1; j < m->getColumns(); j++) {
            QDateTime d = QDateTime::fromString(m->getValue(0,j), "dd.MM.yyyy");
            series->append(d.toMSecsSinceEpoch(), m->getValue(i,j).toInt());
        }
        chart->addSeries(series);
    }
    chart->createDefaultAxes();
    chart->axisY()->setMin(0);
    chart->setAxisX(axisX);
    return chart;
}
