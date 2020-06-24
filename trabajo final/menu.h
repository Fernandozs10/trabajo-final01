#pragma once
#include<windows.h>
#include "cliente.h"
#include<fstream>
#include<iomanip>
using namespace std;

/*cliente::cliente(string _nombre, string _edad, string _genero, string _documento, string _direccion) {
	nombre = _nombre;
	edad = _edad;
	genero = _genero;
	documento = _documento;
	direccion = _direccion;
};*/
void cliente::registro() {/*VP*/
	system("cls");
	ifstream archivo;
	archivo.open("clientes.txt", ios::in);
	if (archivo.fail()) {
		cout << "no se encontro el archivo";
		exit(1);
	}
	archivo >> nombre;
	while (!archivo.eof()) {
		archivo >> edad;
		archivo >> genero;
		archivo >> peso;
		archivo >> documento;
		archivo >> direccion;
		cout << "nombre-------:" << nombre << endl;
		cout << "edad---------:" << edad << endl;
		cout << "genero-------:" << genero << endl;
		cout << "peso---------:" << peso << endl;
		cout << "documento----:" << documento << endl;
		cout << "direccion----:" << direccion << endl;
		cout << "\n";
		archivo >> nombre;
	}
	archivo.close();
	string x;
	cout << "퓀ola quiere volver al inicio?:"; cin >> x;
	if (x == "si") {
		system("cls");
		inicio();
	}
	else {
		system("cls");
		cout << "gracias por su preferencia" << endl;
		exit(1);
	}
};
void cliente::obdatos() {/*RP*/
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
	cout << "ingrese su peso: " << endl;
	cin >> peso;
	archivo << peso << " ";
	cout << "ingrese su documento: " << endl;
	cin >> documento;
	archivo << documento << " ";
	cout << "ingrese su direccion: " << endl;
	cin >> direccion;
	archivo << direccion<<endl;
	archivo.close();
	if (archivo.fail()) {
		cout << "hubo un error" << endl;
		exit(1);
	}
	string x;
	cout << "퓀ola quiere volver al inicio?:"; cin >> x;
	if (x == "si") {
		system("cls");
		inicio();
	}
	else {
		system("cls");
		cout << "gracias por su preferencia" << endl;
		exit(1);
	}
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
		archivo >> peso;
		archivo >> documento;
		archivo >> direccion;
		if (documento == dni2) {
			cout << "nombre-------:" << nombre << endl;
			cout << "edad---------:" << edad << endl;
			cout << "genero-------:" << genero << endl;
			cout << "peso---------:" << peso << endl;
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
	string x;
	cout << "퓀ola quiere volver al inicio?:"; cin >> x;
	if (x == "si") {
		system("cls");
		inicio();
	}
	else {
		system("cls");
		cout << "gracias por su preferencia" << endl;
		exit(1);
	}
}
void cliente::modificar() {
	system("cls");
	string nombre2;
	string edad2;
	string direccion2;
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
			archivo >> peso;
			archivo >> documento;
			archivo >> direccion;
			if (documento == documento2) {
				string x;
				string y;
				string z;
				cout << "si desea cambiar el nombre ponga si caso contrario ponga no: "; cin >> x;
				system("cls");
				if (x == "si") {
					cout << "coloque el nuevo nombre:"; cin >> nombre2;
					x = nombre2;
					system("cls");
				}
				if (x == "no") {
					x = nombre;
					system("cls");
				}
				cout << "si desea cambiar la edad ponga si caso contrario ponga no: "; cin >> y;
				if (y == "si") {
					cout << "coloque la nueva edad:"; cin >> edad2;
					y = edad2;
					system("cls");
				}
				if (y == "no") {
					y = edad;
					system("cls");
				}
				cout << "si desea cambiar la direccion si caso contrario ponga no: "; cin >> z;
				if (z == "si") {
					cout << "coloque la nueva direccion:"; cin >> direccion2;
					z = direccion2;
					system("cls");
				}
				if (z == "no") {
					z = direccion;
					system("cls");


				}
				aux << x << " " << y << " " << genero <<" "<< peso << " " << documento << "   " << z << "\n";
			}
			else {
				aux << nombre << " " << edad << " " << genero << " " << peso << " " << documento << "   " << direccion << "\n";
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
	string x;
	cout << "퓀ola quiere volver al inicio?:"; cin >> x;
	if (x == "si") {
		system("cls");
		inicio();
	}
	else {
		system("cls");
		cout << "gracias por su preferencia" << endl;
		exit(1);
	}
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
			archivo >> peso;
			archivo >> documento;
			archivo >> direccion;
			if (documento == documento2) {
				cout << "el cliente fue eliminado: ";
			}
			else {
				aux << nombre << " " << edad << " " << genero << " " << peso << " " << documento << "   " << direccion << "\n";
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
	string x;
	cout << "퓀ola quiere volver al inicio?:"; cin >> x;
	if (x == "si") {
		system("cls");
		inicio();
	}
	else {
		system("cls");
		cout << "gracias por su preferencia" << endl;
		exit(1);
	}
}
void cliente::preinicio() {
	cout << endl;
	cout <<"                ************************************************************************************"<< endl;
	cout <<"                                 "<< "Bienvenido a la base de datos del hospital essalud"<<endl;
	cout <<"               ************************************************************************************" << endl;
	Sleep(3000);
	system("cls");
}
void cliente::inicio() {
	int x;
	cout << setw(68)<<">>>> Bienvenido <<<<" << endl;
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
		system("cls");
		cout << "!! Hasta luego !!";
		exit(1);
		break;
	default:
		system("cls");
		cout << "No existe esa opcion!!!" << endl;
		exit(1);
	}

}