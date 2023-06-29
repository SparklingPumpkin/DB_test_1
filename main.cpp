#include "mainwindow.h"
#include "database.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Database::getConnection();
    // Database::quitConnection();
    MainWindow w;
    w.show();
    return a.exec();
}
