// **********************************************
// METODOLOGÍA DE LA PROGRAMACIÓN
// AUTOR: JUAN OCAÑA VALENZUELA
//
// prueba_pelota.cpp
// Programa para probar la clase Pelota.
// **********************************************

#include "miniwin.h"
#include "Pelota.h"
using namespace miniwin;

int main() {
    vredimensiona(800, 600);

    // Pelotas:
    Pelota * p1 = new Pelota();
    Pelota * p2 = new Pelota(32, 35, PColor.VERDE, 3.0);

    // Bucle de pintado:
    while (tecla() != ESCAPE) {
        borra();
        mueve_pelota(P);
        pinta_pelota(P);
        refresca();
        espera(25);
   }
   
   // Cerrar la ventana:
   vcierra();
   return 0;
}
