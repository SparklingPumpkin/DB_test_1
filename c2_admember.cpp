#include "c2_admember.h"
#include "ui_c2_admember.h"
#include "admwindow.h"

c2_admember::c2_admember(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::c2_admember)
{
    ui->setupUi(this);
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

