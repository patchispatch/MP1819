#include <iostream>
#include <cmath>
#include "punto.h"

void Punto::setX(double nuevoX)  {
	x = nuevoX;
}

void Punto::setY(double nuevoY)  {
	y = nuevoY;
}
 
 
void Punto::escribir() const{
    std::cout << "(" << x << "," << y << ")" << std::endl;
}


void Punto::leer(){
    // Formato de lectura del punto: (x,y)
    char car;
    std::cin >> car >> x >> car >> y >> car;
}

/// Clase Punto

/// Funciones auxiliares (no son métodos de la clase)

/**
@brief Calcula la distancia entre dos puntos
@param p1 primer punto
@param p2 segundo punto
@return la distancia entre el punto @a p1 y el punto @a p2
*/
double distancia(Punto p1, Punto p2){
    return sqrt((p1.getX()-p2.getX())*(p1.getX()-p2.getX()) +
         (p1.getY()-p2.getY())*(p1.getY()-p2.getY()));
}


/**
@brief Calcula el punto que está entre dos puntos dados con distancia mínima a ambos
@param p1 primer punto
@param p2 segundo punto
@return un punto entre el punto @a p1 y el punto @a p2 con distancia mínima a ambos
*/
Punto puntoMedio(Punto p1, Punto p2){
    Punto pMedio;
    pMedio.setX((p1.getX()+p2.getX())/2.0);
    pMedio.setY((p1.getY()+p2.getY())/2.0);
    return pMedio;
}