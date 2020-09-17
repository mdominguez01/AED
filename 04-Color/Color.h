#include <cstdint>
#include <string>

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
Color Mezclar(Color, Color, unsigned); // mezclar dos color con diferentes intensidades, el porcentaje es del primer color
std::string GetHtmlHex(Color); // genera un string con la representación hexadecimal para HTML de un color
std::string GetHtmlRgb(Color);
void CrearSvgConTextoEscritoEnAltoContraste(std::string,std::string, Color);       // obtiene en red --> cyan, green--> magenta y blue--> amarillo
