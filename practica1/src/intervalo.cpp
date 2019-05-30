/** 
 * **
   @file intervalo.cpp
   @brief Se proporciona parte de la clase intervalo y es necesario definir ciertos métodos para darle operatividad 
   @author MP Grupos B, C de GIInformatica
   @warning Módulo no definitivo (creado para ser modificado)

   Un ejemplo de ejecución es:

    Cuantos intervalos (max 10):5 
    Introduce [ o ( cotaInferior, cotaSuperior ) o ]: [0,10] (0,10] [0,10) (0,10) (10,10)
    Cuantos valores reales (max 10):6
    Introduce valor real: -1 -0.001 0 5.7  9.6  10
    Da como salida: 
    
 [0,10] : 0 5.7 9.6 10 
 (0,10] : 5.7 9.6 10 
 [0,10) : 0 5.7 9.6 
 (0,10) : 5.7 9.6 
 (0) :

 */
#include "intervalo.h"
using namespace std;


/******************************/



Intervalo::Intervalo()	{
	cerradoInf = false;
	cerradoSup = false;
	cotaInf = 0.0;
	cotaSup = 0.0;
}

Intervalo::Intervalo(double cotaInferior, double cotaSuperior)	{
	cerradoInf = false;
	cerradoSup = false;
	cotaInf = cotaInferior;
	cotaSup = cotaSuperior;
}

Intervalo::Intervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior)	{
	cerradoInf = cerradoInferior;
	cerradoSup = cerradoSuperior;
	cotaInf = cotaInferior;
	cotaSup = cotaSuperior;
}

double Intervalo::getCotaInf()const	{
	return cotaInf;
}

double Intervalo::getCotaSup()const {
	return cotaSup;
}

bool Intervalo::dentroCotaInf()const {
	return cerradoInf;
}

bool Intervalo::dentroCotaSup()const {
	return cerradoSup;
}

void Intervalo::setIntervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior)	{
	if(cotaInferior <= cotaSuperior)	{
		cotaInf = cotaInferior;
		cotaSup = cotaSuperior;
		cerradoInf = cerradoInferior;
		cerradoSup = cerradoSuperior;
	}
}

bool Intervalo::esVacio()const {
	return (cotaInf == cotaSup && !cerradoInf && !cerradoSup);
}

bool Intervalo::estaDentro(double n)const {
	bool dentro = true;
	if(n < cotaInf || n > cotaSup)
		dentro = false;
	else if((n == cotaInf && !cerradoInf) || (n == cotaSup && !cerradoSup))
		dentro = false;
	
    return dentro;
}

bool Intervalo::valido(double cinf,double csup, bool cerrinf, bool cerrsup){

	return ( cinf < csup ) || ( cinf == csup && cerrinf == cerrsup);
}

void escribir(const Intervalo & obj) {
    if (obj.esVacio())
        cout << "(0)";
    else {
        if (obj.dentroCotaInf())
            cout << '[';
        else 
            cout << '(';
        
        cout << obj.getCotaInf() << "," << obj.getCotaSup();
        
        if (obj.dentroCotaSup())
            cout << ']';
        else 
            cout << ')';
    }
}

void leer(Intervalo & obj){
    // Formato de lectura del intervalo: [|( x,y )|]
    bool cerradoInf = true;
    bool cerradoSup = true;
    double cotaInf, cotaSup;
    char car;

    cin >> car;

    if (car == '(')
        cerradoInf = false;
    cin >> cotaInf;
    cin >> car;
    cin >> cotaSup;
    cin >> car;
    
    if (car == ')')
        cerradoSup = false;
    obj.setIntervalo(cotaInf, cotaSup, cerradoInf, cerradoSup);
}

void comprobarVacio(Intervalo obj){
	escribir(obj);
    if (obj.esVacio())
        cout << " Vacio";
    else  
        cout << " NO Vacio";
    
    cout << endl;
}


