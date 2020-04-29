### ETAPA 1: Análisis del problema
* #### Problema: 
    La adición de dos números
* #### Refinamiento del problema e Hipotesis:
    “Mostrar la suma de dos números ingresados por el usuario”

* #### Modelo IPO:
    ℤ + ℤ ➝ Adición ➝ ℤ

### ETAPA 2: Diseño de la Solución

* #### Léxico del Algoritmo: 
    a,b ∈ ℤ
* #### Representación del Algoritmo:

    ##### Textual: C++
        int main(){
            int a,b;
            std::cout << "Primer nro: ";
            std::cin >> a;
            std::cout << "Segundo nro: ";
            std::cin >> b;
            std::cout << "La suma es: " << a+b;
        }

    
    ##### Visual: Nassi-Shneiderman
    ![](https://github.com/mdominguez01/AED/blob/master/Imagenes/01-Adici%C3%B3n/Diagrama-Nissi.jpg)
    
