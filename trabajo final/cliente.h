#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class cliente
{
private:
	string nombre;
	string edad;
	string genero;
	string documento;
	string direccion;
public:
	cliente(string, string, string, string, string);
	void registro();
	void modificar();
	void obdatos();
	int inicio();
	void ImprimirInfo();
	void buscar();
};