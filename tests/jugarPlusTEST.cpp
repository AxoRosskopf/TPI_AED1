// Tests para la función jugarPlus.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;
// ┌───┬───┬───┬───┬───┐
// │ * │ * │ 2 │ 1 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 3 │ 3 │ 3 │ * │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 1 │ * │ 2 │ 1 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 2 │ 3 │ 2 │ 1 │ 0 │
// ├───┼───┼───┼───┼───┤
// │ * │ 2 │ * │ 1 │ 0 │
// └───┴───┴───┴───┴───┘

tablero tJugar = {
        { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
        { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};
jugadas aunNoGano = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
        jugada(pos(1, 2), 3),jugada(pos(1, 4), 1),
        jugada(pos(2, 0), 1),jugada(pos(2, 2), 2),jugada(pos(2, 3), 1),jugada(pos(2, 4), 1),
        jugada(pos(3, 0), 2),jugada(pos(3, 3), 1),jugada(pos(3, 4), 0),
        jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
};
jugadas aunNoGano2 = {
        jugada(pos(0, 2), 2),};

jugadas controlHayMina = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
        jugada(pos(1, 2), 3),jugada(pos(1, 4), 1),
        jugada(pos(2, 0), 1),jugada(pos(2, 2), 2),jugada(pos(2, 3), 1),jugada(pos(2, 4), 1),
        jugada(pos(3, 0), 2),jugada(pos(3, 3), 1),jugada(pos(3, 4), 0),
        jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0), jugada(pos(0,1),1),
};

jugadas controlHayAdyacente = {
        jugada(pos(0, 2), 2), jugada (pos (0, 3), 1)};

banderitas banderitasJugar={pos(4,4), pos(2,1)};

TEST(jugarPlusTEST, hayMina){
    pos pos1 (0,1);
    jugarPlus(tJugar,banderitasJugar,pos1,aunNoGano );
    EXPECT_TRUE(mismasJugadas(aunNoGano, controlHayMina));
}

TEST(jugarPlusTEST, hayAdyacentes){
    pos pos1 (0,3);
    jugarPlus(tJugar,banderitasJugar,pos1,aunNoGano2 );
    EXPECT_TRUE(mismasJugadas(aunNoGano2,controlHayAdyacente));
}


TEST(jugarPlusTEST, unSoloAnilloDeLibres){}
TEST(jugarPlusTEST, dosAnilloDeLibres){}