#ifndef DATEINPUTDIALOG_H
#define DATEINPUTDIALOG_H

#include "standardinputdialog.h"
#include <QComboBox>
#include <QDateTimeEdit>
#include <QDateTime>

class DateInputDialog : public StandardInputDialog
{
    Q_OBJECT
private:
    QComboBox *selectFormatComboBox;
    QDateTimeEdit *startDateTimeEdit;
public:
    DateInputDialog(QWidget *parent=0);
    QString getFormat();
    QDateTime getDateTime();
    void setDialogLayout();
protected slots:
    void onButtonBoxAccepted();
    void onButtonBoxRejected();


};

#endif // DATEINPUTDIALOG_H
