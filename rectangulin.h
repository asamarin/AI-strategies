#ifndef RECTANGULIN_H
#define RECTANGULIN_H

#include <QObject>
#include <QtGui>
#include "common.h"

class Rectangulin : public QObject, public QGraphicsRectItem
{
Q_OBJECT
public:
    explicit Rectangulin(QObject *parent = 0);
    Rectangulin(qreal x, qreal y, qreal w, qreal h) : QGraphicsRectItem(x, y, w, h) {}

signals:
    void clicked(int x, int y, tipoCasilla type);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // RECTANGULIN_H
