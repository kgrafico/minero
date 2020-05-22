#ifndef MINERO_H
#define MINERO_H

#define MAX 50

typedef enum {
    LIBRE, TIERRA, GEMA, PIEDRA, MURO, SALIDA, MINERO, DINAMITA
} tCasilla;

typedef tCasilla tPlano[MAX][MAX];

typedef struct {
    tPlano plano;
    short nfilas;
    short ncolumnas;
    short fila;
    short columna;
} tMina;

void cargar_Mina(ifstream& fichero, tMina& mina);
void dibujar1_1(const tMina& mina);
void dibujar1_3(const tMina& mina);
void dibuja3x3(tCasilla casilla, tPlanoCaracteres caracteres, tPlanoColores colores, int i, int j);

#endif // MINERO_H
