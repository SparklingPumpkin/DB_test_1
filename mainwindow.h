#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QString>
#include <QDebug>
#include <QMainWindow>
#include <database.h>
#include "admwindow.h"
#include "memberwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Database myDatabase;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


signals:
    void try_login();
    void sendToB(QString m);

//public slots:
//    void send_message();

private slots:
    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    //通信
    admwindow admwindow_d;
    memberwindow memberwindow_d;

};
#endif // MAINWINDOW_H
