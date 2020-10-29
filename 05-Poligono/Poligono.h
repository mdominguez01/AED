#include <array>
#include <fstream>
#include <vector>

struct Punto
{
    double x, y;
};

struct Color
{
    uint8_t r, g, b;
};

struct poligono
{
    std::array<Punto, 20> puntosPoligono;
    unsigned n;
    Color color;
};

/*
IsIgual, GetDistancia, y
GetDistanciaAlOrigen.
*/

bool isIgualPunto(const Punto &, const Punto &);
double GetDistaciaPunto(const Punto &, const Punto &);
double GetDistanciaAlOrigen(const Punto &);

/*
 AddVértice, GetVértice, SetVértice, RemoveVértice,
GetCantidadLados, y Get_GetPerímetro.
*/

void AddVertice(poligono &, Punto);
Punto GetVertice(const poligono &, unsigned);
void SetVertice(poligono &, unsigned, Punto);
void RemoverVertice(poligono &, unsigned);
unsigned CantidadLados(const poligono &);
double Get_Perimetro(const poligono &);

bool ExtraerPoligonos(vector<poligono> &, std::istream &);
bool ExtraerPoligono(poligono &, istream &);
bool ExtraerColor(Color &, istream &);
bool ExtraerPunto(Punto &, istream &);
bool EnviarPoligonos(const vector<poligono> &, std::ostream &);
bool EnviarPoligono(const poligono &, ostream &);
bool EnviarColor(const Color &, ostream &);
bool EnviarPunto(const Punto &, ostream &);
bool ExtraerPoligonosSegunPerimetros(vector<poligono> &, std::istream &, double, double);

