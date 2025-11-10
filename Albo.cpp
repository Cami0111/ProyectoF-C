#include "Albo.h"

Albo::Albo(char s, int v, int x, int y): Criatura(s,v,x,y) , Metamorfita(), Centella() {
    simbolo = 'A';
}

char Albo::getSimbolo() const {return simbolo;}

void Albo::movimiento(int ciclos, char (&mapa)[6][6]) {
        Metamorfita::movimiento(ciclos, mapa);
        Centella::movimiento(ciclos, mapa);

    }



