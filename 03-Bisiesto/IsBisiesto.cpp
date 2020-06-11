/*
 Trabajo practico N°3 Bisiesto
 Dado un año, determinar si es bisiesto
 Alumno: Matias Dominguez
 Legajo: 1743375
 11-06-2020
*/
#include <cassert>

bool IsBisiesto (int); //prototipo

int main(){

    //prueba
    assert(IsBisiesto(2000));
    assert(not IsBisiesto(2019));
    assert(IsBisiesto(1908));
    assert(not IsBisiesto(1910));
    assert(IsBisiesto(1584));

}

//definicion
bool IsBisiesto (int ano){
    return ano>=1582 and ano%4==0 and (ano%100!=0 or ano%400==0);
} 
