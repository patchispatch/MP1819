// **********************************************
// METODOLOGÍA DE LA PROGRAMACIÓN
// AUTORES: JUAN OCAÑA VALENZUELA
//          AARÓN PADIAL VÁZQUEZ
//
// Simulador.cpp
// Definición de la clase Simulador.
// **********************************************

#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <string>
#include <fstream>
#include "Pelotas.h"
using namespace std;
using namespace miniwin;

class Simulador {
private:
    int ancho, alto;
    Pelotas original;
    Pelotas actual;

public:
    Simulador(string path);
    Simulador(const Simulador& otro);
    ~Simulador();

    void setActual(const Pelotas &p);
    Pelotas getOriginal();
    Pelotas getActual();

    void step(int n);
    bool salvar(string path);

    void pintar(int seg);
    
private:

};

#endif /* SIMULADOR_H */

