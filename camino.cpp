#include "camino.h"
#include <iostream>

Camino::Camino() {
    this->costoEstimado = 0.0;
}

Camino::Camino(Casilla *start)
{
    this->costoEstimado = 0.0;
    this->path.clear();

    Nodo nodo;
    nodo.cell = start;
    this->path.append(nodo);

    previo = nodo;
}

void Camino::addCellToPath(Casilla *c)
{
    //std::cout << "path.size() = " << path.size() << "\n";
    previo = path.last();

    Nodo nodo;
    QLineF l(c->getPixelesCentrales(), previo.cell->getPixelesCentrales());
    nodo.line = l;
    nodo.cell = c;

    this->path.append(nodo);
}

void Camino::drawPath(QGraphicsScene *tablero, QColor color)
{
    QPen pen(color);
    pen.setWidth(2);
    //std::cout << "LARUTA.size() = " << path.size() << "\n";
    //std::cout << "linea 1 = " << path[0].line.dx() << "," << path[0].line.dy() << "\n";

    for (int i = 0; i < path.size(); ++i)
        tablero->addLine(path[i].line, pen);
}

bool operator<(const Camino &a, const Camino &b) {
    return a.getCosteTotal() < b.getCosteTotal();
}

bool operator>(const Camino &a, const Camino &b) {
    return a.getCosteTotal() > b.getCosteTotal();
}

bool operator==(const Camino &a, const Camino &b) {
    return a.path.last().cell->getCoords() == b.path.last().cell->getCoords();
}
