#include "Raiz.h"

Raiz::Raiz(char s, int v, int x, int y):Criatura(s,v,x,y) {
    simbolo = 'R';
}

void Raiz::movimiento(int ciclos,  char (&mapa)[6][6]) {
    nx = x;
    ny = y;
    recibirDaño(5);
}
