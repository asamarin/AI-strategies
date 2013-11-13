#ifndef CASILLA_H
#define CASILLA_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QPoint>
#include <QGraphicsScene>
#include "common.h"
#include "rectangulin.h"

class Casilla {
private:
    qreal cellDiameter;
    QPoint coord; // TODO renombrar a coords
    tipoCasilla type;

    QGraphicsEllipseItem *ellipse;
    Rectangulin *rectangle;

public:
    Casilla();
    Casilla(const Casilla &c) { this->cellDiameter = c.cellDiameter; this->type = c.type; this->coord = c.coord; }
    Casilla(QPoint &p, tipoCasilla t, qreal d);
    bool operator ==(const Casilla &c) { return (this->coord == c.coord); }

    QPointF getPixelesCentrales() const;
    qreal getCellDiameter() const { return cellDiameter; }
    void getBla() const { qDebug() << "bla!"; }
    const QPoint& getCoords() const { return coord; }
    tipoCasilla getType() { return type; }
    bool isObstaculo() { return (this->getType() == obstaculo); }
    void draw(QGraphicsScene *tablero);
    void setType(tipoCasilla t) { type = t; }
    Rectangulin* getRectangle() const { return rectangle; }
};

#endif // CASILLA_H
