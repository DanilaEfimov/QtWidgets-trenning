#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "General.h"

MenuBar* MainWindow::mainMenu = nullptr;
QIcon* MainWindow::icon = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Ways Editor");
    mainMenu = new MenuBar;
    this->setMenuBar(mainMenu->getMenuBar());
    ui->tabWidget->setTabText(0, "Notes");
    ui->tabWidget->setTabText(1, "Console");

    icon = new QIcon(ICON_PATH);
    this->setWindowIcon(*icon);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mainMenu;
}

void MainWindow::initIcon() {

}
