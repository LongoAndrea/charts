#ifndef MATRIX_H
#define MATRIX_H

#include <QVector>
#include <QString>

class Matrix {
 private:
  int rows;
  int columns;
  QVector<QVector<QString>> matrix;
 public:
  Matrix(int r = 0, int c = 0, const QString& value = "0");

  int getRows() const { return rows; }
  int getColumns() const { return columns; }

  void insertValue(int x, int y, const QString& value) { matrix[x][y] = value; }
  const QString& getValue(int x, int y) const { return matrix[x][y]; }

  void addRow(const QString& value = "0");
  void addColumn(const QString& value = "0");
  void deleteRow();
  void deleteColumn();
};
#endif
