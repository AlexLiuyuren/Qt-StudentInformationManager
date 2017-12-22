#include "studentmanage.h"

using namespace std;

StudentManage::StudentManage()
{

}

bool StudentManage::addStudent(Student * s){
    if (sm.find(s->studentNum) != sm.end()){
        //cout << "student already exists" << endl;
        return false;
    }else{
        qDebug() << s->studentNum << endl;
        sm.insert(s->studentNum, s);
        return true;
    }
}

bool StudentManage::deleteStudent(QString studentNum){
    if (sm.find(studentNum) == sm.end()){
        cout << "student not exists" << endl;
        return false;
    }else{
        sm.remove(studentNum);
        return true;
    }
}

bool StudentManage::modifyStudent(Student *newst){
    if (sm.find(newst->studentNum) == sm.end()){
        cout << "student not exists" << endl;
        return false;
    }else{
        sm.remove(newst->studentNum);
        sm.insert(newst->studentNum, newst);
        return true;
    }
}

Student *StudentManage::findStudent(QString studentNum){
    if (sm.find(studentNum) != sm.end()){
        return sm[studentNum];
    }else{
        //cout << "student not found" << endl;
        return NULL;
}
}

bool StudentManage::readFromFile(QString fileName){
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))  return false;
    QTextStream in(&file);
    while (!in.atEnd()) {
      QString line = in.readLine();
      QStringList ll = line.split(" ");
      Student *s = new Student(ll[0], ll[1], ll[2], ll[3], ll[4], ll[5]);
      if (sm.find(s->studentNum) != sm.end()){
          cout << "student exists already!" << endl;
      }else{
        sm.insert(s->studentNum, s);
      }
    }
    file.close();
    return true;
}

//QString studentNum;
//QString name;
//QString gender;
//QString date;
//QString birthPlace;
//QString major;
bool StudentManage::outputToFile(QString fileName){
    QFile data(fileName);
    if (!data.open(QFile::WriteOnly | QFile::Truncate)) return false;
    QTextStream out(&data);
    QMap<QString, Student*>::const_iterator i = sm.constBegin();
    while (i != sm.constEnd()) {
        Student *tmp = i.value();
        out << tmp->studentNum << " " << tmp->name << " " << tmp->gender << " " << tmp->date << " " << tmp->birthPlace << " " << tmp->major << endl;
        ++i;
     }
    return true;
}
