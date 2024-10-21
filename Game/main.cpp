#include <QApplication>
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
4 Tutorial topics:
-qDeleteAll
-deleting in qt
5 Tutorial topics:
-QScopePoiter (it's like general pointer)
-QSharedPointer
https://www.qt.io/blog/2009/00/25/count-with-me-how-many-smart-pointer-classes-does-qt-have
*/

#include<QScopedPointer>

void TestScope(){
    QScopedPointer<Test> ptr(new Test());
    ptr->massege("Hello");
}

void finish(QSharedPointer<Test> ptr){
    ptr->massege("Finishing");
}

void work(QSharedPointer<Test> ptr){
    ptr->massege("Working");
}

void step(QSharedPointer<Test> ptr){
    ptr->massege("Stepping");
    for(int i = 0; i < 3; i++){
        work(ptr);
    }
}

void TestShared(Test* test){
    QSharedPointer<Test> ptr(test);
    ptr->massege("Starting");
    step(ptr);
    finish(ptr);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   // TestScope();
    TestShared(new Test());

    return a.exec();
}
