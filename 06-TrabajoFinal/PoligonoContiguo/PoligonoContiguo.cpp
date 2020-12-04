/*
 Trabajo practico N°6 Trabajo Final
 Poligono Contiguo
 Alumno: Matias Dominguez
 Legajo: 1743375
 03-12-2020
*/

#include <string>
#include <array>
#include <cmath>
#include <fstream>
#include <iostream>
#include "PoligonoContiguo.h"

using namespace std;

void CopiarPoligonosConPerimetrosMayoresA (double min, string nombreArchivoIn, string nombreArchivoOut){
    
    Poligonos poligonos;
    ifstream in(nombreArchivoIn+".txt");
    ExtraerPoligonosSegunPerimetros(poligonos,in,min);

    ofstream theFile(nombreArchivoOut+".txt");
    InsertarPoligonos(poligonos,theFile);
    theFile.close();

}

bool ExtraerPoligonosSegunPerimetros(Poligonos &poligonos, istream &in, double min_p){

    poligonos.n=0;
    Poligono n;
    int place=0;
    do
    {
        ExtraerPoligono(n, in);
        //if(max_p > Get_Perimetro(n)){
        double perimetroN=GetPerimetro(n);    
        if(min_p < perimetroN ){
            poligonos.losPoligonos.at(place)=n;
            poligonos.n++;
            
            if(!in.eof())place++;
        }
        
    } while (!in.eof());

    return in.eof();

}

bool ExtraerPoligonos(Poligonos &poligonos, istream &in){
    Poligono n;
    int place=0;
    do
    {
        ExtraerPoligono(n, in);
        poligonos.losPoligonos.at(place)=n;
        poligonos.n=place+1;
        
        if(!in.eof())place++;

    } while (!in.eof());

    return in.eof();

}

bool ExtraerPoligono(Poligono &n, istream &in){
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
    //n.n--;
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



bool InsertarPoligonos(const Poligonos &poligonos, ostream &out){  //cambiar nombre a la funcion
    if(poligonos.n==0)return out.eof();
    int place=0;
    do
    {
        InsertarPoligono(poligonos.losPoligonos.at(place), out);
        if(place<(poligonos.n-1)){
            out << " ";
            place++;
        }else
        {
            place++;
        }
        out << "\n";
    } while ( place<poligonos.n);

    return out.eof();

}

bool InsertarPoligono(const Poligono &n, ostream &out){ //cambiar nombre a la funcion
    unsigned nro=1;
    InsertarColor(n.color,out);
    out << n.n;
    do
    {
        InsertarPunto(GetVertice(n,nro),out);
        nro++;
    } while (nro<=n.n);

    return out.eof();
}


//Funciones puntos
bool InsertarColor(const Color &color, ostream &out){ //cambiar nombre a la funcion

    out << (unsigned)color.r << " ";
    out << (unsigned)color.g << " ";
    out << (unsigned)color.b << " ";

    return out.eof();
}

bool InsertarPunto(const Punto &punto, ostream &out){   
    out << " " << punto.x << " ";
    out << punto.y ;
    return out.eof();
}

bool isIgual(const Punto &a, const Punto &b)  
{
    return (a.x == b.x) && (a.y == b.y) ? true : false;
}
double GetDistacia(const Punto &a, const Punto &b) 
{
    double d = sqrt(pow((b.x - a.x), 2.0) + pow((b.y - a.y), 2.0));
    return d;
}
double GetDistanciaAlOrigen(const Punto &a)
{
    Punto x{0,0};
    return GetDistacia(x,a);
}
//Funiones de un Poligono
void AddVertice(Poligono &a, Punto p)
{
    a.puntosPoligono[a.n].x = p.x;
    a.puntosPoligono[a.n].y = p.y;
    a.n = a.n + 1;
   
}
Punto GetVertice(const Poligono &a, unsigned n2)
{
    return a.puntosPoligono[n2-1];
}
void SetVertice(Poligono &a, unsigned n2, Punto p)
{
    a.puntosPoligono[n2-1].x = p.x;
    a.puntosPoligono[n2-1].y = p.y;
}
void RemoveVertice(Poligono &a, unsigned n2)
{
    for (unsigned i = n2; i <= a.n; i++)
    {
        a.puntosPoligono[i] = a.puntosPoligono[i + 1];
    }
    a.n = a.n - 1;
}
unsigned GetCantidadLados(const Poligono &a)  
{
    return a.n;
}
double GetPerimetro(const Poligono &a)       
{
    double perimetro = 0;
    for (unsigned i = 1; i <= a.n; i++)
    {
        perimetro = i < a.n ? perimetro + GetDistacia(GetVertice(a,i), GetVertice(a,(i+1))) : perimetro + GetDistacia(GetVertice(a,i), GetVertice(a,1));
    }
    return perimetro;
}

//Funciones color
bool IsIgual(Color a, Color b)
{
    return (a.r == b.r) && (a.g == b.g) && (a.b == b.b) ? true : false;
}

Color Mezclar(Color a, Color b){
    double intensidad=0.5;
    Color mezcla{0,0,0};
    double aRojo = (a.r) * intensidad; double aVerde = (a.g) * intensidad; double aAzul = (a.b) * intensidad;
    double bRojo = (b.r) * intensidad; double bVerde = (b.g) * intensidad; double bAzul = (b.b) * intensidad;
    mezcla= {(uint8_t)(aRojo+bRojo),(uint8_t)(aVerde+bVerde),(uint8_t)(aAzul+bAzul)};

    //std::cout<< "mezcla---> RED: " <<(unsigned)mezcla.r <<"  GREEN: "<<(unsigned)mezcla.g<<" BLUE: " << (unsigned)mezcla.b; 

    return mezcla;
}
