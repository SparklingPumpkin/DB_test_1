#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include "mainpage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->myDatabase.getConnection();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString userInputtype;

    if(ui->radioButton_2->isChecked())
    {
        userInputtype = "member";
    }
    else
    {
        userInputtype = "administrator";
    }

    QString userInputNumber = ui->InputNumber->text();
    QString userInputPassword = ui->InputPassword->text();
    qDebug()<<"用户输入的账号"+userInputNumber;
    qDebug()<<"用户输入的密码"+userInputPassword;
    qDebug()<<"用户输入的类别"+userInputtype;

    if(ui->radioButton_2->isChecked()){
        QSqlQuery sql;
        sql.prepare("select * from `member` where `memberNumber` = :userInputNumber");
        sql.bindValue(":userInputNumber", userInputNumber);
        sql.exec();

        QString memberNumber;
        QString memberPassword;
        while(sql.next()){
            memberNumber = sql.value("memberNumber").toString();
            memberPassword = sql.value("memberPassword").toString();
        }
        qDebug()<<"数据库找到的账号"+memberNumber;
        qDebug()<<"数据库找到的密码"+memberPassword;
                    sql.clear();

        if(userInputPassword == memberPassword && userInputNumber == memberNumber){
            qDebug()<<"登录成功!";
        }
        else{
            qDebug()<<"登录失败!";
        }
    }

    if(ui->radioButton->isChecked()){
        QSqlQuery sql;
        sql.prepare("select * from mms.`administrator` where `administratorNumber` = :userInputNumber");
        sql.bindValue(":userInputNumber", userInputNumber);
        sql.exec();

        QString administratorNumber;
        QString administratorPassword;
        while(sql.next()){
            administratorNumber = sql.value("administratorNumber").toString();
            administratorPassword = sql.value("administratorPassword").toString();
        }
        qDebug()<<"数据库找到的账号"+administratorNumber;
        qDebug()<<"数据库找到的密码"+administratorPassword;
                    sql.clear();

        if(userInputPassword == administratorPassword && userInputNumber == administratorNumber){
            qDebug()<<"登录成功!";
            this->~MainWindow();
            mainpage * w = new mainpage();
            w -> show();
        }
        else{
            qDebug()<<"登录失败!";
        }
    }


}

