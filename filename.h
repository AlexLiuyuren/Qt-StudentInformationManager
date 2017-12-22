#ifndef FILENAME_H
#define FILENAME_H

#include <QDialog>
#include <QString>
namespace Ui {
class FileName;
}

class FileName : public QDialog
{
    Q_OBJECT

public:
    explicit FileName(QWidget *parent = 0);
    ~FileName();

signals:
    void sendData(QString filename);

public slots:
    void on_buttonBox_accepted();

private:
    Ui::FileName *ui;
};

#endif // FILENAME_H
