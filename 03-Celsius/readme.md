### ETAPA 1: Análisis del problema
* #### Problema: 
    Desarrollar una función que, dada una magnitud en Farehnheit, calcule la equivalente en Celsius.
    
* #### Refinamiento del problema e Hipotesis:
    Desarrollar una función que, dada una magnitud en Farehnheit , calcule la equivalente en Celsius cuyo resultado es una fraccion. Y luego comparar dicho resultado con el  valor de tolerancia para corroborar que lo obtenido es correcto.


### ETAPA 2: Diseño de la Solución

* #### Léxico del Algoritmo: 
    areNear ∈ B ; f,a,b,t ∈ R 
* #### Representación del Algoritmo:

    ##### Textual: C++
        double Celsius (double);
        bool AreNear(double, double, double = 0.001);

        int main(){

            double f=78.00;
        
            bool areNear=AreNear(Celsius(f),Celsius(f),0.001);
            assert(areNear);
        }
        
        double Celsius(double f){
            return (5.00/9.00)*(f-32);
        }
        
        bool AreNear(double a, double b, double t){
            return a-t< b &&  a+t > b  ? true : false;
        }

