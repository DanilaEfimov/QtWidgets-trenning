#include"MyRect.h"

#include<QKeyEvent>

void MyRect::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Left){
        setPos(x()-10, y());
    }
    else if(event->key() == Qt::Key_Right){
        setPos(x()+10, y());
    }
    else if(event->key() == Qt::Key_Down){
        setPos(x(), y()+10);
    }
    else if(event->key() == Qt::Key_Up){
        setPos(x(), y()-10);
    }
}

/*
*-----------------------------------------------------------*
*  QGraphicsScene                                           *
*                                                           *
*                                                           *
*        *---------------------------------------*          *
*        *  QGraphicsView                        *          *
*        *                                       *          *
*        *                *------*               *          *
*        *                *      * MyRect        *          *
*        *                *------*               *          *
*        *                                       *          *
*        *                                       *          *
*        *---------------------------------------*          *
*                                                           *
*                                                           *
*                                                           *
*-----------------------------------------------------------*
*
*   Scene focused on Item; Item callBack keyPressEvent() function
*   Every Item in Qt application must be unique (it suve frome connect errors
*   between items)
*/
