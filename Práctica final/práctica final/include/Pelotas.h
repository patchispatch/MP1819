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
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <string>
#include <ctype.h>
using namespace std;
class Pelotas {
private:
    Pelota * v;
    int capacidad;
    int util;

public:
    Pelotas(); 
    Pelotas(const Pelotas &otro); 
    ~Pelotas(); 

    int getCapacidad() {return capacidad;}
    int getUtil() {return util;}
    
    void aniadir(Pelota &p);
    void borrar(int i);
    Pelota obtener(int i);

    Pelotas & operator=(Pelotas &otro);
    Pelotas & operator+=(Pelota &p);

    Pelota & operator[](const int i);
    Pelota operator[](const int i) const;

    friend istream &operator>>(istream &fi, Pelotas &p);

private:
    void redimensionar();
    void liberar();
};

#endif /* PELOTAS_H */


