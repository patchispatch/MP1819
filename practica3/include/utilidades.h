// Alumno 1: Ocaña Valenzuela, Juan
// Alumno 2: Padial Vázquez, Aarón

#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <iostream>

#include "valor.h"

const int CAPACIDAD = 20;
/**
 * @brief lee un vector de valores
 * @param coleccion
 * @param util
 * @pre no hay valores repetidos en un vector
 */
void leerContenido(Valor coleccion[], int & util);

/**
 * @brief muestra el contenido de un vector de valores, numero de componentes y cada struct valor
 * @param coleccion vector de entrada
 * @param util numero de componentes validos
 */
void mostrarContenido( Valor const coleccion[], int util);

/**
 * @brief Funcion para combinar elementos Valor, almacenados en dos vectores
 * @param coleccion1
 * @param util1
 * @param coleccion2
 * @param util2
 * @param resultado
 * @return el numero de componentes del vector resultado
 */
int combinarSuma(Valor const [], int , Valor const [], int , Valor []);

int busquedaSecuencial(Valor const array[], int util, Valor const & val);
#endif //UTILIDADES_H
