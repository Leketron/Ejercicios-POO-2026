#include "trex.h"

TRex::TRex() {
    x         = 80;
    y         = SUELO;
    velocidadY = 0;
    enSuelo   = true;
    agachado  = false;
}

void TRex::saltar() {
    if ( enSuelo ) {
        velocidadY = -15;
        enSuelo    = false;
    }
}

void TRex::agachar( bool estado ) {
    agachado = estado;
}

void TRex::adelantar() {
    x = qMin( x + 5, 200 );
}

void TRex::frenar() {
    x = qMax( x - 5, 40 );
}

void TRex::actualizar() {
    if ( !enSuelo ) {
        velocidadY += 1; // gravedad
        y += velocidadY;
    }
    if ( y >= SUELO ) {
        y          = SUELO;
        velocidadY = 0;
        enSuelo    = true;
    }
}

QRect TRex::getRect() const {
    int alto = agachado ? ALTO_AGACHADO : ALTO_NORMAL;
    int yPos = agachado ? SUELO + ALTO_NORMAL - ALTO_AGACHADO : y;
    return QRect( x, yPos, ANCHO, alto );
}
