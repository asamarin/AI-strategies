#include "tablero.h"

Tablero::Tablero(const int w, const int h, const qreal d, QGraphicsScene *gs)
{
    this->height = h;
    this->width = w;
    this->gs = gs;

    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            QPoint coord(i, j);
            Casilla cas(coord, vacio, d);
            cells.append(cas);  // Anyade una casilla a la lista
        }
    }
}

void Tablero::setCell(const int i, const int j, const tipoCasilla type)
{
    Casilla *tmpCell;
    tmpCell = this->getCell(i,j);
    tmpCell->setType(type);
    if (type == robot) this->inicio = tmpCell;
    else if (type == objetivo) this->meta = tmpCell;
}

Casilla* Tablero::getCell(const int i, const int j)
{
    return &cells[i*this->height+j];
}

void Tablero::redraw() {
    gs->clear();
    this->draw();
}

void Tablero::draw()
{
    for (int i = 0; i < this->width * this->height; ++i) {
        cells[i].draw(gs);
        //qDebug() << i << cells.size();
        QObject::connect(cells[i].getRectangle(),
                         SIGNAL(clicked(int, int, tipoCasilla)),
                         this, SLOT(setDrawCell(int, int, tipoCasilla)));
    }

}

void Tablero::setDrawCell(const int i, const int j, tipoCasilla type) {
    // Si es una casilla meta u objetivo no la modifica
    if (this->getCell(i,j)->getType() != objetivo &&
            this->getCell(i, j)->getType() != robot) {
        qDebug() << "cell[" << i << "," << j << "] = " << type;
        this->setCell(i, j, type);
        this->getCell(i, j)->draw(gs);
        //this->getCell(i,j)->draw(this->gs);
        QObject::connect(this->getCell(i, j)->getRectangle(),
                         SIGNAL(clicked(int, int, tipoCasilla)),
                         this, SLOT(setDrawCell(int, int, tipoCasilla)));
    }
}

void Tablero::ramdomizeRobot()
{
    Casilla *tmpCell;
    srand(time(NULL));
    while( (tmpCell = getCell(rand() % this->width, rand() % this->height))->getType() != vacio);
    tmpCell->setType(robot);
    this->inicio = tmpCell;

    while( (tmpCell = getCell(rand() % this->width, rand() % this->height))->getType() != vacio);
    tmpCell->setType(objetivo);
    this->meta = tmpCell;
}

void Tablero::randomize(const float p)
{
    srand(time(NULL));

    for(int i=0; i < this->height * this->width * p; ++i) {
        setCell(rand() % this->width, rand() % this->height, obstaculo);
    }
    ramdomizeRobot();
}
