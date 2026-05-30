#ifndef JUEGOGUI_H
#define JUEGOGUI_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <vector>
#include <stdexcept>
#include "EntidadCombate.h"
#include "EnemigoIA.h"
#include "Proyectil.h"

class JuegoGUI : public QGraphicsView {
    Q_OBJECT
private:
    QGraphicsScene *escena;
    QTimer *timerPrincipal;
    QTimer *timerNivel;
    int tiempoRestante;


    std::vector<Proyectil*> listaProyectiles;


    EntidadCombate *gokuLogica;
    EnemigoIA *enemigoActual;


    QGraphicsPixmapItem *spriteGoku;
    QGraphicsPixmapItem *spriteEnemigo;

public:
    JuegoGUI(QWidget *parent = nullptr);
    void iniciarNivel(int nivel);
    void cargarSprites(int nivel);

public slots:
    void loopJuego();
    void actualizarRelojNivel();
};
#endif