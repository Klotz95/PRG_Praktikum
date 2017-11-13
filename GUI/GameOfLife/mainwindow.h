#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <gamewidget.h>
#include <iostream>
using namespace std;
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    GameWidget* spielobjekt;

private slots:
    void on_btnStart_clicked();

    void on_btnStop_clicked();

    void on_btnClear_clicked();

    void on_btnUniverseMode_currentIndexChanged(const QString &arg1);

    void on_btnCellMode_currentIndexChanged(const QString &arg1);

    void on_spinMS_valueChanged(const QString &arg1);

    void on_btnLoad_clicked();

    void on_btnSave_clicked();

    void on_btnSelectColor_clicked();

    void on_btnRandomColor_clicked();

    void on_btnGo_clicked();

    void on_spinUniverseSize_valueChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    int universeSize = 50;
};

#endif // MAINWINDOW_H
