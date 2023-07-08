#include "mainwindow.h"
#include "memberwindow.h"
#include "database.h"
#include <QApplication>
#include <iostream>

#include <QCoreApplication>
#include <QProcess>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Database::getConnection();
    // Database::quitConnection();
    MainWindow w;
//    memberwindow w2;

    w.show();

    QProcess process;
    process.start("python test_py_1.py"); // 替换为你要执行的命令

    if (process.waitForFinished()) {
        QByteArray output = process.readAllStandardOutput();
        QString outputString(output);
        qDebug() << "Command output:" << outputString;
    } else {
        qDebug() << "Command execution failed.";
    }



    return a.exec();
}
