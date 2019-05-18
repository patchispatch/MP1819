/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ejercicio1.cpp
 * Author: aaron
 *
 * Created on 28 de marzo de 2019, 17:22
 */

#include <iostream>
#include "utilidades.h"

using namespace std;

/*
 * 
 */
int main() {
    const int CAPACIDAD = 20;
    int array[CAPACIDAD];
    int utilArray, utilSecuenciaCreciente;
    int *min, *max, *secuenciaCreciente;
    
    leerContenido(array, utilArray);
    obtenerMayorSecuenciaMonotonaCreciente(array, utilArray, secuenciaCreciente, utilSecuenciaCreciente);
    imprimirArray(array, utilArray);
    cout << "mayor secuencia monotona creciente : " << endl;
    imprimirArray(secuenciaCreciente, utilSecuenciaCreciente);
    hallarMinMax(array, utilArray, min, max);
    cout << "este es el minimo --> " << *min << endl;
    cout << "este es el maximo --> " << *max << endl;
    
    return 0;
}

