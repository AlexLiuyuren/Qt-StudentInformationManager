#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogstudentinformation.h"
#include "findstudentinformation.h"
#include "filename.h"
#include <QDebug>
#include <QLabel>
#include <QStackedLayout>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("学生信息管理系统");
    QHeaderView *headerGoods = ui->tableWidget->horizontalHeader();
    //SortIndicator为水平标题栏文字旁边的三角指示器
    headerGoods->setSortIndicator(0, Qt::AscendingOrder);
    headerGoods->setSortIndicatorShown(true);
    headerGoods->setSectionsClickable(true);
    connect(headerGoods, SIGNAL(sectionClicked(int)), ui->tableWidget, SLOT (sortByColumn(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAdd_clicked(){
    DialogStudentInformation* dlg = new DialogStudentInformation(this);
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->setModal(true);//或者可以使用setModel(true)
    dlg->show();
    connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveStuInfoAndAdd(QString)));
}

void MainWindow::on_pushButtonDelete_clicked(){
    FindStudentInformation *dlg = new FindStudentInformation(this);
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->setModal(true);//或者可以使用setModel(true)
    dlg->show();
    connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveSNAndDelete(QString)));
}

void MainWindow::on_pushButtonModify_clicked(){
    FindStudentInformation *dlg = new FindStudentInformation(this);
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->setModal(true);//或者可以使用setModel(true)
    dlg->show();
    connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveSNAndModify(QString)));
}

void MainWindow::on_pushButtonInFile_clicked(){
    FileName *dlg = new FileName(this);
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->setModal(true);//或者可以使用setModel(true)
    dlg->show();
    connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveInFile(QString)));
}
void MainWindow::on_pushButtonOutFile_clicked(){
    FileName *dlg = new FileName(this);
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->setModal(true);//或者可以使用setModel(true)
    dlg->show();
    connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveOutFile(QString)));
}

void MainWindow::on_pushButtonSearch_clicked(){
    FindStudentInformation *dlg = new FindStudentInformation(this);
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->setModal(true);//或者可以使用setModel(true)
    dlg->show();
    connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveSNAndSearch(QString)));
}

void MainWindow::on_pushButtonClear_clicked(){
    sm.sm.clear();
    all_students_show();
}
void MainWindow::add_student_show(Student *s){
    qDebug() << "in show" << endl;
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    QTableWidgetItem *newItem = new QTableWidgetItem(s->studentNum);
    ui->tableWidget->setItem(row, 0, newItem);
    newItem = new QTableWidgetItem(s->name);
    ui->tableWidget->setItem(row, 1, newItem);
    newItem = new QTableWidgetItem(s->gender);
    ui->tableWidget->setItem(row, 2, newItem);
    newItem = new QTableWidgetItem(s->date);
    ui->tableWidget->setItem(row, 3, newItem);
    newItem = new QTableWidgetItem(s->birthPlace);
    ui->tableWidget->setItem(row, 4, newItem);
    newItem = new QTableWidgetItem(s->major);
    ui->tableWidget->setItem(row, 5, newItem);
    //ui->tableWidget->show();
    return;
}

void MainWindow::delete_student_show(QString sn){
    QList <QTableWidgetItem *> item = ui->tableWidget->findItems(sn, Qt::MatchExactly);
    for (int i = 0; i < item.count(); i++){
        if (item[i]->column() == 0){
            ui->tableWidget->removeRow(item[i]->row());
        }
    }
}

void MainWindow::modify_student_show(Student *s){
    QList <QTableWidgetItem *> item = ui->tableWidget->findItems(s->studentNum, Qt::MatchExactly);
    for (int i = 0; i < item.count(); i++){
        if (item[i]->column() == 0){
            int row = item[i]->row();
            QTableWidgetItem *newItem = new QTableWidgetItem(s->studentNum);
            ui->tableWidget->setItem(row, 0, newItem);
            newItem = new QTableWidgetItem(s->name);
            ui->tableWidget->setItem(row, 1, newItem);
            newItem = new QTableWidgetItem(s->gender);
            ui->tableWidget->setItem(row, 2, newItem);
            newItem = new QTableWidgetItem(s->date);
            ui->tableWidget->setItem(row, 3, newItem);
            newItem = new QTableWidgetItem(s->birthPlace);
            ui->tableWidget->setItem(row, 4, newItem);
            newItem = new QTableWidgetItem(s->major);
            ui->tableWidget->setItem(row, 5, newItem);
        }
    }
}

void MainWindow::all_students_show(){
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    qDebug() << "student number: " << sm.sm.count() << endl;
    QMap<QString, Student *>::iterator i = sm.sm.begin();
      while (i != sm.sm.end()) {
          Student *s = i.value();
          int row = ui->tableWidget->rowCount();
          ui->tableWidget->insertRow(row);
          QTableWidgetItem *newItem = new QTableWidgetItem(s->studentNum);
          ui->tableWidget->setItem(row, 0, newItem);
          newItem = new QTableWidgetItem(s->name);
          ui->tableWidget->setItem(row, 1, newItem);
          newItem = new QTableWidgetItem(s->gender);
          ui->tableWidget->setItem(row, 2, newItem);
          newItem = new QTableWidgetItem(s->date);
          ui->tableWidget->setItem(row, 3, newItem);
          newItem = new QTableWidgetItem(s->birthPlace);
          ui->tableWidget->setItem(row, 4, newItem);
          newItem = new QTableWidgetItem(s->major);
          ui->tableWidget->setItem(row, 5, newItem);
          ++i;
      }
}

void MainWindow::receiveStuInfoAndAdd(QString data){
    QStringList sl = data.split(" ");
    Student *new_s = new Student(sl[0], sl[1], sl[2], sl[3], sl[4], sl[5]);
    if (sm.addStudent(new_s)){
        add_student_show(new_s);
    }else{
        qDebug() << "dlg->exec(): 0" << endl;
    }
}

void MainWindow::receiveSNAndDelete(QString sn){
    if (sm.findStudent(sn) == NULL){
        qDebug() << "delete fails, no such student" << endl;
    }else{
        sm.deleteStudent(sn);
        delete_student_show(sn);
    }
}

void MainWindow::receiveSNAndModify(QString sn){
    if (sm.findStudent(sn) == NULL){
        qDebug() << "modification fails, no such student" << endl;
    }else{
        DialogStudentInformation* dlg = new DialogStudentInformation(this);
        dlg->setSN(sn);
        dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
        dlg->setModal(true);//或者可以使用setModel(true)
        dlg->show();
        connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveStuInfoAndModify(QString)));
    }
}

void MainWindow::receiveSNAndSearch(QString sn){
    Student *s = sm.findStudent(sn);
    if (s == NULL){
        qDebug() << "search fails, no such student" << endl;
    }else{
        DialogStudentInformation* dlg = new DialogStudentInformation(this);
        dlg->setSN(s->studentNum);
        dlg->setName(s->name);
        dlg->setGender(s->gender);
        dlg->setDate(s->date);
        dlg->setBirthPlace(s->birthPlace);
        dlg->setMajor(s->major);
        dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
        dlg->setModal(true);//或者可以使用setModel(true)
        dlg->show();
        //connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveStuInfoAndModify(QString)));
    }
}

void MainWindow::receiveStuInfoAndModify(QString data){
    QStringList sl = data.split(" ");
    Student *new_s = new Student(sl[0], sl[1], sl[2], sl[3], sl[4], sl[5]);
    if (sm.findStudent(sl[0]) == NULL){
        qDebug() << "modification fails, no such student" << endl;
    }else{
        sm.deleteStudent(sl[0]);
        sm.addStudent(new_s);
        modify_student_show(new_s);
    }
}

void MainWindow::receiveInFile(QString fn){
    sm.readFromFile(fn);
    all_students_show();
}

void MainWindow::receiveOutFile(QString fn){
    sm.outputToFile(fn);
}
