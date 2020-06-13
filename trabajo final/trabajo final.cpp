#include <iostream>
#include "cliente.h"
#include "user.h"
#include <fstream>
using namespace std;
user u1;
void inicio() {
    cout << "Bienvenido a la base de datos del hospital" << endl;
    cout << endl;
    cout << endl;
    cout << "Para poder acceder a la base de datos necesita tener un usuario y contrasenia" << endl;
    cout << "Elija una de las opciones: " << endl;
    cout << endl;
    cout << "1. Crear nuevo usuario" << endl;
    cout << "2. Ingresar usuario" << endl;
    cout << "3.Salir" << endl;
    cout << endl;
    cout << endl;
    int op;
    cout << "Digite una opcion: " << endl;
    cin >> op;

    switch (op) {
    case 1:
        system("cls");
        u1.registrarU();
        u1.ingresarU();
        break;
    case 2:
        system("cls");
        u1.ingresarU();
        break;
    case 3:
        system("cls");
        exit(1);
        break;

    default:
        cout << "No existe esa opcion!!!" << endl;

    }

}
int main()
{
    system("color 0E");
    inicio();
    cliente p1;
    usuario p;
    p1.inicio();
    return 0;
}