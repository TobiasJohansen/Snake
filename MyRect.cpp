#include "MyRect.h"
#include <QKeyEvent>

MyRect::MyRect(){
    direction = RIGHT;
}
void MyRect::move(){
    switch(direction){
    case UP: if(!(y()-30 < 0)){setPos(x(),y()-30);}; break;
    case LEFT: if(!(x()-30 < 0)){setPos(x()-30,y());}; break;
    case RIGHT: if(x()+30 < 600){setPos(x()+30, y());}; break;
    case DOWN: if(y()+30 < 600){setPos(x(), y()+30);}; break;
    }
}
void MyRect::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_Up && !(direction==DOWN)){
        direction = UP;
    }
    if(event->key() == Qt::Key_Left && !(direction==RIGHT)){
        direction = LEFT;
    }
    if(event->key() == Qt::Key_Right && !(direction==LEFT)){
        direction = RIGHT;
    }
    if(event->key() == Qt::Key_Down && !(direction==UP)){
        direction = DOWN;
    }
}
