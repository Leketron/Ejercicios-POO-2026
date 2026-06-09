#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPixmap>

class Ventana : public QWidget {
    Q_OBJECT

public:
    Ventana( QWidget * parent = nullptr );

protected:
    void paintEvent( QPaintEvent * event ) override;

private slots:
    void onImagenDescargada( QNetworkReply * reply );

private:
    QNetworkAccessManager * manager;
    QPixmap imagen;
};

#endif // VENTANA_H
