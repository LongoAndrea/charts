#include "myview.h"
#include "mycontroller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyView *w = new MyView();
    MyController *c =  new MyController();
    c->setView(w);
    w->setController(c);
    w->show();

    return a.exec();
}
