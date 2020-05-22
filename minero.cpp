#include <time.h>
#include <cstdlib>
#include <list>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "juego.h"
#include "minero.h"

using namespace std;

const string archivosNiveles[] = {"1.txt", "2.txt", "3.txt", "4.txt"};


bool cargar_Mina(ifstream& archivo, tMina& mina) {
    string fila;

    archivo >> mina.nfilas >> mina.ncolumnas;
    getline(archivo, fila);

    if (mina.nfilas > MAX) {
        cout << "Filas leidas (" << mina.nfilas << ") mayor que maximo (" << MAX << ")" << endl;
        return false;
    }

    if (mina.ncolumnas > MAX) {
        cout << "Columnas leidas (" << mina.ncolumnas << ") mayor que maximo (" << MAX << ")" << endl;
        return false;
    }

    for (int i = 0; i < mina.nfilas; i++) {
        getline(archivo, fila);
        for (int j = 0; j < mina.ncolumnas; j++) {
            mina.plano[i][j] = rellenaCasilla(fila[j]);
        }
    }

    archivo.close();
    return true;
}


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

void dibujar1_1(const tMina& mina) {
    system("cls");

    for(int i = 0; i < mina.nfilas; i++ ) {
        for(int j = 0; j < mina.ncolumnas; j++) {
            cout << pintaCaracteres(mina.plano[i][j]);
        }
        cout << endl;
    }
}

void dibujar1_3(const tMina& mina){
    system("cls");

}

void dibuja3x3(tCasilla casilla, tPlanoCaracteres caracteres, tPlanoColores colores, int i, int j){
    system("cls"); 

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

tTecla leerTecla() {
    int dir;

    cin.sync();
    dir =_getch();

    if (dir == 0xe0) {
        dir = _getch();
    }

    switch(dir) {
        case 27:
            return SALIR;
            break;

        case 77:
            return DERECHA;
            break;
        
        case 72:
            return ARRIBA;
            break;

        case 80:
            return ABAJO;
            break;

        case 75:
            return IZQUIERDA;
            break;
        
        case 'D':
            return TNT;
            break;

        default:
            return NADA;
            break;
    }
}




