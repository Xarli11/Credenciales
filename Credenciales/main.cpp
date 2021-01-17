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

typedef struct {
    string usuario;
    string contraseña;
}tCredenciales;
typedef tCredenciales tListaCredenciales[10];

/*Este es el menu de Usuarios y Contraseñas*/
void login();

void menu();
void leer(tListaCredenciales& Credenciales);
bool comprobar(string usuario, tListaCredenciales &Credendiales, int contador);

int main() {
    system("color 0A");
    login();
    return 0;
}

void login() {
    string nombre;
    tListaCredenciales credenciales;
    leer(credenciales);
    int i;
    for (i= 1; i < 4; i++) {
        system("cls");
        cout << endl;
        cout << "        BIENVENIDO AL SISTEMA DE LOGIN " << endl;
        cout << "___________________________________________" << endl;
        cout << endl;
        cout << "Por favor ingrese su informacion de usuario" << endl;
        cout << endl;
        cout << "¿Nombre de usuario?" << endl;
        cin >> nombre;
        if (comprobar(nombre, credenciales,i) == true) {
            cout << "Contrasena correcta, bienvenido, sera redirigido a la aplicacion" << endl;
        }
        else {
            cout << "Contrasena incorrecta, sera expulsado de la aplicacion" << endl;
        }
    }
}

void menu() {

}
void leer(tListaCredenciales& Credenciales) {

    ifstream fileUsers, filePasswords;
    bool fin = false;
    fileUsers.open("usuarios.txt");    
    filePasswords.open("contraseñas.txt");
    if (fileUsers.is_open() && filePasswords.is_open()) {
        do {
            for (int i = 0; i < 10; i++) {
                fileUsers >> Credenciales[i].usuario;
                filePasswords >> Credenciales[i].contraseña;
            }
            fin = true;
        } while (fin = false);
    }
    else {
        cout << "No se ha podido abrir el archivo para comprobar los usuarios" << endl;
    }

}
bool comprobar(string usuario, tListaCredenciales& Credenciales, int contador) {
        string pass;
        int numUsuario;
        bool encontradoUsuario = false, encontradoContraseña = false;
        int j,k;
        do {
            for (j = 0; j < 10; j++) {
                if (Credenciales[j].usuario == usuario) {
                    encontradoUsuario = true;
                    numUsuario = j;
                }
            }
            }while (encontradoUsuario == false && j < 10);
        if (encontradoUsuario == true) {
            cout << "Nombre de usuario correcto, por favor ingrese su contrasena:" << endl;
            cin >> pass;
            if (Credenciales[numUsuario].contraseña==pass) {
                encontradoContraseña = true;
            }
            if (encontradoContraseña == true) {
                cout << endl;
                cout << "Contrasena correcta, bienvenido, sera redirigido a la aplicacion" << endl;
                system("pause>null");
                exit(0);
            }
            else {
                cout << "Contrasena incorrecta, por favor ingrese un usuario y contrasena valida" << endl;
                system("pause>null");
            }
        }
        else {
            cout << "Nombre de usuario incorrecto, por favor ingrese su nombre de usuario nuevamente" << endl;
            system("pause>null");
        }

        if (contador > 0) {
            cout << endl;
            cout << "Ha realizado " << contador << "/3 intentos" << endl;
            cout << endl;
            system("pause>null");
        }
        if (contador == 3) {
            cout << endl;
            cout << "Ha realizado 3 intentos, por seguridad el programa se cerrara..." << endl;
            system("pause>null");
            exit(0);
        }
    }
