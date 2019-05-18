/**
 * Fichero de implementacion de las funciones que se piden
 */
#include "utilidades.h"
using namespace std;


void leerContenido(int *coleccion, int & util){
    do{
      cout << "Introduce cuantos: ";
      cin >> util;
    }while (util > CAPACIDAD);
    
    for(int i = 0; i < util; i++){
        cin >> coleccion[i];
    }   
}

/**
 * @brief Muestra los elementos del array en la salida estandar
 * @param array array a imprimir
 * @param utilArray numero de elementos utiles en el array
 * @pre array debería contener al menos un elemento
 */
void imprimirArray(const int *array, int utilArray) {
    cout << utilArray << ' ';
    for (int i = 0; i < utilArray; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

/**
  * @brief Obtiene un array con la secuencia más larga creciente de números enteros
  * @param array puntero a primer componente del array de entrada
  * @param utilArray numero de elementos utiles en el array
  * @param secuenciaCreciente puntero a primer componente de salida con la secuencia más larga creciente
  * @param util_secuenciaCreciente numero de elementos utiles en secuenciaCreciente
 */
void obtenerMayorSecuenciaMonotonaCreciente( int *array, int utilArray,
                                            int *& secuenciaCreciente, int & utilSecuenciaCreciente) {
    secuenciaCreciente = array;
    int *lectura = array;
    int utilAux = 0;
    utilSecuenciaCreciente = 0;
    bool esUltimo = false;
    for(int i = 0; i < utilArray - 1; i++) {
        //Para el caso en el que la mayor secuencia monótona creciente se 
        // encuentre al final de de la secuencia.
        if(i + 1 == utilArray - 1)    {
            esUltimo=true;
        }
        // Inicio de la secuencia:
        if(*lectura <= *(lectura + 1))  {
            ++utilAux;
            //Si llegamos al final, no podemos comparar con el siguiente valor,
            // ya que es basura, así que si llegamos aquí y la mayor secuencia
            // monótona creciente está al final, la cogemos.
            if(utilAux > utilSecuenciaCreciente && esUltimo) {
                utilSecuenciaCreciente = utilAux;
                secuenciaCreciente = lectura - utilSecuenciaCreciente + 1;
            }
        }
        //Cuando encontremos que el siguiente valor es más pequeño
        else    {
            //Si es una secuencia mayor nos interesa
            if(utilAux > utilSecuenciaCreciente) {
                //Actualizamos tamaño
                utilSecuenciaCreciente = utilAux;
                //Actualizamos el puntero para que apunte al inicio de nuestra secuencia
                secuenciaCreciente = lectura - utilSecuenciaCreciente;
            }
            //Reseteamos el contador de tamaño auxiliar
            utilAux = 0;
        }    
        ++lectura;
    }
    // Como utilSecuenciaCreciente acaba con uno menos al empezar en 
    // cero, le sumamos uno:    
    ++utilSecuenciaCreciente;
}
                                            
                                    
void hallarMinMax(int *array, int utilArray, int *& pmin, int *& pmax){
    pmin = array;
    pmax = array;
    
    int *ptraux = array;
    for(int i = 0; i< utilArray; i++)   {  
        //En cada iteración se actualizan los punteros si es necesario
        if(*ptraux < *pmin) 
            pmin = ptraux;
        else if(*ptraux > *pmax)
            pmax = ptraux;
        ++ptraux;
    }
}