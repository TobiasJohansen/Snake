#include "Snake.h"

Snake::Snake(QGraphicsScene& scene) : QGraphicsPixmapItem(), scene(scene), pixmapTail(":/images/tail.png"){
    currentDirection = RIGHT;
    previousDirection = RIGHT;

    QPixmap pixmapHead(":/images/head.png");

    setPos(90,0);
    setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    setFocus();
    setPixmap(pixmapHead.scaled(QSize(30, 30), Qt::IgnoreAspectRatio, Qt::FastTransformation));
    setTransformOriginPoint(15, 15);
    setRotation(90);
    scene.addItem(this);

    grow(60, 0);
    grow(30, 0);
    grow(0, 0);
}
void Snake::move(){
    for(int i = tailSize-1; i > 0; i--){
        tail.at(i)->setPos(tail.at(i-1)->pos());
    }
    tail.at(0)->setPos(pos());
}
void Snake::grow(){
    grow(tail.at(tailSize-1)->x(), tail.at(tailSize-1)->y());
}
bool Snake::willCollide(int x, int y){
    if(x < 0 || x > 570 || y < 0 || y > 570){
        return true;
    }else{
        if(x == this->x() && y == this->y()){
            return true;
        }
    }
    for(int i = 0; i < tailSize; i++){
        if(x == tail.at(i)->x() && y == tail.at(i)->y()){
            return true;
        }
    }
    return false;
}
Snake::Direction Snake::getCurrentDirection(){
    return currentDirection;
}
Snake::Direction Snake::getPreviousDirection(){
    return previousDirection;
}
void Snake::setPreviousDirection(Direction direction){
    previousDirection = direction;
}
void Snake::grow(int x, int y){
    QGraphicsPixmapItem* tailPart = new QGraphicsPixmapItem();
    tailPart->setPos(x,y);
    tailPart->setPixmap(pixmapTail.scaled(QSize(30, 30), Qt::IgnoreAspectRatio, Qt::FastTransformation));
    scene.addItem(tailPart);
    tail.push_back(tailPart);
    tailSize++;
}
void Snake::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_Up && !(previousDirection==DOWN)){
        currentDirection = UP;
    }
    if(event->key() == Qt::Key_Left && !(previousDirection==RIGHT)){
        currentDirection = LEFT;
    }
    if(event->key() == Qt::Key_Right && !(previousDirection==LEFT)){
        currentDirection = RIGHT;
    }
    if(event->key() == Qt::Key_Down && !(previousDirection==UP)){
        currentDirection = DOWN;
    }
}
