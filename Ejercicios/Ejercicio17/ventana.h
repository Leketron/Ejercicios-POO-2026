#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include "boton.h"

class Ventana : public QWidget {
    Q_OBJECT

public:
    explicit Ventana( QWidget * parent = nullptr );

protected:
    void paintEvent( QPaintEvent * event ) override;

private slots:
    void onBotonClicado();

private:
    Boton * boton1;
    Boton * boton2;
    Boton * boton3;
    Boton * boton4;
    Boton * boton5;
};

#endif // VENTANA_H
