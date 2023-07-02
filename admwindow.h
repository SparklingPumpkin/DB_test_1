#ifndef ADMWINDOW_H
#define ADMWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QDebug>
#include <database.h>
#include <QStandardItemModel>
//#include "mainwindow.h"


namespace Ui {
class admwindow;
}

class admwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit admwindow(QWidget *parent = nullptr);
    ~admwindow();

    // 连接数据库的对象
    Database myDatabase;

    // 设置表格格式
    void setTableInfo();

    // 获取表格信息
    void getDatabaseInfo();

    // 设置表格组件模式
    QStandardItemModel * dataTableModel;

//通信
public slots:

    void get_message(QString m);

    //定义按钮功能函数
private slots:
    void on_pB_memberm_clicked();
    void on_pB_merchandisem_clicked();
    void on_pB_orderm_clicked();
    void on_pB_logoff_clicked();



private:
    Ui::admwindow *ui;
    //MainWindow mainwindow_d;//用来传递信息
};

#endif // ADMWINDOW_H
