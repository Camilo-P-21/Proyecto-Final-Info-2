#ifndef OBJETOJUEGO_H
#define OBJETOJUEGO_H


class ObjetoJuego {
protected:
    float posX;
    float posY;
    float ancho;
    float alto;

public:
    ObjetoJuego(float x, float y, float w, float h) : posX(x), posY(y), ancho(w), alto(h) {}
    virtual ~ObjetoJuego() {}


    virtual void actualizarFisica(float dt) = 0;


    float getX() const { return posX; }
    float getY() const { return posY; }
    void setPos(float x, float y) { posX = x; posY = y; }
};

#endif