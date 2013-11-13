#ifndef BUSQUEDACIEGA_H
#define BUSQUEDACIEGA_H

#include <QDialog>
#include "casilla.h"
#include "camino.h"
#include "tablero.h"

class BusquedaCiega
{
protected:
    QList<Casilla> dameCasillasVecinas(Tablero *tab, Casilla *centro);
    QQueue<Camino> lista;
    QList<Casilla> visitadas;
public:
    BusquedaCiega() {}
    Camino buscar(Tablero *tab);
    virtual void inserta_en_lista(Camino &nueva) = 0;
};

class BusquedaEnAnchura : public BusquedaCiega
{
private:

public:
    BusquedaEnAnchura() { qDebug() << "\nBusqueda en anchura"; }
    void inserta_en_lista(Camino &nueva);

};

class BusquedaEnProfundidad : public BusquedaCiega
{
private:

public:
    BusquedaEnProfundidad() { qDebug() << "\nBusqueda en profundidad"; }
    void inserta_en_lista(Camino &nueva);

};

#endif // BUSQUEDACIEGA_H
