#include "mycontroller.h"
#include "mybarchart.h"
#include "mylinebarchart.h"
#include "myareachart.h"
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

//void MyController::show() {
    /*if(matrix == nullptr) {
        QWidget *w = new QWidget();
        w->show();
    }*/
    //else {
        /*QHBoxLayout *hl = new QHBoxLayout();
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
        msgBox.exec();*/
    //}
//}

MyAbstractChart* MyController::create(QString& type){
    if (type.endsWith("MyBarChart"))
        return new MyBarChart(model->getMatrix());
    //if(type.endsWith("MyAreaChart"))
        //return new MyAreaChart(model->getMatrix());
    //if(type.endsWith("MyLineChart"))
        //return new MyLineChart(model->getMatrix());
    if(type.endsWith("MyRadarChart"))
       return new MyRadarChart(model->getMatrix());

}

void MyController::modifyMatrix(int x, int y, const QString& value) {
    model->modifyValue(x,y,value); //sistema la view, abbiamo aggiunto value
    view->setChart(chart->createChart());
    /*QMessageBox msgBox;
    msgBox.setText(matrix->getValue(x,y));
    msgBox.exec();*/
}

void MyController::newBarChart() {
    QString title = "";
    int rows = 0, columns = 0;
    view->showStandardInputDialog(title, rows, columns);
    /*QMessageBox msgBox;
    msgBox.setText(title);
    msgBox.exec();*/
    model->createMatrix(title,rows+1,columns+1); //la matrix ha sempre una colonna e una riga in più

    QTableWidget *table = new QTableWidget(rows,columns);
    for(int i=1; i<rows+1; i++)
        for(int j=1; j<columns+1; j++)
            table->setItem(i-1,j-1,new QTableWidgetItem(model->getValue(i,j)));
    view->setTable(table);
    //MyAbstractChart *aux = chart;
    //if(chart != nullptr)    delete chart; //quando il programma viene avviato, chart è nullptr
    chart = new MyBarChart(model->getMatrix());
    //delete aux; //controllare i delete
    view->setChart(chart->createChart()); //chiamata polimorfa

}

void MyController::onCellChanged(QTableWidgetItem* item) {
    /* PARSING */
    modifyMatrix(item->row() + 1,item->column() + 1,item->text());

}

void MyController::openFile(){
    QString typechart;//da vedere come gestire
    QString path = QFileDialog::getOpenFileName(view,tr("Open File"), "/home/", tr("chart File (*.xml)"));
    if(path != ""){
        model->openChartFile(path,typechart);

        //mostro nella vista
        int rows = model->getMatrix()->getRows();
        int columns = model->getMatrix()->getColumns();
        QTableWidget *table = new QTableWidget(rows-1,columns-1);
        for(int i=1; i<rows; i++)
            for(int j=1; j<columns; j++)
                table->setItem(i-1,j-1,new QTableWidgetItem(model->getValue(i,j)));
        view->setTable(table);
        //in base al typechart
        //chart = new MyBarChart(model->getMatrix());
        chart = create(typechart);
        view->setChart(chart->createChart()); //chiamata polimorfa
    }

}

void MyController::saveFile(){
    QString typechart = typeid(*chart).name();
    QString path = QFileDialog::getSaveFileName(view,tr("Save File"), "/home/", tr("chart File (*.xml)"));
    model->saveChartFile(path,typechart);
}


void MyController::addRow(){
    model->addRow();
    QString typechart = typeid(*chart).name();
    //mostro nella vista
    int rows = model->getMatrix()->getRows();
    int columns = model->getMatrix()->getColumns();
    QTableWidget *table = new QTableWidget(rows-1,columns-1);
    for(int i=1; i<rows; i++)
        for(int j=1; j<columns; j++)
            table->setItem(i-1,j-1,new QTableWidgetItem(model->getValue(i,j)));
    view->setTable(table);
    //in base al typechart
    chart = create(typechart);
    view->setChart(chart->createChart()); //chiamata polimorfa
}

void MyController::addColumn(){
    model->addColumn();
QString typechart = typeid(*chart).name();
    //mostro nella vista
    int rows = model->getMatrix()->getRows();
    int columns = model->getMatrix()->getColumns();
    QTableWidget *table = new QTableWidget(rows-1,columns-1);
    for(int i=1; i<rows; i++)
        for(int j=1; j<columns; j++)
            table->setItem(i-1,j-1,new QTableWidgetItem(model->getValue(i,j)));
    view->setTable(table);
    //in base al typechart
    chart = create(typechart);
    view->setChart(chart->createChart()); //chiamata polimorfa
}

void MyController::deleteRow(){
    model->deleteRow();
QString typechart = typeid(*chart).name();
    //mostro nella vista
    int rows = model->getMatrix()->getRows();
    int columns = model->getMatrix()->getColumns();
    QTableWidget *table = new QTableWidget(rows-1,columns-1);
    for(int i=1; i<rows; i++)
        for(int j=1; j<columns; j++)
            table->setItem(i-1,j-1,new QTableWidgetItem(model->getValue(i,j)));
    view->setTable(table);
    //in base al typechart
    chart = create(typechart);
    view->setChart(chart->createChart()); //chiamata polimorfa
}

void MyController::deleteColumn(){
    model->deleteColumn();
QString typechart = typeid(*chart).name();
    //mostro nella vista
    int rows = model->getMatrix()->getRows();
    int columns = model->getMatrix()->getColumns();
    QTableWidget *table = new QTableWidget(rows-1,columns-1);
    for(int i=1; i<rows; i++)
        for(int j=1; j<columns; j++)
            table->setItem(i-1,j-1,new QTableWidgetItem(model->getValue(i,j)));
    view->setTable(table);
    //in base al typechart
    chart = create(typechart);
    view->setChart(chart->createChart()); //chiamata polimorfa
}
