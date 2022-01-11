#include "mycontroller.h"
#include "mybarchart.h"
#include "mylinebarchart.h"
#include "myradarchart.h"
#include <QTableWidget>
#include <QMessageBox>
#include <QHBoxLayout>

/*MyController::MyController(Matrix &m, QWidget &w): matrix(&m), mainWidget(&w){
    table = new QTableWidget(matrix->getRows()-1,matrix->getColumns()-1);
    for(int m=1; m<matrix->getColumns(); m++)
        table->setHorizontalHeaderItem(m-1, new QTableWidgetItem(matrix->getValue(0,m)));
    for(int n=1; n<matrix->getRows(); n++)
        table->setVerticalHeaderItem(n-1, new QTableWidgetItem(matrix->getValue(n,0)));
    for(int i=1; i<matrix->getRows(); i++)
        for(int j=1; j<matrix->getColumns(); j++)
            table->setItem(i-1,j-1,new QTableWidgetItem(matrix->getValue(i,j)));
    table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    QObject::connect(table, SIGNAL(cellChanged(int,int)), this, SLOT(modifyMatrix(int,int)));
    chart = new MyRadarChart(*matrix);
    chartView = new QChartView(chart->createChart());
    //table->show(); //fa la vista
}*/

void MyController::show() {
    /*if(matrix == nullptr) {
        QWidget *w = new QWidget();
        w->show();
    }*/
    //else {
        QHBoxLayout *hl = new QHBoxLayout();
        QMessageBox msgBox;
        msgBox.setText("1");
        msgBox.exec();
        hl->addWidget(table);
        msgBox.setText("2");
        msgBox.exec();
        hl->addWidget(chartView); //chiamata polimorfa
        msgBox.setText("3");
        msgBox.exec();
        mainWidget = new QWidget();
        msgBox.setText("4");
        msgBox.exec();
        mainWidget->setLayout(hl);
        msgBox.setText("5");
        msgBox.exec();
        mainWidget->show();
        msgBox.setText("6");
        msgBox.exec();
    //}
}

void MyController::modifyMatrix(int x, int y) {
    model->modifyValue(x+1,y+1,table->item(x,y)->text());
    chartView->setChart(chart->createChart());
    /*QMessageBox msgBox;
    msgBox.setText(matrix->getValue(x,y));
    msgBox.exec();*/
}
