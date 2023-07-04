#ifndef C_MEMBERCHAT_H
#define C_MEMBERCHAT_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QDebug>
#include <database.h>
#include <QStandardItemModel>


namespace Ui {
class c_memberchat;
}

class c_memberchat : public QMainWindow
{
    Q_OBJECT

public:
    explicit c_memberchat(QWidget *parent = nullptr);
    ~c_memberchat();


private slots:
    void on_pB_back_clicked();

    void on_pB_chat_clicked();

private:
    Ui::c_memberchat *ui;
};

#endif // C_MEMBERCHAT_H
