#ifndef BUSQUEDAHEURISTICA_H
#define BUSQUEDAHEURISTICA_H

#include <QList>
#include <cmath>
#include <algorithm>
#include "casilla.h"
#include "camino.h"
#include "tablero.h"

class BusquedaHeuristica
{
protected:
    QList<Camino> openList, closedList;
    QList<Casilla> visited;

    QList<Casilla> getAdjacentCells(Tablero *tab, Casilla *center);
public:
    BusquedaHeuristica();
    Camino search(Tablero *tab);
    virtual qreal getEstimatedCost(Casilla *current, Casilla *target) = 0;
};

class BusquedaEuclidea : public BusquedaHeuristica {
public:
    BusquedaEuclidea() { qDebug() << "\nBusqueda euclidea"; }
    qreal getEstimatedCost(Casilla *current, Casilla *target);
};

class BusquedaManhattan : public BusquedaHeuristica {
public:
    BusquedaManhattan() { qDebug() << "\nBusqueda manhattan"; }
    qreal getEstimatedCost(Casilla *current, Casilla *target);
};

class BusquedaMahalanobis : public BusquedaHeuristica {
public:
    BusquedaMahalanobis() { qDebug() << "\nBusqueda mahalanobis"; }
    qreal getEstimatedCost(Casilla *current, Casilla *target);
};

#endif // BUSQUEDAHEURISTICA_H
