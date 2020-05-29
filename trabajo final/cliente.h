#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class cliente
{
private:
	string nombre;
	int edad;
	string genero;
	int documento;
	string direccion;
public:
	cliente(string, int, string, int, string);
	void registro();
	void modificar();
	void obdatos();
	int inicio();
	void ImprimirInfo();
};