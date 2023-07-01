#ifndef C2_ADMEMBER_H
#define C2_ADMEMBER_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QDebug>
#include <database.h>
#include <QStandardItemModel>

namespace Ui {
class c2_admember;
}

class c2_admember : public QMainWindow
{
    Q_OBJECT

public:
    explicit c2_admember(QWidget *parent = nullptr);
    ~c2_admember();

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
    void on_pB_create_clicked();
    void on_pB_update_clicked();


    void on_pB_delete_clicked();

    void on_pB_shuaxin_clicked();

    void on_pB_select_clicked();

private:
    Ui::c2_admember *ui;
};

#endif // C2_ADMEMBER_H
