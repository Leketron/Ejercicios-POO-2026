#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPixmap>

class Login : public QWidget {
    Q_OBJECT

public:
    Login( QWidget * parent = nullptr );

protected:
    void paintEvent( QPaintEvent * event ) override;

private slots:
    void onEntrarClicked();
    void onImagenDescargada( QNetworkReply * reply );

private:
    QLabel * labelUsuario;
    QLabel * labelClave;
    QLineEdit * lineEditUsuario;
    QLineEdit * lineEditClave;
    QPushButton * botonEntrar;
    QGridLayout * layout;
    QNetworkAccessManager * manager;
    QPixmap imagenFondo;
};

#endif // LOGIN_H
