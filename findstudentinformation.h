#ifndef FINDSTUDENTINFORMATION_H
#define FINDSTUDENTINFORMATION_H

#include <QDialog>
#include <QString>

namespace Ui {
class FindStudentInformation;
}

class FindStudentInformation : public QDialog
{
    Q_OBJECT

public:
    explicit FindStudentInformation(QWidget *parent = 0);
    ~FindStudentInformation();

signals:
    void sendData(QString studentNum);

public slots:
    void on_buttonBox_accepted();

private:
    Ui::FindStudentInformation *ui;
};

#endif // FINDSTUDENTINFORMATION_H
