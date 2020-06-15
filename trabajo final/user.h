#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
using namespace std;
class user
{
private:
	string usuario;
	string contra;
public:
	void registrarU() {
		ofstream es;
		es.open("Usuario.txt", ios::out | ios::app);
		cout << "Escriba su usuario: ";
		cin >> usuario;
		cout << "Esciba su contrasenia: ";
		cin >> contra;
		es << usuario << " " << contra << "\n";
		es.close();
		system("cls");
		cout << "Datos guardados!!!" << endl;
		Sleep(1500);
		system("cls");

	}
	void ingresarU() {
		ifstream lec;
		lec.open("Usuario.txt", ios::in);
		string auxusuario;
		string auxcontra;
		bool encontrado = false;
		cout << "Ingrese su usuario: ";
		cin >> auxusuario;
		cout << "Ingrese su contra: ";
		cin >> auxcontra;
		lec >> usuario;
		while (!lec.eof() && !encontrado) {

			lec >> contra;
			if (usuario == auxusuario && contra == auxcontra) {
				system("cls");
				cout << "Bienvenido " << usuario << " !!!" << endl;
				Sleep(1500);
				system("cls");
				encontrado = true;
			}
			lec >> usuario;
		}
		lec.close();
		if (!encontrado) {
			system("cls");
			cout << "Usuario o Contrasenia incorrectos." << endl;
			exit(1);
		}
		exit;


	}
	/*void confirmarU() {
		ifstream lec;
		lec.open("Usuario.txt", ios::in);

		string auxcontra;
		bool encontrado = false;

		cout << "Ingrese su contra: ";
		cin >> auxcontra;
		lec >> usuario;
		while (!lec.eof() && !encontrado) {

			lec >> contra;
			if (contra == auxcontra) {
				system("cls");
				encontrado = true;
			}
			lec >> usuario;
		}
		lec.close();
		if (!encontrado) {
			system("cls");
			cout << "Contrasenia incorrecta." << endl;
		}



	}*/
};
