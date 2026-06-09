#include "boton.h"
#include <QPainter>
#include <QMouseEvent>

Boton::Boton( QWidget * parent ) : QWidget( parent ) {
    colorActual = Azul;
    setMinimumSize( 100, 60 );
}

void Boton::colorear( Color color ) {
    colorActual = color;
    update();
}

void Boton::paintEvent( QPaintEvent * event ) {
    Q_UNUSED( event );
    QPainter painter( this );
    painter.setRenderHint( QPainter::Antialiasing );

    QColor color;
    switch ( colorActual ) {
        case Azul:    color = QColor( 52, 152, 219 );  break;
        case Verde:   color = QColor( 46, 204, 113 );  break;
        case Magenta: color = QColor( 155, 89, 182 );  break;
    }

    // Dibujar fondo del boton
    painter.setBrush( color );
    painter.setPen( Qt::NoPen );
    painter.drawRoundedRect( rect(), 10, 10 );

    // Dibujar texto
    painter.setPen( Qt::white );
    painter.setFont( QFont( "Arial", 11, QFont::Bold ) );
    painter.drawText( rect(), Qt::AlignCenter, "Boton" );
}

void Boton::mousePressEvent( QMouseEvent * event ) {
    Q_UNUSED( event );
    emit signal_clic();
}
