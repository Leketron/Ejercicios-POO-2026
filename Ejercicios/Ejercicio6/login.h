#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

class Login : public QWidget {
    Q_OBJECT

public:
    Login( QWidget * parent = nullptr );

private slots:
    void onEntrarClicked();

private:
    QLabel * labelUsuario;
    QLabel * labelClave;
    QLineEdit * lineEditUsuario;
    QLineEdit * lineEditClave;
    QPushButton * botonEntrar;
    QGridLayout * layout;
};

#endif // LOGIN_H
