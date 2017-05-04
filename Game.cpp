#include "Game.h"

//The constructor calls the constructor of QObject and initializes the variables scene and mainWindow as well as creating a new Snake
Game::Game(QGraphicsScene& scene, MainWindow* mainWindow) : QObject(), scene(scene), mainWindow(mainWindow), snake(new Snake(scene)){
    //Add an apple to a random position
    apple = new Apple();
    moveApple();
    scene.addItem(apple);

    //Display current score
    QString text;
    text.append("Current Score: ");
    text.append(QString::number(score));
    textItem = scene.addText(text);
    textItem->setScale(2);
    textItem->setPos(0, -40);

    //Add walls and background color
    QGraphicsRectItem* wall = new QGraphicsRectItem();
    wall->setRect(0, 0, 600, 600);
    wall->setZValue(-1);
    wall->setBrush(QColor(238, 217, 117));
    scene.addItem(wall);

    //Counts down until timeout
    timer = new QTimer();
    //When the timer times out, run the update function in this class
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    //This will happen each 100 ms
    timer->start(100);
}
void Game::update(){
    //Move the snake
    moveSnake();
    //Check if snake hit apple
    if(snake->pos() == apple->pos()){
        //Make snake grow, move apple and update score
        snake->grow();
        moveApple();
        updateScore();
    }
}
void Game::moveSnake(){
    //Check which direction the snake is going to move
    switch(snake->getCurrentDirection()){
    case Snake::UP:
        //Checks if the snake will collide with wall or itself if it moves 30 pixels down
        if(!snake->willCollide(snake->x(), snake->y()-30)){
            //If not, rotate the head to look up, move its body and set the new position of the head
            snake->setRotation(0);
            snake->move();
            snake->setPos(snake->x(), snake->y()-30);
            //The latest move made by the snake was in the upwards direction
            snake->setPreviousDirection(Snake::UP);
        }else{
            //If the snake collided with itself or the wall, call the game over function
            gameOver();
        }
        break;
    case Snake::LEFT:
        if(!snake->willCollide(snake->x()-30, snake->y())){
            snake->setRotation(-90);
            snake->move();
            snake->setPos(snake->x()-30, snake->y());
            snake->setPreviousDirection(Snake::LEFT);
        }else{
            gameOver();
        }
        break;
    case Snake::RIGHT:
        if(!snake->willCollide(snake->x()+30, snake->y())){
            snake->setRotation(90);
            snake->move();
            snake->setPos(snake->x()+30, snake->y());
            snake->setPreviousDirection(Snake::RIGHT);
        }else{
            gameOver();
        }
        break;
    case Snake::DOWN:
        if(!snake->willCollide(snake->x(), snake->y()+30)){
            snake->setRotation(180);
            snake->move();
            snake->setPos(snake->x(), snake->y()+30);
            snake->setPreviousDirection(Snake::DOWN);
        }else{
            gameOver();
        }
        break;
    //Dont move
    case Snake::NONE:
        break;
    }
}
void Game::moveApple(){
    int x;
    int y;
    do{
        //Calculate coordinates for the apple from (0,0) to (570, 570)
        x = (rand() % 20) * 30;
        y = (rand() % 20) * 30;
    //Do this until coordinates does not collide with any existing game objects
    }while(snake->willCollide(x, y));
    //Move the apple to calculated position
    apple->setPos(x,y);
}
void Game::updateScore(){
    //Increase score by 10 points and update the score display
    score += 10;
    QString text;
    text.append("Current Score: ");
    text.append(QString::number(score));
    textItem->setPlainText(text);
}
void Game::gameOver(){
    //Stop the game from running and call the game over function in main window
    disconnect(timer, SIGNAL(timeout()), this, SLOT(update()));
    mainWindow->gameOver(score);
}
