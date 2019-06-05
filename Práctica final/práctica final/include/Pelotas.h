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
#include "utilidades.h"
#include <cstring>
#include <stdexcept>
#include <string>
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

    void mover();

    Pelotas & operator=(const Pelotas &otro);
    Pelotas & operator+=(Pelota &p);

    Pelota & operator[](const int i);
    Pelota operator[](const int i) const;

    void comprobarColisiones();
    friend istream &operator>>(istream &fi, Pelotas &p);
    friend ostream &operator<<(ostream &fo, Pelotas &p);

private:
    void redimensionar();
    void liberar();
};

#endif /* PELOTAS_H */


