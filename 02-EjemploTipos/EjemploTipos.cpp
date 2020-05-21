/*
 Trabajo practico N°2 Ejemplo Tipos de Datos
 Ejemplificar la aplicación de los tipos de datos.
 Alumno: Matias Dominguez
 Legajo: 1743375
 Ultima modificacion: 21-05-2020
*/
#include <iostream>
#include <cassert>

using namespace std;

int main(){

    // Ejemplificacion Tipos de Datos

    bool booleano=false;
    unsigned long long int nro_positivo_lli=999998;
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
    
    
    //operaciones con booleanos
    
    
    //operaciones con unsign long init,init y short (usan las mismas operaciones)
    //SUMA
     nro_positivo_lli= nro_positivo_lli +1;
     assert(nro_positivo_lli==999999);
    //RESTA
     nro_short= nro_short - 1;
     assert(nro_short==1);
    //multiplicacion
     entero= entero*1;
     assert(entero==-5);
    //division
     nro_positivo_lli= nro_positivo_lli/1;
     assert(nro_positivo_lli==999999);
     
     //operaciones con double
    //SUMA
     nro_double= nro_double +1;
     assert(nro_double==13.3456);
    //RESTA
     nro_double= nro_double - 1.0;
     assert(nro_double==12.3456);
    //multiplicaion
     nro_double= nro_double*1;
     assert(nro_double==12.3456);
    //division
     nro_double= nro_double/1;
     assert(nro_double==12.3456);

}
