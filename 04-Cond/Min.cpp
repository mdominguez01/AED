/*
 Trabajo practico N°4 Funciones y Operador Condicional
 Demostrar manejo de funciones y del operador condicional
 Alumno: Matias Dominguez
 Legajo: 1743375
 1-06-2020
*/

/*
 Léxico
 n1,n2,n3,a,b ∈ ℤ 
*/
#include <cassert>

int Minimo(int, int); //prototipo de Minimo

int main(){

    int n1=25, n2=-48 , n3=10;

    assert(n2==Minimo(n1,n2)); //prueba 1 de la funcion absoluto
    assert(n3==Minimo(n3,n1)); //prueba 2 de la funcion absoluto
}

//definicion de Minimo
int Minimo(int a, int b){
    if(a<b){ return a; }
    return b;
}
