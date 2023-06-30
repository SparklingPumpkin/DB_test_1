#include "c_membermarket.h"
#include "ui_c_membermarket.h"
#include "memberwindow.h"

c_membermarket::c_membermarket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::c_membermarket)
{
    ui->setupUi(this);
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
