#ifndef MYRECT_H
#define MYRECT_H

#include "Apple.h"
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QBrush>
#include <QDebug>
#include <QPointF>
#include <stdlib.h>

class MyRect : public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    MyRect(QGraphicsScene&);
    void keyPressEvent(QKeyEvent* event);
public slots:
    void move();
private:
    void addPart();
    enum Direction{UP,LEFT,RIGHT,DOWN};
    Direction currentDirection;
    Direction previousDirection;
    QGraphicsScene& scene;
    QList<QGraphicsRectItem*> tail;
    //QGraphicsRectItem* food;
    Apple* food;

    QBrush* greenBrush;
    QBrush* redBrush;
};

#endif // MYRECT_H
