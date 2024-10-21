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
-delete in qt
*/

typedef QList<Test*> testList;

testList getList(){
    testList list;
    for(int i = 0; i < 5; i++){
        list.append(new Test());
        list.last()->setObjectName("Test " + QString::number(i));
    }
    return list;
}

void Display(testList list){
    foreach(Test* item, list){
        qInfo() << item;
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    testList list = getList();
    Display(list);

    qInfo() << "Deleting...";
    qDeleteAll(list.begin(), list.end());
    list.clear();

    Display(list);

    return a.exec();
}
