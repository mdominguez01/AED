/*
 Trabajo practico N°6 Triangulo,Poligono y Color
 Armar los tipo de dato triangulo y poligono (ambos con color), y sus respectivas funciones (prototipos) 
 Alumno: Matias Dominguez
 Legajo: 1743375
 03-09-2020
*/

#include <iostream>
#include <cassert>
#include <array>


enum struct ColoresBase
{
    RED,
    GREEN,
    BLUE
};                              //colores base del modelo RGB
struct color{unsigned r,g,b;}; // Color en RGB
struct punto{double x, y;};
struct triangulo{std::array<punto, 3> puntosTriangulo; color c;};
struct poligono{std::array<punto, 100> puntosTriangulo; unsigned n; color c;};

//operaciones de POLIGONO
void agregarPuntoPoligono(poligono &, punto);               //agrego un punto
void ordenarPosicionesPuntosPoligono(poligono &);            //reordenaria en caso de habere sido removido alguno punto siempre y cuando no haya sido el ultimo punto agregado
punto removerPuntoPoligono(poligono &, punto, unsigned); // remover un punto especifico y luego ordenar posiciones llamando a ordenarPosicionesPuntosPoligonos
void setColorPoligono(poligono &, color);               //cambia el color
void setPuntoPoligono(poligono &, color);
double longitudLadoPoligono(const poligono &, unsigned); //obtener la medida del lado (posicion y posicion+1), en caso de ser el ultimo lado(posicion y posicion inicial)
double perimetroPoligono(const poligono &);              // utiliza longitudLadoPoligono para calcularlo
color getColorPoligono(const poligono &);                //obtengo el color
ColoresBase colorPredominantePoligono(const poligono &); //obtener el color base predominante
punto getPuntoPoligono(const poligono &, unsigned);      //obtener un punto
unsigned getCantidadPuntosPoligono(const poligono &);    //obtener la cantidad de puntos

//operaciones deL TRIANGULO
void setColorTriangulo(triangulo &, color);                //cambia el color
void setPuntoTriangulo(triangulo &, color);
double longitudLadoTriangulo(const triangulo &, unsigned); //obtener la medida del lado (posicion, posicion+1), en caso de ser el ultimo lado(posicion y posicion inicial)
double perimetroTriangulo(const triangulo &);              // utiliza longitudLadoTriangulo para calcularlo
color getColorTringulo(const triangulo &);                 //obtengo el color
ColoresBase colorPredominanteTrinagulo(const triangulo &);  //obtener el color base predominante
punto getPunto(const triangulo &, unsigned);               //obtener un punto
bool isEquilatero(const triangulo &);                       //compararia los lados para saber si el trinagulo es equilatero, para hacerlo llamaria a longitudLadoTriangulo

int main(){

    return 0;
}
