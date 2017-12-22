#include "findstudentinformation.h"
#include "ui_findstudentinformation.h"

FindStudentInformation::FindStudentInformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindStudentInformation)
{
    ui->setupUi(this);
    setWindowTitle("学生学号输入");
}

FindStudentInformation::~FindStudentInformation()
{
    delete ui;
}

void FindStudentInformation::on_buttonBox_accepted(){
    QString sn = ui->lineEditSN->text();
    emit sendData(sn);
}
