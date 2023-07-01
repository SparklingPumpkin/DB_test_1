#include "c2_admerchandise.h"
#include "ui_c2_admerchandise.h"
#include "admwindow.h"

c2_admerchandise::c2_admerchandise(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::c2_admerchandise)
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

c2_admerchandise::~c2_admerchandise()
{
    delete ui;
}

// 跳转
void c2_admerchandise::on_pB_back_clicked()
{
    this->~c2_admerchandise();
    admwindow * w = new admwindow();
    w -> show();
}

void c2_admerchandise::setTableInfo(){
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
void c2_admerchandise::getDatabaseInfo(){
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





void c2_admerchandise::on_pB_create_4_clicked()
{
    QString c2_merchandiseNumber = ui->new_merchandiseNumber->text();//用户账号
    QString c2_merchandiseName = ui->new_merchandiseName->text();//密码
    QString c2_price = ui->new_price->text();//姓名
    QString c2_stock = ui->new_stock->text();//邮箱
    QString c2_photo = ui->new_photo->text();//余额


    QSqlQuery sql;
    sql.prepare("insert into merchandise values(:c2_merchandiseNumber,:c2_merchandiseName,:c2_price,:c2_stock,:c2_photo)");
    sql.bindValue(":c2_merchandiseNumber",c2_merchandiseNumber);
    sql.bindValue(":c2_merchandiseName",c2_merchandiseName);
    sql.bindValue(":c2_price",c2_price);
    sql.bindValue(":c2_stock",c2_stock);
    sql.bindValue(":c2_photo",c2_photo);

    bool addIF = sql.exec();
    if(addIF)
    {
        qDebug()<<"新建会员成功！";
        c2_admerchandise::getDatabaseInfo();
    }
    else
    {
        qDebug()<<"新建会员失败！";
    }

    sql.clear();
}


void c2_admerchandise::on_pB_update_4_clicked()
{
    QString c2_merchandiseNumber = ui->new_merchandiseNumber->text();//用户账号
    QString c2_merchandiseName = ui->new_merchandiseName->text();//密码
    QString c2_price = ui->new_price->text();//姓名
    QString c2_stock = ui->new_stock->text();//邮箱
    QString c2_photo = ui->new_photo->text();//余额

    //    qDebug()<<c2_merchandiseNumber;
    //    qDebug()<<c2_merchandiseName;
    //    qDebug()<<c2_price;
    //    qDebug()<<c2_stock;
    //    qDebug()<<c2_photo;


    QSqlQuery sql;
    sql.prepare("update merchandise set merchandiseName=:c2_merchandiseName,price=:c2_price,stock=:c2_stock,photo=:c2_photo where merchandiseNumber=:c2_merchandiseNumber;");
    sql.bindValue(":c2_merchandiseNumber",c2_merchandiseNumber);
    sql.bindValue(":c2_merchandiseName",c2_merchandiseName);
    sql.bindValue(":c2_price",c2_price);
    sql.bindValue(":c2_stock",c2_stock);
    sql.bindValue(":c2_photo",c2_photo);

    bool addIF = sql.exec();
    if(addIF)
    {
        qDebug()<<"更改信息成功！";
        c2_admerchandise::getDatabaseInfo();
    }
    else
    {
        qDebug()<<"更改信息失败！";
    }

    sql.clear();
}


void c2_admerchandise::on_pB_delete_4_clicked()
{
    QString c2_merchandiseNumber = ui->new_merchandiseNumber->text();//用户账号

    //    qDebug()<<c2_merchandiseNumber;
    //    qDebug()<<c2_merchandiseName;
    //    qDebug()<<c2_price;
    //    qDebug()<<c2_stock;
    //    qDebug()<<c2_photo;


    QSqlQuery sql;
    sql.prepare("delete from merchandise where merchandiseNumber=:c2_merchandiseNumber;");
    sql.bindValue(":c2_merchandiseNumber",c2_merchandiseNumber);

    bool addIF = sql.exec();
    if(addIF)
    {
        qDebug()<<"删除信息成功！";
        c2_admerchandise::getDatabaseInfo();
    }
    else
    {
        qDebug()<<"删除信息失败！";
    }

    sql.clear();

    this->~c2_admerchandise();
    c2_admerchandise * w = new c2_admerchandise();
    w -> show();
}


void c2_admerchandise::on_pB_shuaxin_clicked()
{
    this->~c2_admerchandise();
    c2_admerchandise * w = new c2_admerchandise();
    w -> show();
}


void c2_admerchandise::on_pB_select_clicked()
{
    QString merchandiseNumber_select = ui ->text_select->text();

    if(merchandiseNumber_select == ""){
        c2_admerchandise::setTableInfo();
    }
    else{
        QSqlQuery sql;
        sql.prepare("select * from merchandise where merchandiseNumber=:merchandiseNumber_select;");
        sql.bindValue(":merchandiseNumber_select", merchandiseNumber_select);
        sql.exec();

        this->dataTableModel->clear();

        // newRowData<<sql.value("merchandiseNumber").toString()<<sql.value("merchandiseName").toString()<<sql.value("price").toString()<<sql.value("stock").toString();
        // 设置表头
        this->dataTableModel->setHorizontalHeaderItem(0,new QStandardItem("merchandiseNumber"));
        this->dataTableModel->setHorizontalHeaderItem(1,new QStandardItem("merchandiseName"));
        this->dataTableModel->setHorizontalHeaderItem(2,new QStandardItem("price"));
        this->dataTableModel->setHorizontalHeaderItem(3,new QStandardItem("stock"));
        this->dataTableModel->setHorizontalHeaderItem(4,new QStandardItem("photo"));

        // 设置列宽
        ui->merchandise_view->setColumnWidth(0,100);
        ui->merchandise_view->setColumnWidth(1,100);
        ui->merchandise_view->setColumnWidth(2,100);
        ui->merchandise_view->setColumnWidth(3,100);
        ui->merchandise_view->setColumnWidth(4,100);

        // 设置表格只读属性
        ui->merchandise_view->setEditTriggers(QAbstractItemView::NoEditTriggers);

        int row = 0;
        while(sql.next())
        {
            this->dataTableModel->setItem(row,0,new QStandardItem(sql.value("merchandiseNumber").toString()));
            this->dataTableModel->setItem(row,1,new QStandardItem(sql.value("merchandiseName").toString()));
            this->dataTableModel->setItem(row,2,new QStandardItem(sql.value("price").toString()));
            this->dataTableModel->setItem(row,3,new QStandardItem(sql.value("stock").toString()));
            this->dataTableModel->setItem(row,4,new QStandardItem(sql.value("photo").toString()));
            row++;
        }
        //this->rowData = newRowData;
        sql.clear();

        // 最后，将设计好的表格模式，装载在表格上
        ui->merchandise_view->setModel(this->dataTableModel);
    }
}

