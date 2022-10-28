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
    bool result=false;
    for(int i = 0; i<b.size(); i++){
        if ( p == b[i]){
            result=true;
        };
    }
    return result;
}

bool fueJugada(pos p, jugadas& j){
    bool result= false;
    for(int i = 0; i<j.size(); i++){
        if (p == j[i].first){
            result=true;
        } ;
    }
    return result;
}

bool esPosicionSinJugarYSinBanderita(pos p, jugadas& j , banderitas& b, tablero& t){
    if(posicionValida(p,t.size())
    && (!fueJugada(p,j)&& !esBanderita(p,b))){
        return true;
    }else return false;
}

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

//FUNCIONES AUXILIARES USADAS EN EL EJERCICIO 5
void incluirJugadaActual(pos pos1,jugadas & j, tablero& t){
    jugada jugada1 (pos1, minasAdyacentes(t,pos1));
    j.push_back(jugada1);
}

bool esParteDelCaminoLibre(pos partida, pos final, tablero& t) {
    bool result=false;
    if (esAdyacenteValida(partida,final.first, final.second,t)){
        if (minasAdyacentes(t,final)==0){
            result=true;
        }
    }
    return result;
}

bool mismosElementos(jugadas& j, jugadas& control){
    bool result=true;
    if (j.size()==control.size()){
        for (int i=0; i<j.size();i++){
            int aux=0;
            for (int k=0;k<j.size();k++){
                if (j[i]==control[k]){
                    aux++;
                }
            }
            if (aux!=1){
                result=false;
            }
        }
    }
    return result;
}


//FUNCIONES AUXILIARES USADAS EN EL EJERCICI0 6
bool hayPosicionSugerible(jugadas& j, banderitas& b, tablero& t){
    bool result=false;
    for (int i=0;i<t.size();i++){
        for (int k=0; k<t.size(); k++){
            pos p (i,k);
            if (esPosicionSinJugarYSinBanderita(p,j,b,t) && esAdyacenteA121(p,j)){
                result=true;
            }
        }
    }
    return result;
}

bool esAdyacenteA121(pos p, jugadas& j){
    bool result=false;
    pos pos1 (p.first-1,p.second);
    pos pos2 (p.first+1,p.second);
    pos pos3 (p.first,p.second-1);
    pos pos4 (p.first,p.second+1);

    if (es121Horizontal(pos1,j) || es121Horizontal(pos2,j) || es121Vertical(pos3,j) || es121Vertical(pos4,j)){
        result=true;
    }
    return result;
}

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











