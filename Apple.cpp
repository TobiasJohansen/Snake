#include "Apple.h"

//The constructor calls the constructor of QGraphicsPixmapItem
Apple::Apple() : QGraphicsPixmapItem(){
    //Loads the image of an apple from a resource file
    QPixmap pixmap(":/images/apple.png");
    //Resizes it to the same size as the snake tiles
    setPixmap(pixmap.scaled(QSize(30, 30), Qt::IgnoreAspectRatio, Qt::FastTransformation));
}
