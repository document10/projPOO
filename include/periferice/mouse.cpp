#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "periferic.hpp"
#include "mouse.hpp"

using namespace std;

Mouse::Mouse(string cod, string producator, string denumire, float pret, int stoc, string conexiune, string senzor, string iluminare, int dpi, int butoane) : Periferic(cod, producator, denumire, pret, stoc, conexiune)
{
    this->senzor = senzor;
    this->iluminare = iluminare;
    this->dpi = dpi;
    this->butoane = butoane;
}
Mouse::Mouse(const Mouse &m) : Periferic(m)
{
    this->senzor = m.senzor;
    this->iluminare = m.iluminare;
    this->dpi = m.dpi;
    this->butoane = m.butoane;
}

Mouse::Mouse(string linie) : Periferic(linie)
{
    stringstream s(linie);
    int i, st;
    float pret;
    string temp;
    s >> i;
    s.ignore(1, '|');
    getline(s, temp, '|');
    getline(s, temp, '|');
    getline(s, temp, '|');
    s >> pret;
    s.ignore(1, '|');
    s >> st;
    s.ignore(1, '|');
    getline(s, temp, '|');
    getline(s, this->senzor, '|');
    getline(s, this->iluminare, '|');
    s >> this->dpi;
    s.ignore(1, '|');
    s >> this->butoane;
    s.ignore(1, '|');
}

string Mouse::ToString()
{
    stringstream s("");
    s << "(" << Produs::getCod() << ") " << Produs::getProducator() << ", " << Produs::getDenumire() << ", " << Produs::getPret() << " lei, " << Produs::getStoc() << " in stoc, conexiune " << this->getConexiune() << ", senzor " << this->senzor << ", iluminare " << this->iluminare << ", dpi " << this->dpi << ", butoane " << this->butoane;
    return s.str();
}

string Mouse::ToFile()
{
    stringstream s("");
    s << this->getTip() << "|" << Produs::getCod() << "|" << Produs::getProducator() << "|" << Produs::getDenumire() << "|" << Produs::getPret() << "|" << Produs::getStoc() << "|" << this->getConexiune() << "|" << this->senzor << "|" << this->iluminare << "|" << this->dpi << "|" << this->butoane<< "\n";
    return s.str();
}
int Mouse::getTip()
{
    return 11;
}
string Mouse::getSenzor()
{
    return this->senzor;
}
void Mouse::setSenzor(string senzor)
{
    this->senzor = senzor;
}
string Mouse::getIluminare()
{
    return this->iluminare;
}
void Mouse::setIluminare(string iluminare)
{
    this->iluminare = iluminare;
}
int Mouse::getDPI()
{
    return this->dpi;
}
void Mouse::setDPI(int dpi)
{
    this->dpi = dpi;
}
int Mouse::getButoane()
{
    return this->butoane;
}
void Mouse::setButoane(int butoane)
{
    this->butoane = butoane;
}
Mouse::~Mouse()
{
    // Destructorul clasei Mouse
}