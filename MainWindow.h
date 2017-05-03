#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "Game.h"

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = 0);
    ~MainWindow();
private:
    QGraphicsScene* scene;
    QGraphicsView* view;
    Game* game;
};

#endif // MAINWINDOW_H
