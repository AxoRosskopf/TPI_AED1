// Tests para la función sugerir121.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

// ┌───┬───┬───┐
// │ 1 │ 2 │ 1 │
// ├───┼───┼───┤
// │ * │ 2 │ * │
// ├───┼───┼───┤
// │ 1 │ 2 │ 1 │
// └───┴───┴───┘





TEST(sugerir121TEST, sinBanderitas){

    tablero t1 = {
            { cVACIA,  cVACIA,  cVACIA},
            { cMINA, cVACIA, cMINA},
            { cVACIA, cVACIA,  cVACIA}
    };

    pos p = pos(1,1);

    jugadas j1= {
            jugada(pos(0, 0), 1), jugada(pos(0, 1), 2),
            jugada(pos(0, 2), 1)
    };



    banderitas b1 = {};


    EXPECT_TRUE(sugerirAutomatico121(t1,b1,j1,p));
}
TEST(sugerir121TEST,posEnMina){
    tablero t1 = {
            { cVACIA,  cVACIA,  cVACIA},
            { cMINA, cVACIA, cMINA},
            { cVACIA, cVACIA,  cVACIA}
    };

    pos p = pos(0,1);

    jugadas j1= {
            jugada(pos(0, 0), 1), jugada(pos(0, 1), 2),
            jugada(pos(0, 2), 1)
    };



    banderitas b1 = {};


    EXPECT_FALSE(sugerirAutomatico121(t1,b1,j1,p));

}

TEST(sugerir121TEST, banderitaEnMina){
    tablero t1 = {
            { cVACIA,  cVACIA,  cVACIA},
            { cMINA, cVACIA, cMINA},
            { cVACIA, cVACIA,  cVACIA}
    };

    pos p = pos(1,1);

    jugadas j1= {
            jugada(pos(0, 0), 1), jugada(pos(0, 1), 2),
            jugada(pos(0, 2), 1)
    };



    banderitas b1 = {pos(1,1)};


    EXPECT_FALSE(sugerirAutomatico121(t1,b1,j1,p));

}
TEST(sugerir121TEST, sinPatronEnJugadas){
    tablero t1 = {
            { cVACIA,  cVACIA,  cVACIA},
            { cMINA, cVACIA, cMINA},
            { cVACIA, cVACIA,  cVACIA}
    };

    pos p = pos(1,1);

    jugadas j1= {
            jugada(pos(0, 0), 1),
            jugada(pos(0, 2), 1)
    };



    banderitas b1 = {};


    EXPECT_FALSE(sugerirAutomatico121(t1,b1,j1,p));

}

TEST(sugerir121TEST, tableroInvalido){
    tablero t1 = {
            { cVACIA,  cVACIA,  cVACIA},
            { cMINA, cMINA, cMINA},
            { cVACIA, cVACIA,  cVACIA}
    };

    pos p = pos(1,1);

    jugadas j1= {
            jugada(pos(0, 0), 1), jugada(pos(0, 1), 2),
            jugada(pos(0, 2), 1)
    };



    banderitas b1 = {};


    EXPECT_FALSE(sugerirAutomatico121(t1,b1,j1,p));

}