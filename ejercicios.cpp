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
    int result=0;
    if (tableroValido(t) && posicionValida(p,t.size())){
        result=numMinasAdyacentes(t,p);
    }
    return result;
}

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {

    
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool perdio(tablero& t, jugadas& j) {
    bool result=false;
    if (juegoValido(t,j)){
        for (int i=0; i<j.size();i++){
            if (hayMinaEnPosicion(j[i].first,t)){
                result=true;
            }
        }
    }
    return result;
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
bool gano(tablero& t, jugadas& j) {
    bool result= true;
    if (juegoValido(t,j)){
        for (int i=0;i<t.size();i++){
            for (int k=0;k<t.size();k++){
                pos pos1={i,k};
                if (fueJugada(pos1,j) && t[i][k]==true){
                    result=false;
                }
            }
        }
    }
    return result;
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    // ...
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    // ...
}
