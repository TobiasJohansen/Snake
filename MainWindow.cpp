#include "MainWindow.h"

//The constructor calls the constructor of QMainWindow and initializes the scene, the view and the game object
MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), scene(new QGraphicsScene(this)), view(new QGraphicsView(scene, this)), game(new Game(*scene, this)){
    //Window size
    setFixedSize(610, 650);
    //Add view to main window
    setCentralWidget(view);
}
void MainWindow::gameOver(int score){
    //Display a message box with game over message and players total score
    QMessageBox* msg = new QMessageBox(this);
    msg->setText("========== Game Over ==========");
    QString infoText;
    infoText.append("You received a total score of: ");
    infoText.append(QString::number(score));
    msg->setInformativeText(infoText);
    msg->exec();
    //Exit after the ok button is pressed
    exit(0);
}
