#include "Poligono.h"
#include <cassert>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    Punto uno = {2.0, 2.0};
    Punto unoCopia = {2.0, 2.0}; //igual al punto uno
    Punto dos = {-2.0, 2.0};
    Punto tres = {2.0, -2.0};
    Punto cuatro = {-2.0, -2.0};
    poligono poli{{uno, dos, tres, cuatro}, 3, {0, 0, 0}};
    poligono poli2{{uno, dos, tres, cuatro}, 3, {0, 0, 0}};

    //aserts comparacion puntos
    assert(isIgualPunto(uno, unoCopia));
    assert(!isIgualPunto(uno, dos));
    assert(!isIgualPunto(uno, tres));
    assert(!isIgualPunto(cuatro, dos));

    // asserts getDistacia al punto
    assert(GetDistaciaPunto(uno, dos) == 4.0);
    assert(6.0 > GetDistaciaPunto(dos, tres) && 5.0 < GetDistaciaPunto(dos, tres));
    assert(GetDistaciaPunto(tres, cuatro) == 4.0);
    assert(6.0 > GetDistaciaPunto(cuatro, uno) && 5.0 < GetDistaciaPunto(cuatro, uno));

    //asserts getDistancia al origen
    assert(3.0 > GetDistanciaAlOrigen(uno) && 2.0 < GetDistanciaAlOrigen(uno));
    assert(3.0 > GetDistanciaAlOrigen(tres) && 2.0 < GetDistanciaAlOrigen(tres));
    assert(3.0 > GetDistanciaAlOrigen(dos) && 2.0 < GetDistanciaAlOrigen(dos));
    assert(3.0 > GetDistanciaAlOrigen(cuatro) && 2.0 < GetDistanciaAlOrigen(cuatro));

    //asserts del POligono
    //Get Vertice
    assert(isIgualPunto(uno, GetVertice(poli, 0)));
    assert(isIgualPunto(dos, GetVertice(poli, 1)));
    assert(!isIgualPunto(tres, GetVertice(poli, 0)));
    assert(!isIgualPunto(cuatro, GetVertice(poli, 2)));

    //Add vetice
    Punto cinco{-10, 0};
    AddVertice(poli, cinco);
    assert(isIgualPunto(cinco, GetVertice(poli, 4)));
    assert(!isIgualPunto(tres, GetVertice(poli, 4)));

    //Set vetice
    SetVertice(poli, 4, uno);
    assert(!isIgualPunto(cinco, GetVertice(poli, 4)));
    assert(isIgualPunto(uno, GetVertice(poli, 4)));

    //Catidad de lados
    assert(4 == CantidadLados(poli2));
    assert(4 != CantidadLados(poli));
    assert(5 == CantidadLados(poli));

    //Remover vetice
    RemoverVertice(poli, 0);
    assert(isIgualPunto(dos, GetVertice(poli, 0)));
    assert(!isIgualPunto(dos, GetVertice(poli, 1)));

    //Get_Perimetro
    assert(19.3 < Get_Perimetro(poli2) && 19.4 > Get_Perimetro(poli2));
    assert(!(19.4 < Get_Perimetro(poli2) && 19.5 > Get_Perimetro(poli2)));

    ofstream myfile;
    myfile.open("poligono.txt");
    myfile << "255 255 255 4 1.0 3.0 2.0 4.0 -1.0 8.0 -8.0 2.0";
    //myfile << "1.0 3.0 2.0 4.0 -1.0 8.0 -8.0 2.0";
    //myfile << "255 255 255\n";
    myfile.close();

    poligono n;
    n.n=0;
    Punto p;
    ifstream in;
    in.open("poligono.txt");
    extraerPoligono(n,in);

    return 0;
}