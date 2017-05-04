#ifndef GAME_H
#define GAME_H

#include "MainWindow.h"
#include <QObject>
#include <QGraphicsScene>
#include "Snake.h"
#include "Apple.h"
#include <stdlib.h>
#include <QTimer>
#include <QMessageBox>

//"Forward declaration", to prevent circular dependency
class MainWindow;

class Game : public QObject{
    Q_OBJECT
public:
    Game(QGraphicsScene&, MainWindow*);
public slots:
    void update();
private:
    QGraphicsScene& scene;
    MainWindow* mainWindow;
    Snake* snake;
    Apple* apple;
    QGraphicsTextItem* textItem;
    int score = 0;
    QTimer* timer;
    void moveSnake();
    void moveApple();
    void updateScore();
    void gameOver();
};
#endif // GAME_H
