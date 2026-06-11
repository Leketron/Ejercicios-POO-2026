#include <QApplication>
#include "juego.h"

int main( int argc, char** argv ) {
    QApplication a( argc, argv );

    Juego * juego = new Juego;
    juego->setWindowTitle( "T-Rex Extremo" );
    juego->resize( 800, 300 );
    juego->show();

    return a.exec();
}
