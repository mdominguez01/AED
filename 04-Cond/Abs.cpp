/*
 Trabajo practico N°4 Funciones y Operador Condicional
 Demostrar manejo de funciones y del operador condicional
 Alumno: Matias Dominguez
 Legajo: 1743375
 1-06-2020
*/

/*
 Léxico
 n1,n2,a ∈ ℤ 
*/
#include <cassert>


int absoluto(int);  //prototipo de absoluto

int main(){

    int n1=-88,n2=150;
    assert(88==absoluto(n1)); //prueba 1 de la funcion absoluto
    assert(150==absoluto(n2)); //prueba 2 de la funcion absoluto

}

//definicion de absoluto
int absoluto(int a){
    if(a<0){ a=-a; }
    return a;
}