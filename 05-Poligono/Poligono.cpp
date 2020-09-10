/*
 Trabajo practico N°5 Poligono
 Poligono  
 Alumno: Matias Dominguez
 Legajo: 1743375
 10-09-2020
*/

#include <cassert>
#include <string>
#include <array>
#include <cmath>

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

    return 0;
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