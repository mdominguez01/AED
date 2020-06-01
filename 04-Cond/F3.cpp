/*
 Trabajo practico N°4 Funciones y Operador Condicional
 Demostrar manejo de funciones y del operador condicional
 Alumno: Matias Dominguez
 Legajo: 1743375
 1-06-2020
*/

/*
 Léxico
 n3,n4,x ∈ R; n1,n2 ∈ Z
*/
#include <cassert>

double F3(double); //prototipo de F3

int main(){
    int n1=2,n2=-15;
    double n3=-2.15,n4=15.78;

    assert((-2)==F3(n1)); //prueba 1 de la funcion F3
    assert(2.15==F3(n3)); //prueba 2 de la funcion F3
    assert((-15)==F3(n2)); //prueba 3 de la funcion F3
    assert(15.78==F3(n4)); //prueba 4 de la funcion F3
}

//definicion de F3
double F3(double x){
    if(x>=-3 && x<=3){ return -x; }
    return x;
}
