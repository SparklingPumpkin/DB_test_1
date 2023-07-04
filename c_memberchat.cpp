#include "c_memberchat.h"
#include "ui_c_memberchat.h"
#include "memberwindow.h"
#include <QString>

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


void c_memberchat::on_pB_chat_clicked()
{
    QString userInput = ui->Input->text();
    QString program = "D:/Anaconda/envs/DB/python.exe";  // Python解释器的路径或命令
    QStringList arguments;  // Python脚本和参数列表

    QString scriptPath = "E:/Program Data/Qt/MMS/MMS/test_py_1.py";  // Python脚本的路径
    //    QString scriptPath = "E:/C_projects/ChaGPT-API-Call-main/test.py";
    arguments << scriptPath << userInput;

    QProcess process;
    process.start(program, arguments);
    process.waitForFinished();  // 等待命令执行完成

    QByteArray output = process.readAllStandardOutput();  // 获取命令输出结果
    QString outputString = QString::fromUtf8(output);

    // 处理输出结果，例如更新UI或打印日志
    qDebug() << "Command output:" << outputString;

    // 更新UI中的LineEdit
    ui->Output->setText(outputString);
}
