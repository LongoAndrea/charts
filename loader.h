#ifndef LOADER_H
#define LOADER_H

#include <QString>
#include"matrix.h"


class Loader
{
public:
    Loader() = default;
    virtual ~Loader() = default;
    virtual Matrix& Open(QString&, QString&,QString&,bool&) =0 ;
    virtual void Save(const Matrix&, QString&, QString&,QString&) =0 ;

};

#endif // LOADER_H
