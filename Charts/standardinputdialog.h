#ifndef STANDARDINPUTDIALOG_H
#define STANDARDINPUTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QDialogButtonBox>

class StandardInputDialog : public QDialog
{
    Q_OBJECT
protected:

    QLineEdit *titleLineEdit;
    QSpinBox *rowsSpinBox;
    QSpinBox *columnsSpinbox;
    QDialogButtonBox *buttonBox;
public:
    StandardInputDialog(QWidget *parent =0);
    QString getTitle() const {return titleLineEdit->text();}
    int getRows() const {return rowsSpinBox->value();}
    int getColumns() const {return columnsSpinbox->value();}
    void setDialogLayout();
protected slots:
    void onButtonBoxAccepted();
    void onButtonBoxRejected();
};

#endif // STANDARDINPUTDIALOG_H
