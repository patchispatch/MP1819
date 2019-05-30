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

void  mezclarUnico_old(double const array1[], int util1,  double const array2[], int util2, double resultado[], int & utilR){
    // Primero concatenamos los dos arrays:
    utilR = concatenar(array1, util1, array2, util2, resultado);
    
    // Después, eliminamos valores repetidos:
    unico(resultado, utilR);
    
    // Por último, ordenamos el resultado:
    ordenar(resultado, utilR, true);
}

void mezclarUnico(double const array1[], int util1,  double const array2[], int util2, double resultado[], int & utilR) {
    
    // Índices sobre los vectores:
    int i = 0;  // Array1
    int j = 0;  // Array2
    int k;      // Resultado
    
    // Iteramos sobre los tres vectores simultáneamente, comparando valores:
    for(k = 0; i < util1 && j < util2; k++) {
        if(array1[i] < array2[j]) {
            resultado[k] = array1[i];
            i++;
        }
        else if(array1[i] > array2[j]) {
            resultado[k] = array2[j];
            j++;
        }
        else {
            resultado[k] = array1[i];
            i++;
            j++;
        }
    }
    
    // Una vez hemos terminado con un array, volcamos el otro en el resultado:
    if(i < util1) {
        for(; i < util1; i++, k++) {
            resultado[k] = array1[i];
        }
    } 
    else if(j < util2) {
        for(; j < util2; j++, k++) {
            resultado[k] = array2[j];
        }
    }
    
    // Por último, igualamos utilR a k:
    utilR = k;
}

void ordenar(double array[], int num, bool asc){
    // Variable auxiliar para los intercambios:
    double aux;

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

void unico (double array1[], int & utilArray1){
    for(int i = 0; i < utilArray1; i++) {
        for(int j = i + 1; j < utilArray1; j++) {
            if(array1[i] == array1[j]) {
                cout << "Antes de eliminar" << endl;
                eliminar(array1, utilArray1, j);
                imprimirArray(array1, utilArray1);
            }
        }
    }
}

int concatenar(double const array1[], int util1,  double const array2[], int util2, double resultado[]){
    int utilR = util1 + util2;
    
    // Copiamos array1 en resultado:
    for(int i = 0; i < util1; ++i) {
        resultado[i] = array1[i];
    }
    
    // Copiamos array2 en resultado a continuación:
    for(int i = util1; i < utilR; ++i) {
        resultado[i] = array2[i - util1];
    }
    
    return utilR;
}

void eliminar(double array[], int & utilArray, int pos){
    
    --utilArray;
    
    for(int i = pos; i < utilArray; ++i) {
        array[i] = array[i+1];
    }
}

