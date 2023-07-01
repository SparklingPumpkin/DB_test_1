#include "c_memberinfo.h"
#include "ui_c_memberinfo.h"
#include "memberwindow.h"

c_memberinfo::c_memberinfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::c_memberinfo)
{
    ui->setupUi(this);


    // 连接数据库
    this -> myDatabase.getConnection();

    // 为表格模式指针指定内存
    this -> dataTableModel = new QStandardItemModel();

    // 设置表格
    // this -> setTableInfo();

}

c_memberinfo::~c_memberinfo()
{
    delete ui;
}

// 跳转
void c_memberinfo::on_pB_back_clicked()
{
    this->~c_memberinfo();
    memberwindow * w = new memberwindow();
    w -> show();
}

