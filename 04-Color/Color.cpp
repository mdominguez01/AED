#include <string>
#include <cstdint>
#include "Color.h"
#include <sstream>
#include <fstream>


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

Color Mezclar(Color a, Color b, unsigned porcentaje){
    double intA=porcentaje/100.0;
    double intB=(1.0-intA);
    Color mezcla{0,0,0};
    double aRojo = (a.r) * intA; double aVerde = (a.g) * intA; double aAzul = (a.b) * intA;
    double bRojo = (b.r) * intB; double bVerde = (b.g) * intB; double bAzul = (b.b) * intB;
    mezcla= {(uint8_t)(aRojo+bRojo),(uint8_t)(aVerde+bVerde),(uint8_t)(aAzul+bAzul)};

    //std::cout<< "mezcla---> RED: " <<(unsigned)mezcla.r <<"  GREEN: "<<(unsigned)mezcla.g<<" BLUE: " << (unsigned)mezcla.b; 

    return mezcla;
}


std::string fixHexString(std:: string);// prototipo de la funcicon que se usa en GetHtmolHEx

std::string GetHtmlHex(Color x){

    std::stringstream ss;
    std::stringstream ss1;
    std::stringstream ss2;
    ss << std::hex << (unsigned)x.r;
    std::string red= ss.str();
    red=fixHexString(red);
    
    ss1 << std::hex << (unsigned)x.g;
    std::string green= ss1.str();
    green=fixHexString(green);
    

    ss2 << std::hex << (unsigned)x.b;
    std::string blue= ss2.str();
    blue=fixHexString(blue);
    std::string htmlHex= "#"+ red + green + blue;
    
    //std::cout << "\nAZUL: #" << std::hex << (unsigned)x.r << std::hex << (unsigned)x.g << std::hex << (unsigned)x.b;
    //std::cout << "\nAZUL: " << htmlHex;
    return htmlHex;
}

std::string fixHexString(std:: string fix){
    if (fix=="0" || fix=="1" || fix=="2" || fix=="3" ||fix=="4" ||fix=="5" ||fix=="6" ||fix=="7" ||fix=="8" || fix=="9" || fix=="a" || fix=="b" || fix=="c" || fix=="d" || fix=="e" || fix=="f" )
    {
        return fix= "0"+fix;
    }
    return fix;
}

std::string GetHtmlRgb(Color x){
    std::string htmlRgb= "rgb(" + std::to_string(x.r) +","+ std::to_string(x.g) +","+ std::to_string(x.b) + ")" ; 
    return htmlRgb;
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
    Color z;
    return x.r == 0 && x.g == 0 && x.b == 0 ? z={255,255,255}  : x.r == 0 && x.g == 0 ? z={255,255,0} : x.r == 0 && x.b == 0 ? z={255,0,255} : x.g == 0 && x.b == 0 ? z={0,255,255} : x.r == 0 ? z={255,0,0} : x.g == 0 ? z={0,255,0} : x.b == 0 ? z={0,0,255} : z={0,0,0};

    //return x.r==255 ? z={0,255,255} : x.g==255 ? z={255,0,255} : z={255,255,0};
}

void CrearSvgConTextoEscritoEnAltoContraste(std::string nombreArchivo,std::string mensaje, Color color){

    std::ofstream file(nombreArchivo + ".svg");
    
    file << "<?xml version=\"1.0\" standalone=\"no\"?>" << std::endl
       << "  <svg xmlns=\"http://www.w3.org/2000/svg\">" << std::endl
       << "  <rect x=\"" << 0 <<"\"  y=\"" << 0 <<"\" width=\"" << 120 << "\" height=\"" << 30 << "\"" << " style=\"fill:" << GetHtmlRgb(GetComplentario(color))<< "\"/>" << std::endl
       << "  <text x=\"" << 5 <<"\"  y=\"" << 18 << "\"" << " style=\"fill:" << GetHtmlRgb(color)<< "\">" << "\"" <<  mensaje  << "\" </text>" << std::endl
       << "</svg>" << std::endl;
    file.close();
}