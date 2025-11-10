#include "Criatura.h"
Criatura::Criatura(char simbolo, int vida, int x, int y): simbolo(simbolo), vida(vida), x(x), y(y), nx(x), ny(y) {
}

void Criatura::movimiento(int ciclos, char(&mapa)[6][6]) {
}
bool Criatura::dentroDelimites(int y, int x) {
    return x >= 0 && x < 6 && y >= 0 && y < 6 ;
}

char Criatura::getSimbolo() const {
}

void Criatura::aumentarVida(int v) { vida += v; }

void Criatura::recibirDaño(int v) { vida -= v; }

Criatura::~Criatura() {
}

int Criatura::getNx() {return nx;}

int Criatura::getNy() {return ny;}

void Criatura::setNx(int x) {
    nx = x;
}

void Criatura::setNy(int y) {
    ny = y;
}

int Criatura::getX() {return x;}

int Criatura::getY() {return y;}

void Criatura::setX(int nx) {
    x = nx;
}

void Criatura::setY(int ny) {
    y = ny;
}


