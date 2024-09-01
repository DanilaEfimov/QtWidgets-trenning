#ifndef EDITOR_H
#define EDITOR_H

#include <QObject>
#include <QWidget>
#include<QVBoxLayout>
#include<QComboBox>
#include<QPlainTextEdit>

class Editor : public QWidget
{
    Q_OBJECT
public:
    explicit Editor(QWidget *parent = nullptr);
private:
    QVBoxLayout* box;
    QComboBox* combo;
    QPlainTextEdit* edit;

signals:

};

#endif // EDITOR_H
