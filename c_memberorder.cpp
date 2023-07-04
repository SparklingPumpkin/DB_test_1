#include "c_memberorder.h"
#include "ui_c_memberorder.h"
#include "memberwindow.h"

QString globalkey2;

c_memberorder::c_memberorder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::c_memberorder)
{
    ui->setupUi(this);
    // 连接数据库
    this -> myDatabase.getConnection();

    // 为表格模式指针指定内存
    this -> dataTableModel = new QStandardItemModel();
}

c_memberorder::~c_memberorder()
{
    delete ui;
}
//通信
void c_memberorder::get_message_3(QString m){
//    qDebug()<<"是本大爷!!!!!!";
//    qDebug()<<m;
//    key_id = new QString(m);
    globalkey2 = m;
}
// 跳转
void c_memberorder::on_pB_back_clicked()
{
    this->~c_memberorder();
    memberwindow * w = new memberwindow();
    w -> show();
}

void c_memberorder::on_pB_getinfo_clicked()
{
    c_memberorder::setTableInfo();
}


void c_memberorder::setTableInfo(){
    // 设置表头
    this->dataTableModel->setHorizontalHeaderItem(0,new QStandardItem("orderNumber"));
    this->dataTableModel->setHorizontalHeaderItem(1,new QStandardItem("memberNumber"));
    this->dataTableModel->setHorizontalHeaderItem(2,new QStandardItem("merchandiseNumber"));
    this->dataTableModel->setHorizontalHeaderItem(3,new QStandardItem("quantity"));
    this->dataTableModel->setHorizontalHeaderItem(4,new QStandardItem("amount"));


    // 设置表格信息
    this->getDatabaseInfo();
    // 设置列宽
    ui->member_view->setColumnWidth(0,100);
    ui->member_view->setColumnWidth(1,100);
    ui->member_view->setColumnWidth(2,100);
    ui->member_view->setColumnWidth(3,100);
    ui->member_view->setColumnWidth(4,100);
    // 设置表格只读属性
    ui->member_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 最后，将设计好的表格模式，装载在表格上
    ui->member_view->setModel(this->dataTableModel);
}
// 连接数据库
void c_memberorder::getDatabaseInfo(){
    // 1, 从数据库获取信息
    QSqlQuery sql;

    sql.prepare("select * from `order` where memberNumber=:key;");
    sql.bindValue(":key", globalkey2);
    sql.exec();
    //        this->dataTableModel->clear();

    int row = 0; //表格行数
    while(sql.next()){
        this->dataTableModel->setItem(row,0,new QStandardItem(sql.value("orderNumber").toString()));
        this->dataTableModel->setItem(row,1,new QStandardItem(sql.value("memberNumber").toString()));
        this->dataTableModel->setItem(row,2,new QStandardItem(sql.value("merchandiseNumber").toString()));
        this->dataTableModel->setItem(row,3,new QStandardItem(sql.value("quantity").toString()));
        this->dataTableModel->setItem(row,4,new QStandardItem(sql.value("amount").toString()));
        row++;
    }
    sql.clear();

}
