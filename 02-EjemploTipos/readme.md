### ETAPA 1: Análisis del problema
* #### Problema: 
    Ejemplificar la aplicación de los tipos de datos.
    
* #### Refinamiento del problema e Hipotesis:
    Ejemplificar la aplicación de los tipos de datos usando valores literales(constantes).


### ETAPA 2: Diseño de la Solución

* #### Léxico del Algoritmo: 
    booleano ∈ B ; nro_positivo_lli ∈ N ; nro_short, entero ∈ Z ; nro_double ∈ R ; caracter ∈ Σ ; cadena ∈ Σ*
* #### Representación del Algoritmo:

    ##### Textual: C++
        int main(){

            // Ejemplificacion Tipos de Datos

            bool booleano=false;
            unsigned long long int nro_positivo_lli=999999999999999;
            short nro_short=2;
            int entero=-5;
            double nro_double=12.3456;
            char caracter='d';
            string cadena="hola";
        
            assert(booleano!=true);
            assert(nro_positivo_lli>=0);
            assert(nro_short<=4);
            assert(entero==-5);
            assert(nro_double==12.3456);
            assert(caracter!='b');
            assert(cadena=="hola");

        }

