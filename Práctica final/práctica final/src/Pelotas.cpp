// **********************************************
// METODOLOGÍA DE LA PROGRAMACIÓN
// AUTORES: JUAN OCAÑA VALENZUELA
//          AARÓN PADIAL VÁZQUEZ
//
// Pelotas.cpp
// Definición de la clase pelotas.
// **********************************************

#include "Pelotas.h"

// Crea un objeto Pelotas con capacidad = c:
Pelotas::Pelotas(int c) {
    // Primero reservamos el espacio:
    v = reservar(c);

    // Actualizamos la capacidad:
    capacidad = c;

    // Inicializamos util a 0:
    util = 0;
}

Pelotas::Pelotas(const Pelotas &otro) {
    // Copiamos el array:
    Pelota * aux = reservar(otro.capacidad);
    memcpy(aux, otro.v, otro.capacidad * sizeof(Pelota));

    // Asignamos el puntero:
    v = aux;
}

Pelotas::~Pelotas() {
    liberar();
    capacidad = 0;
    util = 0;
}

void Pelotas::aniadir(Pelota &p) {
    if(util + 1 >= capacidad) {
        redimensionar();
    }
    
    v[util] = p;
    ++util;
}

void Pelotas::borrar(int b) {
    if(i < util) {
        // Copiar todo menos el elemento a borrar:
        for(int i = 0; i < util-1; ++i) {
            if(i >= b) {
                v[i] = v[i+1];
            }
        }

        --util; 
    }
    else {
        throw out_of_range("Index out of bounds.");
    }
}

Pelota * Pelotas::reservar(int c) {
    Pelota * aux = new Pelota[c];

    return aux;
}

void Pelota::redimensionar() {
    // Reservar array auxiliar:
    Pelota * aux = reservar(capacidad + 1);

    // Copiar datos:
    memcpy(aux, v, capacidad * sizeof(Pelota));

    // Liberar antiguo:
    liberar();

    // Asignar el nuevo:
    v = aux;

    // Aumentar la capacidad:
    ++capacidad;
}

void Pelotas::liberar() {
    delete [] v;
}

Pelotas & Pelotas::operator=(Pelotas &otro) {
    // Reservar array auxiliar:
    Pelota * aux = reservar(otro.capacidad);

    // Copiar datos:
    memcpy(aux, otro.v, otro.capacidad * sizeof(Pelota));

    // Liberar antiguo:
    liberar();

    // Asignar el nuevo:
    v = aux;
}

Pelotas & Pelotas::operator+=(Pelota &p) {
    aniadir(p);
}

Pelota & Pelotas::operator[](int i) {
    
    if (i < 0 || i >= util) {
        throw out_of_range("Indice fuera de rango en acceso con []");
    }

    return v[i];
}

Pelota Pelotas::operator[](int i) const {
    return v[i];
}


