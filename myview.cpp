#include "myview.h"
#include "mycontroller.h"
#include "standardinputdialog.h"
#include "dateinputdialog.h"
#include <QTableWidget>
#include <QInputDialog>
#include <QMenuBar>


MyView::MyView(QWidget *parent) : QWidget(parent) {
    QVBoxLayout* vlayout = new QVBoxLayout();

    QHBoxLayout* buttonLayout = new QHBoxLayout();

    QMenuBar* menuBar = new QMenuBar(this);
    file = new QMenu("File", menuBar);
    menuBar->addMenu(file);
    file->addAction(new QAction("Open Xml", file));
    file->addAction(new QAction("Save Xml", file));


    addRowButton = new QPushButton("", this);
    addRowButton->setFixedSize(QSize(40,40));
    addRowButton->setIconSize(QSize(40,40));
    addRowButton->setIcon(QIcon("../icons/addrow.jpeg"));
    addColumnButton = new QPushButton("", this);
    addColumnButton->setFixedSize(QSize(40,40));
    addColumnButton->setIconSize(QSize(40,40));
    addColumnButton->setIcon(QIcon("../icons/addcolumn.jpeg"));
    deleteRowButton = new QPushButton("", this);
    deleteRowButton->setFixedSize(QSize(40,40));
    deleteRowButton->setIconSize(QSize(40,40));
    deleteRowButton->setIcon(QIcon("../icons/deleterow.jpeg"));
    deleteColumnButton = new QPushButton("", this);
    deleteColumnButton->setFixedSize(QSize(40,40));
    deleteColumnButton->setIconSize(QSize(40,40));
    deleteColumnButton->setIcon(QIcon("../icons/deletecolumn.jpeg"));

    //charts
    QSize* s = new QSize(60,60);
    newAreaChartButton = new QPushButton("", this);
    newAreaChartButton->setFixedSize(*s);
    newAreaChartButton->setIconSize(*s);
    newAreaChartButton->setIcon(QIcon("../icons/areachart.png"));

    newBarChartButton = new QPushButton("", this);
    newBarChartButton->setFixedSize(*s);
    newBarChartButton->setIconSize(*s);
    newBarChartButton->setIcon(QIcon("../icons/barchart.png"));
    newLineChartButton = new QPushButton("", this);
    newLineChartButton->setFixedSize(*s);
    newLineChartButton->setIconSize(*s);
    newLineChartButton->setIcon(QIcon("../icons/linechart.png"));
    newLineBarChartButton = new QPushButton("", this);
    newLineBarChartButton->setFixedSize(*s);
    newLineBarChartButton->setIconSize(*s);
    newLineBarChartButton->setIcon(QIcon("../icons/linebarchart.jpeg"));
    newPieChartButton = new QPushButton("", this);
    newPieChartButton->setFixedSize(*s);
    newPieChartButton->setIconSize(*s);
    newPieChartButton->setIcon(QIcon("../icons/piechart.png"));
    newRadarChartButton = new QPushButton("", this);
    newRadarChartButton->setFixedSize(*s);
    newRadarChartButton->setIconSize(*s);
    newRadarChartButton->setIcon(QIcon("../icons/radarchart.png"));

    buttonLayout->addWidget(newAreaChartButton);
    buttonLayout->addWidget(newBarChartButton);
    buttonLayout->addWidget(newLineChartButton);
    buttonLayout->addWidget(newLineBarChartButton);
    buttonLayout->addWidget(newPieChartButton);
    buttonLayout->addWidget(newRadarChartButton);
    buttonLayout->addWidget(addRowButton);
    buttonLayout->addWidget(addColumnButton);
    buttonLayout->addWidget(deleteRowButton);
    buttonLayout->addWidget(deleteColumnButton);
    buttonLayout->setSpacing(5);
    buttonLayout->setContentsMargins(20, 0, 20, 0);




    vlayout->addWidget(menuBar);
    vlayout->addLayout(buttonLayout);


    centralLayout = new QHBoxLayout();
    table = new QTableWidget(this);
    chartView = new QChartView(this);
    centralLayout->addWidget(table);
    centralLayout->addWidget(chartView);



    hideModifyButtons();
    vlayout->addLayout(centralLayout);    
    vlayout->setSpacing(5);
    setLayout(vlayout);
    setWindowIcon(QIcon("../icons/barchart.png"));
    resize(QSize(1024,720));
}

void MyView::setController(MyController *c) {
    controller = c;

    connect(newBarChartButton,SIGNAL(clicked()),controller,SLOT(newBarChart()));
    connect(file->actions()[0],SIGNAL(triggered()),controller,SLOT(openFile()));
    connect(file->actions()[1],SIGNAL(triggered()),controller,SLOT(saveFile()));
    connect(addRowButton,SIGNAL(clicked()),controller,SLOT(addRow()));
    connect(addColumnButton,SIGNAL(clicked()),controller,SLOT(addColumn()));
    connect(deleteRowButton,SIGNAL(clicked()),controller,SLOT(deleteRow()));
    connect(deleteColumnButton,SIGNAL(clicked()),controller,SLOT(deleteColumn()));
    connect(newRadarChartButton,SIGNAL(clicked()),controller,SLOT(newRadarChart()));
    connect(newLineChartButton,SIGNAL(clicked()),controller,SLOT(newLineChart()));
    connect(newAreaChartButton,SIGNAL(clicked()),controller,SLOT(newAreaChart()));
    connect(newLineBarChartButton,SIGNAL(clicked()),controller,SLOT(newLineBarChart()));

    connect(newPieChartButton,SIGNAL(clicked()),controller,SLOT(newPieChart()));
}

bool MyView::showStandardInputDialog(QString& title, int& rows, int& columns) {
    StandardInputDialog *dialog = new StandardInputDialog();
    dialog->setWindowTitle("Insert new Chart data");
    dialog->setDialogLayout();
    int res = dialog->exec();
    if(res == QDialog::Rejected) return false;
    title = dialog->getTitle();
    rows = dialog->getRows();
    columns = dialog->getColumns();
    return true;
}

bool MyView::showDataInputDialog(QString& title, int& rows, int& columns, QString& format, QDateTime& dateTime) {
    DateInputDialog *dialog = new DateInputDialog();
    dialog->setWindowTitle("Insert new Chart data");
    dialog->setDialogLayout();
    int res = dialog->exec();
    if(res == QDialog::Rejected) return false;
    title = dialog->getTitle();
    rows = dialog->getRows();
    columns = dialog->getColumns();
    format = dialog->getFormat();
    dateTime = dialog->getDateTime();
    return true;
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


QString MyView::inputHeaderTableDialog(const QString& label){
    return QInputDialog::getText(this,"Input Header Table",label, QLineEdit::Normal);
}


void MyView::hideModifyButtons(){
    addRowButton->setEnabled(false);
    addColumnButton->setEnabled(false);
    deleteRowButton->setEnabled(false);
    deleteColumnButton->setEnabled(false);
    file->actions()[1]->setEnabled(false);
}

void MyView::showModifyButtons(){
    addRowButton->setEnabled(true);
    addColumnButton->setEnabled(true);
    deleteRowButton->setEnabled(true);
    deleteColumnButton->setEnabled(true);
    file->actions()[1]->setEnabled(true);
}
