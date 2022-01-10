#include "myview.h"

MyView::MyView(QWidget *parent) : QWidget(parent) {
    QVBoxLayout* vlayout = new QVBoxLayout();

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    openFileButton = new QPushButton("Open File", this); //cambia tutto
    saveFileButton = new QPushButton("Save File", buttonWidget);
    addRowButton = new QPushButton("Add Row", buttonWidget);
    addColumnButton = new QPushButton("Add Column", buttonWidget);
    deleteRowButton = new QPushButton("Delete Row", buttonWidget);
    deleteColumnButton = new QPushButton("Delete Column", buttonWidget);
    newAreaChartButton = new QPushButton("New Area Chart", buttonWidget);
    newBarChartButton = new QPushButton("New Bar Chart", buttonWidget);
    newLineChartButton = new QPushButton("New Line Chart", buttonWidget);
    newLineBarChartButton = new QPushButton("New LineBar Chart", buttonWidget);
    newPieChartButton = new QPushButton("New Pie Chart", buttonWidget);
    newRadarChartButton = new QPushButton("New Radar Chart", buttonWidget);
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

    vlayout->addLayout(buttonLayout);

    QHBoxLayout* centralLayout = new QHBoxLayout();
    table = new QTableWidget(this);
    chartView = new QChartView(this);
}
