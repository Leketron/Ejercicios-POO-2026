#include "login.h"
#include "formulario.h"
#include <QMessageBox>
#include <QKeyEvent>

Login::Login( QWidget * parent ) : QWidget( parent ) {
    setWindowTitle( "Login" );
    resize( 300, 150 );

    labelUsuario = new QLabel( "Usuario:" );
    labelClave = new QLabel( "Clave:" );
    lineEditUsuario = new QLineEdit;
    lineEditClave = new QLineEdit;
    lineEditClave->setEchoMode( QLineEdit::Password ); // asteriscos
    botonEntrar = new QPushButton( "Entrar" );

    layout = new QGridLayout;
    layout->addWidget( labelUsuario,    0, 0 );
    layout->addWidget( lineEditUsuario, 0, 1 );
    layout->addWidget( labelClave,      1, 0 );
    layout->addWidget( lineEditClave,   1, 1 );
    layout->addWidget( botonEntrar,     2, 0, 1, 2 );
    setLayout( layout );

    connect( botonEntrar, SIGNAL( clicked() ), this, SLOT( onEntrarClicked() ) );

    // Detectar Enter en el campo clave
    connect( lineEditClave, SIGNAL( returnPressed() ), this, SLOT( onEntrarClicked() ) );
}

void Login::onEntrarClicked() {
    if ( lineEditUsuario->text() == "admin" && lineEditClave->text() == "1111" ) {
        Formulario * formulario = new Formulario;
        formulario->show();
        this->close();
    } else {
        lineEditClave->clear();
        QMessageBox::warning( this, "Error", "Usuario o clave incorrectos." );
    }
}
