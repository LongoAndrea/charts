#include "standardinputdialog.h"
#include <QVBoxLayout>
#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QDialogButtonBox>

StandardInputDialog::StandardInputDialog(QWidget *parent) : QDialog(parent){
    titleLineEdit = new QLineEdit("Insert here the title of your chart", this);
    rowsSpinBox = new QSpinBox(this);
    columnsSpinbox = new QSpinBox(this);
    buttonBox = new QDialogButtonBox(this);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(onButtonBoxAccepted()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(onButtonBoxRejected()));

    titleLineEdit->setMaxLength(30);
    rowsSpinBox->setMinimum(1);
    columnsSpinbox->setMinimum(1);
    buttonBox->setVisible(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(titleLineEdit);
    layout->addWidget(rowsSpinBox);
    layout->addWidget(columnsSpinbox);
    layout->addWidget(buttonBox);

    setLayout(layout);
    resize(QSize(400,300));
}

void StandardInputDialog::onButtonBoxAccepted() {
    accept();
}
void StandardInputDialog::onButtonBoxRejected() {
    reject();
}
