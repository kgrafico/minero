#include <time.h>
#include <cstdlib>
#include <list>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int MAX = 50;

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

typedef struct {
    tMina mina;
    short gemas;
    short movimientos;
    short tnt;
} tJuego;

typedef enum {
     ARRIBA, ABAJO, DCHA, IZDA, SALIR, NADA, TNT
} tTecla;

const string archivosNiveles[] = {"1.txt", "2.txt", "3.txt", "4.txt"};
char planoCaracteres[3*MAX][3*MAX];
int planoColores[3*MAX][3*MAX];


tCasilla rellenaCasilla(char c) {
    switch(c) {
        case ' ':
            return LIBRE;
            break;

        case 'T':
            return TIERRA;
            break;

        case 'G':
            return GEMA;
            break;
        
        case 'P':
            return PIEDRA;
            break;
        
        case 'M':
            return MURO;
            break;
        
        case 'S':
            return SALIDA;
            break;
        
        case 'J':
            return MINERO;
            break;
        
        default:
        exit(-1);
        break;
    }
}


char pintaCaracteres(tCasilla c) {
    switch(c) {
        case LIBRE:
            return ' ';
            break;

        case TIERRA:
            return '.';
            break;

        case GEMA:
            return 'G';
            break;
        
        case PIEDRA:
            return '@';
            break;
        
        case MURO:
            return 'X';
            break;
        
        case SALIDA:
            return 'S';
            break;
        
        case MINERO:
            return 'M';
            break;
        
        default:
        exit(-1);
        break;
    }
}

bool readGame(tJuego& juego, short nivel) {
    ifstream archivo;
    string fila;

    archivo.open(archivosNiveles[nivel-1], ios::in);
    if (!archivo.is_open()) {
        cout << "¡No se ha podido abrir el archivo "<< archivosNiveles[nivel-1] <<"!" << endl;
        return false;
    }

    archivo >> juego.mina.nfilas >> juego.mina.ncolumnas;
    getline(archivo, fila);

    if (juego.mina.nfilas > MAX) {
        cout << "Filas leidas (" << juego.mina.nfilas << ") mayor que maximo (" << MAX << ")" << endl;
        return false;
    }

    if (juego.mina.ncolumnas > MAX) {
        cout << "Columnas leidas (" << juego.mina.ncolumnas << ") mayor que maximo (" << MAX << ")" << endl;
        return false;
    }

    for (int i = 0; i < juego.mina.nfilas; i++) {
        getline(archivo, fila);
        for (int j = 0; j < juego.mina.ncolumnas; j++) {
            juego.mina.plano[i][j] = rellenaCasilla(fila[j]);
        }
    }

    archivo.close();
    return true;
}

void pintaMina(tMina& mina) {
    for(int i = 0; i < mina.nfilas; i++ ) {
        for(int j = 0; j < mina.ncolumnas; j++) {
            cout << pintaCaracteres(mina.plano[i][j]);
        }
        cout << endl;
    }
}

// void colorFondo(int color) {
//  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//  SetConsoleTextAttribute(handle, 15 | (color << 4));
// }


// void writeGame(tPlay play) {
//     ofstream file;
//     file.open("domino_save.txt", ios::out);

//     if (file.is_open()) {
//     file << play.numbersPlayers << " " << play.maxNumber <<endl
// 		<< board << endl
//         << play.pool.cont << endl;
// 		writeListToken(file, play.pool);
// 		for (int i = 0; i < play.numbersPlayers; i++) {
// 			file << play.players[i].cont << endl;
// 			writeListToken(file, play.players[i]);
// 			file << play.points[i] << endl;
// 		}

//         file.close();

//     } else {
//         cout << "¡No se ha podido abrir el archivo!" << endl;
//     }
// }


int main(int argc, const char * argv[]) {
    tJuego juego;
    short nivel = 1;

    readGame(juego, nivel);
    pintaMina(juego.mina);

    return 0;
}



