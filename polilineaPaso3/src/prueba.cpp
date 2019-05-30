/* 
 * File:   prueba.cpp
 * Author: mgomez
 *
 * Created on 7 de abril de 2019, 21:18
 */

#include <cstdlib>
#include <assert.h>
#include "polilinea.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    // se crea objeto de la clase Polilinea con los 3 constructores
    // definidos
    Polilinea poli1;
    Polilinea poli2(10);
    Polilinea poli3(1, 2.3, 3.4);
    int numeroVertices, espacioReservado;

    // se muestran por pantalla
    cout << "------------------- PASO 1 ----------------------" << endl;
    cout << "Polilinea creada con constructor por defecto: " << endl;
    poli1.mostrar();
    // se prueban las dimensiones de poli1
    espacioReservado = poli1.obtenerEspacioReservado();
    numeroVertices = poli1.obtenerNumeroVertices();
    cout << "vertices y espacio poli1 (deben ser 0 y 0): ---------------------------" << endl;
    assert(numeroVertices == 0 && espacioReservado == 0);
    cout << "------------------------------------------------" << endl;
    cout << endl;
    
    // se prueban las dimensiones de poli2
    cout << "------------------- PASO 2 ----------------------" << endl;
    cout << "Polilinea con constructor para reserva de 10 vertices: " << endl;
    poli2.mostrar();
    espacioReservado = poli2.obtenerEspacioReservado();
    numeroVertices = poli2.obtenerNumeroVertices();
    cout << "vertices y espacio poli2 (deben ser 0 y 10): ---------------------------" << endl;
    assert(numeroVertices == 0 && espacioReservado == 10);
    cout << "------------------------------------------------" << endl;
    cout << endl;

    // se prueban las dimensiones de poli3
    cout << "------------------- PASO 3 ----------------------" << endl;
    cout << "Polilinea con constructor con coordenadas de punto: " << endl;
    poli3.mostrar();
    espacioReservado = poli3.obtenerEspacioReservado();
    numeroVertices = poli3.obtenerNumeroVertices();
    cout << "vertices y espacio poli3 (deben ser 1 y 1): ---------------------------" << endl;
    assert(numeroVertices == 1 && espacioReservado == 1);
    cout << "------------------------------------------------" << endl;
    cout << endl;

    
    // se prueba el metodo de obtencion de vertice, con
    // indices validos e incorrectos para comprobar
    // el mecanismo de las excepciones
    // se intenta obtener vertice de indice 0 sobre poli1. Esto
    // debe generar el salto de la excepcion
    cout << "------------------- PASO 4 ----------------------" << endl;
    try {
        Punto poli1Vert0 = poli1.obtenerVertice(0);

        // si no se genera la excepcion, podemos visualizar el
        // punto
        cout << "punto obtenido de poli1: ";
        poli1Vert0.mostrar();
    } catch (invalid_argument &exception) {
        cout << "problema ejecucion: " << exception.what() << endl;
    }
    cout << "------------------------------------------------" << endl;
    cout << endl;

    // se prueba ahora con indice 5 en poli2: tambien debe fallar,
    // ya que se ha reservado espacio, pero no hay datos utiles
    cout << "------------------- PASO 5 ----------------------" << endl;
    try {
        Punto poli2Vert5 = poli2.obtenerVertice(5);

        // se muestra el punto obtenido
        cout << "punto obtenido de poli2: ";
        poli2Vert5.mostrar();
    } catch (invalid_argument &exception) {
        cout << "problema ejecucion: " << exception.what() << endl;
    }
    cout << "------------------------------------------------" << endl;
    cout << endl;

    // se prueba ahora con poli3, que si tiene un vertice
    // valido en la posicion 0
    cout << "------------------- PASO 6 ----------------------" << endl;
    try {
        Punto poli3Vert0 = poli3.obtenerVertice(0);

        // se muestra el punto obtenido
        cout << "punto obtenido de poli3: ";
        poli3Vert0.mostrar();
    } catch (invalid_argument &exception) {
        cout << "problema ejecucion: " << exception.what() << endl;
    }
    cout << "------------------------------------------------" << endl;
    cout << endl;

    // se prueba el metodo de asignacion de vertice. Se 
    // prueban diferentes escenarios. Si se llama sobre poli1
    // y posicion 0, se reservara espacio para 10 vertices y
    // el pasado como argumento se almacenara en la posicion 0
    cout << "------------------- PASO 7 ----------------------" << endl;
    bool resultado = poli1.asignarVertice(0, 1.1, 2.2);
    cout << "resultado de asignacion de vertice en poli1: " << resultado << endl;
    cout << "contenido de poli1 tras asignacion de vertice en indice 0: " << endl;
    poli1.mostrar();
    // se prueban las dimensiones de poli1
    espacioReservado = poli1.obtenerEspacioReservado();
    numeroVertices = poli1.obtenerNumeroVertices();
    cout << "vertices y espacio poli1 (deben ser 1 y 10): ---------------------------" << endl;
    assert(numeroVertices == 1 && espacioReservado == 10);
    cout << "------------------------------------------------" << endl;
    cout << endl;

    // se asigna punto en posicion 1
    cout << "------------------- PASO 8 ----------------------" << endl;
    resultado = poli1.asignarVertice(1, 1.1, 2.2);
    cout << "resultado de asignacion de vertice en poli1: " << resultado << endl;
    cout << "contenido de poli1 tras asignacion de vertice en indice 10: " << endl;
    poli1.mostrar();
    // se prueban las dimensiones de poli1
    espacioReservado = poli1.obtenerEspacioReservado();
    numeroVertices = poli1.obtenerNumeroVertices();
    cout << "vertices y espacio poli1 (deben ser 2 y 10): ---------------------------" << endl;
    assert(numeroVertices == 2 && espacioReservado == 10);
    cout << "------------------------------------------------" << endl;
    cout << endl;
    
    // se asigna punto en posicion 15
    cout << "------------------- PASO 9 ----------------------" << endl;
    resultado=poli1.asignarVertice(15, 15.0, 15.0);
    cout << "resultado de asignacion de vertice en poli1: " << resultado << endl;
    cout << "contenido de poli1 tras asignacion de vertice en indice 15: " << endl;
    poli1.mostrar();
    // se prueban las dimensiones de poli1
    espacioReservado = poli1.obtenerEspacioReservado();
    numeroVertices = poli1.obtenerNumeroVertices();
    cout << "vertices y espacio poli1 (deben ser 16 y 25): ---------------------------" << endl;
    assert(numeroVertices == 16 && espacioReservado == 25);
    cout << "------------------------------------------------" << endl;
    cout << endl;

    // se inserta sobre poli3 en la posicion 0. En este caso no hace
    // falta reservar espacio nuevo
    cout << "------------------- PASO 10 ----------------------" << endl;
    resultado = poli3.asignarVertice(0, 1.1, 2.2);
    cout << "resultado de asignacion de vertice en poli3: " << resultado << endl;
    cout << "contenido de poli3 tras asignacion de vertice en indice 0: " << endl;
    poli3.mostrar();
    // se prueban las dimensiones de poli3
    espacioReservado = poli3.obtenerEspacioReservado();
    numeroVertices = poli3.obtenerNumeroVertices();
    cout << "vertices y espacio poli3 (deben ser 1 y 1): ---------------------------" << endl;
    assert(numeroVertices == 1 && espacioReservado == 1);
    cout << "------------------------------------------------" << endl;
    cout << endl;
    
    // se prueba a insertar en la posicion 0 en poli3
    cout << "------------------- PASO 11 ----------------------" << endl;
    resultado = poli3.insertarVertice(0, -3.4, -2.9);
    cout << "resultado de insercion de vertice en poli3: " << resultado << endl;
    cout << "contenido de poli3 tras insercion de vertice en indice 0: " << endl;
    poli3.mostrar();
    // se prueban las dimensiones de poli3
    espacioReservado = poli3.obtenerEspacioReservado();
    numeroVertices = poli3.obtenerNumeroVertices();
    cout << "vertices y espacio poli3 (deben ser 2 y 11): ---------------------------" << endl;
    assert(numeroVertices == 2 && espacioReservado == 11);
    cout << "------------------------------------------------" << endl;
    cout << endl;

    // se prueba a insertar en la posicion 2 en poli3 
    cout << "------------------- PASO 12 ----------------------" << endl;
    resultado = poli3.insertarVertice(2, -9.4, -10.9);
    cout << "resultado de insercion de vertice en poli3: " << resultado << endl;
    cout << "contenido de poli3 tras insercion de vertice en indice 1: " << endl;
    poli3.mostrar();
    // el resultado de la insercion debe ser false
    assert(resultado == false);
    cout << "------------------------------------------------" << endl;
    cout << endl;
    
    // se prueba a insertar en la posicion 1 en poli3 
    cout << "------------------- PASO 13 ----------------------" << endl;
    resultado = poli3.insertarVertice(1, -9.4, -10.9);
    cout << "resultado de insercion de vertice en poli3: " << resultado << endl;
    cout << "contenido de poli3 tras insercion de vertice en indice 1: " << endl;
    poli3.mostrar();
    // el resultado de la insercion debe ser false
    assert(resultado == true);
    // se prueban las dimensiones de poli3
    espacioReservado = poli3.obtenerEspacioReservado();
    numeroVertices = poli3.obtenerNumeroVertices();
    cout << "vertices y espacio poli3 (deben ser 3 y 11): ---------------------------" << endl;
    assert(numeroVertices == 3 && espacioReservado == 11);
    cout << "------------------------------------------------" << endl;
    cout << endl;

    // se prueba a insertar en posicion intermedia de poli1
    cout << "------------------- PASO 14 ----------------------" << endl;
    resultado = poli1.insertarVertice(5, -9.4, -10.9);
    cout << "resultado de insercion de vertice en poli1: " << resultado << endl;
    cout << "contenido de poli1 tras insercion de vertice en indice 5: " << endl;
    poli1.mostrar();
    // se prueban las dimensiones de poli1
    espacioReservado = poli1.obtenerEspacioReservado();
    numeroVertices = poli1.obtenerNumeroVertices();
    cout << "vertices y espacio poli1 (deben ser 17 y 25): ---------------------------" << endl;
    assert(numeroVertices == 17 && espacioReservado == 25);
    cout << "------------------------------------------------" << endl;
    cout << endl;
    
    // se prueba a insertar en posicion mas alla de espacioReservado
    cout << "------------------- PASO 15 ----------------------" << endl;
    resultado = poli1.insertarVertice(20, -9.4, -10.9);
    cout << "resultado de insercion de vertice en poli1: " << resultado << endl;
    cout << "contenido de poli1 tras insercion de vertice en indice 20: " << endl;
    poli1.mostrar();
    assert(resultado == false);
    cout << "------------------------------------------------" << endl;
    cout << endl;
    
    // borrado de vertice en indice 0 sobre poli1
    cout << "------------------- PASO 16 ----------------------" << endl;
    resultado = poli1.borrarVertice(0);
    cout << "resultado de borrado de vertice en poli1: " << resultado << endl;
    cout << "contenido de poli1 tras borrado de vertice en indice 0: " << endl;
    poli1.mostrar();
    // se prueban las dimensiones de poli1
    espacioReservado = poli1.obtenerEspacioReservado();
    numeroVertices = poli1.obtenerNumeroVertices();
    cout << "vertices y espacio poli1 (deben ser 16 y 25): ---------------------------" << endl;
    assert(numeroVertices == 16 && espacioReservado == 25);
    cout << "------------------------------------------------" << endl;
    cout << endl;
    
    // borrado de ultimo vertice en indice 4 sobre poli1
    cout << "------------------- PASO 17 ----------------------" << endl;
    resultado = poli1.borrarVertice(15);
    cout << "resultado de borrado de vertice en poli1: " << resultado << endl;
    cout << "contenido de poli1 tras borrado de vertice en indice 15: " << endl;
    poli1.mostrar();
    // se obtiene espacio reservado de poli1
    espacioReservado = poli1.obtenerEspacioReservado();
    numeroVertices = poli1.obtenerNumeroVertices();
    cout << "vertices y espacio poli1 (deben ser 15 y 25): ---------------------------" << endl;
    assert(numeroVertices == 15 && espacioReservado == 25);
    cout << "------------------------------------------------" << endl;
    cout << endl;
        
    // prueba de union de poli1 y poli3
    cout << "------------------- PASO 18 ----------------------" << endl;
    Polilinea * poliUnion=poli1.unionOp(poli3);
    cout << "resultado de union de poli1 y poli3: " << endl;
    poliUnion->mostrar();
    // se obtiene espacio reservado de poliUnion
    espacioReservado = poliUnion->obtenerEspacioReservado();
    numeroVertices = poliUnion->obtenerNumeroVertices();
    cout << "vertices y espacio poliUnion (deben ser 18 y 28): ---------------------------" << endl;
    assert(numeroVertices == 18 && espacioReservado == 28);
    cout << "------------------------------------------------" << endl;
    cout << endl;
   
    // prueba de interseccion entre poliUnion y poli3
    cout << "------------------- PASO 19 ----------------------" << endl;
    Polilinea * poliInterseccion=poliUnion->interseccionOp(poli3);
    cout << "resultado de interseccion de poliUnion y poli3: " << endl;
    poliInterseccion->mostrar();
    // se obtiene espacio reservado de poliInterseccion
    espacioReservado = poliInterseccion->obtenerEspacioReservado();
    numeroVertices = poliInterseccion->obtenerNumeroVertices();
    cout << "vertices y espacio poliInterseccion (deben ser 3 y 10): ---------------------------" << endl;
    assert(numeroVertices == 3 && espacioReservado == 10);
    cout << "------------------------------------------------" << endl;
    cout << endl;
    
    // se hace uso del constructor de copia
    cout << "------------------- PASO 19 ----------------------" << endl;
    Polilinea poli4(poli3);
    cout << "resultado de constructor de copia de poli3: " << endl;
    poli4.mostrar();
    // se obtiene espacio reservado de poli4
    espacioReservado = poli4.obtenerEspacioReservado();
    numeroVertices = poli4.obtenerNumeroVertices();
    cout << "vertices y espacio poli4 (deben ser 3 y 11): ---------------------------" << endl;
    assert(numeroVertices == 3 && espacioReservado == 11);
    cout << "------------------------------------------------" << endl;
    cout << endl;

    // se libera el espacio de poliUnion y poliInterseccion
    delete poliInterseccion;
    delete poliUnion;
    
    cout << "salida del programa principal" << endl;
    
    return 0;
}

