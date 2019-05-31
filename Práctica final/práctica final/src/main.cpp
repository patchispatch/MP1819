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
#include <fstream>
using namespace miniwin;
using namespace std;

int main() {
    ifstream fi;
    ofstream fo;
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
    fi >> p;

    //p.aniadir(*p1);
    //p.aniadir(*p2);
    cout << p[0].getRadio();
    fo.open("data/salida.txt");

    // Bucle de pintado:
    while (tecla() != ESCAPE) {
        borra();
        p.comprobarColisiones();
        for(int i = 0; i < p.getUtil(); ++i) {
            mover(p[i]);
            pintar(p[i]);
        }

        refresca();
        espera(25);
    }

    fo << cabecera << "\n" << ancho << "\n" << alto << "\n";
    fo << p;


    // Cerrar la ventana:
    vcierra();
    return 0;
}