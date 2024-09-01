#include "menubar.h"

QMenuBar* MenuBar::bar = nullptr;
uint MenuBar::menuc = 0;
QMenu* MenuBar::menuv = nullptr;
uint MenuBar::actc = 0;
QAction* MenuBar::actv = nullptr;

MenuBar::MenuBar(uint menc, uint actsc) {
    this->bar = new QMenuBar();
    this->menuc = menc;
    this->menuv = new QMenu[this->menuc];
    this->actc = actsc;
    this->actv = new QAction[this->actc];

    this->setMenuName(0, "File");
}

MenuBar::~MenuBar()
{
    delete this->actv;
    delete this->menuv;
    delete this->bar;
}

// Setters
void MenuBar::setAction(uint menu_index, QAction* act) {
    if(menu_index < menuc){
        menuv[menu_index].addAction(act);
    }
}

void MenuBar::setSlot(QAction *act, QMenu* menu, void *signal, void *slot) {
    QAction::connect(menu, SIGNAL(signal()), act, SLOT(slot()));
}

void MenuBar::setActionName(QAction *act, const QString name) {
    act->setText(name);
}

void MenuBar::setMenuName(uint menu_index, const QString name) {
    if(menu_index < menuc){
        menuv[menu_index].setTitle(name);
    }
}
