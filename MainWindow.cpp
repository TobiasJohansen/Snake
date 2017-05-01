#include "MainWindow.h"
#include "MyRect.h"

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
    MyRect* item = new MyRect(*scene);
    item->setRect(0, 0, 30, 30);
    item->setPos(90, 0);
    item->setFlag(QGraphicsItem::ItemIsFocusable);
    item->setFocus();
    scene->addItem(item);

    //Timer which runs the logic 4 times each second
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), item, SLOT(move()));
    timer->start(100);
}
MainWindow::~MainWindow(){}
