
#include "Metamorfita.h"

Metamorfita::Metamorfita(char s,int v, int x, int y):Criatura(s ,v,x,y) {
    simbolo = 'M';
}

void Metamorfita::movimiento(int ciclos, char (&mapa)[6][6]) {

    if (ciclos % 2 != 0) {
        nx = x;
        ny = y;
        return;
    }

    nx = x;
    ny = y;

    for (int i = 0; i < 4; ++i) {
        int dir = rand() % 4;

        int tx = x;
        int ty = y;

        switch (dir) {
            case 0: tx--; break;
            case 1: tx++; break;
            case 2: ty--; break;
            case 3: ty++; break;
        }


        if (Criatura::dentroDelimites(ty, tx) && mapa[ty][tx] == '_') {

            nx = tx;
            ny = ty;

            return;
        }
    }
}

