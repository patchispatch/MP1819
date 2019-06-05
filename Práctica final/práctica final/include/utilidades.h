// **********************************************
// METODOLOGÍA DE LA PROGRAMACIÓN
// AUTORES: JUAN OCAÑA VALENZUELA
//          AARÓN PADIAL VÁZQUEZ
//
// utilidades.h
// Definición de funciones útiles para el proyecto.
// **********************************************


#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "miniwin.h"
#include "Pelota.h"

// Mueve una pelota según su velocidad definida:
void mover_pelota(Pelota &p);

// Pinta una pelota:
void pintar_pelota(const Pelota &p);

#endif /* UTILIDADES_H */

