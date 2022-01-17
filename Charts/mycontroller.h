#ifndef MYCONTROLLER_H
#define MYCONTROLLER_H

#include "matrix.h"
#include "mymodel.h"
#include "myabstractchart.h"
#include "myview.h"
#include <QObject>
#include <QTableWidget>

class MyController : public QObject {
    Q_OBJECT
private:
  MyModel *model;
  MyAbstractChart *chart;
  MyView *view;

public:
  explicit MyController(QObject* parent = nullptr) : QObject(parent), chart(nullptr) {}
  //MyController(Matrix &m, QWidget &w);
  //void show();
  void setModel(MyModel *m) {model = m;}
  void setView(MyView *v) {view = v;}
  void modifyMatrix(int x, int y, const QString& value);
  //QTableWidget* getTableWidget() {return table;} //const ???

public slots:

  void newBarChart();
  void onCellChanged(QTableWidgetItem* item);
};
#endif
