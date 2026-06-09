#include "ventana.h"
#include <QPainter>
#include <QNetworkRequest>
#include <QUrl>

Ventana::Ventana( QWidget * parent ) : QWidget( parent ) {
    setWindowTitle( "Ventana Principal" );

    manager = new QNetworkAccessManager( this );
    connect( manager, SIGNAL( finished( QNetworkReply* ) ),
             this,    SLOT( onImagenDescargada( QNetworkReply* ) ) );

    QNetworkRequest request;
    request.setUrl( QUrl( "https://images.unsplash.com/photo-1470770841072-f978cf4d019e?w=1920" ) );
    manager->get( request );
}

void Ventana::paintEvent( QPaintEvent * event ) {
    Q_UNUSED( event );
    if ( !imagen.isNull() ) {
        QPainter painter( this );
        QPixmap escalada = imagen.scaled( size(), Qt::KeepAspectRatio,
                                          Qt::SmoothTransformation );
        int x = ( width()  - escalada.width()  ) / 2;
        int y = ( height() - escalada.height() ) / 2;
        painter.drawPixmap( x, y, escalada );
    }
}

void Ventana::onImagenDescargada( QNetworkReply * reply ) {
    if ( reply->error() == QNetworkReply::NoError ) {
        imagen.loadFromData( reply->readAll() );
        // Mostrar solo cuando la imagen esté lista
        showFullScreen();
        update();
    }
    reply->deleteLater();
}
