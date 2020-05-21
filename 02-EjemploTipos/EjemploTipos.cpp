/*
 Curso: K1051 
 Alumno: Matias Dominguez
 Legajo: 1743375
 TP: 02-Ejemplo Tipos de Datos
*/
#include <iostream>
#include <cassert>

using namespace std;

int main(){

    // Ejemplificacion Tipos de Datos

    bool booleano=false;
    unsigned long long int nro_positivo_lli=999999999999999;
    short nro_short=2;
    int entero=-5;
    double nro_double=12.3456;
    char caracter='d';
    string cadena="hola";

    assert(booleano!=true);
    assert(nro_positivo_lli>=0);
    assert(nro_short<=4);
    assert(entero==-5);
    assert(nro_double==12.3456);
    assert(caracter!='b');
    assert(cadena=="hola");


}