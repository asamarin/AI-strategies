#ifndef CAMINO_H
#define CAMINO_H

#include <QtCore>
#include <QtGui>
#include <QList>
#include "casilla.h"
#include "tablero.h"

class Nodo
{
public:
    Casilla *cell;
    QLineF line;
};


class Camino
{
private:
    QList<Nodo> path;
    Nodo previo;
    qreal costoEstimado;

public:
    Camino();
    Camino(Casilla *start);
    Camino(const Camino &c) { this->path = c.path; this->previo = c.previo; this->costoEstimado = c.costoEstimado; }
    void addCellToPath(Casilla *c);
    Casilla* ultimoNodo() { return path.last().cell; }
    Casilla* getCasillaVisitada() { return previo.cell; }
    void setCosteEstimado(qreal c) { costoEstimado = c; }
    qreal getCosteTotal() const { return (qreal) path.length() + costoEstimado; }
    void drawPath(QGraphicsScene *tablero, QColor color);
    friend bool operator<(const Camino &a, const Camino &b);
    friend bool operator>(const Camino &a, const Camino &b);
    friend bool operator==(const Camino &a, const Camino &b);
};

#endif // CAMINO_H
