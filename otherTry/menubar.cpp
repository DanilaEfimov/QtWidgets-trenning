#include<QDebug>
#include "menubar.h"

QMenu** MenuBar::menues = nullptr;
QAction** MenuBar::actions = nullptr;
QMenuBar* MenuBar::bar = nullptr;

MenuBar::MenuBar() {
    this->setVisible(true);

    initActions();
    initMenues();
    bindActions();
    bindMenues();

    this->bindActionSignals();
}

MenuBar::~MenuBar() {
    deleteActions();
    deleteMenues();
    delete bar;
}

//  ----------  ACCESSORS   ----------

QMenuBar *MenuBar::getMenuBar() {
    return bar;
}

QMenu *MenuBar::getMenu(uint index) {
    if(index >= menuc){
        return nullptr;
    }
    else{
        return menues[index];
    }
}

QAction *MenuBar::getAction(uint index) {
    if(index >= actc){
        return nullptr;
    }
    else{
        return actions[index];
    }
}

//  ----------  INITIALIZE  ----------

void MenuBar::initActions()
{
    actions = new QAction*[actc];
    for(uint i = 0; i < actc; i++){
        actions[i] = new QAction;
    }
    // set texts
    actions[0]->setText("New Session"); // for file menu
    actions[1]->setText("Save");
    actions[2]->setText("White theme"); // for view menu
    actions[3]->setText("Black theme");
    actions[4]->setText("Right mode");
    actions[5]->setText("Left mode");
    actions[6]->setText("Help");        // for line menu
    actions[7]->setText("History");

    // default is actived right mode & black theme:
    actions[3]->setCheckable(true);     // Black Theme
    actions[3]->setChecked(true);
    actions[4]->setCheckable(true);     // Right Mode
    actions[4]->setChecked(true);

    actions[2]->setCheckable(true);     // White Theme
    actions[5]->setCheckable(true);     // Left Mode
}

void MenuBar::initMenues()
{
    menues = new QMenu*[menuc];
    for(uint i = 0; i < menuc; i++){
        menues[i] = new QMenu;
    }
    // set names
    menues[0]->setTitle("File");
    menues[1]->setTitle("View");
    menues[2]->setTitle("Command line");
}

void MenuBar::bindActions()
{
    menues[0]->addAction(actions[0]);   // file menu
    menues[0]->addAction(actions[1]);
    menues[1]->addAction(actions[2]);   // view menu
    menues[1]->addAction(actions[3]);
    menues[1]->addAction(actions[4]);
    menues[1]->addAction(actions[5]);
    menues[2]->addAction(actions[6]);   // line menu
    menues[2]->addAction(actions[7]);
}

void MenuBar::bindMenues()
{
    bar = new QMenuBar;
    for(uint i = 0; i < menuc; i++){
        bar->addMenu(menues[i]);
    }
}

//  ----------  BINDING ----------

void MenuBar::bindActionSignals() {
    connect(actions[Names::whiteTheme], SIGNAL(whiteTheme()), actions[Names::blackTheme], SLOT(triggered(bool)));
    connect(actions[Names::blackTheme], SIGNAL(blackTheme()), actions[Names::whiteTheme], SLOT(triggered(bool)));
    connect(actions[Names::rightMode],  SIGNAL(rightMode()),  actions[Names::leftMode],   SLOT(triggered(bool)));
    connect(actions[Names::leftMode],   SIGNAL(leftMode()),   actions[Names::rightMode],  SLOT(triggered(bool)));
}

//  ----------  DESTRUCTING ----------

void MenuBar::deleteActions() {
    for(uint i = 0; i < actc; i++){
        delete actions[i];
    }
    delete[] actions;
}

void MenuBar::deleteMenues() {
    for(uint i = 0; i < menuc; i++){
        delete menues[i];
    }
    delete[] menues;
}

//  ----------  SIGNALS ----------

void MenuBar::newSession(){

}

void MenuBar::save(){

}

void MenuBar::whiteTheme(){
    bool state = actions[Names::whiteTheme]->isChecked();
    actions[Names::whiteTheme]->setChecked(!state);
    actions[Names::blackTheme]->setChecked(state);

    qDebug() << "WHITETHEME\n";
}

void MenuBar::blackTheme(){
    bool state = actions[Names::blackTheme]->isChecked();
    actions[Names::whiteTheme]->setChecked(state);
    actions[Names::blackTheme]->setChecked(!state);

    qDebug() << "BLACKTHEME\n";
}

void MenuBar::rightMode(){
    bool state = actions[Names::rightMode]->isChecked();
    actions[Names::rightMode]->setChecked(!state);
    actions[Names::leftMode]->setChecked(state);

    qDebug() << "RIGHTMODE\n";
}

void MenuBar::leftMode(){
    bool state = actions[Names::leftMode]->isChecked();
    actions[Names::rightMode]->setChecked(state);
    actions[Names::leftMode]->setChecked(!state);

    qDebug() << "LEFTMODE\n";
}

void MenuBar::help(){

}

void MenuBar::history(){

}
