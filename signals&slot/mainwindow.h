#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QLabel>
#include<QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
/*
    QHBoxLayout* h;
    QVBoxLayout* v;
    QVBoxLayout* main;

    QPushButton* okButton;
    QPushButton* cancelButton;

    QLabel* login;
    QLabel* password;
*/
};
#endif // MAINWINDOW_H
