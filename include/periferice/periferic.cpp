#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "periferic.hpp"
#include "../exceptie.hpp"

using namespace std;

Periferic::Periferic(string cod, string producator, string denumire, float pret, int stoc, string conexiune) : Produs(cod, producator, denumire, pret, stoc)
{
    this->conexiune = conexiune;
}
Periferic::Periferic(const Periferic &p) : Produs(p)
{
    this->conexiune = p.conexiune;
}
Periferic::Periferic(string linie) : Produs(linie)
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
    getline(s, this->conexiune, '|');
}
string Periferic::ToString()
{
    // char *rez = new char[100];
    // sprintf(rez, "(%s) %s, %s, %.2f lei, %d in stoc, conexiune %s", Produs::getCod().c_str(), Produs::getProducator().c_str(), Produs::getDenumire().c_str(), Produs::getPret(), Produs::getStoc(), this->conexiune.c_str());
    // return string(rez);
    stringstream s("");
    s << "(" << Produs::getCod() << ") " << Produs::getProducator() << ", " << Produs::getDenumire() << ", " << Produs::getPret() << " lei, " << Produs::getStoc() << " in stoc, conexiune " << this->conexiune;
    return s.str();
}
string Periferic::ToFile()
{
    char *rez = new char[100];
    sprintf(rez, "%d|%s|%s|%s|%.2f|%d|%s\n", this->getTip(), Produs::getCod().c_str(), Produs::getProducator().c_str(), Produs::getDenumire().c_str(), Produs::getPret(), Produs::getStoc(), this->conexiune.c_str());
    return string(rez);
}
int Periferic::getTip()
{
    return 2;
}

void Periferic::setVal(int index, string value)
{
    switch (index)
    {
    case 0:
        Produs::setCod(value);
        break;
    case 1:
        Produs::setProducator(value);
        break;
    case 2:
        Produs::setDenumire(value);
        break;
    case 3:
        //check if value is a float
        try {
            Produs::setPret(stof(value));
        }
        catch (...) {
            throw Exceptie("Valoarea nu este un numar!", "Periferic::setVal", "Eroare float");
        }
        break;
    case 4:
        //check if value is an int
        try {
            Produs::setStoc(stoi(value));
        }
        catch (...) {
            throw Exceptie("Valoarea nu este un numar!", "Periferic::setVal", "Eroare int");
        }
        break;
    case 5:
        this->conexiune = value;
        break;
    default:
        throw Exceptie("Proprietatea nu a fost gasita!", "Periferic::setVal", "Eroare index");
        break;
    }
}

string Periferic::getConexiune()
{
    return this->conexiune;
}
void Periferic::setConexiune(string conexiune)
{
    this->conexiune = conexiune;
}
Periferic::~Periferic()
{
    
}