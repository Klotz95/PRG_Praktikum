#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <gamewidget.h>

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


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
