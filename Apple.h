#ifndef APPLE_H
#define APPLE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Apple: public QObject, public QGraphicsPixmapItem{
public:
    Apple(QGraphicsItem* parent=0);
};

#endif // APPLE_H
