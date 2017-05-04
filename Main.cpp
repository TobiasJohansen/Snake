#include "MainWindow.h"
#include <QApplication>

int main(int argc, char* argv[]){
    //Initializes the application
    QApplication a(argc, argv);
    //Initializes the main window
    MainWindow w;
    //Shows the main window;
    w.show();
    //Runs the application
    return a.exec();
}
