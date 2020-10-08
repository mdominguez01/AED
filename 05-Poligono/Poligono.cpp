/*
 Trabajo practico N°5 Poligono
 Poligono  
 Alumno: Matias Dominguez
 Legajo: 1743375
 10-09-2020
*/

#include <string>
#include <array>
#include <cmath>
#include <fstream>
#include <iostream>
#include "Poligono.h"

using namespace std;

bool isIgualPunto(const Punto &a, const Punto &b)
{
    return (a.x == b.x) && (a.y == b.y) ? true : false;
}

double GetDistaciaPunto(const Punto &a, const Punto &b)
{
    double d = sqrt(pow((b.x - a.x), 2.0) + pow((b.y - a.y), 2.0));
    return d;
}

double GetDistanciaAlOrigen(const Punto &a)
{
    Punto x{0,0};
    return GetDistaciaPunto(x,a);
}

//Funiones de un Poligono

void AddVertice(poligono &a, Punto p)
{
    a.n = a.n + 1;
    a.puntosPoligono[a.n].x = p.x;
    a.puntosPoligono[a.n].y = p.y;
}

Punto GetVertice(const poligono &a, unsigned n2)
{
    return a.puntosPoligono[n2];
}

void SetVertice(poligono &a, unsigned n2, Punto p)
{
    a.puntosPoligono[n2].x = p.x;
    a.puntosPoligono[n2].y = p.y;
}

void RemoverVertice(poligono &a, unsigned n2)
{

    for (unsigned i = n2; i <= a.n; i++)
    {
        a.puntosPoligono[i] = a.puntosPoligono[i + 1];
    }
    a.n = a.n - 1;
}

unsigned CantidadLados(const poligono &a)
{
    return a.n + 1;
}

double Get_Perimetro(const poligono &a)
{
    double perimetro = 0;
    for (unsigned i = 0; i <= a.n; i++)
    {
        perimetro = i < a.n ? perimetro + GetDistaciaPunto(a.puntosPoligono[i], a.puntosPoligono[i + 1]) : perimetro + GetDistaciaPunto(a.puntosPoligono[i], a.puntosPoligono[0]);
    }
    return perimetro;
}

void extraerPoligono(poligono &n, ifstream &in){
    Color color;
    int i=0;

       for (int s; in >> s; )
       {
           int nro = s;

           switch(i){
               case 0: 
                        color.r = (uint8_t) nro;
                        cout << nro << " aca ";
                        i++; break;
               case 1: 
                        color.g = (uint8_t) nro;
                        cout << nro << " acaaa ";
                        i++; break;
               case 2: 
                        color.b = (uint8_t) nro;
                        cout << nro << " ACAAA \n" ;
                        i++; 
                        n.color=color;
                        break;
               default: 
                        extraerPuntos(n,in);
                        break;
           }

       }
}

void extraerPuntos(poligono &n, ifstream &in){
    Punto p;
    bool op=true;
    for (double d; in >> d; ){ 
        double nro = d; 
        if(op){
            p.x=nro;
            cout << p.x << "a\n"; 
            op=false;
        }
        else{
            p.y = nro;
            
            cout << p.y << "b\n"; 
            AddVertice(n,p);
        }
        cout << nro << "\n";    
    }
}