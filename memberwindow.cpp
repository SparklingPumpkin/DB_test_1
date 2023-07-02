#include "memberwindow.h"
#include "ui_memberwindow.h"
#include <QApplication>
#include "c_memberinfo.h"
#include "c_membermarket.h"
#include "c_memberorder.h"
#include "c_memberchat.h"
#include "mainwindow.h"

QString globalkey;

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
    //this -> setTableInfo();

}

memberwindow::~memberwindow()
{
    delete ui;
}

void memberwindow::get_message_2(QString m){
//    qDebug()<<"是本大爷!";
//    qDebug()<<m;
//    key_id = new QString(m);
    globalkey = m;
}


//跳转
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

void memberwindow::setTableInfo(){
        // 设置表头
        this->dataTableModel->setHorizontalHeaderItem(0,new QStandardItem("memberNumber"));
        this->dataTableModel->setHorizontalHeaderItem(1,new QStandardItem("memberPassword"));
        this->dataTableModel->setHorizontalHeaderItem(2,new QStandardItem("Name"));
        this->dataTableModel->setHorizontalHeaderItem(3,new QStandardItem("email"));
        this->dataTableModel->setHorizontalHeaderItem(4,new QStandardItem("balance"));


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
void memberwindow::getDatabaseInfo(){
        // 1, 从数据库获取信息
        QSqlQuery sql;

//        sql.prepare("create view temper as select * from member where memberNumber=:key;");
//        sql.bindValue(":key", globalkey);

//        bool addIF = sql.exec();
//        if(addIF)
//        {
//            qDebug()<<"视图创建成功！";
//        }
//        else
//        {
//            qDebug()<<"视图创建失败！";
//        }

        sql.prepare("select * from member where memberNumber=:key;");
        sql.bindValue(":key", globalkey);
        sql.exec();
//        this->dataTableModel->clear();

        int row = 0; //表格行数
        while(sql.next()){
            this->dataTableModel->setItem(row,0,new QStandardItem(sql.value("memberNumber").toString()));
            this->dataTableModel->setItem(row,1,new QStandardItem(sql.value("memberPassword").toString()));
            this->dataTableModel->setItem(row,2,new QStandardItem(sql.value("Name").toString()));
            this->dataTableModel->setItem(row,3,new QStandardItem(sql.value("email").toString()));
            this->dataTableModel->setItem(row,4,new QStandardItem(sql.value("balance").toString()));
            row++;
        }
        sql.clear();

}


void memberwindow::on_pB_update_clicked()
{
        QString c2_memberPassword = ui->new_memberPassword->text();//密码
        QString c2_memberName = ui->new_memberName->text();//姓名
        QString c2_memberEmail = ui->new_memberEmail->text();//邮箱
        QString c2_memberBalance = ui->new_memberBalance->text();//余额

        QSqlQuery sql;
        sql.prepare("update member set memberPassword=:c2_memberPassword,Name=:c2_memberName,email=:c2_memberEmail,balance=:c2_memberBalance where memberNumber=:c2_memberNumber;");
        sql.bindValue(":c2_memberNumber",globalkey);
        sql.bindValue(":c2_memberPassword",c2_memberPassword);
        sql.bindValue(":c2_memberName",c2_memberName);
        sql.bindValue(":c2_memberEmail",c2_memberEmail);
        sql.bindValue(":c2_memberBalance",c2_memberBalance);
        sql.exec();
        memberwindow::setTableInfo();
        sql.clear();
}


void memberwindow::on_pB_delete_clicked()
{
        QSqlQuery sql;
        sql.prepare("delete from member where memberNumber=:c2_memberNumber;");
        sql.bindValue(":c2_memberNumber",globalkey);

        bool addIF = sql.exec();
        if(addIF)
        {
            qDebug()<<"删除信息成功！";
            memberwindow::getDatabaseInfo();
        }
        else
        {
            qDebug()<<"删除信息失败！";
        }

        sql.clear();

        this->~memberwindow();
        MainWindow * w = new MainWindow();
        w -> show();
}


//void memberwindow::on_pB_getinfo_clicked()
//{
//    //this -> getDatabaseInfo();
//        // 1, 从数据库获取信息
//        QSqlQuery sql;

//        sql.prepare("create view temper as select * from member where memberNumber=':key';");
//        sql.bindValue(":key", globalkey);
//        sql.exec();

//        sql.prepare("select * from temper;");
//        sql.exec();
//        this->dataTableModel->clear();
//        // 设置表头
//        this->dataTableModel->setHorizontalHeaderItem(0,new QStandardItem("memberNumber"));
//        this->dataTableModel->setHorizontalHeaderItem(1,new QStandardItem("memberPassword"));
//        this->dataTableModel->setHorizontalHeaderItem(2,new QStandardItem("Name"));
//        this->dataTableModel->setHorizontalHeaderItem(3,new QStandardItem("email"));
//        this->dataTableModel->setHorizontalHeaderItem(4,new QStandardItem("balance"));
//        // 设置列宽
//        ui->member_view->setColumnWidth(0,100);
//        ui->member_view->setColumnWidth(1,100);
//        ui->member_view->setColumnWidth(2,100);
//        ui->member_view->setColumnWidth(3,100);
//        ui->member_view->setColumnWidth(4,100);
//        // 设置表格只读属性
//        ui->member_view->setEditTriggers(QAbstractItemView::NoEditTriggers);


//        int row = 0; //表格行数
//        while(sql.next()){
//            this->dataTableModel->setItem(row,0,new QStandardItem(sql.value("memberNumber").toString()));
//            this->dataTableModel->setItem(row,1,new QStandardItem(sql.value("memberPassword").toString()));
//            this->dataTableModel->setItem(row,2,new QStandardItem(sql.value("Name").toString()));
//            this->dataTableModel->setItem(row,3,new QStandardItem(sql.value("email").toString()));
//            this->dataTableModel->setItem(row,4,new QStandardItem(sql.value("balance").toString()));
//            row++;
//        }
//        ui->member_view->setModel(this->dataTableModel);
//        sql.prepare("drop view temper;");
//        sql.exec();
//        sql.clear();
//}


void memberwindow::on_pB_getinfo_clicked()
{
    memberwindow::setTableInfo();

}

