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

int minasAdyacentes(tablero& t, pos p) {
    int result = numMinasAdyacentes(t, p);
    return result;
}


/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    if (esBanderita(p,b)){
        sacaBanderita(p,b);
    }else plantaBanderita(p, b);
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool perdio(tablero& t, jugadas& j) {
    bool result=false;
    for (int i=0; i<j.size();i++){
        if (hayMinaEnPosicion(j[i].first,t)){
            result=true;
        }
    }

    return result;
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
bool gano(tablero& t, jugadas& j) {
    bool result= true;
    for (int i=0;i<t.size();i++){
        for (int k=0;k<t.size();k++){
            pos pos1={i,k};
            if (t[i][k]==cVACIA){
                if (!fueJugada(pos1, j)) {
                    result = false;
                }
            }
        }
    }

    return result;
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    incluirJugadaActual(p, j, t);
    if (t[p.first][p.second] == cVACIA && minasAdyacentes(t,p)==0){
        for (int i=0; i<t.size();i++){
            for (int k=0;k<t.size();k++){
                pos pos1 (i,k);
                if (!fueJugada(pos1,j) && !esBanderita(pos1,b)){
                    if (esParteDelCaminoLibre(p,pos1,t)){
                        jugarPlus(t,b,pos1,j);
                    }
                }
            }
        }
    }
}


/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
/*bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    bool hay=false;
    if (juegoValido(t,j) && banderitasValidas(b,t,j)){
        if (hayPosicionSugerible(j,b,t)){
            if (esPosicionSinJugarYSinBanderita(p,j,b,t) && esAdyacenteA121(p,j)){
                hay=true;
            }
        }

    }
    return hay;
}
*/