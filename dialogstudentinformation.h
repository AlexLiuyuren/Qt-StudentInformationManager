#ifndef DIALOGSTUDENTINFORMATION_H
#define DIALOGSTUDENTINFORMATION_H

#include <QDialog>
#include "student.h"

namespace Ui {
class DialogStudentInformation;
}

class DialogStudentInformation : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStudentInformation(QWidget *parent = 0);
    void setSN(QString);
    void setName(QString);
    void setGender(QString);
    void setDate(QString);
    void setBirthPlace(QString);
    void setMajor(QString);
    ~DialogStudentInformation();

signals:
    void sendData(QString);
public slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogStudentInformation *ui;
};

#endif // DIALOGSTUDENTINFORMATION_H
