#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "Game.h"

//"Forward declaration", to prevent circular dependency
class Game;

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = 0);
    void gameOver(int);
private:
    QGraphicsScene* scene;
    QGraphicsView* view;
    Game* game;
};

#endif // MAINWINDOW_H
