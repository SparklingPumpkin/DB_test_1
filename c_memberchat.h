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

    void on_pB_chat_clicked();

private:
    Ui::c_memberchat *ui;
};

#endif // C_MEMBERCHAT_H
