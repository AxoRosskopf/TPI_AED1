//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

#include <stdio.h>
#include <iostream>


#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/
//Complejidad 1 * n * n
//Siendo n la cantidad de filas (y columnas) y tablero.
int minasAdyacentes(tablero& t, pos p) {
    int result = numMinasAdyacentes(t, p); //nunMinasAdyacentes tiene complejidad n * n
    return result;
}


/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/
//Complejidad en el peor de los casos es b * b siendo b, el tamaño del vector banderitas.
//El peor caso es si tiene que sacar la banderita.
void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    if (esBanderita(p,b)){  //Complejidad b, siendo b el tamaño del vector banderitas.
        sacaBanderita(p,b); //Complejidad b, siendo b el tamaño del vector banderitas.
    }else plantaBanderita(p, b); // Complejidad 1.
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
// Complejidad j, siendo J el tamaño del vector jugadas.
bool perdio(tablero& t, jugadas& j) {
    bool result=false;
    for (int i=0; i<j.size();i++){ // Complejidad j, siendo J el tamaño del vector jugadas.
        if (hayMinaEnPosicion(j[i].first,t)){ //Complejidad 1
            result=true;
        }
    }

    return result;
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
//El peor caso tiene de complejidad t * t * j.
//Siendo t el tamaño de filas/columnas del tablero y j el tamaño del vector Jugadas.
bool gano(tablero& t, jugadas& j) {
    bool result= true;
    for (int i=0;i<t.size();i++){ //Complejidad t, siendo t las filas del tablero.
        for (int k=0;k<t.size();k++){ //Complejidad t, siendo t las columnas del tablero.
            pos pos1={i,k};
            if (t[i][k]==cVACIA && !fueJugada(pos1, j)){ //Complejidad j, siendo j el tamaño del vector j.
                result = false;
            }
        }
    }

    return result;
}



/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
//En una corrida tiene de complejidad t * t (j + b + t * t).
//j y b van a ser como mucho t * t ya que dependen del tamaño del tablero.
//Por lo que quedaría t * t (3* t* t) siendo eso una complejidad de t * t * t * t.
//En el peor de los casos va a entrar a la recursión 8 veces por casillero hasta


void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    incluirJugadaActual(p, j, t);
    if (t[p.first][p.second] == cVACIA){
        for (int i=0; i<t.size();i++){ //Complejidad t, siendo t el tamaño de filas del tablero.
            for (int k=0;k<t.size();k++){ //Complejidad t, siendo t el tamaño de filas del tablero.
                pos pos1 (i,k);
                //Compledidad
                //Fue jugada => j (tamaño del vector jugadas)
                //esBanderita => b (tamaño del vector banderitas)
                //esPartelCaminoLibre => t * t
                if (t[i][k]==cVACIA && !fueJugada(pos1,j) && !esBanderita(pos1,b) && esParteDelCaminoLibre(p,pos1,t)){ //j + b + t * t
                        jugarPlus(t,b,pos1,j);
                    }
                }
            }
        }
    }


/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
   bool hay=false;
   //Falta el for
    if (hayPosicionSugerible(j,b,t) && esPosicionSinJugarYSinBanderita(p,j,b,t) && esAdyacenteA121(p,j)){
        hay=true;
    }
    return hay;
}
