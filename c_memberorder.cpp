#include "c_memberorder.h"
#include "ui_c_memberorder.h"
#include "memberwindow.h"

c_memberorder::c_memberorder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::c_memberorder)
{
    ui->setupUi(this);
}

c_memberorder::~c_memberorder()
{
    delete ui;
}

// 跳转
void c_memberorder::on_pB_back_clicked()
{
    this->~c_memberorder();
    memberwindow * w = new memberwindow();
    w -> show();
}
