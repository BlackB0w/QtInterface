#include "dialog.h"

const QString &Dialog::getName1() const
{
    return name1;
}

void Dialog::setName1(const QString &newName1)
{
    name1 = newName1;
}

const QString &Dialog::getName2() const
{
    return name2;
}

void Dialog::setName2(const QString &newName2)
{
    name2 = newName2;
}

const QList<Message> &Dialog::getMsgs() const
{
    return msgs;
}

Dialog::Dialog(QString n1, QString n2)
{
    name1 = n1;
    name2 = n2;
}

void Dialog::addMessage(Message msg)
{
    msgs.push_back(msg);
}

void Dialog::delMessage(int index)
{
    msgs.removeAt(index);
}

int Dialog::size()
{
    return msgs.size();
}
