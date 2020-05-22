#ifndef MINERO_H
#define MINERO_H

#define MAX 50
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

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
