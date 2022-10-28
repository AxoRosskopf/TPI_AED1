// Tests para la función cambiarBanderita.
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
tablero t1 = {
        { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
        { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};

jugadas jugadas1= {
        jugada(pos(0, 2), 2), jugada(pos(0, 4), 1),
        jugada(pos(1, 0), 3), jugada(pos(1, 1), 3), jugada(pos(1, 2), 3)};


TEST(cambiarBanderitaTEST, esBanderita) {
    banderitas b = {pos(0, 0), pos (2,1)};
    pos pos1(0, 0);
    cambiarBanderita(t1,jugadas1,pos1,b);
    banderitas c = {pos (2,1)};
    EXPECT_EQ(b,c);
}

TEST(cambiarBanderitaTEST, noEsBanderita) {
    banderitas b = {pos(0, 0), pos (2,1)};
    pos pos1(1, 3);
    cambiarBanderita(t1,jugadas1,pos1,b);
    banderitas c = {pos(0, 0), pos (2,1), pos(1,3)};
    EXPECT_EQ(b,c);
}