#include "mainpage.h"
#include "ui_mainpage.h"

mainpage::mainpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainpage)
{
    ui->setupUi(this);

    //连接数据库
    this -> myDatabase.getConnection();

    //为表格模式指针指定内存
    this -> dataTableModel = new QStandardItemModel();

    //设置表格
    this -> setTableInfo();

}

mainpage::~mainpage()
{
    delete ui;
}
