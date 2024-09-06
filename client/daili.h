#ifndef DAILI_H
#define DAILI_H
#include<QStyledItemDelegate>
#include <QImage>
#include <QDebug>
#include <QPainter>

class daili : public QStyledItemDelegate
{
public:
    daili();
   void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

};

#endif // DAILI_H
