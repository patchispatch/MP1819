// **********************************************
// METODOLOGÍA DE LA PROGRAMACIÓN
// AUTORES: JUAN OCAÑA VALENZUELA
//          AARÓN PADIAL VÁZQUEZ
//
// Pelotas.cpp
// Implementación de la clase pelota y funciones asociadas.
// **********************************************



#include<cstdlib>
#include<cmath>
#include "Pelota.h"
#include "miniwin.h"

Pelota::Pelota() {
    srand(time(NULL));
    x = rand() % int(MIN_X);
    y = rand() % int(MIN_Y);
    dx = rand() % int(MAX_VEL);
    dy = rand() % int(MAX_VEL);
    radio = rand() % int(MAX_RADIO);
    color = PColor::ROJO;
}

Pelota::Pelota(float nx, float ny) {
    x = nx;
    y = ny;
    dx = MAX_VEL;
    dy = MAX_VEL;
    color = PColor::ROJO;
    radio = MAX_RADIO;
}

Pelota::Pelota(float nx=34, float ny=34, PColor nc=PColor::ROJO, float r=MAX_RADIO) {
    x = nx;
    y = ny;
    dx = MAX_VEL;
    dy = MAX_VEL;
    color = nc;
    radio = r;
}


Pelota::Pelota(const Pelota& orig) {
    x = orig.x;
    y = orig.y;
    dx = orig.dx;
    dy = orig.dy;
    color = orig.color;
}

float Pelota::distancia(const Pelota &otro) {
    float d = sqrt((x*x - otro.x*otro.x) + (y*y - otro.y*otro.y));
    d -= (radio + otro.radio);

    return d;
}

bool Pelota::colisionado(const Pelota &otro) {
    bool r = false;
    if(distancia(otro) <= UMBRAL) {
        r = true;
    }

    return r;
}

void mover(Pelota &p) {
    p.setX(p.getX() + p.getDX());
    p.setY(p.getY() + p.getDY());
    
    if (p.getX() > miniwin::vancho() - p.getRadio()) {
        p.setDX(-p.getDX() * FACTOR);
        p.setX(miniwin::vancho() - p.getRadio());
   } 
	else if (p.getX() < p.getRadio()) {
        p.setDX(-p.getDX() * FACTOR);
        p.setX(p.getRadio());
   } 
	else if (p.getY() > miniwin::valto() - p.getRadio()) {
        p.setDY(-p.getDY() * FACTOR);
        p.setY(miniwin::valto() - p.getRadio());
   } 
	else if (p.getY() < p.getRadio()) {
        p.setDY(-p.getDY() * FACTOR);
        p.setY(p.getRadio());
   }
}

void pintar(const Pelota &p) {
   miniwin::color((int) p.getColor());
   miniwin::circulo_lleno(p.getX(), p.getY(), p.getRadio());
}



