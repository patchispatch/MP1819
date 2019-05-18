// *****************************************************************************
// METODOLOGÍA DE LA PROGRAMACIÓN -
// ENCONTRAR REPETICIONES DE UNA CADENA EN OTRA
// Grado en Ingeniería Informática
// Autor: Juan Ocaña Valenzuela
//
// utils.cpp
// Funciones útiles para la ejecución del programa.
// *****************************************************************************
#include<iostream>
#include "utils.h"


int sub_repetitions(char *cadena, char *subcadena) {
    int i = 0;
    int j = 0;
    int contador = 0;

    while(cadena[i] != '\0') {
      std::cout << "EO" << std::endl;

      if(cadena[i] == subcadena[j]) {
        std::cout << "O" << std::endl;
        ++i;
        ++j;
      }
      else{
        std::cout << "A" << std::endl;
        i = i + 1 - j;
        j = 0;
      }

      if(subcadena[j] == '\0') {
        ++contador;
        j = 0;
      }
    }

    return contador;
}
