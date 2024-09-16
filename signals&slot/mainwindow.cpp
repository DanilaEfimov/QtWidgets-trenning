#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("signals & slots");
/*
    this->h = new QHBoxLayout;
    this->v = new QVBoxLayout;
    this->main = new QVBoxLayout;

    this->okButton = new QPushButton("OK");
    this->cancelButton = new QPushButton("Cancel");

    this->login = new QLabel("Login");
    this->password = new QLabel("Password");

    this->h->addWidget(this->okButton);
    this->h->addWidget(this->cancelButton);

    this->v->addWidget(this->login);
    this->v->addWidget(this->password);

    this->main->addLayout(this->h);
    this->main->addLayout(this->v);

    this->setLayout(this->main);
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Ok button clicked";
}

