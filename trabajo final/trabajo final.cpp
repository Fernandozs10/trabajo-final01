#include <iostream>
#include "cliente.h"
#include<fstream>
using namespace std;

int main()
{
    cliente p2("",0,"",0,"");
    cliente p1("", 0,"", 0,"");
    p2.inicio();
    p1.registro();
    p1.obdatos();
    p1.registro();
    return 0;
}