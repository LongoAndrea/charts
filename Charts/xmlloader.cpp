#include "xmlloader.h"
#include "matrix.h"
#include<QString>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
//#include <QXmlSchemaValidator>
//#include <QXmlSchema>
#include <QUrl>
#include <QDebug>
#include <QFile>

#include <QIODevice>


XmlLoader::XmlLoader(){}

/*
Matrix& XmlLoader::Open(QString& path, QString& typechart,  QString& dateformat, bool error=false){

    Matrix *m = new Matrix();
    int col=0, row=0;
    QFile filexml(path);// path passato dalla gui
    if(filexml.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug()<<"file xml aperto in lettura \n";

    QXmlStreamReader reader(&filexml);

    if (reader.readNextStartElement()) {
        if (reader.name() == "data"){
            if(reader.readNextStartElement())
            {
                if (reader.name() == "type"){
                    typechart = reader.readElementText();
                    if(reader.readNextStartElement()){
                        if(reader.name() == "dateformat"){
                            dateformat = reader.readElementText();

                            while(reader.readNextStartElement()){
                                if(reader.name() == "column"){
                                    m->addColumn();

                                    while(reader.readNextStartElement() && reader.name()=="row"){
                                        if(col == 0)//aggiungo row nella quantità della prima colonna
                                            m->addRow();
                                        QString s = reader.readElementText();
                                        qDebug(qPrintable(s));
                                        m->insertValue(row,col,s);
                                        row++;

                                    }
                                    col++;
                                    row = 0;
                                }
                                else
                                    reader.skipCurrentElement();
                            }
                        }
                    }
                }
            }
        }
        else
            reader.raiseError(QObject::tr("Incorrect file"));
    }
    filexml.close();
    return *m;
}*/

Matrix& XmlLoader::Open(QString& path, QString& typechart,  QString& dateformat, bool& error){

    Matrix *m = new Matrix();
    int col=0, row=0;
    QFile filexml(path);// path passato dalla gui
    if(filexml.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug()<<"file xml aperto in lettura \n";

    QXmlStreamReader reader(&filexml);

    if (reader.readNextStartElement()) {
        if (reader.name() == "data"){
            if(reader.readNextStartElement())
            {
                if (reader.name() == "type"){
                    typechart = reader.readElementText();
                    if(reader.readNextStartElement()){
                        if(reader.name() == "dateformat"){
                            dateformat = reader.readElementText();

                            while(reader.readNextStartElement()){
                                if(reader.name() == "column"){
                                    m->addColumn();

                                    while(reader.readNextStartElement() && reader.name()=="row"){
                                        if(col == 0)//aggiungo row nella quantità della prima colonna
                                            m->addRow();
                                        QString s = reader.readElementText();
                                        qDebug(qPrintable(s));
                                        m->insertValue(row,col,s);
                                        row++;

                                    }
                                    col++;
                                    row = 0;
                                }
                                else
                                    reader.skipCurrentElement();
                            }
                        }
                        else
                            error = true;
                    }
                }
                else
                    error=true;
            }
        }
        else
            error=true;//reader.raiseError(QObject::tr("Incorrect file"));
    }
    filexml.close();

    return *m;
}


//aggiunto un parametro string per il nome del file(passato dalla gui)
void XmlLoader::Save(const Matrix& m, QString& name, QString& typechart,QString& dateformat){
    QFile filexml(name);//path passato dalla gui
    if(filexml.open(QIODevice::WriteOnly | QFile::Text))
        qDebug()<<"file xml aperto in scrittura \n";
    QXmlStreamWriter writer(&filexml);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("data");
    writer.writeTextElement("type",typechart);
    writer.writeTextElement("dateformat",dateformat);


    for(int col=0; col<m.getColumns(); col++){
        writer.writeStartElement("column");
        for(int row=0; row<m.getRows();row++){
            writer.writeTextElement("row",m.getValue(row,col));
        }
        writer.writeEndElement();
    }
    writer.writeEndElement();
    writer.writeEndDocument();
}
