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



void MainWindow::on_btnStart_clicked()
{

}

void MainWindow::on_btnStop_clicked()
{

}

void MainWindow::on_btnClear_clicked()
{

}

void MainWindow::on_comboUniverseSize_currentIndexChanged(const QString &arg1)
{

}

void MainWindow::on_btnUniverseMode_currentIndexChanged(const QString &arg1)
{

}

void MainWindow::on_btnCellMode_currentIndexChanged(const QString &arg1)
{

}

void MainWindow::on_spinMS_valueChanged(const QString &arg1)
{

}

void MainWindow::on_btnLoad_clicked()
{

}

void MainWindow::on_btnSave_clicked()
{

}

void MainWindow::on_btnSelectColor_clicked()
{

}

void MainWindow::on_btnRandomColor_clicked()
{

}

void MainWindow::on_btnGo_clicked()
{

}
