/*
 Trabajo practico N°5 Poligono
 Poligono  
 Alumno: Matias Dominguez
 Legajo: 1743375
 28-10-2020
*/

#include <string>
#include <array>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
#include "Poligono.h"

using namespace std;

bool ExtraerPoligonosSegunPerimetros(vector<poligono> &poligonos, istream &in, double min_p,double max_p){
    poligono n;
    do
    {
        ExtraerPoligono(n, in);
        if(min_p < Get_Perimetro(n) && max_p > Get_Perimetro(n))poligonos.push_back(n);
        
    } while (!in.eof());

    return in.eof();
}

bool ExtraerPoligonos(vector<poligono> &poligonos, istream &in){
    poligono n;
    do
    {
        ExtraerPoligono(n, in);
        poligonos.push_back(n);
        
    } while (!in.eof());

    return in.eof();
}

bool ExtraerPoligono(poligono &n, istream &in){
    unsigned nro=0;
    ExtraerColor(n.color,in);
    in >> nro;
    n.n=0;
    do
    {
        ExtraerPunto(n.puntosPoligono.at(n.n),in);
        n.n++;
        nro--;
    } while (nro>0);
    n.n--;
    return in.eof();
}


bool ExtraerColor(Color &color, istream &in){
    int nro;
    in >> nro;
    color.r = (uint8_t) nro;
    in >> nro;
    color.g = (uint8_t) nro;
    in >> nro;
    color.b = (uint8_t) nro;

    return in.eof();
}


bool ExtraerPunto(Punto &p, istream &in){
    in >> p.x;
    in >> p.y;
    return in.eof();
}



bool EnviarPoligonos(const vector<poligono> &poligonos, ostream &out){

    int place=0;
    do
    {
        EnviarPoligono(poligonos.at(place), cout);
        if(place<(poligonos.size()-1)){
            cout << " ";
            place++;
        }else
        {
            place++;
        }
        cout << "\n";
    } while ( place<poligonos.size());
     
    return out.eof();
}

bool EnviarPoligono(const poligono &n, ostream &out){
    unsigned nro=0;
    EnviarColor(n.color,out);
    out << n.n+1;
    do
    {
        EnviarPunto(GetVertice(n,nro),out);
        nro++;
    } while (nro<=n.n);
    
    return out.eof();
}

bool EnviarColor(const Color &color, ostream &out){
    
    out << (unsigned)color.r << " ";
    out << (unsigned)color.g << " ";
    out << (unsigned)color.b << " ";

    return out.eof();
}

bool EnviarPunto(const Punto &punto, ostream &out){
    out << " " << punto.x << " ";
    out << punto.y ;
    return out.eof();
}

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

