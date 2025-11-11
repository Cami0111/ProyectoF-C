#include "Albo.h"

Albo::Albo(char s, int v, int x, int y): Criatura(s,v,x,y) , Metamorfita(), Centella() {
    simbolo = 'A';
}

char Albo::getSimbolo() const {return simbolo;}

void Albo::movimiento(int ciclos, char (&mapa)[6][6]) {
    if (ciclos%2 == 0 ){}
    Centella::movimiento(ciclos, mapa);
    int px = nx, py = ny;


    if (ciclos % 2 == 0) {
        x = px;
        y = py;
        Metamorfita::movimiento(ciclos, mapa);
    }
}

