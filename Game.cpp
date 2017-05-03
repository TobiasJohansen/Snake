#include "Game.h"

Game::Game(QGraphicsScene& scene, QWidget* widget) : QObject(), scene(scene), widget(widget), snake(new Snake(scene)){

    //add walls
    QGraphicsRectItem* wall = new QGraphicsRectItem();
    wall->setRect(0, 0, 600, 600);
    wall->setZValue(-1);
    wall->setBrush(QColor(238, 217, 117));
    scene.addItem(wall);

    //add apple
    apple = new Apple();
    moveApple();
    scene.addItem(apple);

    //start game
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(100);
}
void Game::update(){
    moveSnake();
    if(snake->pos() == apple->pos()){
       snake->grow();
       moveApple();
    }
}
void Game::moveSnake(){
    switch(snake->getCurrentDirection()){
    case Snake::UP:
        if(!snake->willCollide(snake->x(), snake->y()-30)){
            snake->setRotation(0);
            snake->move();
            snake->setPos(snake->x(), snake->y()-30);
            snake->setPreviousDirection(Snake::UP);
        }else{
            disconnect(timer, SIGNAL(timeout()), this, SLOT(update()));
            QMessageBox* msg = new QMessageBox(widget);
            msg->setText("GAME OVER         ");
            msg->exec();
        }
        break;
    case Snake::LEFT:
        if(!snake->willCollide(snake->x()-30, snake->y())){
            snake->setRotation(-90);
            snake->move();
            snake->setPos(snake->x()-30, snake->y());
            snake->setPreviousDirection(Snake::LEFT);
        }else{
            disconnect(timer, SIGNAL(timeout()), this, SLOT(update()));
            QMessageBox* msg = new QMessageBox(widget);
            msg->setText("GAME OVER         ");
            msg->exec();
        }
        break;
    case Snake::RIGHT:
        if(!snake->willCollide(snake->x()+30, snake->y())){
            snake->setRotation(90);
            snake->move();
            snake->setPos(snake->x()+30, snake->y());
            snake->setPreviousDirection(Snake::RIGHT);
        }else{
            disconnect(timer, SIGNAL(timeout()), this, SLOT(update()));
            QMessageBox* msg = new QMessageBox(widget);
           msg->setText("GAME OVER         ");
            msg->exec();
        }
        break;
    case Snake::DOWN:
        if(!snake->willCollide(snake->x(), snake->y()+30)){
            snake->setRotation(180);
            snake->move();
            snake->setPos(snake->x(), snake->y()+30);
            snake->setPreviousDirection(Snake::DOWN);
        }else{
            disconnect(timer, SIGNAL(timeout()), this, SLOT(update()));
            QMessageBox* msg = new QMessageBox(widget);
            msg->setText("GAME OVER         ");
            msg->exec();
        }
        break;
    }
}
void Game::moveApple(){
    int x;
    int y;
    do{
    x = (rand() % 20) * 30;
    y = (rand() % 20) * 30;
    }while(snake->willCollide(x, y));
    apple->setPos(x,y);
}
