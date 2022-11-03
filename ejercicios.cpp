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
//Complejidad O(n^2)
//Siendo n la cantidad de filas (y columnas) y tablero.
int minasAdyacentes(tablero& t, pos p) {
    int result = numMinasAdyacentes(t, p); //nunMinasAdyacentes tiene complejidad O(n^2)
    return result;
}


/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/
//Complejidad en el peor de los casos es O(b^2), siendo b el tamaño del vector banderitas.
//El peor caso es si tiene que sacar la banderita.
void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    if (esBanderita(p,b)){  //Complejidad O(b), siendo b el tamaño del vector banderitas.
        sacaBanderita(p,b); //Complejidad O(b), siendo b el tamaño del vector banderitas.
    }else plantaBanderita(p, b); // Complejidad 1.
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
// Complejidad O(j), siendo j el tamaño del vector jugadas.
bool perdio(tablero& t, jugadas& j) {
    bool result=false;
    for (int i=0; i<j.size();i++){ // Complejidad O(j), siendo j el tamaño del vector jugadas.
        if (hayMinaEnPosicion(j[i].first,t)){ //Complejidad 1
            result=true;
        }
    }

    return result;
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
//El peor caso tiene de complejidad O(t^2 * j).
//Siendo t el tamaño de filas/columnas del tablero y j el tamaño del vector Jugadas.
//En el peor de los casos, el vector jugadas es de tamaño t^2.
// Con lo cual, el peor caso es de O(t^4).

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
//En una corrida tiene de complejidad t^2 (j + b + t^2).
//j y b van a ser como mucho t^2 ya que dependen del tamaño del tablero. De hecho en el peor de los casos j + b como mucho son t^2.
//Por lo que quedaría t^2 (2 * t^2) siendo eso una complejidad O(t^4).
//En el peor de los casos va a entrar a la recursión 8 veces por cada pos que es jugada (o agregada por ser parte del camino libre).


void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    incluirJugadaActual(p, j, t);
    if (t[p.first][p.second] == cVACIA){
        for (int i=0; i<t.size();i++){ //Complejidad t, siendo t el tamaño de filas del tablero.
            for (int k=0;k<t.size();k++){ //Complejidad t, siendo t el tamaño de filas del tablero.
                pos pos1 (i,k);
                //Compledidad
                //fueJugada => j (tamaño del vector jugadas)
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
//Llamemos t a filas/columnas del tablero.
//En el peor de los casos la complejidad es t * t * (t^2 + t^2).
// Complejidad O(t^4)

bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
   bool hay=false;
    for (int i = 0; i <t.size() ; ++i) {  //Complejidad O(t).
        for (int k = 0; k <t.size() ; ++k) {  //Complejidad O(t).
            pos pos1 (i,k);
            if (esPosicionSinJugarYSinBanderita(pos1,j,b,t) && esAdyacenteA121(pos1,j)){
                //esPosi... tiene de complejidad O(t^2) y esAdya.. tiene de complejidad O(j) (que en el peor de los casos j es t^2.
                p=pos1;
                hay=true;
            }
        }

    }
    return hay;
}
