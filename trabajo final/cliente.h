#pragma once
#include<iostream>
#include<fstream>
#include "Persona.h"
using namespace std;
class cliente:public Persona
{
private:
	/*string nombre;
	string edad;
	string genero;
	string documento;
	string direccion;*/
	string peso;
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