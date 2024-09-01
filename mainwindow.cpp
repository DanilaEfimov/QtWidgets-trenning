#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"editor.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->clear(); // удалить скомпанованные виджеты
    on_toolButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_clicked()
{
    Editor* editor = new Editor(this); // связываем с виджетом, в которые его добавили
    QString name = "new doc " + QString::number(ui->tabWidget->count() + 1);
    ui->tabWidget->addTab(editor, name);
    int index = ui->tabWidget->count() - 1;
    ui->tabWidget->setCurrentIndex(index);
}


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    if(ui->tabWidget->count() > 1)
        ui->tabWidget->removeTab(index) ;
}

