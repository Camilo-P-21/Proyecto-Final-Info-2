#ifndef PROYECTIL_H
#define PROYECTIL_H

#include "ObjetoJuego.h"
#include <cmath>

class Proyectil : public ObjetoJuego {
private:
    float velInicial;
    float anguloRadiantes;
    float tiempoVuelo;
    float posXInicial;
    float posYInicial;
    float gravedad;

public:
    Proyectil(float x, float y, float w, float h, float v0, float anguloGrados);

    void actualizarFisica(float dt) override;
};

#endif