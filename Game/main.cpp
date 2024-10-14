#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>

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
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene* scene = new QGraphicsScene();

    // create an item to put into scene
    MyRect* rect = new MyRect(); // default 0 by 0 px
    rect->setRect(0,0, 100, 100); // _x, _y width, height

    // add the item to the scene
    scene->addItem(rect);

    // make rect focussible
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    // here we actually nothing see

    // add a view
    QGraphicsView* view = new QGraphicsView(scene);
    // synonym: view->setScene(scene);

    // default QGraphicsView is a widget and invisible
    view->show();

    return a.exec();
}
