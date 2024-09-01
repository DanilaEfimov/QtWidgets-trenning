#include "editor.h"

Editor::Editor(QWidget *parent)
    : QWidget{parent}
{
    this->box = new QVBoxLayout(this); // чтобы заполнил собой все пространство, привязка к виджету
    this->combo = new QComboBox(this);
    this->edit = new QPlainTextEdit(this);
    // по дефолту они все на нулевых координатах в виджете
    this->box->addWidget(this->combo);
    this->box->addWidget(this->edit);
}
