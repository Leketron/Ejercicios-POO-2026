#ifndef JUEGO_H
#define JUEGO_H

#include <QWidget>
#include <QTimer>
#include <QList>
#include "trex.h"
#include "pajaro.h"

class Juego : public QWidget {
    Q_OBJECT

public:
    explicit Juego( QWidget * parent = nullptr );

protected:
    void paintEvent( QPaintEvent * event ) override;
    void keyPressEvent( QKeyEvent * event ) override;
    void keyReleaseEvent( QKeyEvent * event ) override;

private slots:
    void actualizar();
    void agregarPajaro();
    void aumentarVelocidad();

private:
    TRex * trex;
    QList<Pajaro*> pajaros;
    QTimer * timerPrincipal;
    QTimer * timerPajaros;
    QTimer * timerVelocidad;

    int posXCactus;
    int velocidad;
    bool gameOver;
    int puntuacion;

    void reiniciar();
    void verificarColisiones();
    void dibujarCactus( QPainter & painter );
    void dibujarTrex( QPainter & painter );
    void dibujarPajaros( QPainter & painter );
};

#endif // JUEGO_H
