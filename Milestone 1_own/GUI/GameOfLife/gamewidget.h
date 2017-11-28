#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H
#include <cabase.h>
#include <qwidget.h>
#include <iostream>
using namespace std;


class GameWidget:  public QWidget
{
private:
    double rectHeight;
    double rectWidth;
    CAbase *cabase;
public:
     GameWidget(QWidget * parent);
    //void setTimerIntervall(timer->setInterval(int));
    //void setUniverseSize (ca1.ResetWorldSize(int,int));
    void startGame();
    void stopGame();
    void clear();
    void newGeneration();
    void mousePressEvent();
    void mouseMoveEvent();
    void paintGrid();
    void paintUniverse();
    void setRectHeight(int rectHeight);
    void setRectWidth(int rectWidth);
    CAbase getCAbase();

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
signals:

public slots:

};




#endif // GAMEWIDGET_H
