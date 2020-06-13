#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "usuario.h"
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
	/*cliente(string, string, string, string, string);*/
	/*cliente();*/
	void preinicio();
	void registro();
	void obdatos();
	void inicio();
	void buscar();
	void modificar();
	void elicliente();

};