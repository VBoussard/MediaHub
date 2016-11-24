#include "mainwindow.h"
#include <QApplication>
#include <engine.h>

int main(int argc, char *argv[])
{
    Engine *MediaHub = new Engine;
    QApplication a(argc, argv);
    MainWindow w(MediaHub);
    w.show();

    return a.exec();

}
