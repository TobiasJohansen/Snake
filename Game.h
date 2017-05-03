#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QObject>
#include <QGraphicsScene>
#include "Snake.h"
#include "Apple.h"
#include <stdlib.h>
#include <QTimer>
#include <QMessageBox>

class Game : public QObject{
    Q_OBJECT
public:
    Game(QGraphicsScene&, QWidget*);
public slots:
    void update();
private:
    QGraphicsScene& scene;
    QWidget* widget;
    Snake* snake;
    Apple* apple;
    QTimer* timer;
    void moveSnake();
    void moveApple();
};
#endif // GAME_H
