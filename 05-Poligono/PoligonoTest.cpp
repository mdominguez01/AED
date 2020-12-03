#include "Poligono.h"
#include <cassert>
#include <fstream>
#include <iostream>
using namespace std;
int main()
{
   Punto uno = {-2.0, 2.0};
    Punto unoCopia = {-2.0, 2.0}; //igual al punto uno
    Punto dos = {2.0, 2.0};
    Punto tres = {2.0, -2.0};
    Punto cuatro = {-2.0, -2.0};

    //Poligono poli{{uno, dos, tres, cuatro}, 4, {0, 0, 0}};
    //Poligono poli2{{uno, dos, tres, cuatro}, 4, {0, 0, 0}};
    
    Poligono poli{{}, 0, {0, 0, 0}};

    AddVertice(poli, uno);
    AddVertice(poli, dos);
    AddVertice(poli, tres);
    AddVertice(poli, cuatro);

    //asserts del Poligono
    //Get Vertice
    assert(isIgual(uno, GetVertice(poli, 1)));
    assert(isIgual(dos, GetVertice(poli, 2)));
    assert(!isIgual(tres, GetVertice(poli, 1)));
    assert(!isIgual(cuatro, GetVertice(poli, 2)));

    //Add vetice
    Punto cinco{-10, 0};
    AddVertice(poli, cinco);
    assert(isIgual(cinco, GetVertice(poli, 5)));
    assert(!isIgual(tres, GetVertice(poli, 5)));

    //Set vetice
    SetVertice(poli, 5, uno);
    assert(!isIgual(cinco, GetVertice(poli, 5)));
    assert(isIgual(uno, GetVertice(poli, 5)));

    //Catidad de lados
    assert(4 != GetCantidadLados(poli));
    assert(5 == GetCantidadLados(poli));

    //Remover vetice
    RemoveVertice(poli, 5);
    assert(isIgual(cuatro, GetVertice(poli, poli.n)));
    assert(!isIgual(cuatro, GetVertice(poli, 3)));

    //Get_Perimetro
    assert(15.9 < GetPerimetro(poli) && 16.1 > GetPerimetro(poli));
    assert(!(19.4 < GetPerimetro(poli) && 19.5 > GetPerimetro(poli)));


    // Creacion de los archivos
    
    ofstream myfile("poligono.txt");
    myfile << "255 255 255 5 0.2 2.0 1.2 3.0 2.1 4.0 -1.0 8.0 -8.0 2.0\n0 0 0 4 2.0 2.0 -2.0 2.0 2.0 -2.0 -2.0 -2.0";
    myfile.close();

    ofstream file("p2.txt");
    file << "255 255 255 5 0.2 2.0 1.2 3.0 2.1 4.0 -1.0 8.0 -8.0 2.0\n0 0 0 4 2.0 2.0 -2.0 2.0 -2.0 -2.0 2.0 -2.0";
    file.close();
    
    // ExtaerPoligonos, InsertarPoligonos 

    Poligonos poligonos;
    Poligonos poligonos2;
  
    ifstream in("poligono.txt");
    ifstream in2("p2.txt");
    
    assert(ExtraerPoligonos(poligonos,in));
    assert(ExtraerPoligonos(poligonos2,in2));
    
    assert(!InsertarPoligonos(poligonos,cout));
    assert(!InsertarPoligonos(poligonos2,cout));

    // CopiarPoligonosConPerimetrosMayoresA

    CopiarPoligonosConPerimetrosMayoresA(20.0, "documentoPoligonos","salida");

    
    return 0;
}