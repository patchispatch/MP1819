#include <iostream>
#include "utilidades.h"
using namespace std;

/*
 * 
 */
int main()
{
    const int DIM_ARRAY_SALIDA=20; 
    
    double *arraySalida = new double[DIM_ARRAY_SALIDA];
    double *arrayL1 = new double[DIM_ARRAY_SALIDA/2]; 
    double *arrayL2 = new double[DIM_ARRAY_SALIDA/2];
    int utilArraySalida;
    int utilArrayL1, utilArrayL2;
    
    leer(arrayL1,utilArrayL1);
    leer(arrayL2,utilArrayL2);
    mezclarUnico(arrayL1, utilArrayL1 , arrayL2, utilArrayL2, arraySalida, utilArraySalida);
    imprimirArray(arraySalida, utilArraySalida);
    
    delete [] arrayL1;
    delete [] arrayL2;
    delete [] arraySalida;

}
