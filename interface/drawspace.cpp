#include "drawspace.h"


const QColor &DrawSpace::getCol() const
{
    return col;
}

void DrawSpace::setCol(const QColor &newCol)
{
    col = newCol;
}

const QVector<QVector<int> > &DrawSpace::getPic() const
{
    return pic;
}

void DrawSpace::setPic(const QVector<QVector<int> > &newPic)
{
    pic = newPic;
    repaint();
}


void DrawSpace::paintEvent(QPaintEvent *event)
{
    painter.begin(this);
    painter.setPen(QPen(col,2));
    painter.setBrush(QBrush(QColor(255,255,255)));
    painter.drawRect(0,0,width(),height());
    for(int i =0; i< pic.size();i++){
        painter.drawLine(pic[i][0],height()/2-pic[i][1],pic[i][0],height()/2+pic[i][1]);
    }
    painter.end();
}

DrawSpace::DrawSpace(QWidget *parent) : QWidget(parent)
{
    col = QColor(0,0,0);
    for (int i = 0;i<500 ;i++ ) {
        pic.push_back(QVector<int>({i,0}));
    }
}
