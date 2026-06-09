#include <QApplication>
#include "pintura.h"

int main( int argc, char** argv ) {
    QApplication a( argc, argv );

    Pintura * pintura = new Pintura;
    pintura->setWindowTitle( "Pintura" );
    pintura->showMaximized();

    return a.exec();
}
