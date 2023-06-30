#include "memberwindow.h"
#include "ui_memberwindow.h"
#include <QApplication>
#include "c_memberinfo.h"
#include "c_membermarket.h"
#include "c_memberorder.h"
#include "c_memberchat.h"
#include "mainwindow.h"

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


//跳转
void memberwindow::on_pB_info_clicked()
{
    this->~memberwindow();
    c_memberinfo * w = new c_memberinfo();
    w -> show();
}
void memberwindow::on_pB_market_clicked()
{
    this->~memberwindow();
    c_membermarket * w = new c_membermarket();
    w -> show();
}
void memberwindow::on_pB_order_clicked()
{
    this->~memberwindow();
    c_memberorder * w = new c_memberorder();
    w -> show();
}
void memberwindow::on_pB_chat_clicked()
{
    this->~memberwindow();
    c_memberchat * w = new c_memberchat();
    w -> show();
}
void memberwindow::on_pB_logoff_clicked()
{
    this->~memberwindow();
    MainWindow * w = new MainWindow();
    w -> show();
}

