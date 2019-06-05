// **********************************************
// METODOLOGÍA DE LA PROGRAMACIÓN
// AUTORES: JUAN OCAÑA VALENZUELA
//          AARÓN PADIAL VÁZQUEZ
//
// Pelotas.cpp
// Implementación de la clase pelota y funciones asociadas.
// **********************************************



#include<cstdlib>
#include<cmath>
#include "Pelota.h"
#include "miniwin.h"

Pelota::Pelota() {
    srand(time(NULL));
    x = rand() % int(MIN_X);
    y = rand() % int(MIN_Y);
    dx = rand() % int(MAX_VEL);
    dy = rand() % int(MAX_VEL);
    radio = rand() % int(MAX_RADIO);
    color = PColor::ROJO;
}

Pelota::Pelota(float nx, float ny) {
    x = nx;
    y = ny;
    dx = MAX_VEL;
    dy = MAX_VEL;
    color = PColor::ROJO;
    radio = MAX_RADIO;
}

Pelota::Pelota(float nx, float ny, float r, PColor nc) {
    x = nx;
    y = ny;
    dx = MAX_VEL;
    dy = MAX_VEL;
    color = nc;
    radio = r;
}

Pelota::Pelota(float nx, float ny, float vx, float vy, float r, PColor nc) {
    x = nx;
    y = ny;
    dx = vx;
    dy = vy;
    radio = r;
    color = nc;
}

Pelota::Pelota(const Pelota& orig) {
   *this = orig;
}

float Pelota::distancia(const Pelota &otro) {
    float dist;
    float sum_x = x - otro.x;
    float sum_y = y - otro.y;

	dist = pow(sum_x, 2) + pow(sum_y, 2);
	dist = sqrt(dist);
    dist -= (radio + otro.radio);

    return dist;
}

bool Pelota::colisionado(const Pelota &otro) {
    bool r = false;
    if(distancia(otro) <= UMBRAL) {
        r = true;
    }
    return r;
}

void Pelota::colisionar(Pelota &otro) {
    float dx_temp, dy_temp;
    dx_temp = dx;
    dy_temp = dy;
    dx = otro.dx;
    dy = otro.dy;
    otro.dx = dx_temp;
    otro.dy = dy_temp; 
}

const Pelota & Pelota::operator=(const Pelota &orig) {
    x = orig.x;
    y = orig.y;
    dx = orig.dx;
    dy = orig.dy;
    color = orig.color;
    radio = orig.radio;

    return *this;  
}

bool Pelota::operator==(const Pelota &otro) {
    return (color == otro.color && radio == otro.radio);
}

bool Pelota::operator!=(const Pelota &otro) {
    return !(*this == otro);
}

ostream & operator<<(ostream &fo, Pelota &p) {
    fo << p.x << " " << p.y << " " << p.dx << " " 
    << p.dy << " " << p.radio << " " ;

    string nc;
    PColor color = p.color;

    if (color == PColor::NEGRO) 
        nc = "NEGRO";
    else if (color == PColor::ROJO)
        nc = "ROJO";
    else if (color == PColor::VERDE)
        nc = "VERDE";
    else if (color == PColor::AZUL)
        nc = "AZUL";
    else if (color == PColor::AMARILLO)
        nc = "AMARILLO";
    else if (color == PColor::MAGENTA)
        nc = "MAGENTA";
    else if (color == PColor::CYAN)
        nc = "CYAN";
    else if (color == PColor::BLANCO)
        nc = "BLANCO";
    else {
        cerr << "Color mal" << endl;
        exit(1);
    }

    fo << nc << "\n";

    return fo;
}