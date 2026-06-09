#ifndef BOTON_H
#define BOTON_H

#include <QWidget>

class Boton : public QWidget {
    Q_OBJECT

public:
    enum Color { Azul, Verde, Magenta };

    explicit Boton( QWidget * parent = nullptr );

    void colorear( Color color );

signals:
    void signal_clic();

protected:
    void paintEvent( QPaintEvent * event ) override;
    void mousePressEvent( QMouseEvent * event ) override;

private:
    Color colorActual;
};

#endif // BOTON_H
