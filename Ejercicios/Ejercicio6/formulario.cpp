#include "formulario.h"

Formulario::Formulario( QWidget * parent ) : QWidget( parent ) {
    setWindowTitle( "Formulario" );
    resize( 300, 180 );

    labelLegajo   = new QLabel( "Legajo:" );
    labelNombre   = new QLabel( "Nombre:" );
    labelApellido = new QLabel( "Apellido:" );

    lineEditLegajo   = new QLineEdit;
    lineEditNombre   = new QLineEdit;
    lineEditApellido = new QLineEdit;

    botonAlta = new QPushButton( "Alta" );

    layout = new QGridLayout;
    layout->addWidget( labelLegajo,      0, 0 );
    layout->addWidget( lineEditLegajo,   0, 1 );
    layout->addWidget( labelNombre,      1, 0 );
    layout->addWidget( lineEditNombre,   1, 1 );
    layout->addWidget( labelApellido,    2, 0 );
    layout->addWidget( lineEditApellido, 2, 1 );
    layout->addWidget( botonAlta,        3, 0, 1, 2 );
    setLayout( layout );
}
