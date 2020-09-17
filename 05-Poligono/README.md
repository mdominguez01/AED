### Análisis del problema
* #### Problema: 
Desarrollar el tipo de dato Polígono que representa polígonos con color en el plano. Las operaciones son: AddVértice, GetVértice, SetVértice, RemoveVértice, GetCantidadLados, y Get_GetPerímetro.


* #### Refinamiento del problema e Hipotesis:
El poligono esta compuesto de Puntos (minimo tres puntos).
Cada Punto tiene dos valores reales (x e y).
No pueden existir Puntos iguales en un poligono.


* #### IPO:
    * AddVertice: Poligono,Punto -->
    * Getvertice: Poligono, N --> Punto
    * SetVertice: Poligono, N, Punto -->
    * RemoverVertice: Poligono, N -->
    * CantidadLados: Poligono --> N
    * Get_Perimetro: Poligono --> R