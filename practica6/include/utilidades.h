// Alumno 1: Padial Vázquez, Aarón
// Alumno 2: Ocaña Valenzuela, Juan
#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <iostream>

using namespace std;


const int CAPACIDAD = 20;

/**
 * @brief lee un vecter de enteros, primero el numero de elementos seguido de las entradas
 * @param coleccion vector de enteros
 * @param util numero de componentes de coleccion 
 */
void leerContenido(int coleccion[], int & util);

/**
 * @brief muestra en pantalla el contenido de vector, primero numero de componentes seguido de los valores
 * @param array vector de enteros
 * @param utilArray numero de componentes del vector
 */

void imprimirArray(const int array[], int utilArray);

/**
 * @brief devuelve un subvector con la mayor secuencia monotona creciente
 * @param array, vector original de entrada
 * @param utilArray numero de componentes del vector origianl
 * @param secuenciaCreciente vector de salida
 * @param utilSecuenciaCreciente numero de componentes del vector de salida
 */
void obtenerMayorSecuenciaMonotonaCreciente(int *array, int utilArray,
                                            int *& secuenciaCreciente, int & utilSecuenciaCreciente);


/**
 * @brief halla el minimo y el máximo valor de un vector 
 * @param array ector original de entrada
 * @param utilArray  numero de componentes del vector original
 * @param *pmin puntero al minimo valor 
 * @param *pmax  puntero al máximo valor
 */
void hallarMinMax(int *array, int utilArray,
                                            int *& pmin, int *& pmax);

#endif //UTILIDADES_H
