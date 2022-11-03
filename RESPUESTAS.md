% Contesten aquí la pregunta sobre complejidad


Si la estructura jugadas fuera una matriz conteniendo en cada posición la
cantidad de minas adyacentes (o -1 si la casilla no fue jugada), la complejidad temporal
de jugarPlus cambiaría bastante.
La recorrida de la matriz sostendría la complejidad de t^2 pero la guarda del IF bajaría
de 2 t^2 a 1 para luego entrar en la recursión.
Una pasada de jugarPlus tendría una complejidad temporal de O(t^2) y, en el peor de los casos,
entraría a la recursión 8 veces por cada casilla jugada (o agregada automáticamente).

Con lo cual, esta modificación en la estructura de datos haría que esta función fuese mucho menos compleja temporalmente.

Con respecto a sugerirAutomático121, al igual que en el caso anterior, la recorrida de la matriz da una 
complejidad de t^2 (siendo t la cantidad de filas y columnas del tabero).
Nuevamente la diferencia de complejidad con lo especificado se da en la guarda del if.
La función esAdyacenteA121 podría resolverse en una cantidad constante de pasos (6 para ver si es horizontal y 6 para ver si es vertical).
Con respecto a la funcion esPosicionSinJugarYSinBanderita, hay dos posibilidades. Una que en esta matriz se pueda
identificar las banderitas también. En ese caso la complejidad temporal es 1.
En caso que no, habría que recorrer el vector banderitas (que a lo sumo es t^2).

En resumen, en caso que en la matriz se pueda identificar a las banderitas, la función sugerirAutomático121
pasaría a tener una complejidad de O * (6+6+1), que termina siendo O(t^2), muy inferior a la complejidad
calculada originalmente O(t^4).

En el caso que las banderitas estuvieran en otro vector y haya que recorrerlas, la complejidad temporal, en el peor
de los casos, no se modificaría y seguiría siendo O(t^4).