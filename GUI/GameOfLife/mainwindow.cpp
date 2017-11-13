#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->widget->paintGrid();
    // spielobjekt = new GameWidget();
    // ui->widget = spielobjekt;
    // QObject::connect(ui->widget, SIGNAL(paintGrid()), )

}

MainWindow::~MainWindow()
{
    delete ui;
}


