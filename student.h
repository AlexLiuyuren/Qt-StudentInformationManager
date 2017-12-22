#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QDateEdit>

class StudentManage;
class MainWindow;
class Student
{
public:
    QString studentNum;
    QString name;
    QString gender;
    QString date;
    QString birthPlace;
    QString major;
public:
    friend class StudentManage;
    friend class MainWindow;
    Student(QString studentNum, QString name, QString gender, QString date, QString birthPlace, QString major);
    void print();
};

#endif // STUDENT_H
