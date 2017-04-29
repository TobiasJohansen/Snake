#ifndef MYRECT_H
#define MYRECT_H

#include <QObject>
#include <QGraphicsRectItem>

class MyRect : public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    MyRect();
    void keyPressEvent(QKeyEvent* event);
public slots:
    void move();
private:
    enum Direction{UP,LEFT,RIGHT,DOWN};
    Direction currentDirection;
    Direction previousDirection;
};

#endif // MYRECT_H
