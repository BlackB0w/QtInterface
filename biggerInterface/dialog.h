#ifndef DIALOG_H
#define DIALOG_H
#include <QList>
#include <message.h>

class Dialog
{
    QList <Message> msgs;
    QString name1;
    QString name2;
public:
    Dialog(QString n1, QString n2);
    void addMessage(Message msg);
    void delMessage(int index);
    int size();
    const QString &getName1() const;
    void setName1(const QString &newName1);
    const QString &getName2() const;
    void setName2(const QString &newName2);
    const QList<Message> &getMsgs() const;
};

#endif // DIALOG_H
