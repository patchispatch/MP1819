
/* 
 * File:   Punto.h
 * Author: mgomez
 *
 * Created on 7 de abril de 2019, 20:45
 */

#ifndef PUNTO_H
#define PUNTO_H

# include <iostream>

/**
 * Clase para representar puntos en un espacio bidimensional
 */
class Punto {
private:
    /**
     * Datos miembro para las coordenadas del punto
     */
    double x, y;
    
public:

    /**
     * Constructor por defecto. Se inicializan a 0 los valores
     * de los datos miembros
     */
    inline Punto(){
        x=0;
        y=0;
    }
    
    /**
     * Constructor indicando los valores de los datos miembro
     * @param x
     * @param y
     */
    inline Punto(double x, double y){
        this->x=x;
        this->y=y;
    }
    
    inline ~Punto(){
    }
    
    /**
     * Metodo para acceder al valor de x
     * @return 
     */
    inline double obtenerX(){
        return x;
    }
    
    /**
     * Metodo para acceder al valor de y
     * @return 
     */
    inline double obtenerY(){
        return y;
    }
    
    /**
     * Metodo para asignar el valor del dato miembro X
     * @param x
     */
    inline void asignarX(double x){
        this->x=x;
    }
    
    /**
     * Metodo para asignar el valor del dato miembro Y
     * @param y
     */
    inline void asignarY(double y){
        this->y=y;
    }
    
    /**
     * Metodo para mostrar el contenido del objeto
     */
    inline void mostrar(){
        std::cout << "x: " << x << " y: " << y << std::endl;
    }
};

#endif /* PUNTO_H */

