#include "memberwindow.h"
#include "ui_memberwindow.h"

memberwindow::memberwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::memberwindow)
{
    ui->setupUi(this);

    // 连接数据库
    this -> myDatabase.getConnection();

    // 为表格模式指针指定内存
    this -> dataTableModel = new QStandardItemModel();

    // 设置表格
    // this -> setTableInfo();

}

memberwindow::~memberwindow()
{
    delete ui;
}




void memberwindow::on_pB_info_clicked()
{
    this->~memberwindow();
    memberwindow * w = new memberwindow();
    w -> show();


}
