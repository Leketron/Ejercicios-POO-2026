#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

class Formulario : public QWidget {
    Q_OBJECT

public:
    Formulario( QWidget * parent = nullptr );

private slots:
    void onAltaClicked();
    void generarCaptcha();

private:
    QLabel * labelLegajo;
    QLabel * labelNombre;
    QLabel * labelApellido;
    QLabel * labelCaptcha;
    QLabel * labelCaptchaValor;
    QLineEdit * lineEditLegajo;
    QLineEdit * lineEditNombre;
    QLineEdit * lineEditApellido;
    QLineEdit * lineEditCaptcha;
    QPushButton * botonAlta;
    QGridLayout * layout;
    int captchaActual;
};

#endif // FORMULARIO_H
