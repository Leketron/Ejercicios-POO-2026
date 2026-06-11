#include "juego.h"
#include <QPainter>
#include <QKeyEvent>
#include <QFont>
#include <cstdlib>
#include <ctime>

Juego::Juego( QWidget * parent ) : QWidget( parent ) {
    srand( time( nullptr ) );
    setFocusPolicy( Qt::StrongFocus );
    trex      = new TRex;
    velocidad = 5;
    gameOver  = false;
    puntuacion = 0;
    posXCactus = 800;

    timerPrincipal = new QTimer( this );
    connect( timerPrincipal, SIGNAL( timeout() ), this, SLOT( actualizar() ) );
    timerPrincipal->start( 16 );

    timerPajaros = new QTimer( this );
    connect( timerPajaros, SIGNAL( timeout() ), this, SLOT( agregarPajaro() ) );
    timerPajaros->start( 5000 );

    timerVelocidad = new QTimer( this );
    connect( timerVelocidad, SIGNAL( timeout() ), this, SLOT( aumentarVelocidad() ) );
    timerVelocidad->start( 3000 );
}

void Juego::actualizar() {
    if ( gameOver ) return;

    trex->actualizar();
    posXCactus -= velocidad;
    if ( posXCactus < -30 ) {
        posXCactus = 800 + rand() % 400;
        puntuacion++;
    }

    // Limpiar pajaros fuera de pantalla
    for ( int i = pajaros.size() - 1; i >= 0; i-- ) {
        if ( pajaros[i]->fueraDePantalla() ) {
            delete pajaros[i];
            pajaros.removeAt( i );
        }
    }

    verificarColisiones();
    update();
}

void Juego::agregarPajaro() {
    if ( gameOver ) return;
    Pajaro * pajaro = new Pajaro( velocidad + 2, this );
    pajaros.append( pajaro );
}

void Juego::aumentarVelocidad() {
    if ( gameOver ) return;
    velocidad = qMin( velocidad + 1, 20 );
}

void Juego::verificarColisiones() {
    QRect rectCactus( posXCactus, 195, 25, 75 );
    if ( trex->getRect().intersects( rectCactus ) ) {
        gameOver = true;
        timerPrincipal->stop();
        timerPajaros->stop();
        timerVelocidad->stop();
        return;
    }
    for ( Pajaro * pajaro : pajaros ) {
        if ( trex->getRect().intersects( pajaro->getRect() ) ) {
            gameOver = true;
            timerPrincipal->stop();
            timerPajaros->stop();
            timerVelocidad->stop();
            return;
        }
    }
}

void Juego::paintEvent( QPaintEvent * event ) {
    Q_UNUSED( event );
    QPainter painter( this );
    painter.fillRect( rect(), Qt::white );

    // Suelo
    painter.setPen( QPen( Qt::black, 2 ) );
    painter.drawLine( 0, 270, width(), 270 );

    dibujarTrex( painter );
    dibujarCactus( painter );
    dibujarPajaros( painter );

    // Puntuacion
    painter.setPen( Qt::black );
    painter.setFont( QFont( "Arial", 14, QFont::Bold ) );
    painter.drawText( 650, 30, "Puntos: " + QString::number( puntuacion ) );
    painter.drawText( 10, 30, "Velocidad: " + QString::number( velocidad ) );

    if ( gameOver ) {
        painter.setPen( Qt::red );
        painter.setFont( QFont( "Arial", 36, QFont::Bold ) );
        painter.drawText( rect(), Qt::AlignCenter, "GAME OVER\nPresiona R para reiniciar" );
    }
}

void Juego::dibujarTrex( QPainter & painter ) {
    QRect r = trex->getRect();
    painter.setBrush( QColor( 80, 80, 80 ) );
    painter.setPen( Qt::NoPen );
    painter.drawRect( r );

    // Ojo
    painter.setBrush( Qt::white );
    painter.drawEllipse( r.x() + r.width() - 12, r.y() + 5, 8, 8 );
    painter.setBrush( Qt::black );
    painter.drawEllipse( r.x() + r.width() - 10, r.y() + 7, 4, 4 );
}

void Juego::dibujarCactus( QPainter & painter ) {
    painter.setBrush( QColor( 0, 150, 0 ) );
    painter.setPen( Qt::NoPen );
    // Tronco
    painter.drawRect( posXCactus, 195, 25, 75 );
    // Brazo izquierdo
    painter.drawRect( posXCactus - 15, 210, 15, 10 );
    painter.drawRect( posXCactus - 15, 195, 10, 25 );
    // Brazo derecho
    painter.drawRect( posXCactus + 25, 215, 15, 10 );
    painter.drawRect( posXCactus + 25, 200, 10, 25 );
}

void Juego::dibujarPajaros( QPainter & painter ) {
    painter.setBrush( QColor( 50, 50, 200 ) );
    painter.setPen( Qt::NoPen );
    for ( Pajaro * pajaro : pajaros ) {
        QRect r = pajaro->getRect();
        painter.drawRect( r );
        // Alas
        painter.drawRect( r.x() - 10, r.y() + 5, 10, 8 );
        painter.drawRect( r.x() + r.width(), r.y() + 5, 10, 8 );
    }
}

void Juego::keyPressEvent( QKeyEvent * event ) {
    if ( gameOver ) {
        if ( event->key() == Qt::Key_R )
            reiniciar();
        return;
    }
    switch ( event->key() ) {
        case Qt::Key_Space: trex->saltar();          break;
        case Qt::Key_Down:  trex->agachar( true );   break;
        case Qt::Key_Right: trex->adelantar();        break;
        case Qt::Key_Left:  trex->frenar();           break;
        default: break;
    }
}

void Juego::keyReleaseEvent( QKeyEvent * event ) {
    if ( event->key() == Qt::Key_Down )
        trex->agachar( false );
}

void Juego::reiniciar() {
    delete trex;
    trex = new TRex;

    for ( Pajaro * p : pajaros )
        delete p;
    pajaros.clear();

    posXCactus = 800;
    velocidad  = 5;
    gameOver   = false;
    puntuacion = 0;

    timerPrincipal->start( 16 );
    timerPajaros->start( 5000 );
    timerVelocidad->start( 3000 );
}
