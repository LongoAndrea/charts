#include "standardinputdialog.h"
#include <QVBoxLayout>
#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QLabel>

StandardInputDialog::StandardInputDialog(QWidget *parent) : QDialog(parent){
    titleLineEdit = new QLineEdit("", this);
    rowsSpinBox = new QSpinBox(this);
    columnsSpinbox = new QSpinBox(this);
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,this);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(onButtonBoxAccepted()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(onButtonBoxRejected()));

    titleLineEdit->setMaxLength(30);
    rowsSpinBox->setMinimum(1);
    columnsSpinbox->setMinimum(1);
}

void StandardInputDialog::setDialogLayout() {
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(new QLabel("Title:",this));
    layout->addWidget(titleLineEdit);
    layout->addWidget(new QLabel("Rows:",this));
    layout->addWidget(rowsSpinBox);
    layout->addWidget(new QLabel("Columns:",this));
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
