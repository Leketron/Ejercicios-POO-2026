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

private:
    QLabel * labelLegajo;
    QLabel * labelNombre;
    QLabel * labelApellido;
    QLineEdit * lineEditLegajo;
    QLineEdit * lineEditNombre;
    QLineEdit * lineEditApellido;
    QPushButton * botonAlta;
    QGridLayout * layout;
};

#endif // FORMULARIO_H
