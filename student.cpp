#include "student.h"
#include <QString>
#include <iostream>
#include <QDebug>
using namespace  std;
Student::Student(QString t_studentNum, QString t_name, QString t_gender, QString t_date, QString t_birthPlace, QString t_major)
{
    studentNum = t_studentNum;
    name = t_name;
    gender = t_gender;
    date = t_date;
    birthPlace = t_birthPlace;
    major = t_major;
}


void Student::print(){
    qDebug() << studentNum << " " << name << " " << gender << " " << date << " " << birthPlace << " " << major << endl;
}

