#include <QApplication>
#include<QTimer>
#include"test.h"

/*
Preregs:
-basic knowledge of c++ (pointers and memory manangment)
-VERY basic knowledge of Qt (widgets)
1 Tutorial topics:
-QGraphicsScene
-QGraphicsItem (at the scene can be located only such items)
-QGraphicsRectItem (..Item child, by the way ..Item is abstruct class)
-QGraphicsView
2 Tutorial topics:
-events (keyPressEvent() and QKeyEvent)
-event propogation system
-QDebug
3 Tutorial topics:
-Qt memory managment
-Parent child relationship
*/

// settings in the constructor
Test* getTest(QObject* parent){
    return new Test(parent);
    // no memory lossing
    // due to every Object is unique
    // very simple to find parent or revese
    // and delete all family
}

Test* getTest(){
    return new Test();
    // memory lossing
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTimer timer;
    timer.singleShot(3000, &a, &QCoreApplication::quit);

    Test* test = getTest(&a);
    test->setObjectName("Spot");

    Test* cat = getTest();
    cat->setObjectName("Cat");  // here cat not contained in parent tree Qt
    cat->setParent(&a);

    int value = a.exec();
    qInfo() << "Exit code: " << value;
    return value;
}
