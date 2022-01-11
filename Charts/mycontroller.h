#ifndef MYCONTROLLER_H
#define MYCONTROLLER_H

#include "matrix.h"
#include "mymodel.h"
#include "myabstractchart.h"
#include <QObject>
#include <QTableWidget>

class MyController : public QObject {
Q_OBJECT
private:
  MyModel *model;
  QTableWidget *table;
  QChartView *chartView;
  MyAbstractChart *chart;
  QWidget *mainWidget;
public:
  MyController(MyModel *m) : model(m), table(nullptr), chartView(nullptr), chart(nullptr), mainWidget(nullptr) {}
  //MyController(Matrix &m, QWidget &w);
  void show();
  //QTableWidget* getTableWidget() {return table;} //const ???
public slots:
  void modifyMatrix(int x, int y);
};
#endif
