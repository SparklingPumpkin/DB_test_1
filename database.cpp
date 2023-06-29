#include "database.h"

QSqlDatabase Database :: db = QSqlDatabase :: addDatabase("QODBC");    // 创建静态数据库实例
QSqlQuery * Database :: sql = NULL;

Database::Database()
{
    qDebug()<<"数据库实例已创建";
}
bool Database::getConnection()
{
    // 数据库连接
    db.setHostName("rm-cn-uax39zi420016v5o.rwlb.rds.aliyuncs.com");    // IP
    db.setPort(3306);                                                  // 端口号
    db.setDatabaseName("mms");                                         // ODBC数据源名称
    db.setUserName("fjn");                                             // 用户名
    db.setPassword("1234567890abcDEF");                                // 密码
    if(!db.open ())
    {
        qDebug()<<"database Error";
        qDebug()<<db.lastError().text();
        return false;
    }
    else
    {
        qDebug()<<"connect successfully!";
        return true;
    }
}

void Database::quitConnection()
{
    // 数据库断连
    db.close();
    qDebug()<<"close successfully!";
}
