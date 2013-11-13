#include "busquedaheuristica.h"

#include <iostream>

BusquedaHeuristica::BusquedaHeuristica()
{
}

QList<Casilla> BusquedaHeuristica::getAdjacentCells(Tablero *tab, Casilla *center) {
    QList<Casilla> vecinas;
    int x = center->getCoords().x();
    int y = center->getCoords().y();

    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j) {
            if ((i != j) && (i != -j) &&
                    (x+i >= 0 && x+i < tab->getWidth()) &&
                    (y+j >= 0 && y+j < tab->getHeight())) {
                Casilla *vecina = tab->getCell(x+i, y+j);
                if (!vecina->isObstaculo()) {
                    vecinas.append(*vecina);
                }
            }
        }
    //qDebug() << "vecinas.size() = " << vecinas.size() << "\n";
    return vecinas;
}

Camino BusquedaHeuristica::search(Tablero *tab) {
    /*qDebug() << "BusquedaHeuristica::search";*/
    Camino path(tab->getInicio());
    path.setCosteEstimado(this->getEstimatedCost(path.ultimoNodo(), tab->getMeta()));
    openList.append(path);

    int iteracion = 0;
    int count_visitadas = 0;

    bool targetFound = false;
    while (!openList.empty() && !targetFound) {
        iteracion++;
        /*qDebug() << ">>> lista.size() = " << openList.size() << "\n";*/

        path = openList[0];

        if (tab->isObjetivo(path.ultimoNodo())) {
            targetFound = true;
            //break;
        } else {
            openList.pop_front();
            // Si existe mas de una trayectoria con el mismo nodo final en la lista cerrada,
            // eliminamos la de mayor coste
            if (closedList.contains(path)) {
                if (path < closedList[closedList.indexOf(path)]) {
                    closedList.removeAt(closedList.indexOf(path));  // cambiamos la vieja por
                    closedList.push_back(path);                     // la nueva trayectoria
                }
                // si no es de menor coste dejamos la vieja
            } else {                         // no hay ninguna trayectoria similar
                closedList.push_back(path);                         // introducimos la nueva
            }                                                       // trayectoria
            // Obtener nuevas trayectorias a partir de la ramificacion del ultimo
            // nodo de la trayectoria eliminada de la lista abierta
            QList<Casilla> neighbours = getAdjacentCells(tab, path.ultimoNodo());

            /*std::cout << "vecinas.size() = " << neighbours.size() << "\n";*/

            for (int i = 0; i < neighbours.size(); ++i) {
                /*std::cout << "vecinas[i].getCoords() = " << "(" <<
                    neighbours[i].getCoords().x() << "," << neighbours[i].getCoords().y() << ")" << "\n";*/

                Camino newpath(path);
                Casilla *neighbour = new Casilla(neighbours[i]);
                visited.append(*neighbour);
                newpath.addCellToPath(neighbour);

                if (closedList.contains(newpath)) {
                    continue;
                }

                newpath.setCosteEstimado(this->getEstimatedCost(newpath.ultimoNodo(), tab->getMeta()));
                if (openList.contains(newpath)) {
                    if (newpath < openList[openList.indexOf(newpath)]) {
                        openList.removeAt(openList.indexOf(newpath));
                        openList.push_back(newpath);
                    }
                } else {
                    openList.push_back(newpath);
                    count_visitadas++;
                }
            }
            // Ordenar la lista abierta en base al coste total estimado de cada trayectoria,
            // colocando la de minimo coste al inicio de la lista
            qSort(openList.begin(), openList.end());
        }
    }
    qDebug() << iteracion << " iteraciones ejecutadas;" << count_visitadas << " casillas visitadas.";
    if (targetFound) {
        qDebug() << path.getCosteTotal() << " casillas <- longitud del camino encontrado";
        qDebug() << "Solucion encontrada (HEUR)";
        return path;
    }
    else {
        qDebug() << "No hay solucion (HEUR)";
        return Camino(tab->getInicio());       // No hay solucion
    }
}

qreal BusquedaEuclidea::getEstimatedCost(Casilla *current, Casilla *target) {
    return sqrt(pow((double) target->getCoords().x() - current->getCoords().x(), 2.0) +
                pow((double) target->getCoords().y() - current->getCoords().y(), 2.0));
}

qreal BusquedaManhattan::getEstimatedCost(Casilla *current, Casilla *target) {
    /* El metodo manhattanLength() de la clase QPoint retorna esta distancia unicamente
       respecto al origen de coordenadas (no es posible indicarle un punto de referencia
       alternativo tal como "current"), por lo que es necesario hacer una conversion a
       un nuevo sistema de coordenadas en el que "current" ocupe el origen
    */
    /*QPoint currentAsOrigin(target->getCoords().x() - current->getCoords().x(),
                           target->getCoords().y() - current->getCoords().y());
    return currentAsOrigin.manhattanLength();*/
    return abs(target->getCoords().x() - current->getCoords().x()) +
            abs(target->getCoords().y() - current->getCoords().y());
}

qreal BusquedaMahalanobis::getEstimatedCost(Casilla *current, Casilla *target) {
    return std::max(abs(target->getCoords().x() - current->getCoords().x()),
               abs(target->getCoords().y() - current->getCoords().y()));
}
