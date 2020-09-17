#include "Color.h"
#include <cassert>

int main()
{
    CrearSvgConTextoEscritoEnAltoContraste("Mensaje","¡Hola, Mundo!", magenta); 

    Color mezclaTest1{255, 0, 127};

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

    //Mprueba de la segunda variante de Mezclar

    assert(IsIgual(Mezclar(blanco,blanco,100),blanco));

    // assserts GetHtmlHex
    assert("#00ff00" == GetHtmlHex(green));
    assert("#00ff02" == GetHtmlHex({0,255,2}));
    assert("#ff0000" == GetHtmlHex(red));
    assert("#ffffff" == GetHtmlHex(blanco));

    // asserts GetHtmlRGB
    assert( "rgb(0,0,255)" == GetHtmlRgb(blue) );
    assert( "rgb(0,255,0)" == GetHtmlRgb(green) );
    assert( "rgb(255,255,255)" == GetHtmlRgb(blanco) );
    assert( not ("rgb(0,0,255)" == GetHtmlRgb(red) ));


    //system("Pause");
    return 0;
}