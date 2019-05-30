// ****************************************************************************
// METODOLOGÍA DE LA PROGRAMACIÓN
// AUTORES: JUAN OCAÑA VALENZUELA
//          AARÓN PADIAL VÁZQUEZ
//
// Pelota.h
// Definición de la clase Pelota y funciones asociadas.
// ****************************************************************************

#ifndef PELOTA_H
#define PELOTA_H

#include "definiciones.h"

class Pelota {
private:
    float x, y;
    float dx, dy;
    float radio;
    PColor color;

public:
    Pelota();
    Pelota(float nx, float ny);
    Pelota(float nx, float ny, float r, PColor nc=PColor::ROJO);
    Pelota(float nx, float ny, float vx, float vy, float r, PColor nc);
    Pelota(const Pelota& orig);
    
    void setX(float nx) {x = nx;}
    void setY(float ny) {y = ny;}
    void setDX(float ndx) {dx = ndx;}
    void setDY(float ndy) {dy = ndy;}
    void setColor(PColor nc) {color = nc;}
    void setRadio(float r) {radio = r;}

    float getX() const {return x;}
    float getY() const {return y;}
    float getDX() const {return dx;}
    float getDY() const {return dy;}
    float getRadio() const {return radio;}
    PColor getColor() const {return color;}
    
    float distancia(const Pelota &otro);
    bool colisionado(const Pelota &otro);

    const Pelota & operator=(const Pelota &otro);
    bool operator==(const Pelota &otro);
    bool operator!=(const Pelota &otro);
};

void mover(Pelota &p);
void pintar(const Pelota &p);

#endif /* PELOTA_H */

