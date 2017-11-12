#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H
#include <cabase.h>
#include <qwidget.h>


class GameWidget:  public QWidget
{

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

protected:
    void paintEvent(QPaintEvent *event);
signals:

public slots:

};




#endif // GAMEWIDGET_H
