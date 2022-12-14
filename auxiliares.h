
//
// Este archivo contiene las declaraciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con el código
// de esas mismas funciones, que estará en auxiliares.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

//Ejercicio 1
bool tableroValido(tablero& tablero);
bool tamanioDeTableroValido(tablero& tablero);
bool cantidadDeMinasValida(tablero& tablero);
bool posicionValida(pos p, int n);
int numMinasAdyacentes(tablero& t, pos p);
bool esAdyacenteValida(pos p, int i, int j, tablero& t);

//Ejercicio 2
bool hayMinaEnPosicion(pos p, tablero& t);
int minasPisadas(jugadas& j ,tablero& t);
bool jugadasValidas(jugadas& j , tablero& t);
bool juegoValido(tablero& t,jugadas& j);
bool jugadasNoRepetidas (jugadas& j);
bool esBanderita(pos p, banderitas& b);
bool fueJugada(pos p, jugadas& j);
bool esPosicionSinJugarYSinBanderita(pos p, jugadas& j , banderitas& b, tablero& t);
void sacaBanderita(pos p,banderitas& b);
void plantaBanderita(pos p,banderitas& b);
bool mismasBanderitas(banderitas& b, banderitas& control);
bool banderitasValidas(banderitas& b,tablero& t,jugadas& j);

//Ejercicio 5
void incluirJugadaActual(pos p,jugadas& j, tablero& t);
bool esParteDelCaminoLibre(pos partida, pos final, tablero& t);
bool mismasJugadas(jugadas& j, jugadas& control);
bool esAdyacente(pos p1, pos p2);
bool mismaFila(pos p1, pos p2);
bool mismaColumna(pos p1, pos p2);
bool filaAdyacente(pos p1, pos p2);
bool columnaAdyacente(pos p1, pos p2);


//Ejecicio 6
bool hayPosicionSugerible(jugadas& j, banderitas& b, tablero& t);
bool esAdyacenteA121(pos p, jugadas& j);
bool es121Horizontal(pos p, jugadas& j);
bool es121Vertical(pos p, jugadas& j);









