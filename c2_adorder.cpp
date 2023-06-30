#include "c2_adorder.h"
#include "ui_c2_adorder.h"
#include "admwindow.h"

c2_adorder::c2_adorder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::c2_adorder)
{
    ui->setupUi(this);
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
