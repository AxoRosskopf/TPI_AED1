//
// Este archivo contiene las definiciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con las 
// declaraciones de auxiliares.h
//

#include <iostream>
#include <algorithm>

#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

bool posicionValida(pos p, int n){
    bool result=false;
    if (p.first<n && p.second<n){
        result=true;
    }
    return result;
}

//Complejidad n * n
//Siendo n la cantidad de filas (y columnas) y tablero.
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

//Complejidad 1
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

//Complejidad b, siendo b el tamaño del vector banderitas.
bool esBanderita(pos p, banderitas& b){
    bool result=false;
    for(int i = 0; i<b.size(); i++){
        if ( p == b[i]){
            result=true;
        };
    }
    return result;
}

//Complejidad j, siendo j el tamaño del vector j.
bool fueJugada(pos p, jugadas& j){
    bool result= false;
    for(int i = 0; i<j.size(); i++){
        if (p == j[i].first){
            result=true;
        }
    }
    return result;
}

//Llamemos j a tamaño de vector jugadas, t a cantidad de filas/columnas del tablero y b a tamaño de vector banderitas.
// Esta auxiliar es de complejidad j + b.
// En el peor de los casos la suma de ambas vale t^2
bool esPosicionSinJugarYSinBanderita(pos p, jugadas& j , banderitas& b, tablero& t){
    if(posicionValida(p,t.size())
    && (!fueJugada(p,j)&& !esBanderita(p,b))){ // Complejidad j + b
        return true;
    }else return false;
}
//Complejidad b, siendo b el tamaño del vector banderitas.
void sacaBanderita(pos p,banderitas& b){
    banderitas aux={};
    for (int i=0; i<b.size();i++){
        if (p!=b[i]){
            aux.push_back(b[i]);
        }
    }
    b=aux;
}

void plantaBanderita(pos p,banderitas& b){
    b.push_back(p);
}

bool mismasBanderitas(banderitas& b, banderitas& control){
    bool result = false;
    if (b.size() == control.size()) {
        result = true;
        int contador = 0;
        for (int i = 0; i < b.size(); i++) {
            int aux = 0;
            for (int k = 0; k < b.size(); k++) {
                if (b[i] == control[k]) {
                    aux++;
                }
            }
            if (aux != 1) {
                result = false;
            } else contador++;
            if (contador == b.size()) {
                result = true;
            }
        }
    }
    return result;
}



//FUNCIONES AUXILIARES USADAS EN EL EJERCICIO 5
void incluirJugadaActual(pos pos1,jugadas & j, tablero& t){
    jugada jugada1 (pos1, minasAdyacentes(t,pos1));
    j.push_back(jugada1);
}

bool esAdyacente(pos p1, pos p2){
    if (mismaFila (p1,p2) && columnaAdyacente(p1,p2)) return true;
    else if (filaAdyacente(p1,p2) && mismaColumna(p1,p2)) return true;
    else if (filaAdyacente(p1,p2) && columnaAdyacente(p1,p2)) return true;
    else return false;
}

bool mismaFila(pos p1, pos p2){
    return p1.first==p2.first;
}

bool mismaColumna(pos p1, pos p2){
    return p1.second==p2.second;
}


bool columnaAdyacente(pos p1, pos p2){
    return abs(p1.second-p2.second)==1;
}

bool filaAdyacente(pos p1, pos p2){
    return abs(p1.first-p2.first)==1;
}

//Peor caso, complejidad t * t , siendo t tamaño de filas y columnas del tablero.
bool esParteDelCaminoLibre(pos partida, pos final, tablero& t) {
    bool result=false;
    if (esAdyacente(partida,final)){ // Complejidad 1
        if (minasAdyacentes(t,final)==0){ //Complejidad peor caso t * t
            result=true;
        }
    }
    return result;
}

bool mismasJugadas(jugadas& j, jugadas& control) {
    bool result = false;
    if (j.size() == control.size()) {
        result = true;
        int contador = 0;
        for (int i = 0; i < j.size(); i++) {
            int aux = 0;
            for (int k = 0; k < j.size(); k++) {
                if (j[i] == control[k]) {
                    aux++;
                }
            }
            if (aux != 1) {
                result = false;
            } else contador++;
            if (contador == j.size()) {
                result = true;
            }
        }
    }
    return result;
}

//FUNCIONES AUXILIARES USADAS EN EL EJERCICI0 6

//Tiene de complejidad 4j, que es lo mismo que O(j).
bool esAdyacenteA121(pos p, jugadas& j){
    bool result=false;
    pos pos1 (p.first-1,p.second);
    pos pos2 (p.first+1,p.second);
    pos pos3 (p.first,p.second-1);
    pos pos4 (p.first,p.second+1);
    if (es121Horizontal(pos1,j) || es121Horizontal(pos2,j) || es121Vertical(pos3,j) || es121Vertical(pos4,j)){ //Complejidad j + j + j + j
        result=true;
    }
    return result;
}

//Complejidad O(j), siendo j el tamaño del vector jugadas.
bool es121Horizontal(pos p, jugadas& j){
    bool result= false;
    int aux=0;
    for (int i=0;i<j.size();i++){
        if ((j[i].first.first==p.first && j[i].first.second==p.second-1 && j[i].second==1) ||
            (j[i].first.first==p.first && j[i].first.second==p.second && j[i].second==2) ||
            (j[i].first.first==p.first && j[i].first.second==p.second+1 && j[i].second==1)){
                aux++;
        }
    }
    if (aux==3){
        result=true;
    }
    return result;
}

//Complejidad O(j), siendo j el tamaño del vector jugadas.
bool es121Vertical(pos p, jugadas& j){
    bool result= false;
    int aux=0;
    for (int i=0;i<j.size();i++){
        if ((j[i].first.first==p.first-1 && j[i].first.second==p.second && j[i].second==1) ||
            (j[i].first.first==p.first && j[i].first.second==p.second && j[i].second==2) ||
            (j[i].first.first==p.first+1 && j[i].first.second==p.second && j[i].second==1)){
            aux++;
        }
    }
    if (aux==3){
        result=true;
    }
    return result;
}









