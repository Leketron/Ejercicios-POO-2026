#include "ventana.h"
#include <QPainter>
#include <QGridLayout>
#include <QSpacerItem>
#include <QDebug>

Ventana::Ventana( QWidget * parent ) : QWidget( parent ) {
    setWindowTitle( "Ventana con Botones" );
    resize( 400, 600 );

    boton1 = new Boton;  boton1->colorear( Boton::Azul );
    boton2 = new Boton;  boton2->colorear( Boton::Verde );
    boton3 = new Boton;  boton3->colorear( Boton::Magenta );
    boton4 = new Boton;  boton4->colorear( Boton::Azul );
    boton5 = new Boton;  boton5->colorear( Boton::Verde );

    connect( boton1, SIGNAL( signal_clic() ), this, SLOT( onBotonClicado() ) );
    connect( boton2, SIGNAL( signal_clic() ), this, SLOT( onBotonClicado() ) );
    connect( boton3, SIGNAL( signal_clic() ), this, SLOT( onBotonClicado() ) );
    connect( boton4, SIGNAL( signal_clic() ), this, SLOT( onBotonClicado() ) );
    connect( boton5, SIGNAL( signal_clic() ), this, SLOT( onBotonClicado() ) );

    QGridLayout * layout = new QGridLayout;
    layout->setSpacing( 10 );
    layout->setContentsMargins( 20, 20, 20, 20 );

    // Spacer arriba
    layout->addItem( new QSpacerItem( 20, 40, QSizePolicy::Minimum,
                                      QSizePolicy::Expanding ), 0, 0 );

    layout->addWidget( boton1, 1, 0 );
    layout->addWidget( boton2, 2, 0 );
    layout->addWidget( boton3, 3, 0 );
    layout->addWidget( boton4, 4, 0 );
    layout->addWidget( boton5, 5, 0 );

    // Spacer abajo
    layout->addItem( new QSpacerItem( 20, 40, QSizePolicy::Minimum,
                                      QSizePolicy::Expanding ), 6, 0 );

    setLayout( layout );
}

void Ventana::paintEvent( QPaintEvent * event ) {
    Q_UNUSED( event );
    QPainter painter( this );

    // Fondo degradado
    QLinearGradient degradado( 0, 0, width(), height() );
    degradado.setColorAt( 0.0, QColor( 255, 100, 100 ) );
    degradado.setColorAt( 0.3, QColor( 255, 165, 0  ) );
    degradado.setColorAt( 0.5, QColor( 100, 200, 100 ) );
    degradado.setColorAt( 0.7, QColor( 50,  100, 255 ) );
    degradado.setColorAt( 1.0, QColor( 150, 50,  200 ) );

    painter.fillRect( rect(), degradado );
}

void Ventana::onBotonClicado() {
    qDebug() << "Boton clicado!";
}
