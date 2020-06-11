### ETAPA 1: Análisis del problema
* #### Problema: 
   Dado un año, determinar si es bisiesto.

* #### Refinamiento del problema e Hipotesis:

  Dado un numero entero que representa el año, determinar si cumple los requisitos para que sea bisiesto o no. 
  
  El primer año bisiesto fue el año 1584.
  
  Es bisiesto si: 
  - el numero er mayor o igual 1584
  - divisible por 4
  - no ser divisible por 100
  - ser divisible por 400
  
  Los años 1600,2000 y 2400 son bisiestos aunque son divisibles por 100 y 400.
  
* #### IPO: 
    Z --> IsBisiesto --> B


### ETAPA 2: Diseño de la Solución
* #### Lexico del algoritmo: 
   ano ∈ ℤ, IsBisiesto ∈ B;
   
   
* #### Lexico de la funcion:
    
    IsBisiesto: Z --> B: a ∧ p ∧ (¬q ∨ r) 
    
    - a: x es mayor o igual 1584
    - p: x es divisible por 4
    - q: x es divisible por 100
    - r: x es divisible por 4
    
* #### Árbol de expresion:
![](https://github.com/mdominguez01/AED/blob/master/Imagenes/03-Bisiesto/arbol.png)
    
