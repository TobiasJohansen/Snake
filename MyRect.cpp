#include "MyRect.h"
#include <QKeyEvent>

MyRect::MyRect(){
    currentDirection = RIGHT;
    previousDirection = RIGHT;
}
void MyRect::move(){
    switch(currentDirection){
    case UP: if(!(y()-30 < 0)){setPos(x(),y()-30); previousDirection = UP;}; break;
    case LEFT: if(!(x()-30 < 0)){setPos(x()-30,y()); previousDirection = LEFT;}; break;
    case RIGHT: if(x()+30 < 600){setPos(x()+30, y()); previousDirection = RIGHT;}; break;
    case DOWN: if(y()+30 < 600){setPos(x(), y()+30); previousDirection = DOWN;}; break;
    }
}
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
