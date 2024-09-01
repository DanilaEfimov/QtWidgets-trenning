#ifndef MENUBAR_H
#define MENUBAR_H

#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QString>

// Menu bar system
class MenuBar : public QMenuBar
{
private:
    static QMenuBar* bar;

    static uint menuc;
    static QMenu* menuv;

    static uint actc;
    static QAction* actv;

public:
    MenuBar(uint menc, uint actsc);
    ~MenuBar();

    // Seters
    static void setAction(uint menu_index, QAction* act);
    static void setSlot(QAction* act, QMenu* menu, void* signal, void* slot);
    static void setActionName(QAction* act, const QString name);
    static void setMenuName(uint menu_index, const QString name);
};

#endif // MENUBAR_H
