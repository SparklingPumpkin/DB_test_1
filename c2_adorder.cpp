#include "c2_adorder.h"
#include "ui_c2_adorder.h"
#include "admwindow.h"
#include <QApplication>

c2_adorder::c2_adorder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::c2_adorder)
{
    ui->setupUi(this);
    // 连接数据库
    this -> myDatabase.getConnection();

    // 为表格模式指针指定内存
    this -> dataTableModel = new QStandardItemModel();

    // 设置表格
    this -> setTableInfo();

    ui->orderinfo_table->setCurrentIndex(1);

}

c2_adorder::~c2_adorder()
{
    delete ui;
}

// 跳转
void c2_adorder::on_pB_back_clicked()
{
    this->~c2_adorder();
    admwindow * w = new admwindow();
    w -> show();
}

void c2_adorder::setTableInfo(){
    // 设置表头
    this->dataTableModel->setHorizontalHeaderItem(0,new QStandardItem("orderNumber"));
    this->dataTableModel->setHorizontalHeaderItem(1,new QStandardItem("memberNumber"));
    this->dataTableModel->setHorizontalHeaderItem(2,new QStandardItem("merchandiseNumber"));
    this->dataTableModel->setHorizontalHeaderItem(3,new QStandardItem("quantity"));
    this->dataTableModel->setHorizontalHeaderItem(4,new QStandardItem("amount"));

    // 设置表格信息
    this->getDatabaseInfo();

    // 设置列宽W
    ui->order_view->setColumnWidth(0,100);
    ui->order_view->setColumnWidth(1,100);
    ui->order_view->setColumnWidth(2,100);
    ui->order_view->setColumnWidth(3,100);
    ui->order_view->setColumnWidth(4,100);

    // 设置表格只读属性
    ui->order_view->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 最后，将设计好的表格模式，装载在表格上
    ui->order_view->setModel(this->dataTableModel);

}


// 连接数据库
void c2_adorder::getDatabaseInfo(){
    // 1, 从数据库获取信息
    QSqlQuery sql;
    sql.prepare("select * from order;");
    sql.exec();

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

void c2_adorder::on_pB_create_4_clicked()
{
    QString c2_orderNumber = ui->new_orderNumber->text();//用户账号
    QString c2_memberNumber = ui->new_memberNumber->text();//密码
    QString c2_merchandiseNumber = ui->new_merchandiseNumber->text();//姓名
    QString c2_quantity = ui->new_quantity->text();//密码
    QString c2_amount = ui->new_amount->text();//姓名

    QSqlQuery sql;
    sql.prepare("insert into order values(:c2_orderNumber,:c2_memberNumber,:c2_merchandiseNumber, :c2_quantity, :c2_amount)");
    sql.bindValue(":c2_orderNumber",c2_orderNumber);
    sql.bindValue(":c2_memberNumber",c2_memberNumber);
    sql.bindValue(":c2_merchandiseNumber",c2_merchandiseNumber);
    sql.bindValue(":c2_quantity",c2_quantity);
    sql.bindValue(":c2_amount",c2_amount);

    bool addIF = sql.exec();
    if(addIF)
    {
        qDebug()<<"新建会员成功！";
        c2_adorder::getDatabaseInfo();
    }
    else
    {
        qDebug()<<"新建会员失败！";
    }

    sql.clear();
}


void c2_adorder::on_pB_update_4_clicked()
{
    QString c2_orderNumber = ui->new_orderNumber->text();//用户账号
    QString c2_memberNumber = ui->new_memberNumber->text();//密码
    QString c2_merchandiseNumber = ui->new_merchandiseNumber->text();//姓名
    QString c2_quantity = ui->new_quantity->text();//密码
    QString c2_amount = ui->new_amount->text();//姓名

    QSqlQuery sql;
    sql.prepare("update order set memberNumber=:c2_memberNumber,merchandiseNumber=:c2_merchandiseNumber, quantity=:c2_quantity, amount=:c2_amount where orderNumber=:c2_orderNumber;");
    sql.bindValue(":c2_orderNumber",c2_orderNumber);
    sql.bindValue(":c2_memberNumber",c2_memberNumber);
    sql.bindValue(":c2_merchandiseNumber",c2_merchandiseNumber);
    sql.bindValue(":c2_quantity",c2_quantity);
    sql.bindValue(":c2_amount",c2_amount);

    bool addIF = sql.exec();
    if(addIF)
    {
        qDebug()<<"更改信息成功！";
        c2_adorder::getDatabaseInfo();
    }
    else
    {
        qDebug()<<"更改信息失败！";
    }

    sql.clear();
}


void c2_adorder::on_pB_delete_4_clicked()
{
    QString c2_orderNumber = ui->new_orderNumber->text();//用户账号

    QSqlQuery sql;
    sql.prepare("delete from order where orderNumber=:c2_orderNumber;");
    sql.bindValue(":c2_orderNumber",c2_orderNumber);

    bool addIF = sql.exec();
    if(addIF)
    {
        qDebug()<<"删除信息成功！";
        c2_adorder::getDatabaseInfo();
    }
    else
    {
        qDebug()<<"删除信息失败！";
    }

    sql.clear();

    this->~c2_adorder();
    c2_adorder * w = new c2_adorder();
    w -> show();
}


void c2_adorder::on_pB_shuaxin_clicked()
{
    this->~c2_adorder();
    c2_adorder * w = new c2_adorder();
    w -> show();
}



void c2_adorder::on_pB_select_clicked()
{
    QString orderNumber_select = ui ->text_select->text();

    if(orderNumber_select == ""){
        c2_adorder::setTableInfo();
    }
    else{
        QSqlQuery sql;
        sql.prepare("select * from order where orderNumber=:orderNumber_select;");
        sql.bindValue(":orderNumber_select", orderNumber_select);
        sql.exec();

        this->dataTableModel->clear();

        // 设置表头
        this->dataTableModel->setHorizontalHeaderItem(0,new QStandardItem("orderNumber"));
        this->dataTableModel->setHorizontalHeaderItem(1,new QStandardItem("memberNumber"));
        this->dataTableModel->setHorizontalHeaderItem(2,new QStandardItem("merchandiseNumber"));
        this->dataTableModel->setHorizontalHeaderItem(3,new QStandardItem("quantity"));
        this->dataTableModel->setHorizontalHeaderItem(4,new QStandardItem("amount"));

        // 设置列宽
        ui->order_view->setColumnWidth(0,100);
        ui->order_view->setColumnWidth(1,100);
        ui->order_view->setColumnWidth(2,100);
        ui->order_view->setColumnWidth(3,100);
        ui->order_view->setColumnWidth(4,100);

        // 设置表格只读属性
        ui->order_view->setEditTriggers(QAbstractItemView::NoEditTriggers);

        int row = 0;
        while(sql.next())
        {
            this->dataTableModel->setItem(row,0,new QStandardItem(sql.value("orderNumber").toString()));
            this->dataTableModel->setItem(row,1,new QStandardItem(sql.value("memberNumber").toString()));
            this->dataTableModel->setItem(row,2,new QStandardItem(sql.value("merchandiseNumber").toString()));
            this->dataTableModel->setItem(row,3,new QStandardItem(sql.value("quantity").toString()));
            this->dataTableModel->setItem(row,4,new QStandardItem(sql.value("amount").toString()));
            row++;
        }
        //this->rowData = newRowData;
        sql.clear();

        // 最后，将设计好的表格模式，装载在表格上
        ui->order_view->setModel(this->dataTableModel);
    }
}

