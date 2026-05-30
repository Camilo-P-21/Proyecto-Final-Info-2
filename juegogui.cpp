#include "JuegoGUI.h"
#include <QMessageBox>

JuegoGUI::JuegoGUI(QWidget *parent) : QGraphicsView(parent) {
    escena = new QGraphicsScene(this);
    escena->setSceneRect(0, 0, 800, 600);
    setScene(escena);

    gokuLogica = new EntidadCombate("Goku", 100, 15, 100, 400, 50, 100);

    timerPrincipal = new QTimer(this);
    connect(timerPrincipal, &QTimer::timeout, this, &JuegoGUI::loopJuego);

    timerNivel = new QTimer(this);
    connect(timerNivel, &QTimer::timeout, this, &JuegoGUI::actualizarRelojNivel);


    iniciarNivel(1);
}

void JuegoGUI::iniciarNivel(int nivel) {
    escena->clear();
    listaProyectiles.clear();

    try {
        cargarSprites(nivel);
    } catch (const std::runtime_error& e) {

        QMessageBox::critical(this, "Error Crítico", e.what());
        return;
    }

    if (nivel == 1) {

        enemigoActual = new EnemigoIA("Vegeta", 100, 10, 600, 400, 1);
    } else if (nivel == 2) {

        enemigoActual = new EnemigoIA("Freezer", 200, 25, 600, 300, 2);
        tiempoRestante = 300;
        timerNivel->start(1000);
    }

    timerPrincipal->start(16);
}

void JuegoGUI::cargarSprites(int nivel) {
    QPixmap imgGoku(":/sprites/goku_idle.png");
    if (imgGoku.isNull()) {
        throw std::runtime_error("No se pudo cargar el sprite de Goku. Verifica el archivo .qrc");
    }

    spriteGoku = escena->addPixmap(imgGoku);
    spriteGoku->setPos(gokuLogica->getX(), gokuLogica->getY());


}

void JuegoGUI::loopJuego() {
    float dt = 0.016f;
    gokuLogica->actualizarFisica(dt);
    spriteGoku->setPos(gokuLogica->getX(), gokuLogica->getY());

    enemigoActual->tomarDecision(dt, gokuLogica->getX(), gokuLogica->getY(), false);

    for (auto it = listaProyectiles.begin(); it != listaProyectiles.end();) {
        (*it)->actualizarFisica(dt);

        ++it;
    }
}

void JuegoGUI::actualizarRelojNivel() {
    tiempoRestante--;
    if (tiempoRestante <= 0) {
        timerNivel->stop();
        timerPrincipal->stop();
        QMessageBox::information(this, "Fin", "¡Namekusei ha explotado!");
    }
}