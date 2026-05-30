#include "Proyectil.h"

Proyectil::Proyectil(float x, float y, float w, float h, float v0, float anguloGrados)
    : ObjetoJuego(x, y, w, h), velInicial(v0), tiempoVuelo(0), posXInicial(x), posYInicial(y), gravedad(9.8f) {

    anguloRadiantes = anguloGrados * (M_PI / 180.0f);
}

void Proyectil::actualizarFisica(float dt) {
    tiempoVuelo += dt;


    posX = posXInicial + (velInicial * cos(anguloRadiantes) * tiempoVuelo);

    posY = posYInicial - (velInicial * sin(anguloRadiantes) * tiempoVuelo) + (0.5f * gravedad * tiempoVuelo * tiempoVuelo);
}