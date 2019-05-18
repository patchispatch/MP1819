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
  char * cadena = "";
  char * subcadena = "";
  int repeticiones;

  // Gestionar argumentos:
  if(argc != 5) {
    std::cerr << "Número de argumentos incorrecto.";
    exit(1);
  }
  else {
    bool used_c = false;
    bool used_s = false;

    // Recorrer todos los argumentos salvo el nombre del programa:
    for(int i = 1; i < argc - 1; ++i) {
      // Cadena:
      if(argv[i] == "-c") {
        if(!used_c) {
          cadena = argv[i+1];
          used_c = true;
        }
        else {
          std::cerr << "Argumento -c ya especificado.";
          exit(1);
        }
      }
      // Subcadena:
      else if(argv[i] == "-s") {
        if(!used_s) {
          subcadena = argv[i+1];
          used_s = true;
        }
        else {
          std::cerr << "Argumento -s ya especificado.";
          exit(1);
        }
      }
    }
  }
  
  std::cout << "Cadena: " << cadena << std::endl;
  std::cout << "Subcadena: " << subcadena << std::endl;

  // Obtener repeticiones de subcadena en cadena:
  repeticiones = sub_repetitions(cadena, subcadena);

  // Muestra los resultados:
  std::cout << "Repeticiones encontradas: " << repeticiones << std::endl;

  return 0;
}
