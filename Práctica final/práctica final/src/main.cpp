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
using namespace std;


    /*
    if (argc != 2) {
        cerr << "Número de argumentos incorrecto." << endl;
        return 1;
    }
    else {
        fi.open(argv[1]);
    }
    */
int main() {
    ifstream fi;

    fi.open("./data/pelotas.txt");
    string cabecera;
    fi >> cabecera;

    if(!fi) {
        cerr << "hola" << endl;
        return 2;
    }

    if(cabecera != "MP-PELOTAS-T-1.0") {
        cerr << "error de lectura de fichero\n";
        return 1;
    }

    int ancho;
    fi >> ancho;
    int alto;
    fi >> alto;
    vredimensiona(ancho, alto);

    // Pelotas:
    Pelotas p = Pelotas();
    //Pelota * p1 = new Pelota();
    //Pelota * p2 = new Pelota(32, 35, 3, PColor::VERDE);
    fi >> p;

    //p.aniadir(*p1);
    //p.aniadir(*p2);

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

