#include "rectangulin.h"

Rectangulin::Rectangulin(QObject *parent) :
    QObject(parent)
{
}

void Rectangulin::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QPointF *clickedCell = new QPointF(event->pos().x() / this->rect().width(),
                                       event->pos().y() / this->rect().height());
    QGraphicsRectItem::mousePressEvent(event);
    if (event->button() == Qt::RightButton) {
        emit clicked(clickedCell->x(), clickedCell->y(), vacio);
        qDebug() << "right ";
    } else if (event->button() == Qt::LeftButton) {
        emit clicked(clickedCell->x(), clickedCell->y(), obstaculo);
        qDebug() << "left ";
    }
    qDebug() << "clickety! [" << clickedCell->x() << "," << clickedCell->y() << "]";
    event->accept();
}
