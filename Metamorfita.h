#ifndef PROY_METAMORFITAS_H
#define PROY_METAMORFITAS_H
#include "Criatura.h"
#include <iostream>
using namespace std;
class Metamorfita : public virtual Criatura {
    public:
    Metamorfita() = default;
    Metamorfita(char s, int v , int x, int y);
    char getSimbolo()const override;

    void movimiento(int ciclos, char (&mapa)[6][6]) override;

};


#endif //PROY_METAMORFITAS_H