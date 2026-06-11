#ifndef PAJARO_H
#define PAJARO_H

#include <QObject>
#include <QRect>
#include <QTimer>

class Pajaro : public QObject {
    Q_OBJECT

public:
    explicit Pajaro( int velocidad, QObject * parent = nullptr );
    ~Pajaro();

    QRect getRect() const;
    bool fueraDePantalla() const;

private slots:
    void mover();

private:
    int x, y;
    int ancho, alto;
    QTimer * timer;
    int velocidad;
};

#endif // PAJARO_H
