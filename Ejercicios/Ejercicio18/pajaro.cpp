#include "pajaro.h"
#include <cstdlib>

Pajaro::Pajaro( int velocidad, QObject * parent ) : QObject( parent ) {
    x         = 850;
    // Altura aleatoria entre 80 y 180
    y         = 80 + ( rand() % 100 );
    ancho     = 40;
    alto      = 30;
    this->velocidad = velocidad;

    timer = new QTimer( this );
    connect( timer, SIGNAL( timeout() ), this, SLOT( mover() ) );
    timer->start( 16 ); // ~60fps
}

Pajaro::~Pajaro() {
    timer->stop();
}

void Pajaro::mover() {
    x -= velocidad;
}

QRect Pajaro::getRect() const {
    return QRect( x, y, ancho, alto );
}

bool Pajaro::fueraDePantalla() const {
    return x + ancho < 0;
}
