#ifndef C_MEMBERMARKET_H
#define C_MEMBERMARKET_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QDebug>
#include <database.h>
#include <QStandardItemModel>


namespace Ui {
class c_membermarket;
}

class c_membermarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit c_membermarket(QWidget *parent = nullptr);
    ~c_membermarket();

    // 连接数据库的对象
    Database myDatabase;

    // 设置表格格式
    void setTableInfo();

    // 获取表格信息
    void getDatabaseInfo();

    // 设置表格组件模式
    QStandardItemModel * dataTableModel;

private slots:
    void on_pB_back_clicked();

    void on_pB_create_4_clicked();

private:
    Ui::c_membermarket *ui;
};

#endif // C_MEMBERMARKET_H
