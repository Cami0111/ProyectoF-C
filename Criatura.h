//
// Created by Maria-Camila on 3/11/2025.
//

#ifndef PROY_CRIATURA_H
#define PROY_CRIATURA_H
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

class Criatura {
protected:
    char simbolo;
    int vida,x,y,nx,ny;
public:
    Criatura() = default;
    Criatura(char simbolo, int vida, int x, int y);
    virtual ~Criatura();
    virtual void movimiento(int ciclos, char(&mapa)[6][6]);
    virtual bool dentroDelimites(int y,int x);
    char getSimbolo() const;
    int getVida(){return vida;}
    void aumentarVida(int v);

    void recibirDaño(int v);



    int getNx();
    int getNy();

    void setNx(int x);
    void setNy(int y);

    int getX();
    int getY();

    void setX(int nx);
    void setY(int ny);


};




#endif //PROY_CRIATURA_H