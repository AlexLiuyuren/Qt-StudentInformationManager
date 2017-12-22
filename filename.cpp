#include "filename.h"
#include "ui_filename.h"

FileName::FileName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileName)
{
    ui->setupUi(this);
    setWindowTitle("文件名输入");
}

FileName::~FileName()
{
    delete ui;
}

void FileName::on_buttonBox_accepted(){
    QString filename = ui->lineEdit->text();
    emit sendData(filename);
}

