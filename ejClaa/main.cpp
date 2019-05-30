// *****************************************************************************
// METODOLOGÍA DE LA PROGRAMACIÓN -
// ENCONTRAR REPETICIONES DE UNA CADENA EN OTRA
// Grado en Ingeniería Informática
// Autor: Juan Ocaña Valenzuela
//
// main.cpp
// Programa principal.
// *****************************************************************************
#include <iostream>
#include "utils.h"

int main(int argc, char **argv) {
  char * cadena;
  char * subcadena;
  int repeticiones;

  // Gestionar argumentos:
  arguments(argc, argv, cadena, subcadena);

  // Obtener repeticiones de subcadena en cadena:
  repeticiones = sub_repetitions(cadena, subcadena);

  // Muestra los resultados:
  std::cout << "Repeticiones encontradas: " << repeticiones << std::endl;

  return 0;
}
