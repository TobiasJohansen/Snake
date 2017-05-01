#include "MyRect.h"

MyRect::MyRect(QGraphicsScene& scene) : scene(scene){
    //Current moving direction and direction previously moved
    currentDirection = RIGHT;
    previousDirection = RIGHT;

    greenBrush = new QBrush(Qt::green);
    redBrush = new QBrush(Qt::red);

    setBrush(greenBrush->color());

    //3 snake parts added to scene and list
    QGraphicsRectItem* item1 = new QGraphicsRectItem();
    item1->setRect(0, 0, 30, 30);
    item1->setPos(60, 0);
    item1->setBrush(greenBrush->color());
    scene.addItem(item1);
    tail.prepend(item1);

    QGraphicsRectItem* item2 = new QGraphicsRectItem();
    item2->setRect(0, 0, 30, 30);
    item2->setPos(30, 0);
    item2->setBrush(greenBrush->color());
    scene.addItem(item2);
    tail.prepend(item2);

    QGraphicsRectItem* item3 = new QGraphicsRectItem();
    item3->setRect(0, 0, 30, 30);
    item3->setPos(0, 0);
    scene.addItem(item3);
    item3->setBrush(greenBrush->color());
    tail.prepend(item3);

    food = new Apple();
    food->setPos(120, 120);
    scene.addItem(food);
}
void MyRect::move(){
    bool crashed = false;
    //checking input direction
    switch(currentDirection){
    case UP:
        for(int i = 0; i < tail.length(); i++){
            if(tail.at(i)->y() == y()-30 && tail.at(i)->x() == x()){
                crashed = true;
            }
        }
        //checking if next move will crash with wall
        if(!(y()-30 < 0) && !crashed){
            addPart();
            setPos(x(), y()-30);
            //setting the previous move direction
            previousDirection = UP;
        }
        break;
    case LEFT:
        for(int i = 0; i < tail.length(); i++){
            if(tail.at(i)->x() == x()-30 && tail.at(i)->y() == y()){
                crashed = true;
            }
        }
        if(!(x()-30 < 0) && !crashed){
            addPart();
            setPos(x()-30, y());
            previousDirection = LEFT;
        }
        break;
    case RIGHT:
        for(int i = 0; i < tail.length(); i++){
            if(tail.at(i)->x() == x()+30 && tail.at(i)->y() == y()){
                crashed = true;
            }
        }
        if(x()+30 < 600 && !crashed){
            addPart();
            setPos(x()+30, y());
            previousDirection = RIGHT;
        }
        break;
    case DOWN:
        for(int i = 0; i < tail.length(); i++){
            if(tail.at(i)->y() == y()+30 && tail.at(i)->x() == x()){
                crashed = true;
            }
        }
        if(y()+30 < 600 && !crashed){
            addPart();
            setPos(x(), y()+30);
            previousDirection = DOWN;
        }
        break;
    }
}

void MyRect::addPart(){
    for(int i = 0; i < tail.length()-1; i++){
        tail.at(i)->setPos(tail.at(i+1)->pos());
    }
    tail.at(tail.length()-1)->setPos(pos());
    if(pos() == food->pos()){
        QGraphicsRectItem* item3 = new QGraphicsRectItem();
        item3->setRect(0, 0, 30, 30);
        item3->setPos(tail.at(0)->pos());
        item3->setBrush(greenBrush->color());
        scene.addItem(item3);
        tail.prepend(item3);

        int x;
        int y;

        bool exists;
        do{
            exists = false;
            x = (rand() % 20) * 30;
            y = (rand() % 20) * 30;
            QPointF point(x, y);
            for(int i = 0; i < tail.length(); i++){
                if(tail.at(i)->pos() == point){
                    exists = true;
                }
            }
        }while(exists);
        food->setPos(x,y);
    }
}

//checking user input, setting new move direction only if it is not the opposite of last moved
void MyRect::keyPressEvent(QKeyEvent* event){
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
