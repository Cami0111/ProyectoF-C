#include "Criatura.h"
#ifndef PROY_RAIZ_H
#define PROY_RAIZ_H


class Raiz : public Criatura {
    public:
    Raiz() = default;
    Raiz(char s,int v, int x, int y);

    void movimiento(int ciclos,  char (&mapa)[6][6]) override;
};


#endif //PROY_RAIZ_H