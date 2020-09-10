/*
 Trabajo practico N°4 Color
 Color
 Alumno: Matias Dominguez
 Legajo: 1743375
 10-09-2020
*/

#include <cassert>
#include <string>
#include <cstdint>

enum modo
{
    SUMAR,
    RESTAR
}; //MODO del metodo sumar o restar

struct Color
{
    uint8_t r, g, b;
}; // Color en RGB

//declaraccion colores
const Color red{255, 0, 0};
const Color green{0, 255, 0};
const Color blue{0, 0, 255};

const Color cyan{0, 255, 255};
const Color magenta{255, 0, 255};
const Color amarillo{255, 255, 0};

const Color blanco{255, 255, 255};
const Color negro{0, 0, 0};

//prototipos
bool IsIgual(Color, Color);             // comparar dos colores
Color Mezclar(Color, Color);            //mezclarr dos colores , por promedio de intensidad
Color SumarYRestar(modo, Color, Color); //sumar dos colores
Color GetComplentario(Color);           // obtiene en red --> cyan, green--> magenta y blue--> amarillo

int main()
{
    Color mezclaTest1{255, 0, 128};

    //asserts de las constantes
    assert(red.r == 255);
    assert(green.g != 0);
    assert(cyan.r != 255);

    Color mezcla1 = Mezclar(red, magenta);

    //asserts de la comparacion,suma y resta
    assert(IsIgual(mezcla1, mezclaTest1));

    Color mezcla2 = SumarYRestar(modo::SUMAR, green, blue);
    assert(IsIgual(mezcla2, cyan));
    assert(IsIgual(SumarYRestar(modo::SUMAR, red, blue), magenta));
    assert(IsIgual(SumarYRestar(modo::SUMAR, red, green), amarillo));
    assert(IsIgual(SumarYRestar(modo::SUMAR, red, cyan), blanco));

    assert(IsIgual(SumarYRestar(modo::RESTAR, blanco, blue), amarillo));
    assert(IsIgual(SumarYRestar(modo::RESTAR, blanco, red), cyan));
    assert(IsIgual(SumarYRestar(modo::RESTAR, blanco, green), magenta));
    assert(IsIgual(SumarYRestar(modo::RESTAR, red, red), negro));

    // asserts GetCOmplementario
    assert(IsIgual(GetComplentario(red), cyan));
    assert(IsIgual(GetComplentario(green), magenta));
    assert(IsIgual(GetComplentario(blue), amarillo));

    //std::cout << "\nwhite: " << std::hex << (unsigned)negro.r << "," << std::hex << (unsigned)negro.g << "," << std::hex << (unsigned)negro.b;
    //std::cout << "\nwhite: " << std::hex << (unsigned)blanco.r << "," << std::hex << (unsigned)blanco.g << "," << std::hex << (unsigned)blanco.b;

    system("Pause");
    return 0;
}

bool IsIgual(Color a, Color b)
{
    return (a.r == b.r) && (a.g == b.g) && (a.b == b.b) ? true : false;
}

Color Mezclar(Color a, Color b)
{
    Color mezcla{0, 0, 0};
    unsigned sumaR = (unsigned)(a.r + b.r);
    unsigned sumaV = (unsigned)(a.g + b.g);
    unsigned sumaA = (unsigned)(a.b + b.b);

    double restoR = (sumaR) / 2.0;
    double restoV = (sumaV) / 2.0;
    double restoA = (sumaA) / 2.0;
    std::string rojo = std::to_string(restoR);
    std::string verde = std::to_string(restoV);
    std::string azul = std::to_string(restoA);

    std::string delimitador = ".";
    std::string R = rojo.substr((rojo.find(delimitador) + 1), 1);
    std::string V = verde.substr((verde.find(delimitador) + 1), 1);
    std::string A = azul.substr((azul.find(delimitador) + 1), 1);

    restoR = std::stod(R);
    restoV = std::stod(V);
    restoA = std::stod(A);

    unsigned caso = restoR == 0 && restoV == 0 && restoA == 0 ? 7 : restoR == 0 && restoV == 0 ? 1 : restoR == 0 && restoA == 0 ? 2 : restoV == 0 && restoA == 0 ? 3 : restoR == 0 ? 4 : restoV == 0 ? 5 : restoA == 0 ? 6 : 0;

    //casos:
    /*
    0 --> todos
    1 --> azul
    2 --> verde
    3 --> rojo
    4 --> verde y azul
    5 --> rojo y azul
    6 --> rojo y verde
    7---> ninguno
    */
    switch (caso)
    {
    case 0:
        sumaV++;
        sumaA++;
        sumaR++;
        break;
    case 1:
        sumaA++;
        break;
    case 2:
        sumaV++;
        break;
    case 3:
        sumaR++;
        break;
    case 4:
        sumaV++;
        sumaA++;
        break;
    case 5:
        sumaR++;
        sumaA++;
        break;
    case 6:
        sumaR++;
        sumaV++;
        break;
    default:
        break;
    }

    return mezcla = {(uint8_t)(sumaR / 2), (uint8_t)(sumaV / 2), (uint8_t)(sumaA / 2)};
}

Color SumarYRestar(modo modo, Color a, Color b)
{
    uint8_t rojo, verde, azul;
    Color color;

    if (modo == modo::SUMAR)
    {
        rojo = b.r != 0 ? b.r : a.r;
        verde = b.g != 0 ? b.g : a.g;
        azul = b.b != 0 ? b.b : a.b;
    }
    else
    {
        rojo = b.r != 0 ? 0 : a.r;
        verde = b.g != 0 ? 0 : a.g;
        azul = b.b != 0 ? 0 : a.b;
    }

    return color = {rojo, verde, azul};
}

Color GetComplentario(Color x)
{
    return IsIgual(x, red) ? cyan : IsIgual(x, green) ? magenta : amarillo;
}
