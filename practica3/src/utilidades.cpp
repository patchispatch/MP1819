//
// Created by mgomez on 16/02/17.
// editado by acid on 27/02/19
//

#include "utilidades.h"
using namespace std;

void leerContenido(Valor coleccion[], int & util){
    int fila,columna; 
    double valor;
    cout << "Nuevo vector" << endl;
    do{
      cout << "Introduce cuantos: ";
      cin >> util;
    }while (util > CAPACIDAD/2);
    
    for(int i = 0; i < util; i++){
        cin >> fila;
        cin >> columna;
        cin >> valor;
        coleccion[i]= Valor(fila, columna, valor);
    } 
    
}

void mostrarContenido(Valor const coleccion[], int util){
    cout << util << " ";
    for(int i=0; i < util; i++) {
        coleccion[i].mostrar();
        if(i < (util-1)){
            cout << " -- ";
        }
    }
    cout << endl;
}

int combinarSuma(Valor const array1[], int util1, Valor const array2[], int util2, Valor resultado[])	{
    int tam_resultado = 0;
    bool encontrado;
    for(int i=0; i< util1; i++)   {
        resultado[tam_resultado]=array1[i];
        tam_resultado++;
    }
    for(int i=0;  i<util2; i++) {
        
        int indice1 = busquedaSecuencial(resultado, tam_resultado, array2[i]);
        
        if(indice1 == -1) {
            resultado[tam_resultado]=array2[i];
            tam_resultado++;
        }
        else {
            resultado[indice1].valor += array2[i].valor;   
        }
    }
    return tam_resultado;
}

int busquedaSecuencial(Valor const array[], int util, Valor const & val) {
    int indice;
    bool encontrado;
    
    for(int i = 0; i < util && !encontrado; i++) {
        encontrado = false;
        if(array[i].fila == val.fila && array[i].columna == val.columna) {
            indice = i;
            encontrado = true;
        }  
    }
    
    if(!encontrado)
        indice = -1;
    
    return indice;
}