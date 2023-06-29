#include "memberinfo.h"
#include "ui_memberinfo.h"

memberinfo::memberinfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::memberinfo)
{
    ui->setupUi(this);
}

memberinfo::~memberinfo()
{
    delete ui;
}
