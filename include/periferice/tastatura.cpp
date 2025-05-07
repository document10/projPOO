#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "tastatura.hpp"
#include "periferic.hpp"
#include "../exceptie.hpp"

using namespace std;
Tastatura::Tastatura(string cod, string producator, string denumire, float pret, int stoc, string conexiune, string format, string taste, string iluminare) : Periferic(cod, producator, denumire, pret, stoc, conexiune)
{
    this->format = format;
    this->taste = taste;
    this->iluminare = iluminare;
}

Tastatura::Tastatura(const Tastatura &t) : Periferic(t)
{
    this->format = t.format;
    this->taste = t.taste;
    this->iluminare = t.iluminare;
}

Tastatura::Tastatura(string linie) : Periferic(linie)
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
    getline(s, this->format, '|');
    getline(s, this->taste, '|');
    getline(s, this->iluminare, '|');
}

string Tastatura::ToString()
{
    stringstream s("");
    s << "(" << Produs::getCod() << ") " << Produs::getProducator() << ", " << Produs::getDenumire() << ", " << Produs::getPret() << " lei, " << Produs::getStoc() << " in stoc, conexiune " << this->getConexiune() << ", format " << this->format << ", taste " << this->taste << ", iluminare " << this->iluminare;
    return s.str();
}
string Tastatura::ToFile()
{
    stringstream s("");
    s << this->getTip() << "|" << Produs::getCod() << "|" << Produs::getProducator() << "|" << Produs::getDenumire() << "|" << Produs::getPret() << "|" << Produs::getStoc() << "|" << this->getConexiune() << "|" << this->format << "|" << this->taste << "|" << this->iluminare << "\n";
    return s.str();
}

void Tastatura::setVal(int index, string value)
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
        try
        {
            Produs::setPret(stof(value));
        }
        catch (...)
        {
            throw Exceptie("Pret invalid!", "Tastatura::setVal", "Exceptie");
        }
        break;
    case 4:
        //check if value is an int
        try
        {
            Produs::setStoc(stoi(value));
        }
        catch (...)
        {
            throw Exceptie("Stoc invalid!", "Tastatura::setVal", "Exceptie");
        }
        break;
    case 5:
        Periferic::setConexiune(value);
        break;
    case 6:
        this->format = value;
        break;
    case 7:
        this->taste = value;
        break;
    case 8:
        this->iluminare = value;
        break;
    default:
        throw Exceptie("Index invalid!", "Tastatura::setVal", "Exceptie");
        break;
    }
}

int Tastatura::getTip()
{
    return 10;
}

string Tastatura::getFormat()
{
    return this->format;
}

void Tastatura::setFormat(string format)
{
    this->format = format;
}

string Tastatura::getTaste()
{
    return this->taste;
}

void Tastatura::setTaste(string taste)
{
    this->taste = taste;
}

string Tastatura::getIluminare()
{
    return this->iluminare;
}

void Tastatura::setIluminare(string iluminare)
{
    this->iluminare = iluminare;
}

Tastatura::~Tastatura()
{
}