#ifndef JUEGO_H
#define JUEGO_H

#include "minero.h"

typedef struct {
    tMina mina;
    short gemas;
    short movimientos;
    short tnt;
} tJuego;

typedef enum {
     ARRIBA, ABAJO, DCHA, IZDA, SALIR, NADA, TNT
} tTecla;

bool cargar_Juego(tJuego& juego, int nivel);
bool hacerMovimiento(tJuego& juego, tTecla tecla);
void dibujar(const tJuego& juego);

#endif // JUEGO_H