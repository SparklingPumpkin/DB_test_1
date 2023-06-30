#ifndef MEMBERWINDOW_H
#define MEMBERWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QDebug>
#include <database.h>
#include <QStandardItemModel>

namespace Ui {
class memberwindow;
}

class memberwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit memberwindow(QWidget *parent = nullptr);
    ~memberwindow();

    // 连接数据库的对象
    Database myDatabase;

    // 设置表格格式
    void setTableInfo();

    // 获取表格信息
    void getDatabaseInfo();

    // 设置表格组件模式
    QStandardItemModel * dataTableModel;


//定义按钮功能函数
private slots:
    void on_pB_info_clicked();
    void on_pB_market_clicked();
    void on_pB_order_clicked();
    void on_pB_chat_clicked();
    void on_pB_logoff_clicked();



private:
    Ui::memberwindow *ui;
};



#endif // MEMBERWINDOW_H
