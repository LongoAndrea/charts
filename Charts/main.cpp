#include "myview.h".h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyView *w = new MyView();
    w->show();

    return a.exec();
}
