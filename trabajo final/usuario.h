#pragma once
#include<windows.h>
#include <string>
#include "cliente.h"
#include<fstream>
#include<stdlib.h>
#include<iomanip>
using namespace std;
class usuario
{
private:
	string contra;
public:
	 usuario() {
	}
	void mostrarC() {
		cout << "Escoja una contrasenia para poder acceder a la base de datos: "; cin >> contra;
		system("cls");
		cout << "Contrasenia guardada!" << endl;
		Sleep(1500);
		system("cls");
	}
	int verificarC() {
		string aucontra;
		cout << "Ingrese su contrasenia:" << endl;
		cin >> aucontra;
		if (aucontra == contra) {
			return 1;
		}
		else {
			return 0;
		}
	}
	void protegerC() {
		int veri;
		//	do {
		int i;
		for (i = 3; i >= 1; i--) {
			veri = verificarC();

			system("cls");
			if (veri == 1) {
				cout << "Acceso concedido" << endl;
				break;
			}
			else {
				cout << "Constrasenia Incorrecta!!!" << endl;
				Sleep(1000);
				system("cls");
				cout << "Vuelva a Escribir tu Contrasenia!!!" << endl;
				cout << "Le quedan " << i - 1 << " intentos" << endl;

				Sleep(2000);
				system("cls");
				if (i == 1) {
					//cout << "Se acabaron los intentos,hasta luego"<<endl;
					cout << "Habil te crees CTM" << endl;
					cout << endl;
					cout << endl;
				}
			}
		}

	
	}
};

