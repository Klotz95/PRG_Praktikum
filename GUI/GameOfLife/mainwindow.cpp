#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

void MainWindow::on_spinUniverseSize_valueChanged(const QString &arg1) {
    string number = arg1.toUtf8().constData();
    string deleted = " cells";
    number = number.substr(0, number.size()-deleted.size());
    this->universeSize = atoi( number.c_str() );

    this->ui->gameWidget->getCAbase().setNx(universeSize);
    this->ui->gameWidget->getCAbase().setNy(universeSize);
    this->ui->gameWidget->setRectWidth(this->ui->gameWidget->getCAbase().getNx()/
                                        this->ui->gameWidget->width());
    this->ui->gameWidget->setRectHeight(this->ui->gameWidget->getCAbase().getNy()/
                                        this->ui->gameWidget->height());
}
