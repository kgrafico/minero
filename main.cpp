#include "minero.h"
#include "juego.h"

int showMenu() {
    char chooseOption = 0x00;
    
    while (chooseOption < '0' || chooseOption > '2') {
        cout << "1. Jugar partida escala 1:1" << endl;
        cout << "2. Jugar partida escala 1:3" << endl;
        cout << "0. Salir" << endl;
        
        cout << "Elija opción: ";
        cin >> chooseOption;
    }
    
    return chooseOption-0x30;
}

int showTeclado() {
    char chooseOption = 0x00;
    
    while (chooseOption < '0' || chooseOption > '2') {
        cout << "1. Introducir movimientos por teclado" << endl;
        cout << "2. Introducir movimientos por fichero" << endl;
        cout << "0. Salir" << endl;
        
        cout << "Elija opción: ";
        cin >> chooseOption;
    }
    
    return chooseOption-0x30;
}

int showSiguienteNivel() {
    char chooseOption = '0';
    
    while (chooseOption < '0' || chooseOption > '1') {
        cout << "1. Jugar siguiente nivel" << endl;
        cout << "0. Salir" << endl;
        
        cout << "Elija opción: ";
        cin >> chooseOption;
    }
    
    return chooseOption-0x30;
}


int main(int argc, const char * argv[]) {
    ifstream archivo;
    char planoCaracteres[3*MAX][3*MAX];
    int planoColores[3*MAX][3*MAX];
    tJuego juego ;
    short nivel = 1;
    short option = 0;
    bool escala = false;


    option = showMenu();

    archivo.open(archivosNiveles[nivel-1], ios::in);
    if (!archivo.is_open()) {
        cout << "¡No se ha podido abrir el archivo " << archivosNiveles[nivel-1] << "!" << endl;
        return false;
    }

    switch(option) {
        case 1:
            escala = false; 
            break;

        case 2:
            escala = true; 
            break;

        case 3:
            cout << "Hasta luego" << endl;
            return 0;
            break;

        default:
            break;
    }

    cargar_Mina(juego, nivel);
    pintaMina(juego.mina);

    return 0;
}