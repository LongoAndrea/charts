#include "matrix.h"
Matrix::Matrix(int r, int c, const QString& value): rows(r), columns(c) {
  QVector<QVector<QString>> m;
  for(int i=0; i<r; i++) {
    QVector<QString> s(c, value);
    m.append(s);
  }
  matrix = m;
}

void Matrix::addRow(const QString& value) {
  matrix.append(QVector<QString>(columns, value));
  rows += 1;
}

void Matrix::addColumn(const QString& value) {
  for(int i=0; i<rows; i++)
    matrix[i].append(value);
  columns += 1;
}

void Matrix::deleteRow() {
  matrix.removeLast();
  rows -= 1;
}

void Matrix::deleteColumn() {
  for(int i=0; i<rows; i++)
    matrix[i].removeLast();
  columns -= 1;
}
