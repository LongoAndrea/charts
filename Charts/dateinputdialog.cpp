#include "dateinputdialog.h"
#include <QVBoxLayout>
#include <QLabel>

DateInputDialog::DateInputDialog(QWidget* parent) : StandardInputDialog(parent)
{
    selectFormatComboBox = new QComboBox(this);
    selectFormatComboBox->addItem("Year by Year");
    selectFormatComboBox->addItem("Month by Month");
    startDateTimeEdit = new QDateTimeEdit(this);
    startDateTimeEdit->setDisplayFormat("dd.MM.yyyy");
}

void DateInputDialog::setDialogLayout() {
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Title:",this));
    layout->addWidget(titleLineEdit);
    layout->addWidget(new QLabel("Rows:",this));
    layout->addWidget(rowsSpinBox);
    layout->addWidget(new QLabel("Columns:",this));
    layout->addWidget(columnsSpinbox);
     layout->addWidget(new QLabel("Date Format:",this));
    layout->addWidget(selectFormatComboBox);
     layout->addWidget(new QLabel("Start Date:",this));
    layout->addWidget(startDateTimeEdit);
    layout->addWidget(buttonBox);

    setLayout(layout);
    resize(QSize(400,300));
}

QString DateInputDialog::getFormat() {
    int value = selectFormatComboBox->currentIndex();
    if(value == 0)  return "yyyy";
    if(value == 1)  return "MM.yyyy";
    return "";
}

QDateTime DateInputDialog::getDateTime() {
    return startDateTimeEdit->dateTime();
}

void DateInputDialog::onButtonBoxAccepted() {
    accept();
}
void DateInputDialog::onButtonBoxRejected() {
    reject();
}


