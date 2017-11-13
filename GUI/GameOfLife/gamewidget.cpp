#include "gamewidget.h"
#include "qpainter.h"

GameWidget::GameWidget(QWidget* parent) {
    this->cabase = new CAbase(50, 50);
}

CAbase GameWidget::getCAbase() {
    return *cabase;
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

void GameWidget::setRectHeight(int rectHeight){
    this->rectHeight = rectHeight;
}
void GameWidget::setRectWidth(int rectWidth){
    this->rectWidth = rectWidth;
}

void GameWidget::resizeEvent(QResizeEvent *event) {
    int widgetWidth = width();
    int widgetHeight = height();

}

void GameWidget::paintEvent(QPaintEvent *event) {



    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QRect* rect;

    for(int i = 0; i < cabase->getNy(); i++) {
        for(int j = 0; j < cabase->getNx(); j++) {
        rect = new QRect(i*cabase->getNx(),j*cabase->getNy(), rectWidth, rectHeight);
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
