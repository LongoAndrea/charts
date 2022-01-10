#ifndef LOADER_H
#define LOADER_H

#include <QString>
#include"matrix.h"


class Loader
{
public:

    virtual ~Loader();
    virtual Matrix& Open(const QString& file) =0 ;
    virtual void Save(const Matrix& m,const QString& file) =0 ;

};

#endif // LOADER_H
