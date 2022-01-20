#include "myview.h"
#include "mycontroller.h"
#include "standardinputdialog.h"
#include "dateinputdialog.h"
#include <QTableWidget>
#include <QInputDialog>

MyView::MyView(QWidget *parent) : QWidget(parent) {
    QVBoxLayout* vlayout = new QVBoxLayout();

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    openFileButton = new QPushButton("Open File", this);
    saveFileButton = new QPushButton("Save File", this);
    addRowButton = new QPushButton("Add Row", this);
    addColumnButton = new QPushButton("Add Column", this);
    deleteRowButton = new QPushButton("Delete Row", this);
    deleteColumnButton = new QPushButton("Delete Column", this);
    newAreaChartButton = new QPushButton("New Area Chart", this);
    newBarChartButton = new QPushButton("New Bar Chart", this);
    newLineChartButton = new QPushButton("New Line Chart", this);
    newLineBarChartButton = new QPushButton("New LineBar Chart", this);
    newPieChartButton = new QPushButton("New Pie Chart", this);
    newRadarChartButton = new QPushButton("New Radar Chart", this);
    //addRowButton->setEnabled(false);
    buttonLayout->addWidget(openFileButton);
    buttonLayout->addWidget(saveFileButton);
    buttonLayout->addWidget(addRowButton);
    buttonLayout->addWidget(addColumnButton);
    buttonLayout->addWidget(deleteRowButton);
    buttonLayout->addWidget(deleteColumnButton);
    buttonLayout->addWidget(newAreaChartButton);
    buttonLayout->addWidget(newBarChartButton);
    buttonLayout->addWidget(newLineChartButton);
    buttonLayout->addWidget(newLineBarChartButton);
    buttonLayout->addWidget(newPieChartButton);
    buttonLayout->addWidget(newRadarChartButton);
    buttonLayout->setSpacing(5);
    buttonLayout->setContentsMargins(20, 0, 20, 0);

    vlayout->addLayout(buttonLayout);

    //mainWidget = new QWidget(this);
    centralLayout = new QHBoxLayout();
    table = new QTableWidget(this);
    chartView = new QChartView(this);
    centralLayout->addWidget(table);
    centralLayout->addWidget(chartView);
    //mainWidget->setLayout(centralLayout);

    vlayout->addLayout(centralLayout);
    //vlayout->addWidget(mainWidget);
    vlayout->setSpacing(0);
    setLayout(vlayout);
    resize(QSize(1024,720));
}

void MyView::setController(MyController *c) {
    controller = c;

    connect(newBarChartButton,SIGNAL(clicked()),controller,SLOT(newBarChart()));
    connect(openFileButton,SIGNAL(clicked()),controller,SLOT(openFile()));
    connect(saveFileButton,SIGNAL(clicked()),controller,SLOT(saveFile()));
    connect(addRowButton,SIGNAL(clicked()),controller,SLOT(addRow()));
    connect(addColumnButton,SIGNAL(clicked()),controller,SLOT(addColumn())); //risolvere problema nomi identici per le colonne -> porta a non visulaizzare tutto il chart
    connect(deleteRowButton,SIGNAL(clicked()),controller,SLOT(deleteRow()));
    connect(deleteColumnButton,SIGNAL(clicked()),controller,SLOT(deleteColumn()));
    connect(newRadarChartButton,SIGNAL(clicked()),controller,SLOT(newRadarChart()));
    connect(newLineChartButton,SIGNAL(clicked()),controller,SLOT(newLineChart()));
    connect(newAreaChartButton,SIGNAL(clicked()),controller,SLOT(newAreaChart()));
    connect(newLineBarChartButton,SIGNAL(clicked()),controller,SLOT(newLineBarChart()));
    /*
    connect(newPieChartButton,SIGNAL(clicked()),controller,SLOT()); */
}

void MyView::showStandardInputDialog(QString& title, int& rows, int& columns) {
    StandardInputDialog *dialog = new StandardInputDialog();
    dialog->setWindowTitle("Insert new Chart data");
    dialog->setDialogLayout();
    int res = dialog->exec();
    if(res == QDialog::Rejected) return;
    title = dialog->getTitle();
    rows = dialog->getRows();
    columns = dialog->getColumns();
}

void MyView::showDataInputDialog(QString& title, int& rows, int& columns, QString& format, QDateTime& dateTime) {
    DateInputDialog *dialog = new DateInputDialog();
    dialog->setWindowTitle("Insert new Chart data");
    dialog->setDialogLayout();
    int res = dialog->exec();
    if(res == QDialog::Rejected) return;
    title = dialog->getTitle();
    rows = dialog->getRows();
    columns = dialog->getColumns();
    format = dialog->getFormat();
    dateTime = dialog->getDateTime();
}

void MyView::setChart(QChart* c) {
    chartView->setChart(c);
}

void MyView::setTable(QTableWidget* t) {
    delete table;
    table = t;
    table->setParent(this);
    table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    centralLayout->addWidget(table);
    connect(table,SIGNAL(itemChanged(QTableWidgetItem*)),controller,SLOT(onCellChanged(QTableWidgetItem*)));
}


QString MyView::inputHeaderTableDialog(){
    return QInputDialog::getText(this,"Input Header Table","Nome colonna:", QLineEdit::Normal);
}
