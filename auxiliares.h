
//
// Este archivo contiene las declaraciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con el código
// de esas mismas funciones, que estará en auxiliares.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

bool tableroValido(tablero& tablero);
bool tamanioDeTableroValido(tablero& tablero);
bool cantidadDeMinasValida(tablero& tablero);
bool posicionValida(pos p, int n);
int numMinasAdyacentes(tablero& t, pos p);
bool esAdyacenteValida(pos p, int i, int j, tablero& t);



