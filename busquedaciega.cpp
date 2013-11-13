#include "busquedaciega.h"
#include <iostream>

QList<Casilla> BusquedaCiega::dameCasillasVecinas(Tablero *tab, Casilla *centro) {
    QList<Casilla> vecinas;
    int x = centro->getCoords().x();
    int y = centro->getCoords().y();

    //qDebug() << "ancho = " << tab->getWidth() << "; alto = " << tab->getHeight();

    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j) {
            if ((i != j) && (i != -j) &&
                    (x+i >= 0 && x+i < tab->getWidth()) &&
                    (y+j >= 0 && y+j < tab->getHeight())) {
                Casilla *vecina = tab->getCell(x+i, y+j);
                if (!vecina->isObstaculo() && !visitadas.contains(*vecina)) {
                    vecinas.append(*vecina);
                }
            }
        }
    //qDebug << "vecinas.size() = " << vecinas.size() << "\n";
    return vecinas;
}

Camino BusquedaCiega::buscar(Tablero *tab)
{
    Camino trayectoria(tab->getInicio());
    lista.append(trayectoria);

    int iteracion = 0;
    int visited = 0;

    bool objetivoEncontrado = false;
    while (!lista.empty() && !objetivoEncontrado ) {
        iteracion++;
        /*std::cout << ">>> lista.size() = " << lista.size() << "\n";*/
        trayectoria = lista[0];
        lista.pop_front();

        if (tab->isObjetivo(trayectoria.ultimoNodo())) {
            objetivoEncontrado = true;
            //break;
        }
        else {
            /*std::cout << "primernodo = (" << trayectoria.primerNodo()->getCoords().x() << ","
                                          << trayectoria.primerNodo()->getCoords().y() << ")\n";
            std::cout << "CasillaVisitada = (" << trayectoria.getCasillaVisitada()->getCoords().x() << ","
                        << trayectoria.getCasillaVisitada()->getCoords().y() << ")\n";*/

            QList<Casilla> vecinas = dameCasillasVecinas(tab, trayectoria.ultimoNodo());
            /*std::cout << "vecinas.size() = " << vecinas.size() << "\n";*/

            for (int i = 0; i < vecinas.size(); ++i) {
                /*std::cout << "vecinas[i].getCoords() = " << "(" <<
                             vecinas[i].getCoords().x() << "," << vecinas[i].getCoords().y() << ")" << "\n"; */

                Camino nueva(trayectoria);
                Casilla *vecina = new Casilla(vecinas[i]);
                visitadas.append(*vecina);
                nueva.addCellToPath(vecina);
                visited++;
                inserta_en_lista(nueva);
            }
        }
    }
    qDebug() << iteracion << " iteraciones ejecutadas;" << visited << " casillas visitadas.";
    if (objetivoEncontrado) {
        qDebug() << trayectoria.getCosteTotal() << " casillas <- longitud del camino encontrado";
        qDebug() << "Solucion encontrada";
        return trayectoria;
    }
    else {
        qDebug() << "No hay solucion";
        return Camino(tab->getInicio());       // No hay solucion
    }
}

void BusquedaEnAnchura::inserta_en_lista(Camino &nueva) {
    lista.push_back(nueva);
}

void BusquedaEnProfundidad::inserta_en_lista(Camino &nueva) {
    lista.push_front(nueva);
}
