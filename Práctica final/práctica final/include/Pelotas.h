// **********************************************
// METODOLOGÍA DE LA PROGRAMACIÓN
// AUTORES: JUAN OCAÑA VALENZUELA
//          AARÓN PADIAL VÁZQUEZ
//
// Pelotas.h
// Definición de la clase pelotas.
// **********************************************

#ifndef PELOTAS_H
#define PELOTAS_H

#include "Pelota.h"
#include <cstring>

class Pelotas {
private:
    Pelota * v;
    int capacidad;
    int util;

public:
    Pelotas(int c); 
    Pelotas(const Pelotas &otro); 
    ~Pelotas(); 

    int getCapacidad() {return capacidad;}
    int getUtil() {return util;}
    
    void aniadir(Pelota &p);
    void borrar(int i);
    Pelota obtener(int i);

    Pelotas & operator=(Pelotas &otro);
    Pelotas & operator+=(Pelotas &otro);//

    Pelota & operator[](int i);
    Pelota operator[](int i) const;
    
private:
    Pelota * reservar(int c);
    void redimensionar();
    void liberar();
}

#endif /* PELOTAS_H */


