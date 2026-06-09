#ifndef PINTURA_H
#define PINTURA_H

#include <QWidget>
#include <QImage>
#include <QColor>
#include <QPoint>

class Pintura : public QWidget {
    Q_OBJECT

public:
    Pintura( QWidget * parent = nullptr );

protected:
    void paintEvent( QPaintEvent * event ) override;
    void mousePressEvent( QMouseEvent * event ) override;
    void mouseMoveEvent( QMouseEvent * event ) override;
    void mouseReleaseEvent( QMouseEvent * event ) override;
    void wheelEvent( QWheelEvent * event ) override;
    void keyPressEvent( QKeyEvent * event ) override;
    void resizeEvent( QResizeEvent * event ) override;

private:
    QImage lienzo;
    QColor colorActual;
    QPoint ultimoPunto;
    int tamanioPincel;
    bool dibujando;

    void dibujarLinea( QPoint desde, QPoint hasta );
};

#endif // PINTURA_H
