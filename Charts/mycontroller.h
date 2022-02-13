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

  MyAbstractChart* create(QString&,QString&);
  void updateTable();
  void newTableHeaders(int rows, int columns);
  void insertTableHeader(int k, const QString& id, const QString& label);
  bool checkHeader(const QString& id, const QString& value);

public:
  explicit MyController(QObject* parent = nullptr) : QObject(parent), chart(nullptr) {}
  void setModel(MyModel *m) {model = m;}
  void setView(MyView *v) {view = v;}
  void modifyMatrix(int x, int y, const QString& value);

public slots:

  void newBarChart();
  void onCellChanged(QTableWidgetItem* item);
  void openFile();
  void saveFile();
  void addRow();
  void addColumn();
  void deleteRow();
  void deleteColumn();
  void newRadarChart();
  void newLineChart();
  void newAreaChart();
  void newLineBarChart();
  void newPieChart();
};
#endif
