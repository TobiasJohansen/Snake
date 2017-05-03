#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <vector>
#include <QKeyEvent>

class Snake : public QGraphicsPixmapItem{
public:
    Snake(QGraphicsScene&);
    void move();
    void grow();
    bool willCollide(int, int);
    enum Direction {UP,LEFT,RIGHT,DOWN};
    Direction getCurrentDirection();
    Direction getPreviousDirection();
    void setPreviousDirection(Direction);
private:
    QGraphicsScene& scene;
    QPixmap pixmapTail;
    Direction currentDirection;
    Direction previousDirection;
    std::vector<QGraphicsPixmapItem*> tail;
    int tailSize = 0;
    void grow(int, int);
    void keyPressEvent(QKeyEvent* event);
};

#endif // SNAKE_H
