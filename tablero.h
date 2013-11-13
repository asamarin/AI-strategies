#ifndef TABLERO_H
#define TABLERO_H

#include <QMainWindow>
#include <QList>
#include <QPoint>
#include <QGraphicsScene>
#include <ctime>
#include "casilla.h"
#include "camino.h"

class Tablero : public QMainWindow {
    Q_OBJECT

private:
    int height, width;
    QList<Casilla> cells;
    Casilla *inicio, *meta;
    QGraphicsScene *gs;

public:
    explicit Tablero(const int w, const int h, const qreal d, QGraphicsScene *gs);
    Casilla* getCell(const int i, const int j);

    int getHeight() { return this->height; }
    int getWidth() { return this->width; }
    Casilla* getInicio() { return inicio; }
    Casilla* getMeta() { return meta; }
    bool isObjetivo(Casilla *c) { return (c->getCoords() == meta->getCoords()); }
    void redraw();
    void draw();
    void drawPath();
    void randomize(const float p);
    void ramdomizeRobot();
    void setCell(const int i, const int j, const tipoCasilla type);

signals:

public slots:
    void setDrawCell(const int i, const int j, tipoCasilla type);
};

#endif // TABLERO_H
