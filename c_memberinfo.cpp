#include "c_memberinfo.h"
#include "ui_c_memberinfo.h"
#include "memberwindow.h"

c_memberinfo::c_memberinfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::c_memberinfo)
{
    ui->setupUi(this);
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

