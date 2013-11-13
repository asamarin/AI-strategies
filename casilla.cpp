#include "casilla.h"

Casilla::Casilla(QPoint &p, tipoCasilla t, qreal d)
{
    this->coord = p;
    this->type = t;
    this->cellDiameter = d;
}

QPointF Casilla::getPixelesCentrales() const
{
    qreal x = (this->coord.x() * this->cellDiameter) + this->cellDiameter / 2;
    qreal y = (this->coord.y() * this->cellDiameter) + this->cellDiameter / 2;
    return QPointF(x, y);
}

void Casilla::draw(QGraphicsScene *tablero)
{
    //obstacleBrush.setStyle(Qt::DiagCrossPattern);
    penClaro.setWidth(3);
    pen.setWidth(1);

    rectangle = new Rectangulin(coord.x() * cellDiameter, coord.y() * cellDiameter,
                                cellDiameter, cellDiameter);
    rectangle->setPen(pen);

    switch(this->type) {
    case vacio:
        rectangle->setBrush(lightBrush);
        tablero->addItem(rectangle);
        break;
    case obstaculo:
        rectangle->setBrush(obstacleBrush);
        tablero->addItem(rectangle);
        break;
    case objetivo:
        rectangle->setBrush(targetBrush);
        tablero->addItem(rectangle);
        break;
    case robot:
        rectangle->setBrush(robotBrush);
        tablero->addItem(rectangle);
        //tablero->addEllipse(coord.x() * cellDiameter * FACTOR_CORRECCION + 1,
        //                    coord.y() * cellDiameter * FACTOR_CORRECCION + 1,
        //                    cellDiameter * 0.9, cellDiameter * 0.9,
        //                    pen, robotBrush);
        break;
    default:
        qDebug() << "!";
    }
}
