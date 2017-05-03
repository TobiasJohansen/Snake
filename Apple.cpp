#include "Apple.h"

Apple::Apple() : QGraphicsPixmapItem(){
    QPixmap pixmap(":/images/apple.png");
    setPixmap(pixmap.scaled(QSize(30, 30), Qt::IgnoreAspectRatio, Qt::FastTransformation));
}
