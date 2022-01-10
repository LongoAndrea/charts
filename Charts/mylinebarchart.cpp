#include "mylinebarchart.h"
#include "matrix.h"

MyLineBarChart::MyLineBarChart(Matrix& mat, const QString& f): MyAbstractChart(mat), MyLineChart(mat,f) {}

QChart* MyLineBarChart::createChart() const {
    QChart *chart = new QChart();
    chart->setTitle(m->getValue(0,0));
    QDateTimeAxis *axisX = new QDateTimeAxis();
    axisX->setTickCount(m->getColumns()-1);
    axisX->setMin(QDateTime::fromString(m->getValue(0,1), format));
    axisX->setMax(QDateTime::fromString(m->getValue(0,m->getColumns()-1), format));
    axisX->setFormat(format);
    QBarSet *bset;
    QBarSeries *bseries = new QBarSeries();
    for(int i = 1; i < m->getRows(); i++) {
        bset = new QBarSet(m->getValue(i,0));
        for(int j = 1; j < m->getColumns(); j++) {
            //QDateTime d = QDateTime::fromString(m->getValue(0,j), "dd.MM.yyyy");
            //lseries->append(d.toMSecsSinceEpoch(), m->getValue(i,j).toInt());
            bset->append(m->getValue(i,j).toInt());
        }
        bseries->append(bset);
    }
    chart->addSeries(bseries);
    QLineSeries *lseries = new QLineSeries();
    lseries->setName("Media");
    for(int j = 1; j < m->getColumns(); j++) {
        QDateTime d = QDateTime::fromString(m->getValue(0,j), "dd.MM.yyyy");
        double sum = 0;
        for(int i = 1; i < m->getRows(); i++) {
            sum += m->getValue(i,j).toInt();
        }
        lseries->append(d.toMSecsSinceEpoch(), sum/(m->getRows()-1));
    }
    chart->addSeries(lseries);
    chart->createDefaultAxes();
    chart->axisY()->setMin(0);
    chart->setAxisX(axisX);
    return chart;
}
