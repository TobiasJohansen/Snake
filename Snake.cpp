#include "Snake.h"

//The constructor calls the constructor of QGraphicsPixmapItem and initializes the variables scene and pixmapTail, pixmapTail is a pixmap of the snake's body
Snake::Snake(QGraphicsScene& scene) : QGraphicsPixmapItem(), scene(scene), pixmapTail(":/images/tail.png"){
    //Sets the current direction to none and previous direction of the snake to right
    currentDirection = NONE;
    previousDirection = RIGHT;

    //Loads the pixmap for the snake head
    QPixmap pixmapHead(":/images/head.png");

    //Sets the start position for the snake head
    setPos(90,0);
    //Sets the head to be focusable and focuses it (to enable keypressevents)
    setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    setFocus();
    //Scales the snake head to the correct tile size
    setPixmap(pixmapHead.scaled(QSize(30, 30), Qt::IgnoreAspectRatio, Qt::FastTransformation));
    //Rotates the head to look to the right
    setTransformOriginPoint(15, 15);
    setRotation(90);
    //Adds the snakehead to the scene
    scene.addItem(this);

    //Adds three body parts to the snake
    grow(60, 0);
    grow(30, 0);
    grow(0, 0);
}
void Snake::move(){
    //Move each bodypart to the position of the next
    for(int i = tail.size()-1; i > 0; i--){
        tail.at(i)->setPos(tail.at(i-1)->pos());
    }
    //Move the part closest to the head to the heads position
    tail.at(0)->setPos(pos());
}
void Snake::grow(){
    //Add a bodypart at the location of the last bodypart
    grow(tail.at(tail.size()-1)->x(), tail.at(tail.size()-1)->y());
}
bool Snake::willCollide(int x, int y){
    //Checks if the the object will collide with the wall
    if(x < 0 || x > 570 || y < 0 || y > 570){
        return true;
    }
    //Checks if the object will collide with the snake head
    if(x == this->x() && y == this->y()){
        return true;
    }
    //Checks if the object will collide with the snake's tail
    for(int i = 0; i < (int) tail.size(); i++){
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
    //Creates a new bodypart which is added to the scene and vector of bodyparts
    QGraphicsPixmapItem* bodyPart = new QGraphicsPixmapItem();
    bodyPart->setPos(x,y);
    bodyPart->setPixmap(pixmapTail.scaled(QSize(30, 30), Qt::IgnoreAspectRatio, Qt::FastTransformation));
    scene.addItem(bodyPart);
    tail.push_back(bodyPart);
}
void Snake::keyPressEvent(QKeyEvent* event){
    //Sets the current direction to input from keyboard, but only if the last move was NOT the opposite of the input
    if(event->key() == Qt::Key_Up && !(previousDirection==DOWN)){
        currentDirection = UP;
    }else if(event->key() == Qt::Key_Left && !(previousDirection==RIGHT)){
        currentDirection = LEFT;
    }else if(event->key() == Qt::Key_Right && !(previousDirection==LEFT)){
        currentDirection = RIGHT;
    }else if(event->key() == Qt::Key_Down && !(previousDirection==UP)){
        currentDirection = DOWN;
    //If spacebar is pressed, pause
    }else if(event->key() == Qt::Key_Space){
        currentDirection = NONE;
    }
}
