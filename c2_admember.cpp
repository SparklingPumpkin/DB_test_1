#include "c2_admember.h"
#include "ui_c2_admember.h"
#include "admwindow.h"
#include <QApplication>
#include <QLabel>

c2_admember::c2_admember(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::c2_admember)
{
    ui->setupUi(this);


    // 连接数据库
    this -> myDatabase.getConnection();

    // 为表格模式指针指定内存
    this -> dataTableModel = new QStandardItemModel();

    // 设置表格
    this -> setTableInfo();

    ui->memberinfo_table->setCurrentIndex(1);

}

c2_admember::~c2_admember()
{
    delete ui;
}

// 跳转
void c2_admember::on_pB_back_clicked()
{
    this->~c2_admember();
    admwindow * w = new admwindow();
    w -> show();
}

void c2_admember::setTableInfo(){
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
void c2_admember::getDatabaseInfo(){
    // 1, 从数据库获取信息
    QSqlQuery sql;
    sql.prepare("select * from member;");
    sql.exec();

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


void c2_admember::on_pB_create_clicked()
{
    QString c2_memberNumber = ui->new_memberNumber->text();//用户账号
    QString c2_memberPassword = ui->new_memberPassword->text();//密码
    QString c2_memberName = ui->new_memberName->text();//姓名
    QString c2_memberEmail = ui->new_memberEmail->text();//邮箱
    QString c2_memberBalance = ui->new_memberBalance->text();//余额

//    qDebug()<<c2_memberNumber;
//    qDebug()<<c2_memberPassword;
//    qDebug()<<c2_memberName;
//    qDebug()<<c2_memberEmail;
//    qDebug()<<c2_memberBalance;


    QSqlQuery sql;
    sql.prepare("insert into member values(:c2_memberNumber,:c2_memberPassword,:c2_memberName,:c2_memberEmail,:c2_memberBalance)");
    sql.bindValue(":c2_memberNumber",c2_memberNumber);
    sql.bindValue(":c2_memberPassword",c2_memberPassword);
    sql.bindValue(":c2_memberName",c2_memberName);
    sql.bindValue(":c2_memberEmail",c2_memberEmail);
    sql.bindValue(":c2_memberBalance",c2_memberBalance);

    bool addIF = sql.exec();
    if(addIF)
    {
        qDebug()<<"新建会员成功！";
        c2_admember::getDatabaseInfo();
    }
    else
    {
        qDebug()<<"新建会员失败！";
    }

    sql.clear();
}


void c2_admember::on_pB_update_clicked()
{
    QString c2_memberNumber = ui->new_memberNumber->text();//用户账号
    QString c2_memberPassword = ui->new_memberPassword->text();//密码
    QString c2_memberName = ui->new_memberName->text();//姓名
    QString c2_memberEmail = ui->new_memberEmail->text();//邮箱
    QString c2_memberBalance = ui->new_memberBalance->text();//余额

//    qDebug()<<c2_memberNumber;
//    qDebug()<<c2_memberPassword;
//    qDebug()<<c2_memberName;
//    qDebug()<<c2_memberEmail;
//    qDebug()<<c2_memberBalance;


    QSqlQuery sql;
    sql.prepare("update member set memberPassword=:c2_memberPassword,Name=:c2_memberName,email=:c2_memberEmail,balance=:c2_memberBalance where memberNumber=:c2_memberNumber;");
    sql.bindValue(":c2_memberNumber",c2_memberNumber);
    sql.bindValue(":c2_memberPassword",c2_memberPassword);
    sql.bindValue(":c2_memberName",c2_memberName);
    sql.bindValue(":c2_memberEmail",c2_memberEmail);
    sql.bindValue(":c2_memberBalance",c2_memberBalance);

    bool addIF = sql.exec();
    if(addIF)
    {
        qDebug()<<"更改信息成功！";
        c2_admember::getDatabaseInfo();
    }
    else
    {
        qDebug()<<"更改信息失败！";
    }

    sql.clear();
}


void c2_admember::on_pB_delete_clicked()
{
    QString c2_memberNumber = ui->new_memberNumber->text();//用户账号

    //    qDebug()<<c2_memberNumber;
    //    qDebug()<<c2_memberPassword;
    //    qDebug()<<c2_memberName;
    //    qDebug()<<c2_memberEmail;
    //    qDebug()<<c2_memberBalance;


    QSqlQuery sql;
    sql.prepare("delete from member where memberNumber=:c2_memberNumber;");
    sql.bindValue(":c2_memberNumber",c2_memberNumber);

    bool addIF = sql.exec();
    if(addIF)
    {
        qDebug()<<"删除信息成功！";
        c2_admember::getDatabaseInfo();
    }
    else
    {
        qDebug()<<"删除信息失败！";
    }

    sql.clear();

    this->~c2_admember();
    c2_admember * w = new c2_admember();
    w -> show();

}


void c2_admember::on_pB_shuaxin_clicked()
{
    this->~c2_admember();
    c2_admember * w = new c2_admember();
    w -> show();
}


void c2_admember::on_pB_select_clicked()
{
    QString memberNumber_select = ui ->text_select->text();

    if(memberNumber_select == ""){
        c2_admember::setTableInfo();
    }
    else{
        QSqlQuery sql;
        sql.prepare("select * from member where memberNumber=:memberNumber_select;");
        sql.bindValue(":memberNumber_select", memberNumber_select);
        sql.exec();

        this->dataTableModel->clear();

        // newRowData<<sql.value("memberNumber").toString()<<sql.value("memberPassword").toString()<<sql.value("Name").toString()<<sql.value("email").toString();
        // 设置表头
        this->dataTableModel->setHorizontalHeaderItem(0,new QStandardItem("memberNumber"));
        this->dataTableModel->setHorizontalHeaderItem(1,new QStandardItem("memberPassword"));
        this->dataTableModel->setHorizontalHeaderItem(2,new QStandardItem("Name"));
        this->dataTableModel->setHorizontalHeaderItem(3,new QStandardItem("email"));
        this->dataTableModel->setHorizontalHeaderItem(4,new QStandardItem("balance"));

        // 设置列宽
        ui->member_view->setColumnWidth(0,100);
        ui->member_view->setColumnWidth(1,100);
        ui->member_view->setColumnWidth(2,100);
        ui->member_view->setColumnWidth(3,100);
        ui->member_view->setColumnWidth(4,100);

        // 设置表格只读属性
        ui->member_view->setEditTriggers(QAbstractItemView::NoEditTriggers);

        int row = 0;
        while(sql.next())
        {
            this->dataTableModel->setItem(row,0,new QStandardItem(sql.value("memberNumber").toString()));
            this->dataTableModel->setItem(row,1,new QStandardItem(sql.value("memberPassword").toString()));
            this->dataTableModel->setItem(row,2,new QStandardItem(sql.value("Name").toString()));
            this->dataTableModel->setItem(row,3,new QStandardItem(sql.value("email").toString()));
            this->dataTableModel->setItem(row,4,new QStandardItem(sql.value("balance").toString()));
            row++;
        }
        //this->rowData = newRowData;
        sql.clear();

        // 最后，将设计好的表格模式，装载在表格上
        ui->member_view->setModel(this->dataTableModel);
    }
}






