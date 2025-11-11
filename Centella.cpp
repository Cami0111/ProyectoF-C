#include "Centella.h"

Centella::Centella(char s, int v, int x, int y): Criatura(s, v, x, y){
}

char Centella::getSimbolo() const {
    return simbolo;}
void Centella::movimiento(int ciclos, char (&mapa)[6][6]) {
    int accion = rand() % 2 + 1;
    nx = x;
    ny = y;
    if (accion == 1){
        for (int salto = 0; salto < 2; ++salto) {

            bool movido_exitosamente_en_salto = false;

            for (int intento = 0; intento < 4; ++intento) {

                int dir = rand() % 4;

                int tx = nx;
                int ty = ny;

                switch (dir) {
                    case 0: tx--; break;
                    case 1: tx++; break;
                    case 2: ty--; break;
                    case 3: ty++; break;
                }

                if (Criatura::dentroDelimites(ty, tx) && mapa[ty][tx] == '_') {

                    nx = tx;
                    ny = ty;
                    movido_exitosamente_en_salto = true;
                    break;
                }
            }

            if (!movido_exitosamente_en_salto) {
                break;
            }
        }
    }else if (accion == 2) {
        int limites[][2]= {
            {0,0},{0,1},{0,2},{0,3},{0,4},{0,5},
    {1,0},{1,5},
    {2,0},{2,5},
    {3,0},{3,5},
    {4,0},{4,5},
    {5,0},{5,1},{5,2},{5,3},{5,4},{5,5}
        };
        int n = sizeof(limites)/sizeof(limites[0]);
        int libres[20][2];
        int k = 0;
        for (int i = 0; i < n; ++i) {
            int ty = limites[i][0];
            int tx = limites[i][1];
            if (mapa[ty][tx] == '_') {
                libres[k][0] = tx;
                libres[k][1] = ty;
                k++;
            }
        }
        if (k > 0) {
            int idx = rand() % k;
            ny = libres[idx][0];
            nx = libres[idx][1];
        }
        cout << simbolo << " volo hasta: ( " << ny<< " , "<< nx <<" ) "<<endl;

    }
}