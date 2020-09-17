### Análisis del problema
* #### Problema: 
Diseñar un tipo Color basado en el modelo RGB, con tres canales de 8 bits. Todo color está compuesto por tres componentes: intensidad de red (rojo), de green (verde), y de blue (azul). Cada intensidad está en el rango [0, 255]. Definir los valores para rojo, azul, verde, cyan, magenta, amarillo, negro, y blanco. Dos colores se pueden mezclar, lo cual produce un nuevo color que tiene el promedio de intensidad para cada componente.

* #### Refinamiento del problema e Hipotesis:
La intensidad de cada componente que conforma al Color no puede ser mayor a 255 ni tampoco numeros reales.

El valor del porcentaje de intensidad es un numero entero de 0 a 100


* #### IPO:
    * IsIgual: Color x Color --> B   
    * Mezclar: Color x Color --> Color
    * SumarYRestar: enum x Color x Color --> Color
    * GetComplementario: Color --> Color
    * Mezclar: Color x Color x N --> Color  
    * GetHtmlHex: Color --> Σ*
    * GethtmlRgb: Color --> Σ*
    * CrearSvgConTextoEscritoEnAltoContraste: Σ* x Σ* x Color -->  SVG
