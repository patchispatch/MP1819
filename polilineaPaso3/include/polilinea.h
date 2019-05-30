/* 
 * File:   polilinea.h
 * Author: mgomez
 *
 * Created on 7 de abril de 2019, 20:45
 */

#ifndef POLILINEA_H
#define POLILINEA_H

#include <iostream>
#include <stdexcept>
#include "punto.h"

/**
 * Clase para representar poligonos mediante un array de vertices,
 * gestionado de forma dinamica
 */
class Polilinea{
private:
   /**
    * Constante privada indicando el numero de celdas a reservar
    * cada vez que se amplie la memoria
    */
   static const int BLOQUE=10;
   
    /**
     * Dato para almacenar los puntos que definen los vertices
     * de la polilinea
     */
    Punto *puntos;
    
    /**
     * Permite almacenar el numero de vertices del poligono
     */
    int numeroVertices;
    
    /**
     * Dato miembro para indicar el espacio maximo de almacenamiento
     */
    int espacioReservado;
    
    /**
     * Metodo privado para reservar espacio de memoria
     * @param dimension numero de celdas a reservar para vertices
     * @return 
     */
    Punto * reservarEspacio(int dimension);
    
    /**
     * Metodo privado para localizar el indice que ocupa en el poligono
     * el vertice cuyas coordenadas se pasan como argumento
     * @param x
     * @param y
     * @return 
     */
    int buscarVertice(double x, double y) const;
    
    /**
     * Metodo privado para liberar el espacio de memoria ocupado
     * por el objeto
     */
    void liberarEspacio();
    
public:    
    /**
     * Constructor creando espacio el numero de puntos
     * pasados como argumento, que se inicializan con el
     * valor de punto por defecto
     * @param espacioAlmacenamiento espacio de almacenamiento a reservar
     */
    Polilinea(int espacioAlmacenamiento=0, double x=0.0, double y=0.0);
    
    /**
     * Constructor de copia
     * @param otra
     */
    Polilinea(const Polilinea & otra);
    
    /**
     * Destructor de la clase
     */
    ~Polilinea();
    
    /**
     * Metodo para mostrar el contenido del objeto
     */
    void mostrar() const;
    
    /**
     * Devuelve el valor del dato miembro espacioReservado
     * @return 
     */
    inline int obtenerEspacioReservado() const{
       return espacioReservado;
    }
    
    /**
     * Devuelve el valor del dato miembro numeroVertices
     * @return 
     */
    inline int obtenerNumeroVertices() const{
       return numeroVertices;
    }
    
    /**
     * Metodo para acceder al punto que se almacena en un
     * determinado indice
     * @param indice
     * @return 
     */
    Punto obtenerVertice(int indice) const;
    
    /**
     * Metodo para insertar un nuevo indice enel poligono
     * @param indice
     * @param x
     * @param y
     * @return 
     */
    bool asignarVertice(int indice, double x, double y);
    
    /**
     * Metodo para insertar un vertice en una determinada
     * posicion. Esto obligara a desplazar todos los vertices
     * a partir de la posicion de insercion
     * @param indice
     * @param x
     * @param y
     * @return 
     */
    bool insertarVertice(int indice, double x, double y);
    
    /**
     * Metodo para borrar un vertice dado un indice
     * @param indice
     * @return 
     */
    bool borrarVertice(int indice);
    
    /**
     * Metodo de union de objetos
     * @param otra polilinea a unir
     */
    Polilinea * unionOp(const Polilinea & otra) const;
    
    /**
     * Metodo para devolver una polilinea con los vertices
     * interseccion de this y otra
     * @param otra
     */
    Polilinea * interseccionOp(const Polilinea & otra) const;
};

#endif /* POLILINEA_H */

