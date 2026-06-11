#ifndef TREX_H
#define TREX_H

#include <QWidget>
#include <QRect>

class TRex {
public:
    TRex();

    void saltar();
    void agachar( bool agachado );
    void adelantar();
    void frenar();
    void actualizar();

    QRect getRect() const;
    bool estaAgachado() const { return agachado; }

private:
    int x, y;
    int velocidadY;
    bool enSuelo;
    bool agachado;

    static const int SUELO = 220;
    static const int ALTO_NORMAL = 50;
    static const int ALTO_AGACHADO = 25;
    static const int ANCHO = 40;
};

#endif // TREX_H
