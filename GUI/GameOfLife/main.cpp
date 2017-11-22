#include "mainwindow.h"
#include <QApplication>

/*
 * Author: Daniel Holzinger
 *
 */

/**
 * starting point
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    w.show();

    return a.exec();
}
