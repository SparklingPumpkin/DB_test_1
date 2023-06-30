#ifndef C_MEMBERINFO_H
#define C_MEMBERINFO_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QDebug>
#include <database.h>
#include <QStandardItemModel>

namespace Ui {
class c_memberinfo;
}

class c_memberinfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit c_memberinfo(QWidget *parent = nullptr);
    ~c_memberinfo();

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

private:
    Ui::c_memberinfo *ui;
};

#endif // C_MEMBERINFO_H
