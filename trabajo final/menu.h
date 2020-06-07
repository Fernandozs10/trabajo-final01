#pragma once
#include<windows.h>
#include <string>
#include "cliente.h"
#include<fstream>
#include<stdlib.h>
#include<iomanip>
using namespace std;

/*cliente::cliente(string _nombre, string _edad, string _genero, string _documento, string _direccion) {
	nombre = _nombre;
	edad = _edad;
	genero = _genero;
	documento = _documento;
	direccion = _direccion;
};*/
void cliente::registro() {
	system("cls");
	ifstream archivo;
	string texto;
	archivo.open("clientes.txt", ios::in);
	if (archivo.fail()) {
		cout << "no se encontro el archivo";
		exit(1);
	}
	archivo >> nombre;
	while (!archivo.eof()) {
		archivo >> edad;
		archivo >> genero;
		archivo >> documento;
		archivo >> direccion;
		cout << "nombre-------:" << nombre << endl;
		cout << "edad---------:" << edad << endl;
		cout << "genero-------:" << genero << endl;
		cout << "documento----:" << documento << endl;
		cout << "direccion----:" << direccion << endl;
		cout << "\n";
		archivo >> nombre;
	}
	archivo.close();
};
void cliente::obdatos() {
	system("cls");
	ofstream archivo;
	archivo.open("clientes.txt",ios::out | ios::app);
	cout << "ingrese su nombre: " << endl;
	cin >> nombre;
	archivo << nombre << " ";
	cout << "ingrese su edad: " << endl;
	cin >> edad;
	archivo << edad << " ";
	cout << "ingrese su genero: " << endl;
	cin >> genero;
	archivo << genero << " ";
	cout << "ingrese su documento: " << endl;
	cin >> documento;
	archivo << documento << " ";
	cout << "ingrese su direccion: " << endl;
	cin >> direccion;
	archivo << direccion<<endl;
	if (archivo.fail()) {
		cout << "hubo un error" << endl;
		exit(1);
	}
	archivo.close();
}
void cliente::buscar() {
	system("cls");
	string dni2;
	ifstream archivo;
	bool encontrado = false;
	archivo.open("clientes.txt", ios::in);
	cout << "ingrese el dni" << endl;
	cin >> dni2;
	archivo >> nombre;
	if (archivo.fail()) {
		cout << "hubo un error" << endl;
		exit(1);
	}
	while (!archivo.eof() && !encontrado) {
		archivo >> edad;
		archivo >> genero;
		archivo >> documento;
		archivo >> direccion;
		if (documento == dni2) {
			cout << "nombre-------:" << nombre << endl;
			cout << "edad---------:" << edad << endl;
			cout << "genero-------:" << genero << endl;
			cout << "documento----:" << documento << endl;
			cout << "direccion----:" << direccion << endl;
			cout << "\n";
			encontrado = true;
		}
		archivo >> nombre;
	}
	if (!encontrado) {
		cout << "No se encontro el registro del cliente" << endl;
	}
	archivo.close();
}
void cliente::modificar() {
	system("cls");
	string nombre2;
	string documento2;
	ifstream archivo;
	archivo.open("clientes.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if (archivo.is_open()) {
		cout << "Digite el dni para modificar los datos: "; 
		cin >> documento2;
		archivo >> nombre;
		while (!archivo.eof()) {
			archivo >> edad;
			archivo >> genero;
			archivo >> documento;
			archivo >> direccion;
			if (documento == documento2) {
				cout << "Ingrese el nuevo nombre: "; cin >> nombre2;
				aux << nombre2 << " " << edad << " " << genero << " " << documento << "   " << direccion << "\n";
			}
			else {
				aux << nombre << " " << edad << " " << genero << " " << documento << "   " << direccion << "\n";
			}
			archivo >> nombre;
		}
		archivo.close();
		aux.close();
	}
	else
		cout << "No se pudo abrir el archivo" << "\n" << endl;
	remove("Clientes.txt");
	rename("auxiliar.txt", "Clientes.txt");
}
void cliente::elicliente() {
	system("cls");
	string nombre2;
	string documento2;
	ifstream archivo;
	archivo.open("clientes.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if (archivo.is_open()) {
		cout << "Digite el dni: ";
		cin >> documento2;
		archivo >> nombre;
		while (!archivo.eof()) {
			archivo >> edad;
			archivo >> genero;
			archivo >> documento;
			archivo >> direccion;
			if (documento == documento2) {
				cout << "el cliente fue eliminado: ";
			}
			else {
				aux << nombre << " " << edad << " " << genero << " " << documento << "   " << direccion << "\n";
			}
			archivo >> nombre;
		}
		archivo.close();
		aux.close();
	}
	else
		cout << "No se pudo abrir el archivo" << "\n" << endl;
	remove("Clientes.txt");
	rename("auxiliar.txt", "Clientes.txt");
}
void cliente::preinicio() {
	cout << endl;
	cout <<"                ************************************************************************************"<< endl;
	cout <<"                                 "<< "Bienvenido a la base de datos del hospital essalud"<<endl;
	cout <<"               ************************************************************************************" << endl;
	Sleep(2000);
	system("cls");
}
void cliente::inicio() {
	int x;
	cout << setw(68)<<">>>> Bienvenido mongol <<<<" << endl;
	cout << endl;
	cout << "1. Agregar Clientes" << endl;
	cout << endl;
	cout << "2. Ver Clientes" << endl;
	cout << endl;
	cout << "3. Buscar Clientes" << endl;
	cout << endl;
	cout << "4. Modificar clientes" << endl;
	cout << endl;
	cout << "5. Borrar datos del cliente" << endl;
	cout << endl;
	cout << "6. Salir" << endl;
	cout << endl;
	cout << "Elija una opcion " << endl;
	cin >> x;
	switch (x) {
	case 1:
		obdatos();
		break;
	case 2:
		registro();
		break;
	case 3:
		buscar();
		break;
	case 4:
		modificar();
		break;
	case 5:
		elicliente();
		break;
	case 6:
		exit;
		break;
	}
}