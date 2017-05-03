#include "MainWindow.h"
#include "MyRect.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), scene(new QGraphicsScene(this)), view(new QGraphicsView(scene, this)){
    setFixedSize(610, 610);
    scene->setBackgroundBrush(Qt::black);
    setCentralWidget(view);
    game = new Game(*scene, parent);
}
MainWindow::~MainWindow(){}
