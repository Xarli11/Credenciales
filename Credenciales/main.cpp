/*
 * main.cpp
 *
 *  Creado en: 16/01/2021
 *      Autor: Xarli11
 */

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;


/*Estructuras y Constantes Globales*/
const string USUARIO = "Xarli11", CONTRASEÑA = "Carlosgt2001";

typedef struct {
    string usuario;
    string contraseña;
}tCredenciales;
typedef tCredenciales tListaCredenciales[10];

/*Este es el menu de Usuarios y Contraseñas*/
void login();

void menu();
void leer(tListaCredenciales& Credenciales);

int main() {
    login();
    return 0;
}

void login() {
    string nombre;
    string pass;
    tListaCredenciales credenciales;
    int i;
    for (i = 1; i < 4; i++) {
        system("cls");
        cout << endl;
        cout << "        BIENVENIDO AL SISTEMA DE LOGIN " << endl;
        cout << "___________________________________________" << endl;
        cout << endl;
        cout << "Por favor ingrese su informacion de usuario" << endl;
        cout << endl;
        cout << "¿Nombre de usuario?" << endl;
        cin >> nombre;
        if (nombre == USUARIO) {
            cout << "Nombre de usuario correcto, por favor ingrese su contrasena:" << endl;
            cin >> pass;
            if (pass == CONTRASEÑA) {
                cout << endl;
                cout << "Contrasena correcta, bienvenido, sera redirigido a la aplicacion" << endl;
                //menu();
                leer(credenciales);
                system("pause>null");
                exit(0);
            }
            else
                if (pass != CONTRASEÑA) {
                    cout << "Contrasena incorrecta, por favor ingrese un usuario y contrasena valida" << endl;
                    system("pause>null");
                }
        }
        else
            if (nombre != USUARIO) {
                cout << "Nombre de usuario incorrecto, por favor ingrese su nombre de usuario nuevamente" << endl;
                system("pause>null");
            }

        if (i > 0) {
            cout << endl;
            cout << "Ha realizado " << i << "/3 intentos" << endl;
            cout << endl;
            system("pause>null");
        }
        if (i == 3) {
            cout << endl;
            cout << "Ha realizado 3 intentos, por seguridad el programa se cerrara..." << endl;
            system("pause>null");
            exit(0);
        }
    }

}

void menu() {

}
void leer(tListaCredenciales& Credenciales) {

    ifstream file;
    bool fin = false;
    file.open("usuarios.txt");
    if (file.is_open()) {
        do {
            for (int i = 0; i < 10; i++) {
                file >> Credenciales[i].usuario;
                file >> Credenciales[i].contraseña;
            }
            fin = true;
        } while (fin = false);
    }
    else {
        cout << "No se ha podido abrir el archivo para comprobar los usuarios" << endl;
    }

}