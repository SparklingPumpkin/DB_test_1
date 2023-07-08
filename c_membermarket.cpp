#include "c_membermarket.h"
#include "ui_c_membermarket.h"
#include "memberwindow.h"


c_membermarket::c_membermarket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::c_membermarket)
{
    ui->setupUi(this);

    // 连接数据库
    this -> myDatabase.getConnection();

    // 为表格模式指针指定内存
    this -> dataTableModel = new QStandardItemModel();

    // 设置表格
    this -> setTableInfo();

    ui->merchandiseinfo_table->setCurrentIndex(1);


}

c_membermarket::~c_membermarket()
{
    delete ui;
}

// 跳转
void c_membermarket::on_pB_back_clicked()
{
    this->~c_membermarket();
    memberwindow * w = new memberwindow();
    w -> show();
}

void c_membermarket::on_pB_create_4_clicked()
{
    QString c2_merchandiseNumber = ui->new_merchandiseNumber->text();
    QString c2_stock = ui->new_stock->text();
    QString temper = QString::number(rand());

    QSqlQuery sql;

    //获取商品价格
    sql.prepare("SELECT price FROM `merchandise` WHERE merchandiseNumber = :merchandiseNumber");
    sql.bindValue(":merchandiseNumber",c2_merchandiseNumber);
    sql.exec();
    sql.next();
    int c2_price = sql.value(0).toInt();
    //获取余额
    sql.prepare("SELECT balance FROM `member` WHERE memberNumber = :merchandiseNumber");
    sql.bindValue(":merchandiseNumber",globalkey);
    sql.exec();
    sql.next();
    int c2_balance = sql.value(0).toInt();
    //获取库存
    sql.prepare("SELECT stock FROM `merchandise` WHERE merchandiseNumber = :merchandiseNumber");
    sql.bindValue(":merchandiseNumber",c2_merchandiseNumber);
    sql.exec();
    sql.next();
    int c2_stockori = sql.value(0).toInt();

    if(c2_balance < c2_price*c2_stock.toInt() || c2_stockori < c2_stock.toInt()){
        qDebug()<<"库存不足或余额不足，购买失败！";
    }
    else{
        sql.prepare("insert into `order` values(:c2_merchandiseNumber,:c2_merchandiseName,:c2_price,:c2_stock,:c2_photo)");
        sql.bindValue(":c2_merchandiseNumber",temper);
        sql.bindValue(":c2_merchandiseName",globalkey);
        qDebug() << globalkey;
        sql.bindValue(":c2_price",c2_merchandiseNumber);
        sql.bindValue(":c2_stock",c2_stock);
        qDebug() << c2_price;
        sql.bindValue(":c2_photo",c2_price*c2_stock.toInt());
        bool addIF3 = sql.exec();
        if(addIF3)
        {
            qDebug()<<"库存充足，购买成功！";
        }
        else
        {
            qDebug()<<"库存不足，购买失败！";
        }


        sql.prepare("update `merchandise` set stock=stock-:c2_stock where merchandiseNumber=:c2_merchandiseNumber");
        sql.bindValue(":c2_merchandiseNumber",c2_merchandiseNumber);
        sql.bindValue(":c2_stock",c2_stock);
        bool addIF = sql.exec();
        if(addIF)
        {
            qDebug()<<"库存更改成功！";
        }
        else
        {
            qDebug()<<"库存更改失败！";
        }


        sql.prepare("update `member` set balance=balance-:c2_stock*(select sum(`price`) from `merchandise` where merchandiseNumber=:c2_merchandiseNumber) where memberNumber=:globalkey");
        sql.bindValue(":c2_stock",c2_stock.toInt());
        sql.bindValue(":c2_merchandiseNumber",c2_merchandiseNumber);
        sql.bindValue(":globalkey",globalkey);
        bool addIF2 = sql.exec();
        if(addIF2)
        {
            qDebug()<<"balance更改成功！";
        }
        else
        {
            qDebug()<<"balance更改失败！";
        }

        sql.clear();
        c_membermarket::getDatabaseInfo();

    }


}




void c_membermarket::setTableInfo(){
    // 设置表头
    this->dataTableModel->setHorizontalHeaderItem(0,new QStandardItem("merchandiseNumber"));
    this->dataTableModel->setHorizontalHeaderItem(1,new QStandardItem("merchandiseName"));
    this->dataTableModel->setHorizontalHeaderItem(2,new QStandardItem("price"));
    this->dataTableModel->setHorizontalHeaderItem(3,new QStandardItem("stock"));
    this->dataTableModel->setHorizontalHeaderItem(4,new QStandardItem("photo"));


    // 设置表格信息
    this->getDatabaseInfo();

    // 设置列宽
    ui->merchandise_view->setColumnWidth(0,100);
    ui->merchandise_view->setColumnWidth(1,100);
    ui->merchandise_view->setColumnWidth(2,100);
    ui->merchandise_view->setColumnWidth(3,100);
    ui->merchandise_view->setColumnWidth(4,100);

    // 设置表格只读属性
    ui->merchandise_view->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 最后，将设计好的表格模式，装载在表格上
    ui->merchandise_view->setModel(this->dataTableModel);

}

// 连接数据库
void c_membermarket::getDatabaseInfo(){
    // 1, 从数据库获取信息
    QSqlQuery sql;
    sql.prepare("select * from merchandise;");
    sql.exec();

    int row = 0; //表格行数
    while(sql.next()){
        this->dataTableModel->setItem(row,0,new QStandardItem(sql.value("merchandiseNumber").toString()));
        this->dataTableModel->setItem(row,1,new QStandardItem(sql.value("merchandiseName").toString()));
        this->dataTableModel->setItem(row,2,new QStandardItem(sql.value("price").toString()));
        this->dataTableModel->setItem(row,3,new QStandardItem(sql.value("stock").toString()));
        this->dataTableModel->setItem(row,4,new QStandardItem(sql.value("photo").toString()));
        row++;
    }
    sql.clear();
}

