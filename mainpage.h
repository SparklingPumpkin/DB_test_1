#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QDebug>
#include <database.h>
#include <QStandardItemModel>


namespace Ui {
class mainpage;
}

class mainpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainpage(QWidget *parent = nullptr);
    ~mainpage();
    // 连接数据库的对象
    Database myDatabase;

    // 设置表格格式
    void setTableInfo();

    //获取表格信息
    void getDatabaseInfo();

    //设置表格组件模式
    QStandardItemModel * dataTableModel;


private:
    Ui::mainpage *ui;
};

#endif // MAINPAGE_H
