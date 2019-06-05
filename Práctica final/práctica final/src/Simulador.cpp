// **********************************************
// METODOLOGÍA DE LA PROGRAMACIÓN
// AUTORES: JUAN OCAÑA VALENZUELA
//          AARÓN PADIAL VÁZQUEZ
//
// Simulador.cpp
// Implementación de la clase Simulador.
// **********************************************


#include "Simulador.h"

Simulador::Simulador(string path) {
    ifstream fi;
    fi.open(path);
    
    string cabecera;
    fi >> cabecera;

    if(!fi) {
        cerr << "Formato de archivo erróneo." << endl;
        exit(1);
    }

    if(cabecera != "MP-PELOTAS-T-1.0") {
        cerr << "Error de lectura de fichero\n";
        exit(2);
    }

    fi >> ancho;
    fi >> alto;
    vredimensiona(ancho, alto);

    // Pelotas:
    original = Pelotas();
    fi >> original;
    actual = original;

    fi.close();
}

Simulador::Simulador(const Simulador& otro) {
    ancho = otro.ancho;
    alto = otro.alto;
    original = otro.original;
    actual = otro.actual;
}

Simulador::~Simulador() {
    vcierra();
}

void Simulador::setActual(const Pelotas &p) {
    actual = p;
}

Pelotas Simulador::getOriginal() {
    return original;
}

Pelotas Simulador::getActual() {
    return actual;
}

void Simulador::step(int n) {
    for(int i = 0; i < n; ++i)
        actual.mover();
}

bool Simulador::salvar(string path) {
    ofstream fo;
    fo.open(path);

    if(!fo) {
        return false;
    }

    fo << "MP-PELOTAS-T-1.0" << "\n" << ancho << "\n" << alto << "\n";
    fo << actual;

    fo.close();

    return true;
}

void Simulador::pintar(int seg) {
    borra();
    
    for(int i = 0; i < actual.getUtil(); ++i) {
        pintar_pelota(actual[i]);
    }

    refresca();
    espera(seg);
}

