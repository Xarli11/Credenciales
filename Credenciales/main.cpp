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
const int MAX_CREDENCIALES=10;
const int MAX_USERS=100;
typedef struct {
    string usuario;
    string contraseña;
}tCredenciales;
typedef tCredenciales tListaCredenciales[MAX_CREDENCIALES];
/*Lista de usuarios y contraseñas guardadas*/
typedef tCredenciales tListaUsuarios[MAX_USERS];
/*Este es el menu de Usuarios y Contraseñas*/
void login();

void menu();
void leer(tListaCredenciales& Credenciales);
bool comprobar(string usuario, tListaCredenciales &Credendiales, int contador);
void leer2(tListaUsuarios& Usuarios);
void menu2(tListaUsuarios& Usuarios);
void mostrarCredenciales(tListaUsuarios Usuarios);

int main() {
    menu();
    return 0;
}

void login() {
    string nombre;
    tListaCredenciales credenciales;
    tListaUsuarios usuarios;
    leer(credenciales);
    leer2(usuarios);
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
    system("color 0A");
    login();
}

void leer(tListaCredenciales& Credenciales) {

    ifstream fileUsers, filePasswords;
    bool fin = false;
    fileUsers.open("usuarios.txt");    
    filePasswords.open("contraseñas.txt");
    if (fileUsers.is_open() && filePasswords.is_open()) {
        do {
            for (int i = 0; i < MAX_CREDENCIALES; i++) {
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
void leer2(tListaUsuarios& Usuarios) {

    ifstream fileUsers, filePasswords;
    bool fin = false;
    fileUsers.open("usuariosSaved.txt");
    filePasswords.open("contraseñasSaved.txt");
    if (fileUsers.is_open() && filePasswords.is_open()) {
        do {
            for (int i = 0; i < MAX_USERS; i++) {
                fileUsers >> Usuarios[i].usuario;
                filePasswords >> Usuarios[i].contraseña;
            }
            fin = true;
        } while (fin = false);
    }
    else {
        cout << "No se ha podido abrir el archivo para comprobar los usuarios" << endl;
    }
}
void menu2(tListaUsuarios &Usuarios) {
    int opcion = -1;
    system("cls");
    cout << "---------------------" << endl;
    cout << "-                   -" << endl;
    cout << "-        MENU       -" << endl;
    cout << "-                   -" << endl;
    cout << "---------------------" << endl;
    cout << "1.Mostrar todas las contraseñas y usuarios" << endl;
    cout << "Elija una opcion: ";
    cin >> opcion;
    switch (opcion) {
    case 1:
        mostrarCredenciales(Usuarios);
        break;

    };
}

    void mostrarCredenciales(tListaUsuarios Usuarios) {
        for (int i = 0; i < MAX_USERS;) {
            cout
        }
    }