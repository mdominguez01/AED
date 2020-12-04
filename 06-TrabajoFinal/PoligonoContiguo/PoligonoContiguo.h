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



const Color red{255, 0, 0};
const Color green{0, 255, 0};
const Color blue{0, 0, 255};

const Color cyan{0, 255, 255};
const Color magenta{255, 0, 255};
const Color amarillo{255, 255, 0};

const Color blanco{255, 255, 255};
const Color negro{0, 0, 0};


//PROTOTIPOS

//Funciones de color

bool IsIgual(Color, Color);             // comparar dos colores
Color Mezclar(Color, Color);            //mezclar dos colores

//Funciones de punto

bool isIgual(const Punto &, const Punto &);        // comparar dos puntos
double GetDistacia(const Punto &, const Punto &);       // obtener la distancia emtre dos puntos
double GetDistanciaAlOrigen(const Punto &);             // obtener la distancia de un punto al origen

//Funciones del poligono

void AddVertice(Poligono &, Punto);                     // anadir un vertice al poligono
Punto GetVertice(const Poligono &, unsigned);           // obtener un vertice del poligono
void SetVertice(Poligono &, unsigned, Punto);           // modificar un vertice del poligono
void RemoveVertice(Poligono &, unsigned);               // remover un vertice del poligono
unsigned GetCantidadLados(const Poligono &);            // obtener la cantidad de lados de un poligono
double GetPerimetro(const Poligono &);                  // obtener el perimetro de un poligono

//IN / OUT de cada tipo

bool ExtraerPoligonos(Poligonos &, istream &);          // Extraer todos los poligonos de una entrada y guardarlo en poligonos
bool ExtraerPoligono(Poligono &, istream &);            // Extraer el poligono de una entrada y guardarlo en poligono
bool ExtraerColor(Color &, istream &);                  // Extraer el color de una entrada y guardarlo en color
bool ExtraerPunto(Punto &, istream &);                  // Extraer el punto de una entrada y guardarlo en puntto
bool InsertarPoligonos(const Poligonos &, ostream &);   // Insertar poligonos en una salida
bool InsertarPoligono(const Poligono &, ostream &);     // Insertar poligono en una salida
bool InsertarColor(const Color &, ostream &);           // Insertar color en una salida
bool InsertarPunto(const Punto &, ostream &);           // Insertar un punto en una salida


bool ExtraerPoligonosSegunPerimetros(Poligonos &, std::istream &, double);          // Extraer los poligonos que cumplan con el requisitmo de perimetro minimo
void CopiarPoligonosConPerimetrosMayoresA(double,string,string);                    // Copia los polignos de un archivo "x" que cumplan con la condicion de perimetro minimo a otro archivo llamado "salida"