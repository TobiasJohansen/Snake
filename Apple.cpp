#include "Apple.h"

Apple::Apple(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent){
    QPixmap pixmap(":/images/apple.png");
    setPixmap(pixmap.scaled(QSize(30, 30), Qt::IgnoreAspectRatio, Qt::FastTransformation));
}
