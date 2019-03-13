/**
 * Fichero de implementacion de las funciones que se piden
 */
#include <iostream> 
#include "utilidades.h"
using namespace std;

/**
 * @brief lee el vector y devuelve el numero de componentes en util_array
 * @param array
 * @param util_array
 */
void leer(double array[], int &util_array){
    cout << "Cuantos: ";
    cin >> util_array;
    for(int i=0; i<util_array; ++i)
    {
        cin >> array[i];
    }
    cout<<endl;
}

/**
@brief Escribe la longitud y los elementos del array en la salida estándar
@param array El array a imprimir
@param util_array Número de elementos útiles en el array
@pre array puede no contener ningun elemento
*/
void imprimirArray(const double array[],int util_array){
    cout << util_array << " ";
    for(int i=0; i<util_array; ++i)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void  mezclarUnico(double [], int ,  double [], int , double [], int  ){

}

void ordenar(double array[], int num, bool asc){
    // Variable auxiliar para los intercambios:
    int aux;

    // Si asc es true, orden ascendente:
    if(asc) {
        // Recorrido del array y ordenación:
        for(int x = 1; x < num; x++) {
            for(int y = 0; y < (num - x); y++) {
                // Si [i] es mayor que [i+1], se intercambian:
                if(array[y] > array[y + 1]){
                    aux = array[y];
                    array[y] = array[y + 1];
                    array[y + 1] = aux;
                }
            }
        }
    }
    else {
        // Recorrido del array y ordenación:
        for(int x = 1; x < num; x++) {
            for(int y = 0; y < (num - x); y++) {
                // Si [i] es menor que [i+1], se intercambian:
                if(array[y] < array[y + 1]){
                    aux = array[y];
                    array[y] = array[y + 1];
                    array[y + 1] = aux;
                }
            }
        } 
    }
}
void unico (double array1[], int utilArray1){
    
}

void concatenar( double [], int ,  double [], int , double [], int ){
    
}

