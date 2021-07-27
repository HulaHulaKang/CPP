#include "dlg1.h"
#include <QApplication>
#include"classes/DataBase.h"

DataBase mydata;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dlg1 mainwindow;
    mainwindow.show();

    return a.exec();
}
