#include "myview.h"
#include "mycontroller.h"
#include "standardinputdialog.h"

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
    table = new QTableWidget(1,1,this);
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
/*
    connect(openFileButton,SIGNAL(clicked()),controller,SLOT(openFile()));
    connect(saveFileButton,SIGNAL(clicked()),controller,SLOT(saveFile()));
    connect(addRowButton,SIGNAL(clicked()),controller,SLOT(addRow()));
    connect(addColumnButton,SIGNAL(clicked()),controller,SLOT(addColumn()));
    connect(deleteRowButton,SIGNAL(clicked()),controller,SLOT(deleteRow()));
    connect(deleteColumnButton,SIGNAL(clicked()),controller,SLOT(deleteColumn()));
    connect(newAreaChartButton,SIGNAL(clicked()),controller,SLOT());
    connect(newBarChartButton,SIGNAL(clicked()),controller,SLOT());
    connect(newLineChartButton,SIGNAL(clicked()),controller,SLOT());
    connect(newLineBarChartButton,SIGNAL(clicked()),controller,SLOT());
    connect(newPieChartButton,SIGNAL(clicked()),controller,SLOT());
    connect(newRadarChartButton,SIGNAL(clicked()),controller,SLOT());*/
}

void MyView::showStandardInputDialog(QString& title, int& rows, int& columns) {
    StandardInputDialog *dialog = new StandardInputDialog();
    dialog->setWindowTitle("Insert new Chart data");
    int res = dialog->exec();
    if(res == QDialog::Rejected) return;
    title = dialog->getTitle();
    rows = dialog->getRows();
    columns = dialog->getColumns();
}

void MyView::setChart(QChart* c) {
    chartView->setChart(c);
}

void MyView::setTable(QTableWidget* t) {
    delete table;
    table = t;
    table->setParent(this);
    table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    //centralLayout->addWidget(table);
    show();
}
