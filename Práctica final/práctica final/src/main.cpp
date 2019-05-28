// **********************************************
// METODOLOGÍA DE LA PROGRAMACIÓN
// AUTORES: JUAN OCAÑA VALENZUELA
//          AARÓN PADIAL VÁZQUEZ
//
// main.cpp
// Programa principal.
// **********************************************

#include "miniwin.h"
#include "Pelotas.h"
using namespace miniwin;

int main() {
    vredimensiona(800, 600);

    // Pelotas:
    Pelotas * p = new Pelotas();
    Pelota * p1 = new Pelota();
    Pelota * p2 = new Pelota(32, 35, PColor::VERDE);

    // Bucle de pintado:
    while (tecla() != ESCAPE) {
        borra();
        mover(*p1);
        mover(*p2);
        pintar(*p1);
        pintar(*p2);
        refresca();
        espera(25);
    }

    // Cerrar la ventana:
    vcierra();

    // Liberar memoria:
    delete p1;
    delete p2;

    return 0;
}

