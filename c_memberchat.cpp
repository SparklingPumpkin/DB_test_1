#include "c_memberchat.h"
#include "ui_c_memberchat.h"
#include "memberwindow.h"

c_memberchat::c_memberchat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::c_memberchat)
{
    ui->setupUi(this);
}

c_memberchat::~c_memberchat()
{
    delete ui;
}

// 跳转
void c_memberchat::on_pB_back_clicked()
{
    this->~c_memberchat();
    memberwindow * w = new memberwindow();
    w -> show();
}
