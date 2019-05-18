/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ejercicio1.cpp
 * Author: acid
 *
 * Created on 15 de febrero de 2019, 11:01
 */

#include <iostream>
#include "utilidades.h"
using namespace std;

/*
 * 
 */
int main()
{
    
    char cad[] = "Hola, primera cadena de ejemplo";      
    char sub1[] = "no coincide";
    char sub2[] = "Hol";
    char sub3[] = "plo";
    char sub4[] = "cad";
    char sub5[] = "cadenita";
    char resultado[50];
    
    char * cadena = sub4;
    
    int pos = localizarSubcadena(cad, cadena);
    cout << cadena << " - ";
    
    if(pos == -1)
        cout << "no es subcadena de - " << cad << endl;
    else {
        cout << "es subcadena de - " << cad << endl;
        cout << "Posición: " << pos << endl;
    }
    
    pos = 3;
    
    bool posible = insertarCadena(cad, cadena, pos, resultado);
    
    cout << "Inserción en posición: " << pos << endl; 
    if(posible) {
        cout << "Inserción posible: 1"  << endl;
        cout << resultado << endl; 
    }
    else
        cout << "Inserción posible: 0"  << endl;

    return 0;
}

