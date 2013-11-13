#ifndef COMMON_H
#define COMMON_H

#include <QtGui>

#define FACTOR_CORRECCION 0.975

enum tipoCasilla {vacio, obstaculo, robot, objetivo};

static QColor azulClaro(0xAA, 0xCC, 0xCC);
static QColor azulClaroClaro(0xBB, 0xEE, 0xFF);
static QColor naranja(0xFF, 0x99, 0x00);
//static QColor verde(0x09, 0x70, 0x54);
static QColor verde(0xAA, 0xFF, 0x00);
static QColor azulOscuro(0x3F, 0x6A, 0x6A);
static QColor blanco(0xFF, 0xFF, 0xFF);

static QBrush lightBrush(azulClaro);
static QBrush obstacleBrush(azulOscuro);
static QBrush targetBrush(naranja);
static QBrush robotBrush(verde);

static QPen penClaro(azulClaroClaro);
static QPen pen(blanco);

#endif // COMMON_H
