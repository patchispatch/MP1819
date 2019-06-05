// **********************************************
// METODOLOGÍA DE LA PROGRAMACIÓN
// AUTORES: JUAN OCAÑA VALENZUELA
//          AARÓN PADIAL VÁZQUEZ
//
// main.cpp
// Programa principal.
// **********************************************

#include "miniwin.h"
#include "Simulador.h"


int main() {
    Simulador partida("data/pelotas.txt");

    while (tecla() != ESCAPE) {
        partida.step(1);
        partida.pintar(25);
    }

    bool ok = partida.salvar("data/salida.txt");
    if(!ok) {
        std::cerr << "Error de escritura.";
    }

    // Probar la sobrecarga de << de pelotas
    Pelotas local = partida.getActual();
    std::cout << "Estado final: \n";
    std::cout << local;

    Pelota p1 = partida.getOriginal()[0];
    Pelota p2 = partida.getActual()[0];

    std::cout << p1 << "\n" << p2 << "son:";
    if(p1==p2)
        std::cout << "iguales \n";
    else
        std::cout << "diferentes \n";
    
    std::cout << "\n!!!!! 1 obstaculo: " << std::endl;
    
    return 0;
}