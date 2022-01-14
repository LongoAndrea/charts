#include "myview.h"
#include "mycontroller.h"
#include "mymodel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyModel m;
    MyView w;
    MyController c;
    c.setView(&w);
    w.setController(&c);
    c.setModel(&m);
    w.show();

    return a.exec();
}
