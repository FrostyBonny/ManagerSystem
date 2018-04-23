#include "mainwindow.h"
#include <QApplication>
#include "resources.h"

int main(int argc, char *argv[])
{
    //转double
    QApplication a(argc, argv);
    Resources resources;
    Resources::whichworker = -1;
    MainWindow w;
    w.show();

    return a.exec();
}
