#ifndef MESSAGE_H
#define MESSAGE_H
#include <QString>
#include <QList>
class Message
{
    QString sender;
    QString reciever;
    QString text;
    QList<QString> imgs;
    QList<QString> docs;
public:
    Message(QString s, QString r, QString t);
    Message(QString s, QString r, QString t, QList<QString> i);
    Message(QString s, QString r, QString t, QList<QString> i,QList<QString> d);
    const QString &getText() const;
    void setText(const QString &newText);
    const QList<QString> &getImgs() const;
    void setImgs(const QList<QString> &newImgs);
    const QList<QString> &getDocs() const;
    void setDocs(const QList<QString> &newDocs);
    const QString &getSender() const;
    void setSender(const QString &newSender);
    const QString &getReciever() const;
    void setReciever(const QString &newReciever);
};

#endif // MESSAGE_H
