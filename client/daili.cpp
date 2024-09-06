#include "daili.h"

daili::daili()
{

}


//重写了这个类中的函数，本来是会打印第四列
void daili::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QVariant ret = index.data();
    QImage image;
    if(ret == "done")
    {
        image.load(":/Functionpic/liked.png");
    }
    else if(ret == "undone")
    {
        image.load(":/Functionpic/unlike.png");
    }
    QRect rect = option.rect;
    rect.setLeft(866);
    rect.setRight(66);
    painter->drawImage(rect,image);

}

