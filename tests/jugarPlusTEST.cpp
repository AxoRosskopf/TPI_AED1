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
jugadas jugadasJugarPlus = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
        jugada(pos(1, 2), 3),jugada(pos(1, 4), 1),
        jugada(pos(2, 0), 1),jugada(pos(2, 2), 2),jugada(pos(2, 3), 1),
        jugada(pos(3, 0), 2),jugada(pos(3, 3), 1),
        jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),
};
jugadas jugadasJugarPlus1 = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
        jugada(pos(1, 2), 3),jugada(pos(1, 4), 1),
        jugada(pos(2, 0), 1),jugada(pos(2, 2), 2),jugada(pos(2, 3), 1),
        jugada(pos(3, 0), 2),jugada(pos(3, 3), 1),
        jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),
};
banderitas banderitasJugar={pos(2,1)};

TEST(jugarPlusTEST, hayMina){
    pos pos1 (0,1);
    jugadas aux=jugadasJugarPlus;
    aux.push_back(jugada(pos(0,1),1));
    jugarPlus(tJugar,banderitasJugar,pos1,jugadasJugarPlus);
    EXPECT_TRUE(mismasJugadas(jugadasJugarPlus, aux));
}
TEST(jugarPlusTEST, hayAdyacentes){
    pos pos1 (0,3);
    jugadas aux=jugadasJugarPlus;
    aux.push_back(jugada(pos(0,3),1));
    jugarPlus(tJugar,banderitasJugar,pos1,jugadasJugarPlus );
    EXPECT_TRUE(mismasJugadas(jugadasJugarPlus,aux));
}


TEST(jugarPlusTEST, unSoloAnilloDeLibres){
    pos pos1(3,4);
    jugadas aux=jugadasJugarPlus;
    aux.push_back(jugada(pos(3,4),0));
    aux.push_back(jugada(pos(4,4),0));
    jugarPlus(tJugar,banderitasJugar,pos1,jugadasJugarPlus);
    EXPECT_TRUE(mismasJugadas(jugadasJugarPlus, aux));
}

TEST(jugarPlusTEST, dosAnilloDeLibres){
    pos pos1(2,4);
    jugadas aux=jugadasJugarPlus1;
    aux.push_back(jugada(pos(2,4),1));
    aux.push_back(jugada(pos(3,4),0));
    aux.push_back(jugada(pos(4,4),0));
    jugarPlus(tJugar,banderitasJugar,pos1,jugadasJugarPlus1);
    EXPECT_TRUE(mismasJugadas(jugadasJugarPlus1, aux));
}



