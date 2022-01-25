#ifndef MYVIEW_H
#define MYVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QtCharts> //boh non va se non importiamo tutto
#include <QFileDialog>

class MyController; //serve qui perchè altrimenti si crea un loop di dichiarazioni, nel main partiamo con MyView

class MyView : public QWidget
{
    Q_OBJECT
private:
    MyController *controller;

    QPushButton *openFileButton;
    QPushButton *saveFileButton;
    QPushButton *addRowButton;
    QPushButton *addColumnButton;
    QPushButton *deleteRowButton;
    QPushButton *deleteColumnButton;

    QPushButton *newAreaChartButton;
    QPushButton *newBarChartButton;
    QPushButton *newLineChartButton;
    QPushButton *newLineBarChartButton;
    QPushButton *newPieChartButton;
    QPushButton *newRadarChartButton;

    //QWidget *mainWidget;
    QHBoxLayout* centralLayout;
    QTableWidget *table;
    QChartView *chartView;

public:
    explicit MyView(QWidget *parent = nullptr);
    void setController(MyController *c);
    bool showStandardInputDialog(QString& title, int& rows, int& columns);
    bool showDataInputDialog(QString& title, int& rows, int& columns, QString& format, QDateTime& dateTime);
    void setChart(QChart* c);
    void setTable(QTableWidget* t);

    //QString inputHeaderTableDialog();
    void hideModifyButtons();
    void showModifyButtons();

    QString inputHeaderTableDialog(const QString& label);

};

#endif // MYVIEW_H
