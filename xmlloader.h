#ifndef XMLLOADER_H
#define XMLLOADER_H

#include"loader.h"
#include<QString>


class XmlLoader: public Loader
{
public:
    XmlLoader();
    Matrix& Open(QString&,QString&,QString&,bool&);
    void Save(const Matrix&, QString&,QString&,QString&);

};

#endif // XMLLOADER_H
