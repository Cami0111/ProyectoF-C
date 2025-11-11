#include "Albo.h"

Albo::Albo(char s, int v, int x, int y): Criatura(s,v,x,y) , Metamorfita(), Centella() {
    simbolo = 'A';
}

void Albo::movimiento(int ciclos, char (&mapa)[6][6]) {
    if (ciclos%2 == 0 ){}
    Centella::movimiento(ciclos, mapa);


    if (ciclos % 2 == 0) {
        nx = x;
        ny = y;
        Metamorfita::movimiento(ciclos, mapa);
    }
}

