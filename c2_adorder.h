#ifndef C2_ADORDER_H
#define C2_ADORDER_H


#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QDebug>
#include <database.h>
#include <QStandardItemModel>

namespace Ui {
class c2_adorder;
}

class c2_adorder : public QMainWindow
{
    Q_OBJECT

public:
    explicit c2_adorder(QWidget *parent = nullptr);
    ~c2_adorder();

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
    Ui::c2_adorder *ui;
};

#endif // C2_ADORDER_H
