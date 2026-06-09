#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QTimer>
#include <QScreen>

int main( int argc, char** argv ) {
    QApplication a( argc, argv );

    // Cargar imagen desde disco
    QPixmap imagen( "imagen.jpg" );

    QLabel * label = new QLabel;
    label->setWindowTitle( "Imagen" );

    // Escalar la imagen al tamaño de la pantalla sin deformar
    QScreen * pantalla = QApplication::primaryScreen();
    QSize tamanioPantalla = pantalla->size();

    label->setPixmap( imagen.scaled( tamanioPantalla,
                                     Qt::KeepAspectRatio,
                                     Qt::SmoothTransformation ) );

    label->setAlignment( Qt::AlignCenter );
    label->showMaximized();

    // Cerrar la app luego de 3 segundos
    QTimer::singleShot( 3000, &a, SLOT( quit() ) );

    return a.exec();
}
