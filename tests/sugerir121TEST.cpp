// Tests para la función sugerir121.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

// ┌───┬───┬───┬───┬
// │ 0 │ 1 │ * │ 1 │
// ├───┼───┼───┤───┤
// │ 0 │ 2 │ 2 │ 2 │
// ├───┼───┼───┼───┤
// │ 0 │ 1 │ * │ 1 │
// ├───┼───┼───┼───┤
// │ 0 │ 1 │ 1 │ 1 │
// └───┴───┴───┴───┘




TEST(sugerir121TEST, hayVertical){
    tablero t1 = {
            { cVACIA,  cVACIA,  cMINA, cVACIA},
            { cVACIA, cVACIA, cVACIA, cVACIA},
            { cVACIA,  cVACIA,  cMINA, cVACIA},
            { cVACIA, cVACIA,  cVACIA, cVACIA}
    };
    pos p = pos(-1,-1);
    jugadas j1= {
            jugada(pos(0, 1), 1), jugada(pos(1, 1), 2),
            jugada(pos(2, 1), 1), jugada (pos (3,3),1)
    };
    banderitas b1 = {pos(1,2)};
    bool hay= sugerirAutomatico121(t1, b1,j1,p);
    EXPECT_TRUE(hay);
    EXPECT_TRUE(p== pos (1,0));
}
TEST(sugerir121TEST,hayHorizontal){

// ┌───┬───┬───┬───┬
// │ 1 │ * │ 2 │ * │
// ├───┼───┼───┤───┤
// │ 1 │ 1 │ 2 │ 1 │
// ├───┼───┼───┼───┤
// │ 1 │ 1 │ 0 │ 0 │
// ├───┼───┼───┼───┤
// │ * │ 1 │ 0 │ 0 │
// └───┴───┴───┴───┘
    tablero t1 = {
            { cVACIA,  cMINA,  cVACIA, cMINA},
            { cVACIA, cVACIA, cVACIA, cVACIA},
            { cVACIA,  cVACIA,  cVACIA, cVACIA},
            { cMINA, cVACIA,  cVACIA, cVACIA}
    };

    pos p = pos(-1,-1);

    jugadas j1= {
            jugada(pos(1, 1), 1), jugada(pos(1, 2), 2),
            jugada(pos(1, 3), 1), jugada(pos(2, 0), 1),
            jugada(pos(2, 1), 1),jugada(pos(2, 2), 0),
            jugada(pos(2, 3), 0)
    };
    banderitas b1 = {pos(0,1), pos(0,3), pos(3,0)};
    bool hay= sugerirAutomatico121(t1, b1,j1,p);
    EXPECT_TRUE(hay);
    EXPECT_TRUE(p== pos (0,2));
}

TEST(sugerir121TEST, noHayPatronDescubierto){

// ┌───┬───┬───┬───┬
// │ 1 │ * │ 2 │ * │
// ├───┼───┼───┤───┤
// │ 1 │ 1 │ 2 │ 1 │
// ├───┼───┼───┼───┤
// │ 1 │ 1 │ 0 │ 0 │
// ├───┼───┼───┼───┤
// │ * │ 1 │ 0 │ 0 │
// └───┴───┴───┴───┘
    tablero t1 = {
            { cVACIA,  cMINA,  cVACIA, cMINA},
            { cVACIA, cVACIA, cVACIA, cVACIA},
            { cVACIA,  cVACIA,  cVACIA, cVACIA},
            { cMINA, cVACIA,  cVACIA, cVACIA}
    };

    pos p = pos(-1,-1);

    jugadas j1= {
             jugada(pos(1, 2), 2),
            jugada(pos(1, 3), 1), jugada(pos(2, 0), 1),
            jugada(pos(2, 1), 1),jugada(pos(2, 2), 0),
            jugada(pos(2, 3), 0)
    };
    banderitas b1 = {pos(0,1), pos(0,3), pos(3,0)};
    bool hay= sugerirAutomatico121(t1, b1,j1,p);
    EXPECT_FALSE(hay);
}
TEST(sugerir121TEST, casillaDePatronMarcadaConBanderita){

// ┌───┬───┬───┬───┬
// │ 1 │ * │ 2 │ * │
// ├───┼───┼───┤───┤
// │ 1 │ 1 │ 2 │ 1 │
// ├───┼───┼───┼───┤
// │ 1 │ 1 │ 0 │ 0 │
// ├───┼───┼───┼───┤
// │ * │ 1 │ 0 │ 0 │
// └───┴───┴───┴───┘
    tablero t1 = {
            { cVACIA,  cMINA,  cVACIA, cMINA},
            { cVACIA, cVACIA, cVACIA, cVACIA},
            { cVACIA,  cVACIA,  cVACIA, cVACIA},
            { cMINA, cVACIA,  cVACIA, cVACIA}
    };

    pos p = pos(-1,-1);

    jugadas j1= {
            jugada(pos(1, 2), 2),
            jugada(pos(1, 3), 1), jugada(pos(2, 0), 1),
            jugada(pos(2, 1), 1),jugada(pos(2, 2), 0),
            jugada(pos(2, 3), 0)
    };
    banderitas b1 = {pos(1,1)};
    bool hay= sugerirAutomatico121(t1, b1,j1,p);
    EXPECT_FALSE(hay);

}

TEST(sugerir121TEST, noHayPatronEnTablero){

// ┌───┬───┬───┬───┬
// │ 1 │ * │ 2 │ 1 │
// ├───┼───┼───┤───┤
// │ 1 │ 1 │ 2 │ * │
// ├───┼───┼───┼───┤
// │ 1 │ 1 │ 1 │ 1 │
// ├───┼───┼───┼───┤
// │ * │ 1 │ 0 │ 0 │
// └───┴───┴───┴───┘
    tablero t1 = {
            { cVACIA,  cMINA,  cVACIA, cVACIA},
            { cVACIA, cVACIA, cVACIA, cMINA},
            { cVACIA,  cVACIA,  cVACIA, cVACIA},
            { cMINA, cVACIA,  cVACIA, cVACIA}
    };

    pos p = pos(-1,-1);

    jugadas j1= {
            jugada(pos(0, 0), 1), jugada(pos(0, 2), 2),
            jugada(pos(1, 0), 1), jugada(pos(1, 1), 1), jugada(pos(1, 2), 2),
            jugada(pos(2, 1), 1),jugada(pos(2, 2), 1),
            jugada(pos(2, 3), 1)
    };
    banderitas b1 = {pos(0,1), pos(0,3), pos(3,0)};
    bool hay= sugerirAutomatico121(t1, b1,j1,p);
    EXPECT_FALSE(hay);
}


