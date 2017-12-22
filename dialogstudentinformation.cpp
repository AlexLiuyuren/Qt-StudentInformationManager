#include "dialogstudentinformation.h"
#include "ui_dialogstudentinformation.h"
#include <QString>
#include "student.h"
#include <QDebug>

DialogStudentInformation::DialogStudentInformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStudentInformation)
{
    ui->setupUi(this);
    setWindowTitle("学生信息");
}

DialogStudentInformation::~DialogStudentInformation()
{
    delete ui;
}

void DialogStudentInformation::on_buttonBox_accepted(){
    QString data = ui->lineEditSN->text() + " " + ui->lineEditName->text() + " " + ui->lineEditGender->text()
            + " " + ui->lineEditDate->text() + " " + ui->lineEditPlace->text() + " " + ui->lineEditMajor
            ->text();
    emit sendData(data);
}

void DialogStudentInformation::setSN(QString sn){
    ui->lineEditSN->setText(sn);
}

void DialogStudentInformation::setName(QString name){
    ui->lineEditName->setText(name);
}
void DialogStudentInformation::setGender(QString gender){
    ui->lineEditGender->setText(gender);
}
void DialogStudentInformation::setDate(QString date){
    ui->lineEditDate->setText(date);
}
void DialogStudentInformation::setBirthPlace(QString bp){
    ui->lineEditPlace->setText(bp);
}
void DialogStudentInformation::setMajor(QString major){
    ui->lineEditMajor->setText(major);
}
