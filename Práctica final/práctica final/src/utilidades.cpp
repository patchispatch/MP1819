// **********************************************
// METODOLOGÍA DE LA PROGRAMACIÓN
// AUTORES: JUAN OCAÑA VALENZUELA
//          AARÓN PADIAL VÁZQUEZ
//
// utilidades.cpp
// Implementación de funciones útiles para el proyecto.
// **********************************************
#include "utilidades.h"

void mover_pelota(Pelota &p) {
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

void pintar_pelota(const Pelota &p) {
   miniwin::color((int) p.getColor());
   miniwin::circulo_lleno(p.getX(), p.getY(), p.getRadio());
}