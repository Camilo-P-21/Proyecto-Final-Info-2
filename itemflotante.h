#ifndef ITEMFLOTANTE_H
#define ITEMFLOTANTE_H
#include "ObjetoJuego.h"
#include <cmath>

class ItemFlotante : public ObjetoJuego {
private:
    float amplitud;
    float frecuencia;
    float tiempo;
    float posYInicial;

public:
    ItemFlotante(float x, float y, float w, float h)
        : ObjetoJuego(x, y, w, h), amplitud(20.0f), frecuencia(2.0f), tiempo(0) {
        posYInicial = y;
    }


    void actualizarFisica(float dt) override {
        tiempo += dt;

        posY = posYInicial + amplitud * sin(frecuencia * tiempo);
    }
};
#endif