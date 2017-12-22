#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "studentmanage.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void add_student_show(Student *s);
    void delete_student_show(QString sn);
    void modify_student_show(Student *s);
    void all_students_show();
    ~MainWindow();

public slots: 
    void receiveStuInfoAndAdd(QString data);
    void receiveSNAndDelete(QString sn);
    void receiveSNAndModify(QString sn);
    void receiveStuInfoAndModify(QString data);
    void receiveSNAndSearch(QString);
    void receiveInFile(QString filename);
    void receiveOutFile(QString filename);
    void on_pushButtonAdd_clicked();
    void on_pushButtonDelete_clicked();
    void on_pushButtonModify_clicked();
    void on_pushButtonSearch_clicked();
    void on_pushButtonInFile_clicked();
    void on_pushButtonOutFile_clicked();
    void on_pushButtonClear_clicked();

private:
    Ui::MainWindow *ui;
    StudentManage sm;
};

#endif // MAINWINDOW_H
