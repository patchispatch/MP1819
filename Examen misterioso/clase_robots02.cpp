/* 

* corta desde aqui :
10
1 9.1 9.2 1
2 10.5 10.5 1
3 11.0 11.0 1
4 3.5 1.2 2
5 2.7 10.3 2
6 4.5 6.7 2
7 19.9 10.10 3
8 1.1 4.4 3
9 10.0 9.0 3
10 0.0 0.0 1
3
100 10 10 3
101 1 1 2
102 4 6 1  
hasta aqui para preparar un fichero de datos

Con la ayuda de la clase Robot ya definida se pide:
dimensionar un vector de Robot original, con el tamaño necesario para leer una serie de robotes,
y otro vector de Robot inhibidores en las mismas condiciones.
Todos tienen un id, 2 coordenadas y una potencia de accion (alcance).
Cuando un robot r, se encuentra a una distancia inferior a la potencia de alcance de un inhibidor,
el robot r, queda inactivo (muerto).
Es necesario elaborar un vector (tambien dinamico) resultante con los robotes originales supervivientes
(no muertos) resultante de aplicar los robotes inhibidores.

Tareas a realizar
1. Completar las funciones:
reservarM
liberarM
supervivientes
main

2. Revisar las cabeceras de las funciones independientes el numero y tipos son los correctos.
La forma de pasar los argumentos (por valor, referencia etc.) lo decides tu

3. Partir o no el codigo
Se puede dejar todo en un solo fichero, en ese caso el ejercicio tan solo se evalua sobre 7.
Si decide hacer compilacion separada usara la estructura de ficheros y directorios habitual:
utilidades.h, utilidades.cpp y main.cpp

4. Entregar en decsai de los ficheros
robot.zip si opcion en un solo fichero
robot_separado.zip  si opcion de compilacion separado

En ambos casos debera entregar el makefile, propio o generado por netbeans.
*/
// Alumno:


#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Robot{
private:
	unsigned id;
	float x,y;
	double potencia;
public:
    /**
     * @brief Constructor base
     */
    Robot();
    Robot(long _id);
    Robot(float x, float y);
    Robot(long _id, float _x, float _y, double _potencia);

    /**
     * @brief Devuelve el id del robot
     * @return nombre
     */
    unsigned get_id() const;
    /**
     * @brief Devuelve coordenada x del robot
     * @return x
     */
    float get_X() const;
    /**
     * @brief Devuelve coordenada y del robot
     * @return y
     */

    float get_Y() const;
    /**
     * @brief Devuelve potencia  del robot
     * @return potencia
    */
    double get_potencia() const;

    /**
     * @brief Actualiza los datos del robot, si la longitud adecuada,
     *  en otro caso, no se actualiza
     * @param cadena, x e y
     */
    void set_Robot(long _id, float _x, float _y, double _potencia );
    bool es_positivo(double v){
     return v >= 0;
    }
};

void imprimirVector(Robot v[], int n);
    /**
     * @brief calcula la distancia entre 2 robots
     * da igual el orden de los robots, el calculo de la distancia es
     * simetrica y positiva.
     * @param rb1 robot
     * @param rb2 robot
     * @return devuelve la distancia calculada
     */
float distancia( const Robot &rb1,  const Robot &rb2);
 /**
     * @brief indica si un robot se ve afectado "muerto" por la influencia de
     * un inhibidor con un rango de potencia.
     * @param rt, robot que se comprueba si est� muerto o no
     * @param robot inhibidor, con su posicion x y y rango de potencia interna
     * @return devuelve true si queda afectado, esta muerto, falso si esta activo.
     */
bool afectado(const Robot &rt, const Robot &inhibidor);

/**
     * @brief realiza un  filtrado de cada uno de los robots de v_original
     * con respecto al robot inhibidor y su rango de accion, se queda con
     * los robots no afectados en un vector resultante
     * @param entrada de vector de original
     * @param entrada del tama�o de original
     * @param entrada de vector de robot v_inhibidor
     * @param entrada del tama�o de  inhibidor
     * @param devuelve el vector de salida
     * @param devuelve el nuevo tama�o
     */
void supervivientes( Robot *v_original, int no,  Robot *v_inhibidor, int ni, Robot *  v_salida, int  n_salida);

/**
 * @brief reserva memoria para  n robots,
 * @param n numero de robots a reservar
 * @return direcion de inicio de memoria reservada
 */
    
Robot * reservaM(int n);
/**
 * @brief Libera la memoria correspondiente a un vector
 */
void liberarM(Robot * v);

Robot::Robot(){
    x = y = 0;
    id = 0;
    potencia = 1;
}
Robot::Robot(long _id){
    x = y = 0;
    if (es_positivo(_id))
        id = _id;
    else {
        id = 0;
    }
}
Robot::Robot( long _id, float _x, float _y, double _potencia){
    x = _x;
    y = _y;
    if (es_positivo(_id))
        id = _id;
    else {
        id = 0;
    }
    if (es_positivo(_potencia))
       potencia = _potencia;
    else potencia = 1;
}
unsigned Robot::get_id() const{
    return id;
}
float Robot::get_X() const{
    return x;
}
float Robot::get_Y() const{
    return y;
}
double Robot::get_potencia()const{
    return potencia;
}
void Robot::set_Robot(long _id, float _x, float _y, double _potencia){
    x = _x;
    y = _y;
    if (es_positivo(_id))
        id = _id;
    else {
        id = 0;
    }
    if (es_positivo(_potencia))
       potencia = _potencia;
    else potencia = 1;
}

void imprimirVector(Robot v[], int n)  {
	for (int i=0; i<n; i++)
		cout << v[i].get_id() << "->(" << v[i].get_X() << "," << v[i].get_Y() << "," << v[i].get_potencia()<< ")," << endl;
}


    /**
     * @brief calcula la distancia entre 2 robots
     * da igual el orden de los robots, el calculo de la distancia es
     * simetrica y positiva.
     * @param rb1 robot
     * @param rb2 robot
     * @return devuelve la distancia calculada
     */
float distancia( const Robot &rb1,  const Robot &rb2){
	float x = fabs(rb1.get_X() - rb2.get_X());
	float y = fabs(rb1.get_Y() - rb2.get_Y());

	return(sqrt( x*x + y*y ));
}
 /**
     * @brief indica si un robot se ve afectado "muerto" por la influencia de
     * un inhibidor con un rango de potencia.
     * @param rt, robot que se comprueba si est� muerto o no
     * @param robot inhibidor, con su posicion x y y rango de potencia interna
     * @return devuelve true si queda afectado, esta muerto, falso si esta activo.
     */
bool afectado(const Robot &rt, const Robot &inhibidor){
	float dist = distancia(rt, inhibidor);
	return (dist < inhibidor.get_potencia());

}

void supervivientes( Robot *v_original, int no,  Robot *v_inhibidor, int ni, Robot *  v_salida, int  n_salida){

 -> ...
}

Robot * reservaM(int n){
 -> ...
}
    /**
     * @brief Libera la memoria correspondiente a un vector
     */

void liberarM(Robot * v){
 -> ...

}

int main()  {
	Robot *v_org = nullptr;  // vector de robots original
        Robot *v_inhib = nullptr;  // vector de robots inhibidores
	Robot *v_rsult = nullptr;  // vector de robots resultante
	int n_org, n_inhib, n_rsult; // longitudes respectivas
	int i;
	float x, y;  // variables de usar y tirar para la lectura
	long id;
	double potencia;

        cout << "Cuantos:";
	cin >> n_org;
	v_org = reservaM(n_org);

	// cargar los valores
	for(i=0; i < n_org; i++){
		cin >> id >> x >> y >> potencia;
                -> ...
	}
	cout << "Vector de robots originales " << endl;
	imprimirVector(v_org,n_org);

        cout << "Cuantos:";
	cin >> n_inhib;
 -> ...
	cout << "\n\n\n Se filtra el vector de robots " << endl;
 -> ...
         
	return 0;
}
