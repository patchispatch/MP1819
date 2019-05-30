// ****************************************************************************
// METODOLOGÍA DE LA PROGRAMACIÓN
// Parcial 1 - Prueba de examen
// Autor: Juan Ocaña Valenzuela
//
// sec_bigramas.h
// Declaración de funciones útiles para trabajar con arrays de bigramas.
//
// Nota: Por conveniencia, utilizamos la clase std::string, ya que
// trabajar con ella es más intuitivo y seguro que utilizar cadenas estilo C.
// ****************************************************************************

#include<string>
using namespace std;

// Devuelve un vector con la intersección de dos vectores de bigramas:
string * interseccion(const string * array1, const string * array2);

// Devuelve un vector con la unión de dos vectores de bigramas:
string * _union(const string * array1, const string * array2);

// Devuelve la diferencia entre dos vectores de bigramas:
string * diferencia(const string * array1, const string * array2);

// Redimensiona un vector dinámico el número de casillas solicitado:
void redimensiona(string * array, int tam, int n);