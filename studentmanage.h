#ifndef STUDENTMANAGE_H
#define STUDENTMANAGE_H

#include <QMap>
#include <QString>
#include "student.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class StudentManage
{
private:
    QMap<QString, Student *> sm;
public:
    friend class MainWindow;
    StudentManage();
    bool addStudent(Student *);
    bool deleteStudent(QString studentnum);
    bool modifyStudent(Student *newst);
    Student *findStudent(QString studentnum);
    bool readFromFile(QString fileName);
    bool outputToFile(QString fileName);

};

#endif // STUDENTMANAGE_H
