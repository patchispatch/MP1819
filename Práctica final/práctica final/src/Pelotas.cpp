// **********************************************
// METODOLOGÍA DE LA PROGRAMACIÓN
// AUTORES: JUAN OCAÑA VALENZUELA
//          AARÓN PADIAL VÁZQUEZ
//
// Pelotas.cpp
// Definición de la clase pelotas.
// **********************************************

#ifndef PELOTAS_H
#define PELOTAS_H

#include "Pelota.h"

class Pelotas {
private:
    Pelota * v;
    int capacidad;
    int util;

public:
    Pelotas(int c);
    ~Pelotas();

    void setCapacidad(int c);
    void setUtil(int c);
    int getCapacidad() {return capacidad;}
    int getUtil() {return util;}
    
    void aniadir(Pelota &p);
    void eliminar(const Pelota &p);
    Pelota get(int i);

    void clear();
private:
    void redimensionar();

}

#endif /* PELOTAS_H */

