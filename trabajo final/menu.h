#pragma once
#include <string>
#include "cliente.h"
#include<fstream>
using namespace std;

cliente::cliente(string _nombre, int _edad, string _genero, int _documento, string _direccion) {
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
void cliente::modificar() {
	cout << "modifique el nombre" << endl;
	cin >> nombre;
}
void cliente::obdatos() {
	cout << "ingrese su nombre: " << endl;
	cin >> nombre;
	cout << "ingrese dsu edad: " << endl;
	cin >> edad;
	cout << "ingrese su genero: " << endl;
	cin >> genero;
	cout << "ingrese su documento: " << endl;
	cin >> documento;
	cout << "ingrese su direccion: " << endl;
	cin >> direccion;
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