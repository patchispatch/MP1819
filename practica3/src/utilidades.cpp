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
    bool encontrado=false;
    for(int i=0; i< util1; i++)   {
        resultado[tam_resultado]=array1[i];
        tam_resultado++;
    }
    for(int i=0;  i<util2; i++) {
        for(int j=0; j<tam_resultado && !encontrado; j++)    {
            if(array2[i].fila == resultado[j].fila && array2[i].columna == resultado[j].columna) {
                resultado[j].valor += array2[i].valor; 
                encontrado=true;
            }
        }
        if(!encontrado) {
            resultado[tam_resultado]=array2[i];
            tam_resultado++;
        }
        encontrado=false;
    }
    return tam_resultado;
}