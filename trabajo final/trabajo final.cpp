#include <iostream>
#include "cliente.h"
#include "user.h"
#include <fstream>
using namespace std;
void inicioContra() {
    user u1;
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
        system("cls");
        cout << "No existe esa opcion!!!" << endl;
        exit(1);
    }

}
int main()
{
    system("color 0E");
    cliente p1;
    p1.preinicio();
    inicioContra();
    p1.inicio();
    return 0;
}