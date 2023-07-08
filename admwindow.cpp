#include "admwindow.h"
#include "ui_admwindow.h"
#include "c2_admember.h"
#include "c2_admerchandise.h"
#include "c2_adorder.h"
#include "mainwindow.h"
#include <QLabel>

admwindow::admwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admwindow)
{
    ui->setupUi(this);
}

admwindow::~admwindow()
{
    delete ui;
}

//通信
void admwindow::get_message(QString m){
    qDebug()<<"是本大爷!";
    qDebug()<<m;

}

//跳转
void admwindow::on_pB_memberm_clicked()
{
    this->~admwindow();
    c2_admember * w = new c2_admember();
    w -> show();

}
void admwindow::on_pB_merchandisem_clicked()
{
    this->~admwindow();
    c2_admerchandise * w = new c2_admerchandise();
    w -> show();
}
void admwindow::on_pB_orderm_clicked()
{
    this->~admwindow();
    c2_adorder * w = new c2_adorder();
    w -> show();
}
void admwindow::on_pB_logoff_clicked()
{
    this->~admwindow();
    MainWindow * w = new MainWindow();
    w -> show();
}

