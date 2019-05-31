// ****************************************************************************
// METODOLOGÍA DE LA PROGRAMACIÓN
// AUTORES: JUAN OCAÑA VALENZUELA
//          AARÓN PADIAL VÁZQUEZ
//
// definiciones.h
// Constantes y enumerados necesarios para la práctica final
// ****************************************************************************

#ifndef CONSTANTES_H
#define CONSTANTES_H

const int MIN_X = 800;
const int MIN_Y = 600;
const float MAX_VEL = 50.0;
const float MAX_RADIO = 30.0;
const int UMBRAL = 2;
const float FACTOR = 0.97;

enum class PColor {
  NEGRO, ROJO, VERDE, AZUL,
  AMARILLO, MAGENTA, CYAN, BLANCO
};

#endif /* CONSTANTES_H */

