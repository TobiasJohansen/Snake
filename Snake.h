#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <vector>
#include <QKeyEvent>

class Snake : public QGraphicsPixmapItem{
public:
    Snake(QGraphicsScene&);
    void move();
    void grow();
    bool willCollide(int, int);
    enum Direction {NONE,UP,LEFT,RIGHT,DOWN};
    Direction getCurrentDirection();
    Direction getPreviousDirection();
    void setPreviousDirection(Direction);
private:
    QGraphicsScene& scene;
    QPixmap pixmapTail;
    Direction currentDirection;
    Direction previousDirection;
    std::vector<QGraphicsPixmapItem*> tail;
    void grow(int, int);
    void keyPressEvent(QKeyEvent* event);
};

#endif // SNAKE_H
