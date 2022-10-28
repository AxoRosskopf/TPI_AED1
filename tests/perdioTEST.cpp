// Tests para la función perdio.
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



jugadas jugadasValidasConMina = {
        jugada(pos(0, 2), 2), jugada(pos(0, 4), 1),
        jugada(pos(1, 0), 3), jugada(pos(1, 1), 3), jugada(pos(1, 2), 3), jugada(pos(1, 3), 1),
};

jugadas jugadasValidasSinMina = {
        jugada(pos(0, 2), 2), jugada(pos(0, 4), 1),
        jugada(pos(1, 0), 3), jugada(pos(1, 1), 3), jugada(pos(1, 2), 3)};

jugadas jugadasVacias={};

TEST(perdioTEST, sinMina) {
    tablero t = {
            {cMINA,  cMINA,  cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cMINA,  cVACIA},
            {cVACIA, cMINA,  cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cMINA,  cVACIA, cMINA,  cVACIA, cVACIA},
    };
    EXPECT_FALSE(perdio(t, jugadasValidasSinMina));
}
TEST(perdioTEST, conMina){
    tablero t = {
            { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
    };
    EXPECT_TRUE(perdio(t,jugadasValidasConMina));
}

TEST(perdioTEST, jugadasVacias){
    tablero t = {
            { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
    };
    EXPECT_FALSE(perdio(t,jugadasVacias));
}

