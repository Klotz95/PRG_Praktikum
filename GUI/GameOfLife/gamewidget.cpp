#include "gamewidget.h"
#include "qpainter.h"

GameWidget::GameWidget(QWidget* parent) {
}


//void GameWidget::setTimerIntervall (timer->setInterval(int))() {

//}
//void GameWidget::setUniverseSize (ca1.ResetWorldSize(int,int))() {

//}
void GameWidget::startGame() {

}
void GameWidget::stopGame() {

}
void GameWidget::clear() {

}
void GameWidget::newGeneration() {

}
void GameWidget::mousePressEvent() {

}
void GameWidget::mouseMoveEvent() {

}
void GameWidget::paintGrid() {
    update();
}
void GameWidget::paintUniverse() {

}

void GameWidget::paintEvent(QPaintEvent *event) {



    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QRect* rect;

    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
        rect = new QRect(i*20,j*20,20,20);
        if(i!= 10) {
            painter.fillRect(*rect, QBrush(Qt::red));
        }
        painter.drawRect(*rect);
        }
    }


    rect = new QRect(-50, -50, 100, 100);
    painter.setWindow(*rect);
    painter.drawRect(*rect);
    int side = qMin(width(), height());
     int x = (width() - side / 2);
     int y = (height() - side / 2);

     painter.setViewport(x, y, side, side);

     painter.end();
     update();
}
