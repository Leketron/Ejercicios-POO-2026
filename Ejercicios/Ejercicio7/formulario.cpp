#include "formulario.h"
#include <QMessageBox>
#include <QApplication>
#include <cstdlib>
#include <ctime>

Formulario::Formulario( QWidget * parent ) : QWidget( parent ) {
    setWindowTitle( "Formulario" );
    resize( 350, 250 );

    srand( time( nullptr ) );

    labelLegajo   = new QLabel( "Legajo:" );
    labelNombre   = new QLabel( "Nombre:" );
    labelApellido = new QLabel( "Apellido:" );
    labelCaptcha  = new QLabel( "Captcha:" );
    labelCaptchaValor = new QLabel;

    lineEditLegajo   = new QLineEdit;
    lineEditNombre   = new QLineEdit;
    lineEditApellido = new QLineEdit;
    lineEditCaptcha  = new QLineEdit;

    botonAlta = new QPushButton( "Alta" );

    layout = new QGridLayout;
    layout->addWidget( labelLegajo,       0, 0 );
    layout->addWidget( lineEditLegajo,    0, 1 );
    layout->addWidget( labelNombre,       1, 0 );
    layout->addWidget( lineEditNombre,    1, 1 );
    layout->addWidget( labelApellido,     2, 0 );
    layout->addWidget( lineEditApellido,  2, 1 );
    layout->addWidget( labelCaptcha,      3, 0 );
    layout->addWidget( labelCaptchaValor, 3, 1 );
    layout->addWidget( lineEditCaptcha,   4, 1 );
    layout->addWidget( botonAlta,         5, 0, 1, 2 );
    setLayout( layout );

    generarCaptcha();

    connect( botonAlta, SIGNAL( clicked() ), this, SLOT( onAltaClicked() ) );
}

void Formulario::generarCaptcha() {
    captchaActual = ( rand() % 10000 ) + 1; // entre 1 y 10000
    labelCaptchaValor->setText( QString::number( captchaActual ) );
    labelCaptchaValor->setStyleSheet( "color: red; font-weight: bold;" );
    lineEditCaptcha->clear();
}

void Formulario::onAltaClicked() {
    if ( lineEditCaptcha->text().toInt() == captchaActual ) {
        QMessageBox::information( this, "Alta", "Alta realizada correctamente." );
        QApplication::quit();
    } else {
        QMessageBox::warning( this, "Captcha", "Captcha incorrecto." );
        generarCaptcha();
    }
}
