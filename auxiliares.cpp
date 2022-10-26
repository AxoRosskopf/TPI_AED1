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


// FUNCIONES AUXILIARES USADAS EN EL EJERCICIO 1

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
        for (int j=0;j<tablero[i].size();j++){
            if (tablero[i][j]== true){
                cantidadDeMinas++;
            }
        }
    }
    if (cantidadDeMinas<(tablero.size()*tablero.size())){
        return true;
    }else return false;
}

bool posicionValida(pos p, int n){
    bool result=false;
    if (p.first<n && p.second<n){
        result=true;
    }
    return result;
}

int numMinasAdyacentes(tablero& t, pos p){
    int result=0;
    for (int i=-1; i<=1;i++){
        for (int j=-1;j<=1;j++){
            if (esAdyacenteValida(p,i,j,t) && t[p.first+i][p.second+j]==true){
                result++;
            }
        }
    }
    return result;
}

bool esAdyacenteValida(pos p, int i, int j, tablero& t){
    if (p.first+i<t.size() && p.second+j<t.size() && (i!=0 || j!=0)){
        return true;
    }else return false;
}


// FUNCIONES AUXILIARES USADAS EN EL EJERCICI0 2

bool hayMinaEnPosicion(pos p, tablero& t){
    if (t[p.first][p.second] == cMINA){
        return true;
    }else return false;
}

int minasPisadas(jugadas& j ,tablero& t){
    int minas = 0;
    for(int i = 0; i<j.size(); i++){
        if (hayMinaEnPosicion(j[i].first, t)){
            minas++;
        }
    }
    return minas;
}

bool jugadasValidas(jugadas& j , tablero& t){
    for (int i =0; i<j.size();i++){
        if ( posicionValida(j[i].first,t.size())
        && (numMinasAdyacentes(t,j[i].first) == j[i].second)){
            return true;
        } else return false;
    }
}

bool juegoValido(tablero& t,jugadas& j){
    if (tableroValido(t)&& jugadasValidas(j,t)
    && (minasPisadas(j,t) <= 1)){
        return true;
    } else return false;
}

bool jugadasNoRepetidas (jugadas& j){
 for(int i=0 ; i < j.size();i++){
     for (int k = 0 ; k < j.size(); k++){
        if(j[i].first != j[k].first && (i != k)){
            return true;
        } else return false;
     }
 }
}

bool esBanderita(pos p, banderitas& b){
    for(int i = 0; i<b.size(); i++){
        if ( p == b[i]){
            return true;
        }else return false;
    }
}

bool fueJugada(pos p, jugadas& j){
    for(int i = 0; i<j.size(); i++){
        if (p == j[i].first){
            return true;
        } else return false;
    }
}

bool esPosicionSinJugarYSinBanderita(pos p, jugadas& j , banderitas& b, tablero& t){
    if(posicionValida(p,t.size())
    && (!fueJugada(p,j)&& !esBanderita(p,b))){
        return true;
    }else return false;
}




















