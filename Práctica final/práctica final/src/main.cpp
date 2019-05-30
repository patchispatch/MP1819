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
    Pelotas p = Pelotas();
    Pelota * p1 = new Pelota();
    Pelota * p2 = new Pelota(32, 35, 3, PColor::VERDE);

    p.aniadir(*p1);
    p.aniadir(*p2);

    // Bucle de pintado:
    while (tecla() != ESCAPE) {
        borra();
        mover(p[0]);
        mover(p[1]);
        pintar(p[0]);
        pintar(p[1]);
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

