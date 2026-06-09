#include "pintura.h"
#include <QPainter>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QResizeEvent>

Pintura::Pintura( QWidget * parent ) : QWidget( parent ) {
    colorActual   = Qt::black;
    tamanioPincel = 5;
    dibujando     = false;
    lienzo        = QImage( size(), QImage::Format_RGB32 );
    lienzo.fill( Qt::white );
    setFocusPolicy( Qt::StrongFocus );
}

void Pintura::resizeEvent( QResizeEvent * event ) {
    Q_UNUSED( event );
    // Redimensionar el lienzo manteniendo lo dibujado
    QImage nuevoLienzo( size(), QImage::Format_RGB32 );
    nuevoLienzo.fill( Qt::white );
    QPainter painter( &nuevoLienzo );
    painter.drawImage( 0, 0, lienzo );
    lienzo = nuevoLienzo;
}

void Pintura::paintEvent( QPaintEvent * event ) {
    Q_UNUSED( event );
    QPainter painter( this );
    painter.drawImage( 0, 0, lienzo );

    // Mostrar info del pincel
    painter.setPen( Qt::black );
    painter.drawText( 10, 20, "Tamanio pincel: " + QString::number( tamanioPincel ) );
    painter.drawText( 10, 40, "Color: R=rojo G=verde B=azul | Esc=borrar" );
}

void Pintura::mousePressEvent( QMouseEvent * event ) {
    if ( event->button() == Qt::LeftButton ) {
        dibujando    = true;
        ultimoPunto  = event->pos();
    }
}

void Pintura::mouseMoveEvent( QMouseEvent * event ) {
    if ( dibujando && ( event->buttons() & Qt::LeftButton ) ) {
        dibujarLinea( ultimoPunto, event->pos() );
        ultimoPunto = event->pos();
        update();
    }
}

void Pintura::mouseReleaseEvent( QMouseEvent * event ) {
    if ( event->button() == Qt::LeftButton )
        dibujando = false;
}

void Pintura::wheelEvent( QWheelEvent * event ) {
    // Scroll hacia arriba aumenta, hacia abajo disminuye
    if ( event->angleDelta().y() > 0 )
        tamanioPincel = qMin( tamanioPincel + 2, 50 );
    else
        tamanioPincel = qMax( tamanioPincel - 2, 1 );
    update();
}

void Pintura::keyPressEvent( QKeyEvent * event ) {
    switch ( event->key() ) {
        case Qt::Key_R: colorActual = Qt::red;   break;
        case Qt::Key_G: colorActual = Qt::green; break;
        case Qt::Key_B: colorActual = Qt::blue;  break;
        case Qt::Key_Escape:
            lienzo.fill( Qt::white );
            update();
            break;
        default: break;
    }
}

void Pintura::dibujarLinea( QPoint desde, QPoint hasta ) {
    QPainter painter( &lienzo );
    painter.setPen( QPen( colorActual, tamanioPincel,
                          Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin ) );
    painter.drawLine( desde, hasta );
}
