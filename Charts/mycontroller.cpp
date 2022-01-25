#include "mycontroller.h"
#include "mybarchart.h"
#include "mylinebarchart.h"
#include "myareachart.h"
#include "myradarchart.h"
#include "mypiechart.h"
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

MyAbstractChart* MyController::create(QString& type,QString& dateformat){
    if (type.endsWith("MyBarChart"))
        return new MyBarChart(model->getMatrix());
    if (type.endsWith("MyPieChart"))
        return new MyPieChart(model->getMatrix());
    if(type.endsWith("MyAreaChart")){
        MyAreaChart* tmp = new MyAreaChart(dateformat);
        tmp->setMatrix(model->getMatrix());
        return tmp;
    }
    if(type.endsWith("MyLineChart")){
        MyLineChart* tmp = new MyLineChart(dateformat);
        tmp->setMatrix(model->getMatrix());
        return tmp;
    }
    if(type.endsWith("MyLineBarChart")){
        MyLineBarChart* tmp = new MyLineBarChart(dateformat);
        tmp->setMatrix(model->getMatrix());
        return tmp;
    }
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
    model->createMatrix(title,1,1);
    newTableHeaders(rows,columns);
    updateTable();
    //MyAbstractChart *aux = chart;
    //if(chart != nullptr)    delete chart; //quando il programma viene avviato, chart è nullptr
    chart = new MyBarChart(model->getMatrix());
    //delete aux; //controllare i delete
    view->setChart(chart->createChart()); //chiamata polimorfa
    view->showModifyButtons();
}

void MyController::newRadarChart() {
    QString title = "";
    int rows = 0, columns = 0;
    view->showStandardInputDialog(title,rows,columns);
    model->createMatrix(title,rows+1,columns+1);
    newTableHeaders(rows,columns);
    updateTable();
    chart = new MyRadarChart(model->getMatrix());
    view->setChart(chart->createChart());
    view->showModifyButtons();
}

void MyController::newLineChart() {
    QString title = "", format = "";
    int rows = 0, columns = 0;
    QDateTime dateTime;
    view->showDataInputDialog(title, rows, columns, format, dateTime);
    model->createMatrix(title,1,columns+1);
    /*QTableWidget *table = new QTableWidget(rows,columns);
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            table->setItem(i,j,new QTableWidgetItem(model->getValue(i+1,j+1)));*/
    for(int j = 1; j < columns+1; j++) {
        model->modifyValue(0,j,dateTime.toString(format));
        //table->setHorizontalHeaderItem(j-1,new QTableWidgetItem(dateTime.toString(format)));
        if(format == "yyyy")
            dateTime = dateTime.addYears(1);
        if(format == "MM.yyyy")
            dateTime = dateTime.addMonths(1);
    }
    for(int i = 1; i < rows+1; i++)
        insertTableHeader(i,"r","Title of row " + QString::number(i) + ":");
    updateTable();
    //view->setTable(table);
    chart = new MyLineChart(format);
    chart->setMatrix(model->getMatrix());
    view->setChart(chart->createChart());
    view->showModifyButtons();
}

void MyController::newAreaChart() {
    QString title = "", format = "";
    int rows = 0, columns = 0;
    QDateTime dateTime;
    view->showDataInputDialog(title, rows, columns, format, dateTime);
    model->createMatrix(title,1,columns+1);
    /*QTableWidget *table = new QTableWidget(rows,columns);
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            table->setItem(i,j,new QTableWidgetItem(model->getValue(i+1,j+1)));*/
    for(int j = 1; j < columns+1; j++) {
        model->modifyValue(0,j,dateTime.toString(format));
        //table->setHorizontalHeaderItem(j-1,new QTableWidgetItem(dateTime.toString(format)));
        if(format == "yyyy")
            dateTime = dateTime.addYears(1);
        if(format == "MM.yyyy")
            dateTime = dateTime.addMonths(1);
    }
    for(int i = 1; i < rows+1; i++)
        insertTableHeader(i,"r","Title of row " + QString::number(i) + ":");
    updateTable();
    //view->setTable(table);
    chart = new MyAreaChart(format);
    chart->setMatrix(model->getMatrix());
    view->setChart(chart->createChart());
    view->showModifyButtons();
}

void MyController::newLineBarChart() {
    QString title = "", format = "";
    int rows = 0, columns = 0;
    QDateTime dateTime;
    view->showDataInputDialog(title, rows, columns, format, dateTime);
    model->createMatrix(title,1,columns+1);
    /*
    QTableWidget *table = new QTableWidget(rows,columns);
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            table->setItem(i,j,new QTableWidgetItem(model->getValue(i+1,j+1)));*/

    for(int j = 1; j < columns+1; j++) {
        model->modifyValue(0,j,dateTime.toString(format));
        //table->setHorizontalHeaderItem(j-1,new QTableWidgetItem(dateTime.toString(format)));
        if(format == "yyyy")
            dateTime = dateTime.addYears(1);
        if(format == "MM.yyyy")
            dateTime = dateTime.addMonths(1);
    }
    for(int i = 1; i < rows+1; i++)
        insertTableHeader(i,"r","Title of row " + QString::number(i) + ":");
    updateTable();
    //view->setTable(table);
    chart = new MyLineBarChart(format);
    chart->setMatrix(model->getMatrix());
    view->setChart(chart->createChart());
    view->showModifyButtons();
}

void MyController::newPieChart(){
    QString title = "";
    int rows = 0, columns = 0;
    view->showStandardInputDialog(title, rows, columns);
    model->createMatrix(title,rows+1,columns+1); //la matrix ha sempre una colonna e una riga in più
    updateTable();
    chart = new MyPieChart(model->getMatrix());    
    view->setChart(chart->createChart()); //chiamata polimorfa
    view->showModifyButtons();
}

void MyController::onCellChanged(QTableWidgetItem* item) {
    /* PARSING */
    modifyMatrix(item->row() + 1,item->column() + 1,item->text());
}

void MyController::openFile(){
    QString typechart;
    QString dateformat;
    bool error=false;
    QString path = QFileDialog::getOpenFileName(view,tr("Open File"), "/home/", tr("chart File (*.xml)"));
    if(path != ""){

        model->openChartFile(path,typechart,dateformat,error);
        if(error){

                QMessageBox msgBox;
                msgBox.setText("Errore riscontrato nella lettura del file.\n");
                msgBox.exec();

        }
        //mostro nella vista
        updateTable();
        chart = create(typechart,dateformat);
        view->setChart(chart->createChart()); //chiamata polimorfa
        view->showModifyButtons();
    }

}

void MyController::saveFile(){
    QString typechart = typeid(*chart).name();
    QString dateformat = "null";
    MyAbstractDateChart* p = dynamic_cast<MyAbstractDateChart*>(chart);
    if(p!=nullptr)
        dateformat = p->getFormat();
    QString path = QFileDialog::getSaveFileName(view,tr("Save File"), "/home/", tr("chart File (*.xml)"));
    model->saveChartFile(path,typechart,dateformat);
}


void MyController::addRow(){

    /*model->addRow();
    model->modifyValue(model->getMatrix()->getRows()-1,0,view->inputHeaderTableDialog("Title of new row:"));*/
    insertTableHeader(model->getMatrix()->getRows(),"r","Title of new row:");
    //mostro nella vista
    updateTable();
    view->setChart(chart->createChart()); //chiamata polimorfa
}

void MyController::addColumn(){
    MyAbstractDateChart* ptr = dynamic_cast<MyAbstractDateChart*>(chart);
    if(ptr !=nullptr)
    {
        //sono datechart
        model->addColumn();
        int columns = model->getMatrix()->getColumns();
        QString format = ptr->getFormat();
        QDateTime lastDate = QDateTime::fromString(model->getValue(0,columns-2),format);
        if(format == "yyyy")
            lastDate = lastDate.addYears(1);
        if(format == "MM.yyyy")
            lastDate = lastDate.addMonths(1);
        model->modifyValue(0,columns-1,lastDate.toString(format));
    }
    else
        //sono un chart senza date
        //mostro nella vista
        //model->modifyValue(0,columns-1,view->inputHeaderTableDialog("Title of new column:"));
        insertTableHeader(model->getMatrix()->getColumns(),"c","Title of new column:");
    updateTable();
    view->setChart(chart->createChart()); //chiamata polimorfa

}

void MyController::deleteRow(){
    model->deleteRow();/*
    if(model->getMatrix()->getRows() == 1){
        QMessageBox msgBox;
        msgBox.setText("non puoi cancellare");
        return;
    }*/
    //mostro nella vista
    updateTable();
    view->setChart(chart->createChart()); //chiamata polimorfa
}

void MyController::deleteColumn(){
    model->deleteColumn();
    //mostro nella vista
    updateTable();
    view->setChart(chart->createChart()); //chiamata polimorfa
}


void MyController::updateTable(){
    int rows = model->getMatrix()->getRows();
    int columns = model->getMatrix()->getColumns();
    QTableWidget *table = new QTableWidget(rows-1,columns-1);
    for(int i=1; i<rows; i++)
        for(int j=1; j<columns; j++)
            table->setItem(i-1,j-1,new QTableWidgetItem(model->getValue(i,j)));
    //valori header table
    for(int i=0; i < rows-1; ++i)
        table->setVerticalHeaderItem(i,new QTableWidgetItem(model->getValue(i+1,0)));

    for(int i=0; i < columns-1; ++i)
        table->setHorizontalHeaderItem(i,new QTableWidgetItem(model->getValue(0,i+1)));

    view->setTable(table);
}

void MyController::newTableHeaders(int rows, int columns) {
    for(int i = 1; i < rows+1; i++)
        insertTableHeader(i,"r","Title of row " + QString::number(i) + ":");
    for(int j = 1; j < columns+1; j++)
        insertTableHeader(j,"c","Title of column " + QString::number(j) + ":");
}

void MyController::insertTableHeader(int k, const QString& id, const QString& label) {
    bool checkValue = true;
    while(checkValue) {
        QString value = view->inputHeaderTableDialog(label);
        checkValue = checkHeader(id,value);
        if(id == "r") {
            if(!checkValue) {
                model->addRow();
                model->modifyValue(k,0,value);
            }
            else {
                QMessageBox b;
                b.setText("Row title already used!");
                b.exec();
            }
        }
        else {
            if(!checkValue) {
                model->addColumn();
                model->modifyValue(0,k,value);
            }
            else {
                QMessageBox b;
                b.setText("Column title already used!");
                b.exec();
            }
        }
    }
}

bool MyController::checkHeader(const QString& id, const QString& value) {
    if(id == "r") {
        for(int i = 1; i < model->getMatrix()->getRows(); i++)
            if(model->getValue(i,0) == value)
                return true;
    }
    else {
        for(int j = 1; j < model->getMatrix()->getColumns(); j++)
            if(model->getValue(0,j) == value)
                return true;
    }
    return false;
}
