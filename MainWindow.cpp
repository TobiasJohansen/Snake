#include "MainWindow.h"
#include "MyRect.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent){

    //Window init
    QGraphicsScene* scene = new QGraphicsScene(this);
    QGraphicsView* view = new QGraphicsView(scene, this);
    setFixedSize(610, 610);
    setCentralWidget(view);

    //Walls
    QGraphicsRectItem* wall = new QGraphicsRectItem();
    wall->setRect(0, 0, 600, 600);
    scene->addItem(wall);

    //"Snake"
    MyRect* item = new MyRect();
    item->setRect(0, 0, 30, 30);
    item->setFlag(QGraphicsItem::ItemIsFocusable);
    item->setFocus();
    scene->addItem(item);

    //Timer which runs the logic 4 times each second
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), item, SLOT(move()));
    timer->start(250);
}
MainWindow::~MainWindow(){}
