#ifndef MEMBERINFO_H
#define MEMBERINFO_H

#include <QMainWindow>

namespace Ui {
class memberinfo;
}

class memberinfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit memberinfo(QWidget *parent = nullptr);
    ~memberinfo();

private:
    Ui::memberinfo *ui;
};

#endif // MEMBERINFO_H
