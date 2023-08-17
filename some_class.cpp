#include "some_class.h"
#include <some_class.h>
#include <QDebug>
#include <QFile>
#include <sstream>
#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <QtGlobal>
#include <QCoreApplication>
#include <QIODevice>
#include <QTextStream>
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <charconv>
#include <cmath>
#include <thread>
#include <mydatamodel.h>

using namespace std;

double arr[] = {};
double t =0;

some_class::some_class(QObject *parent) : QObject(parent)
{

}
some_class::~some_class(){

}


int some_class::callMe()
{
         QFile file("test.txt");
         if(!file.open(QIODevice::ReadWrite))
         {
             qDebug() << "Could not open file";
             qDebug() << file.errorString();
             return 0;
         }
         {
             t= t+1;
             if(t==10000){
                 t=0;
             }
             int length = to_string(t).length();
             char* nchar = new char[length];

             double y = (1 + sin(t/10.0)) / 2.0; //produces sine wave
             sprintf(nchar,"%lf\n",y);
             file.write(QByteArray(nchar));


         }
         file.flush();
         //qDebug() << "Reading file";
         file.seek(0);
         //qDebug() << file.readAll();
         myint1 = atoi(file.readAll());
         //myint1 = file.readAll();
         //myint1 = myint1*2;
         qDebug() << myint1;


         return myint1;
         file.close();
}
void some_class::readtext(void)
{
    ifstream textvalues;
    string line, temp;
    stringstream ss;
    float found;
    unsigned int intIndex=0;
    textvalues.open ("test.txt", ios::in);

    if (textvalues.is_open())
    {
        cout << "Success in open IED_Data.txt file" << endl;
         while ( (getline (textvalues,line)) && (intIndex < 50) )
        {
          if(textvalues.bad())
          {
              cout << "error in reading line" << endl;
          }
          else
          {
              /* Storing the whole string into string stream */
              ss << line;
              /* Running loop till the end of the stream */
              while (!ss.eof())
              {
                  /* extracting word by word from stream */
                  ss >> temp;
                  /* Checking the given word is integer or not */
                  if (stringstream(temp) >> found)
                  {
                      // cout << found << " ";
                      m_floatarray[intIndex]=found;

                      arr[intIndex]=m_floatarray[intIndex];

                      //cout << "m_floatarray[" <<intIndex <<"]:"<<m_floatarray[intIndex]<<"\t"<<arr[intIndex] <<endl;

                  }
                  /* To save from space at the end of string */
                  temp = "";
              }
              ss.clear();
          }
          intIndex++;
        }
        if(textvalues.eof())
        {
            cout << "reached end of file" << endl;
        }
        else
        {
            cout << "Not reached end of file" << endl;
        }
        textvalues.close();
    }
    else
    {
        // qDebug() << "Not opened";
        cout << "Unable to open IED_Data.txt file" << endl;
    }
}



