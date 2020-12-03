/*
 Trabajo practico N°6 Trabajo Final
 Poligono Contiguo
 Alumno: Matias Dominguez
 Legajo: 1743375
 03-12-2020
*/

#include <array>
#include <fstream>
#include <iostream>

using namespace std;

struct Punto
{
    double x, y;
};
struct Color
{
    uint8_t r, g, b;
};
struct Poligono
{
    std::array<Punto, 20> puntosPoligono;
    unsigned n;
    Color color;
};

struct Poligonos
{
    std::array<Poligono, 20> losPoligonos;
    unsigned n;
};

/*
IsIgual, GetDistancia, y
GetDistanciaAlOrigen.
*/
bool isIgual(const Punto &, const Punto &);
double GetDistacia(const Punto &, const Punto &);
double GetDistanciaAlOrigen(const Punto &);
/*
 AddVértice, GetVértice, SetVértice, RemoveVértice,
GetCantidadLados, y Get_GetPerímetro.
*/
void AddVertice(Poligono &, Punto);
Punto GetVertice(const Poligono &, unsigned);
void SetVertice(Poligono &, unsigned, Punto);
void RemoveVertice(Poligono &, unsigned);
unsigned GetCantidadLados(const Poligono &);
double GetPerimetro(const Poligono &);

bool ExtraerPoligonos(Poligonos &, istream &);
bool ExtraerPoligono(Poligono &, istream &);
bool ExtraerColor(Color &, istream &);
bool ExtraerPunto(Punto &, istream &);
bool InsertarPoligonos(const Poligonos &, ostream &);
bool InsertarPoligono(const Poligono &, ostream &);
bool InsertarColor(const Color &, ostream &);
bool InsertarPunto(const Punto &, ostream &);
bool ExtraerPoligonosSegunPerimetros(Poligonos &, std::istream &, double);
void CopiarPoligonosConPerimetrosMayoresA(double,string,string);