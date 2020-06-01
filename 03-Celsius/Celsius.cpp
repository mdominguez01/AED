/*
 Trabajo practico N°3 Ejemplo Celsius
 Demostrar el manejo de funciones y valores punto flotante.
 Alumno: Matias Dominguez
 Legajo: 1743375
 1-06-2020
*/

#include <cassert>

double Celsius (double); //prototipo Celsius
bool AreNear(double, double, double = 0.001); //prototipo AreNear

int main(){
    // Ejemplo de punto flotante mediante celsius

    double f=78.00;

    bool areNear=AreNear(Celsius(f),Celsius(f),0.001);
    assert(areNear); //prueba del resultado de la funcion Celsius
}

//definicion de Celsius
double Celsius(double f){
    return (5.00/9.00)*(f-32);
}

//definicion de AreNear
bool AreNear(double a, double b, double t){
    return a-t< b &&  a+t > b  ? true : false;
}

