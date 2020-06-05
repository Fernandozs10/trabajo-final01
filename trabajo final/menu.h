#pragma once
#include <string>
#include "cliente.h"
#include<fstream>
#include<stdlib.h>
using namespace std;

cliente::cliente(string _nombre, string _edad, string _genero, string _documento, string _direccion) {
	nombre = _nombre;
	edad = _edad;
	genero = _genero;
	documento = _documento;
	direccion = _direccion;
};
void cliente::registro() {
	cout << "nombre: " << nombre << endl;
	cout << "edad: " << edad << endl;
	cout << "genero: " << genero << endl;
	cout << "documento de identificacion: " << documento << endl;
	cout << "direccion: " << direccion << endl;
};
void cliente::obdatos() {
	ofstream archivo;
	archivo.open("clientes.txt",ios::out | ios::app);
	cout << "ingrese su nombre: " << endl;
	getline(cin, nombre);
	archivo << nombre << " ";
	cout << "ingrese su edad: " << endl;
	getline(cin,edad);
	archivo << edad << " ";
	cout << "ingrese su genero: " << endl;
	getline(cin,genero);
	archivo << genero << " ";
	cout << "ingrese su documento: " << endl;
	getline(cin, documento);
	archivo << documento << " ";
	cout << "ingrese su direccion: " << endl;
	getline(cin, direccion);
	archivo << direccion<<endl;
	if (archivo.fail()) {
		cout << "hubo un error" << endl;
		exit(1);
	}
	archivo.close();
}
int cliente::inicio() {
	int x;
	cout << "Bienvenido mongol" << endl;
	cout << "1. Buscar Clientes" << endl;
	cout << "2. Agregar Clientes" << endl;
	cout << "3. Modificar Clientes" << endl;
	cout << "4. Borrar clientes" << endl;
	cout << "Elija una opcion " << endl;
	cin >> x;
	return x;
}
void cliente::ImprimirInfo()
{
	cout << "Nombre: " << nombre << '\n';
	cout << "Departamento: " << direccion << '\n';
	cout << "Puesto: " << edad << '\n';
	cout << "Salario: " << documento << '\n';
}
void cliente::buscar() {
	string dni2;
	ifstream archivo;
	bool encontrado = false;
	archivo.open("clientes.txt", ios::in);
	cout << "ingrese el dni" << endl;
	cin >> dni2;
	archivo >> nombre;
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