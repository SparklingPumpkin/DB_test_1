#ifndef C2_ADMERCHANDISE_H
#define C2_ADMERCHANDISE_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QDebug>
#include <database.h>
#include <QStandardItemModel>

namespace Ui {
class c2_admerchandise;
}

class c2_admerchandise : public QMainWindow
{
    Q_OBJECT

public:
    explicit c2_admerchandise(QWidget *parent = nullptr);
    ~c2_admerchandise();

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
    Ui::c2_admerchandise *ui;
};

#endif // C2_ADMERCHANDISE_H
