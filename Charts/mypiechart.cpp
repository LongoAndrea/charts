#include<QtCharts>
#include "mypiechart.h"
#include "drilldownchart.h"
#include "drilldownslice.h"



QChart* MyPieChart::createChart() const{
    DrilldownChart *chart = new DrilldownChart();
        chart->setTheme(QChart::ChartThemeLight);
        chart->setAnimationOptions(QChart::AllAnimations);
        chart->legend()->setVisible(true);

        QPieSeries *serie = new QPieSeries();

        //prendo i nomi delle colonne
        QStringList nomeColonne;
        for(int j=1 ; j< m->getColumns();j++){
            nomeColonne.append(m->getValue(0,j));
        }

        //prendo i nomi delle righe (prima colonna)
        QStringList nomeRighe;
        for(int i=1 ; i< m->getColumns();i++){
            nomeRighe.append(m->getValue(i,0));
        }

        //per ogni titolo della riga faccio una serie
        for (QString &riga : nomeRighe) {
            QPieSeries *series = new QPieSeries();
            series->setName(riga);

            //per ogni titolo della colonna faccio una serie
            for (const QString &colonna : nomeColonne)//qui per ogni colonna della riga selezionata prendo il valore della matrice e lo passo come primo parametro
                *series << new DrilldownSlice((m->getValue(nomeRighe.indexOf(riga)+1,nomeColonne.indexOf(colonna)+1)).toDouble(), colonna, serie);

            QObject::connect(series, &QPieSeries::clicked, chart, &DrilldownChart::handleSliceClicked);
            //nella serie del primo grafico faccio la somma di tutte le serie della riga -> ho il totale della riga
            *serie << new DrilldownSlice(series->sum(), riga, series);
        }

        QObject::connect(serie, &QPieSeries::clicked, chart, &DrilldownChart::handleSliceClicked);

        chart->changeSeries(serie);

        return chart;

}
