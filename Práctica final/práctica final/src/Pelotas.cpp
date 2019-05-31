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
Pelotas::Pelotas() {
    v = nullptr;
    capacidad = 0;
    util = 0;
}

Pelotas::Pelotas(const Pelotas &otro) {
    // Reservar array auxiliar:
    Pelota * aux = new Pelota[otro.capacidad];

    // Copiar datos:
    memcpy(aux, otro.v, otro.capacidad * sizeof(Pelota));

    // Liberar antiguo:
    liberar();

    // Asignar el nuevo:
    v = aux;

    capacidad = otro.capacidad;
    util = otro.util;
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
    if(b < util) {
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

void Pelotas::redimensionar() {
    // Reservar array auxiliar:
    Pelota * aux = new Pelota[capacidad + 1];

    
    if(v != nullptr) {
        // Copiar datos:
        memcpy(aux, v, capacidad * sizeof(Pelota));

        // Liberar antiguo:
        liberar();
    }
    
    // Asignar el nuevo:
    v = aux;

    // Aumentar la capacidad:
    ++capacidad;
}

void Pelotas::liberar() {
    delete [] v;
}

Pelotas & Pelotas::operator=(Pelotas &otro) {
    if (this != &otro)
        *this = otro;

    return *this;
}

Pelotas & Pelotas::operator+=(Pelota &p) {
    aniadir(p);

    return *this;
}

Pelota & Pelotas::operator[](const int i) {
    
    if (i < 0 || i >= util) {
        throw out_of_range("Indice fuera de rango en acceso con []");
    }
    else
        return v[i];
}

Pelota Pelotas::operator[](const int i) const {
    if (i < 0 || i >= util) {
        throw out_of_range("Indice fuera de rango en acceso con []");
    }
    else
        return v[i];
}

istream &operator>>(istream &fi, Pelotas &p)  { 
        int contador;
        
        fi >> contador;

        cout << contador << endl;
        for(int i = 0; i < contador; i++)   {
            float nx, ny, vx, vy, r;
            PColor nc;
            string color;
            fi >> nx >> ny >> vx >> vy >> r >> color;

            if (color == "NEGRO") 
                nc = PColor::NEGRO;
            else if (color == "ROJO")
                nc = PColor::ROJO;
            else if (color == "VERDE")
                nc = PColor::VERDE;
            else if (color == "AZUL")
                nc = PColor::AZUL;
            else if (color == "AMARILLO")
                nc = PColor::AMARILLO;
            else if (color == "MAGENTA")
                nc = PColor::MAGENTA;
            else if (color == "CYAN")
                nc = PColor::CYAN;
            else if (color == "BLANCO")
                nc = PColor::BLANCO;
            else {
                cerr << "Color mal" << endl;
                exit(1);
            }
            
            Pelota * pel = new Pelota(nx, ny, vx, vy, r, nc);
            p += *pel;
        }
        return fi;            
    }