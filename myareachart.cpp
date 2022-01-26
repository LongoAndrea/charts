#include "myareachart.h"

#include <QChart>
#include <QDateTimeAxis>
#include <QLineSeries>

QChart* MyAreaChart::createChart() const {
    QChart *chart = new QChart();
    chart->setTitle(m->getValue(0,0));
    QDateTimeAxis *axisX = new QDateTimeAxis();
    axisX->setTickCount(m->getColumns()-1);
    axisX->setMin(QDateTime::fromString(m->getValue(0,1), format));
    axisX->setMax(QDateTime::fromString(m->getValue(0,m->getColumns()-1), format));
    axisX->setFormat(format);
    QLineSeries *lowerSeries = 0;
    for(int i = 1; i < m->getRows(); i++) {
        QLineSeries *upperSeries = new QLineSeries();
        for(int j = 1; j < m->getColumns(); j++) {
            QDateTime d = QDateTime::fromString(m->getValue(0,j), format);
            if(lowerSeries) {
                int sum = m->getValue(i,j).toInt();
                for(int k = i-1; k > 0; k--)
                    sum += m->getValue(k,j).toInt();
                upperSeries->append(d.toMSecsSinceEpoch(), sum);
            } else {
                upperSeries->append(d.toMSecsSinceEpoch(), m->getValue(i,j).toInt());
            }
        }
        QAreaSeries *area = new QAreaSeries(upperSeries, lowerSeries);
        area->setName(m->getValue(i,0));
        chart->addSeries(area);
        lowerSeries = upperSeries;
    }
    chart->createDefaultAxes();
    chart->axisY()->setMin(0);
    chart->setAxisX(axisX);
    return chart;
}
