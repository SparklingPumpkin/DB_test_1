#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include "memberwindow.h"
#include "admwindow.h"
#include "memberwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->myDatabase.getConnection();
    //通信
    connect(this, &MainWindow::sendToB, &admwindow_d, &admwindow::get_message); // 连接信号与槽
    connect(this, &MainWindow::sendToB, &memberwindow_d, &memberwindow::get_message_2); // 连接信号与槽

}

MainWindow::~MainWindow()
{
    delete ui;
}

// 发送信号
//void MainWindow::send_message(){
//    QString userInputNumber = ui->InputNumber->text();
//    emit sendToB(userInputNumber);
//}

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
//    qDebug()<<"用户输入的账号"+userInputNumber;
//    qDebug()<<"用户输入的密码"+userInputPassword;
//    qDebug()<<"用户输入的类别"+userInputtype;

    //通信
    admwindow_d.get_message(userInputNumber);
    emit sendToB(userInputNumber); //发送信号
    memberwindow_d.get_message_2(userInputNumber);
    emit sendToB(userInputNumber); //发送信号



    //用户
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
            this->~MainWindow();
            memberwindow * w = new memberwindow();
            w -> show();
        }
        else{
            qDebug()<<"登录失败!";
        }
    }

    // 管理员
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


        // 实现跳转
        if(userInputPassword == administratorPassword && userInputNumber == administratorNumber){
            qDebug()<<"登录成功!";
            this->~MainWindow();
            admwindow * w = new admwindow();
            w -> show();

        }
        else{
            qDebug()<<"登录失败!";
        }
    }
}

