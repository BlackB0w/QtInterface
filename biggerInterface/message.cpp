#include "message.h"

Message::Message(QString s, QString r, QString t)
{
    sender = s;
    reciever = r;
    text = t;
}

Message::Message(QString s, QString r, QString t, QList<QString> i)
{
    sender = s;
    reciever = r;
    text = t;
    imgs = i;
}

Message::Message(QString s, QString r, QString t, QList<QString> i, QList<QString> d)
{
    sender = s;
    reciever = r;
    text = t;
    imgs = i;
    docs = d;
}

const QString &Message::getText() const
{
    return text;
}

void Message::setText(const QString &newText)
{
    text = newText;
}

const QList<QString> &Message::getImgs() const
{
    return imgs;
}

void Message::setImgs(const QList<QString> &newImgs)
{
    imgs = newImgs;
}

const QList<QString> &Message::getDocs() const
{
    return docs;
}

void Message::setDocs(const QList<QString> &newDocs)
{
    docs = newDocs;
}

const QString &Message::getSender() const
{
    return sender;
}

void Message::setSender(const QString &newSender)
{
    sender = newSender;
}

const QString &Message::getReciever() const
{
    return reciever;
}

void Message::setReciever(const QString &newReciever)
{
    reciever = newReciever;
}
