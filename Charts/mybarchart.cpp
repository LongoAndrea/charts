#include <QtCharts>
#include "matrix.h"
#include "mybarchart.h"
#include "myabstractchart.h"


QChart* MyBarChart::createChart() const {
    //creo il chart
        QChart *chart = new QChart();

        //salvo il valore max della matrice
        int maxValueMatrix = 0;

        //creo la serie
        QBarSeries *series = new QBarSeries();

        for(int i =1; i < m->getRows(); i++){
            QBarSet *set = new QBarSet(m->getValue(i,0));//prendo la categoria(la prima colonna di tutte le righe)
            for(int j=1; j < m->getColumns(); j++){
                //prendo i dati della matrice
                double tmp = m->getValue(i,j).toDouble();
                if(maxValueMatrix < tmp)
                    maxValueMatrix = tmp;
                *set << tmp;
            }
            series->append(set);
        }

        //prendo la prima riga della matrice per i nomi dell'asse x
        QStringList categories;
        for(int j=1; j < m->getColumns(); j++){
            //prendo i dati della matrice
            categories << m->getValue(0,j);
        }

        chart->addSeries(series);
        chart->setTitle(m->getValue(0,0));
        chart->setAnimationOptions(QChart::SeriesAnimations);


        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,maxValueMatrix);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        return chart;
}
