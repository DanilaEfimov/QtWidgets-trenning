#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << "Constructed" << parent;
}

Test::~Test() {
    qInfo() << this << "Destructed" << this->parent();
}

void Test::massege(QString value)
{
    qInfo() << value;
}
