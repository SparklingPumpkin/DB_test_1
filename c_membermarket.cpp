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
    sql.prepare("insert into `order` values(:c2_merchandiseNumber,:c2_merchandiseName,:c2_price,:c2_stock,:c2_photo)");
    sql.bindValue(":c2_merchandiseNumber",temper);
    sql.bindValue(":c2_merchandiseName",globalkey);
    qDebug() << globalkey;
    sql.bindValue(":c2_price",c2_merchandiseNumber);
    sql.bindValue(":c2_stock",c2_stock);
    sql.bindValue(":c2_photo",100);

    bool addIF = sql.exec();
    if(addIF)
    {
        qDebug()<<"购买成功！";
        c_membermarket::getDatabaseInfo();
    }
    else
    {
        qDebug()<<"购买失败！";
    }

    sql.clear();
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

