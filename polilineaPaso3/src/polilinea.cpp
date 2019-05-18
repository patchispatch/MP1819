
#include "polilinea.h"

using namespace std;

/**
 * Constructor creando espacio el numero de puntos
 * pasados como argumento, que se inicializan con el
 * valor de punto por defecto
 * @param espacioAlmacenamiento espacio de almacenamiento a reservar
 */
Polilinea::Polilinea(int espacioAlmacenamiento, double x, double y) {
  // A RELLENAR ...............................
}

/**
 * Constructor de copia
 * @param otra
 */
Polilinea::Polilinea(const Polilinea & otra){
    // se asignan valores de datos miembro
    numeroVertices=otra.numeroVertices;
    
    // se reserva espacio de memoria
    puntos=reservarEspacio(otra.espacioReservado);
    
    // se asignan los datos de los puntos
    for(int i=0; i < numeroVertices; i++){
        puntos[i].asignarX(otra.puntos[i].obtenerX());
        puntos[i].asignarY(otra.puntos[i].obtenerY());
    }
}

/**
 * Destructor de la clase
 */
Polilinea::~Polilinea() {
    // se llama al metodo de liberacion de espacio
    liberarEspacio();
}

/**
 * Metodo privado para reserva de espacio de memoria
 * @param espacio a reservar
 * valor del dato miembro espoacioReservado o no
 */
Punto * Polilinea::reservarEspacio(int dimension) {
    Punto *espacio=0;
    
    if(dimension != 0){
       // se reserva el espacio deseado
       espacio = new Punto[dimension];

       // se asigna valor al dato miembro espacioReservado
       espacioReservado = dimension;
    }   

    // se devuelve el espacio
    return espacio;
}

/**
 * Metodo privado para localizar el indice que ocupa en el poligono
 * el vertice cuyas coordenadas se pasan como argumento
 * @param x
 * @param y
 * @return 
 */
int Polilinea::buscarVertice(double x, double y) const {
    int posicion = -1;
    bool encontrado = false;

    // bucle de busqueda
    for (int i = 0; i < numeroVertices && !encontrado; i++) {
        if (puntos[i].obtenerX() == x && puntos[i].obtenerY() == y) {
            encontrado = true;
            posicion = i;
        }
    }

    // se devuelve la posicion
    return posicion;
}

/**
 * Metodo privado para liberar espacio en memoria dinamica
 */
void Polilinea::liberarEspacio() {
    // Se libera el espacio de memoria ocupado
    delete [] puntos;
}

/**
 * Metodo para mostrar el contenido del objeto
 */
void Polilinea::mostrar() const {
    // se muestra el contenido del objeto
    cout << "Contenido de objeto de clase Polilinea........." << endl;
    cout << "Numero de vertices: " << numeroVertices << " espacio reservado: "
            << espacioReservado << endl;
    for (int i = 0; i < numeroVertices; i++) {
        cout << "(" << i << ") : ";
        puntos[i].mostrar();
    }
    cout << "------------------------------------------------" << endl;
}

/**
 * Metodo para acceder al punto que se almacena en un
 * determinado indice. En caso de no tratarse de un indice
 * valido se genera una excepcion
 * @param indice
 * @return 
 */
Punto Polilinea::obtenerVertice(int indice) const {
    // si el indice no es valido se lanza excepcion
    if (indice < 0 || indice >= numeroVertices) {
        throw invalid_argument("Indice invalido en Polilinea::obtenerVertice");
    }

    // si se llega hasta aqui el indice es valido y se devuelve
    // el objeto asociado
    return puntos[indice];
}

/**
 * Metodo para insertar un nuevo indice en el poligono
 * @param indice
 * @param x
 * @param y
 * @return 
 */
bool Polilinea::asignarVertice(int indice, double x, double y) {
    // si el indice no es valido, se devuelve false
    bool resultado = false;

    // se comprueba la validez del indice
    if (indice >= 0) {
        // la operacion es factivle
        resultado = true;

        // dos posible situaciones: el indice es inferior al
        // espacio reservado, en cuyo caso se almacena en la
        // posicion indica
        if (indice < espacioReservado) {
            // se asigna el objeto correspondiente
            puntos[indice].asignarX(x);
            puntos[indice].asignarY(y);
            
            if(indice >= numeroVertices){
                numeroVertices=indice+1;
            }
        } 
        else {
            // hay que reserva espacio necesario para contener
            // el indice: se asignan mas espacios de los
            // estrictamente necesarios (10 mas)
            Punto *nuevoPuntos = reservarEspacio(indice + BLOQUE);

            // se copian las coordenadas de los puntos previamente
            // almacenados
            for (int i = 0; i < numeroVertices; i++) {
                nuevoPuntos[i].asignarX(puntos[i].obtenerX());
                nuevoPuntos[i].asignarY(puntos[i].obtenerY());
            }

            // se almacena el pasado como argumento
            nuevoPuntos[indice].asignarX(x);
            nuevoPuntos[indice].asignarY(y);

            // se libera el espacio previo
            liberarEspacio();

            // se hae que puntos apunte al espacio nuevo
            puntos = nuevoPuntos;

            // se modifica el valor numeroVertices
            numeroVertices = indice + 1;
        }
    }

    // se devuelve el resultado
    return resultado;
}

/**
 * Metodo para insertar un vertice en una determinada
 * posicion. Esto obligara a desplazar todos los vertices
 * a partir de la posicion de insercion. Este metodo solo
 * es valido si la posicion de insercion es menor o igual 
 * que el numero de vertices almacenados
 * @param indice
 * @param x
 * @param y
 * @return 
 */
bool Polilinea::insertarVertice(int indice, double x, double y) {
    // si el indice no es valido, se devuelve false
    bool resultado = false;

    // se comprueba la validez del indice
    if (indice >= 0 && indice < numeroVertices) {
        // se indica que la operacion es posible
        resultado = true;

        // si hay espacio reservado de sobra, se almacena
        // sin mas
        if (espacioReservado > numeroVertices) {
            // basta con modificar las coordenadas de los
            // objetos desde indice + 1  en adelante
            for (int i = numeroVertices; i > indice; i--) {
                puntos[i].asignarX(puntos[i - 1].obtenerX());
                puntos[i].asignarY(puntos[i - 1].obtenerY());
            }

            // ahora se asignan las coordenadas del punto
            // que ocupara la posicion dada por indice
            puntos[indice].asignarX(x);
            puntos[indice].asignarY(y);
        } else {
            // es necesario reservar mas espacio: se reserva algo mas
            Punto *nuevoPuntos = reservarEspacio(espacioReservado + BLOQUE);

            // se copian los datos de los vertices hasta indice-1
            for (int i = 0; i < indice; i++) {
                nuevoPuntos[i].asignarX(puntos[i].obtenerX());
                nuevoPuntos[i].asignarY(puntos[i].obtenerY());
            }

            // se asignan los datos del punto pasado como argumento
            nuevoPuntos[indice].asignarX(x);
            nuevoPuntos[indice].asignarY(y);

            // se copian los datos de puntos a partir de indice
            for (int i = indice; i < numeroVertices; i++) {
                nuevoPuntos[i + 1].asignarX(puntos[i].obtenerX());
                nuevoPuntos[i + 1].asignarY(puntos[i].obtenerY());
            }

            // se libera el espacio previo
            liberarEspacio();

            // se asigna puntero a nuevo espacio
            puntos = nuevoPuntos;
        }

        // se modifica el contador de vertices
        numeroVertices++;
    }

    // se devuelve el valor de resultado
    return resultado;
}

/**
 * Metodo para borrar un vertice dado un indice. Solo tiene sentido
 * con valores de indice mayores que 0 y menores de numeroVertices
 * @param indice
 * @return 
 */
bool Polilinea::borrarVertice(int indice) {
    bool resultado = false;

    // tratamiento del borrado en caso de poderse realizar
    if (indice >= 0 && indice < numeroVertices) {
        // se hace que resultado valga true
        resultado=true;
        
        // no se modifica el espacio de memoria. Se copian los
        // datos desde indice+1 hasta el final
        for (int i = indice; i < numeroVertices - 1; i++) {
            puntos[i].asignarX(puntos[i + 1].obtenerX());
            puntos[i].asignarY(puntos[i + 1].obtenerY());
        }

        // se disminuye el contador de vertices
        numeroVertices--;
    }

    // se devuelve el resultado
    return resultado;
}

/**
 * Metodo de union de objetos
 * @param otra polilinea a unir
 */
Polilinea * Polilinea::unionOp(const Polilinea & otra) const {
    Polilinea *resultado = 0;

    // se crea un nuevo objto en memoria dinamica para contener
    // this y el objeto pasado como argumento
    resultado = new Polilinea(numeroVertices + otra.numeroVertices + BLOQUE);

    // se copian los datos de this
    for (int i = 0; i < numeroVertices; i++) {
        resultado->asignarVertice(i, puntos[i].obtenerX(), puntos[i].obtenerY());
    }

    // se copian los datos de otra
    for (int i = 0; i < otra.numeroVertices; i++) {
        resultado->asignarVertice(numeroVertices + i, otra.puntos[i].obtenerX(),
                otra.puntos[i].obtenerY());
    }

    // se asigna el numero de vertices
    resultado->numeroVertices = numeroVertices + otra.numeroVertices;

    // se devuelve resultado
    return resultado;
}

/**
 * Metodo para devolver una polilinea con los vertices
 * interseccion de this y otra. En el objeto resultante 
 * no debe haber puntos repetidos
 * @param otra
 */
Polilinea * Polilinea::interseccionOp(const Polilinea & otra) const {
  // A RELLENAR ...............................
}
