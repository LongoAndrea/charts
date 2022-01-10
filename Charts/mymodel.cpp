#include "mymodel.h"

QString MyModel::defaultValue = "0";

void MyModel::modifyValue(int r, int c, const QString& value) {
    m->insertValue(r, c, value);
}
const QString& MyModel::getValue(int r, int c) const {
    return m->getValue(r,c);
}
void MyModel::addRow() {
    m->addRow(defaultValue);
}
void MyModel::addColumn() {
    m->addColumn(defaultValue);
}
void MyModel::deleteRow() {
    m->deleteRow();
}
void MyModel::deleteColumn() {
    m->deleteColumn();
}
