#include "c2_admerchandise.h"
#include "ui_c2_admerchandise.h"
#include "admwindow.h"

c2_admerchandise::c2_admerchandise(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::c2_admerchandise)
{
    ui->setupUi(this);
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

