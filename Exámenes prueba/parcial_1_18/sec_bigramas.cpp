// ****************************************************************************
// METODOLOGÍA DE LA PROGRAMACIÓN
// Parcial 1 - Prueba de examen
// Autor: Juan Ocaña Valenzuela
//
// utils.cpp
// Implementación de los métodos descritos en utils.h
// ****************************************************************************

#include<cstring>
#include "sec_bigramas.h"

// Redimensionar un vector dinámico el número de casillas solicitado:
void redimensiona(string * array, int &tam, int n) {
    int aux_tam = tam + n;
    
    // Reservamos nuevo array
    string * n_array = new string[aux_tam];
    // Copiamos el actual:
    memcpy(n_array, array, tam*sizeof(string));
    // Reasignamos:
    array = n_array;
}