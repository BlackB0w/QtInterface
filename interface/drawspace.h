#ifndef DRAWSPACE_H
#define DRAWSPACE_H

#include <QWidget>
#include <QPainter>

class DrawSpace : public QWidget
{
    Q_OBJECT
    QVector<QVector<int>> pic;
    QColor col;
    QPainter painter;
protected:
    void paintEvent(QPaintEvent *event) override;
public:
    explicit DrawSpace(QWidget *parent = nullptr);

    int getAmplitude() const;
    void setAmplitude(int newAmpitude);

    int getTime() const;
    void setTime(int newTime);

    const QColor &getCol() const;
    void setCol(const QColor &newCol);

    const QVector<QVector<int> > &getPic() const;
    void setPic(const QVector<QVector<int> > &newPic);
    void update();

signals:

};

#endif // DRAWSPACE_H
