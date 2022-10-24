//
// Este archivo contiene las definiciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con las 
// declaraciones de auxiliares.h
//

#include <iostream>

#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

bool tableroValido(tablero& tablero){
    if (tamanioDeTableroValido(tablero) & cantidadDeMinasValida(tablero)){
        return true;
    }else return false;
}

bool tamanioDeTableroValido(tablero& tablero){
    if (tablero.size()>0){
        bool tamanioDeFila=true;
        int i=0;
        while (i<tablero.size() && tamanioDeFila== true){
            if (tablero.size() != tablero[i].size()){
                tamanioDeFila= false;
            }
            i++;
        }

    }
}

bool cantidadDeMinasValida(tablero& tablero){
    int cantidadDeMinas=0;
    for (int i=0; i<tablero.size(); i++){
        for (int j=0;j<tablero[i].size(),j++){
            if (tablero[i][j]== true){
                cantidadDeMinas++;
            }
        }
    }
    if (cantidadDeMinas<(tablero.size()*tablero.size())){
        return true;
    }else return false;
}
