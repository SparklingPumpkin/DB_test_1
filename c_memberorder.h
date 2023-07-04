#ifndef C_MEMBERORDER_H
#define C_MEMBERORDER_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QDebug>
#include <database.h>
#include <QStandardItemModel>


namespace Ui {
class c_memberorder;
}

class c_memberorder : public QMainWindow
{
    Q_OBJECT

public:
    explicit c_memberorder(QWidget *parent = nullptr);
    ~c_memberorder();

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
    void get_message_3(QString m);

private slots:
    void on_pB_back_clicked();

    void on_pB_getinfo_clicked();

private:
    Ui::c_memberorder *ui;
};

extern QString globalkey2;

#endif // C_MEMBERORDER_H
