#ifndef XMLLOADER_H
#define XMLLOADER_H

#include"loader.h"
#include<QString>


class XmlLoader: public Loader
{
public:
    XmlLoader();
    Matrix& Open(QString&,QString&);
    void Save(const Matrix&, QString&,QString&);

};

#endif // XMLLOADER_H
