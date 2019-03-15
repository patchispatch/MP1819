// Alumno1: Padial Vázquez, Aarón
// Alumno 2: Ocaña Valenzuela, Juan

/* 
 * File:   utilidades.h
 * Author: acid
 *
 * Created on 15 de febrero de 2019, 11:07
 */

#ifndef UTILIDADES_H
#define UTILIDADES_H

/**
 * @brief lee el vector y devuelve el numero de componentes en util_array
 * @param array vector de entreda/salida
 * @param util_array
 */
void leer(double array[], int &util_array);
/**
@brief Escribe la longitud y los elementos del array en la salida estándar
@param array El array a imprimir
@param util_array Número de elementos útiles en el array
@pre array puede no contener ningun elemento
*/
void imprimirArray(const double array[],int util_array);
/**
 * @brief Realiza una mezcla sin introducir elementos comunes en arraySalida
 * @param array1 vector de entrada
 * @param utilArray1
 * @param array2 vector de entrada
 * @param utilArray2
 * @param arraySalida vector de salida
 * @param util_salida de salida
 * @pre los dos arrays deben estar ordenados
 */
void  mezclarUnico(double const array1[], int util1,  double const array2[], int util2, double resultado[], int & utilR);
/**
 * @brief un método de ordenacion que reciba 
 * @param array vecotr de double
 * @param num entero numero de elementos utiles
 * @param asc bool ascendente, false si es descendente
 */
void ordenar(double array[], int num, bool asc);

/**
 * @brief devuelve sobre el mismo vector el resultado sin valores repetidos
 * @param array1 vector de entrada/salida 
 * @param utilArray1 numero de componentes actuales de salida
 */
void unico (double array1[], int & utilArray1);

/**
 * @brief concatena en un tercer vector  el contenido de dos arrays
 * @param array1 vector de entrada
 * @param utilArray1
 * @param array2 vector de entrada
 * @param utilArray2
 * @param arraySalida vector de salida
 * @param util_salida numero de componentes de vector arraySalida,  de salida
 */
int concatenar(double const array1[], int util1,  double const array2[], int util2, double resultado[]);

/**
 * @brief elimina un valor del vector
 * @param array vector de entrada
 * @param utilArray número de componentes del vector de entrada
 * @param pos posición a eliminar
 */
void eliminar(double array[], int & utilArray, int pos);

#endif /* UTILIDADES_H */

