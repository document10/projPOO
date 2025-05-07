#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "periferic.hpp"
#include "display.hpp"
#include "../exceptie.hpp"

using namespace std;

Display::Display(string cod, string producator, string denumire, float pret, int stoc, string conexiune, string tehnologie, int rezolutie, float refreshRate, int diagonala) : Periferic(cod, producator, denumire, pret, stoc, conexiune)
{
    this->tehnologie = tehnologie;
    this->rezolutie = rezolutie;
    this->refreshRate = refreshRate;
    this->diagonala = diagonala;
}

Display::Display(const Display &d) : Periferic(d)
{
    this->tehnologie = d.tehnologie;
    this->rezolutie = d.rezolutie;
    this->refreshRate = d.refreshRate;
    this->diagonala = d.diagonala;
}

Display::Display(string linie) : Periferic(linie)
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
    getline(s, this->tehnologie, '|');
    s >> this->rezolutie;
    s.ignore(1, '|');
    s >> this->refreshRate;
    s.ignore(1, '|');
    s >> this->diagonala;
}

string Display::ToString()
{
    stringstream s("");
    s << "(" << Produs::getCod() << ") " << Produs::getProducator() << ", " << Produs::getDenumire() << ", " << Produs::getPret() << " lei, " << Produs::getStoc() << " in stoc, conexiune " << this->getConexiune() << ", tehnologie " << this->tehnologie << ", rezolutie " << this->rezolutie << ", refresh rate " << this->refreshRate << "Hz, diagonala " << this->diagonala;
    return s.str();
}

string Display::ToFile()
{
    stringstream s("");
    s << this->getTip() << "|" << Produs::getCod() << "|" << Produs::getProducator() << "|" << Produs::getDenumire() << "|" << Produs::getPret() << "|" << Produs::getStoc() << "|" << this->getConexiune() << "|" << this->tehnologie << "|" << this->rezolutie << "|" << this->refreshRate << "|" << this->diagonala << "\n";
    return s.str();
}
int Display::getTip()
{
    return 14;
}

void Display::setVal(int index, string value)
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
        // check if value is a float
        try
        {
            Produs::setPret(stof(value));
        }
        catch (...)
        {
            throw Exceptie("Valoare invalida!", "Display::setVal", "Eroare conversie");
        }
        break;
    case 4:
        // check if value is an int
        try
        {
            Produs::setStoc(stoi(value));
        }
        catch (...)
        {
            throw Exceptie("Valoare invalida!", "Display::setVal", "Eroare conversie");
        }
        break;
    case 5:
        Periferic::setConexiune(value);
        break;
    case 6:
        this->tehnologie = value;
        break;
    case 7:
        // check if value is an int
        try
        {
            this->rezolutie = stoi(value);
        }
        catch (...)
        {
            throw Exceptie("Valoare invalida!", "Display::setVal", "Eroare conversie");
        }
        break;
    case 8:
        // check if value is a float
        try
        {
            this->refreshRate = stof(value);
        }
        catch (...)
        {
            throw Exceptie("Valoare invalida!", "Display::setVal", "Eroare conversie");
        }
        break;
    case 9:
        // check if value is an int
        try
        {
            this->diagonala = stoi(value);
        }
        catch (...)
        {
            throw Exceptie("Valoare invalida!", "Display::setVal", "Exceptie index");
        }
        break;
    default:
        throw Exceptie("Index invalid!", "Display::setVal", "Exceptie");
        break;
    }
}

string Display::getTehnologie()
{
    return this->tehnologie;
}
void Display::setTehnologie(string tehnologie)
{
    this->tehnologie = tehnologie;
}
int Display::getRezolutie()
{
    return this->rezolutie;
}
void Display::setRezolutie(int rezolutie)
{
    this->rezolutie = rezolutie;
}
float Display::getRefreshRate()
{
    return this->refreshRate;
}
void Display::setRefreshRate(float refreshRate)
{
    this->refreshRate = refreshRate;
}
int Display::getDiagonala()
{
    return this->diagonala;
}
void Display::setDiagonala(int diagonala)
{
    this->diagonala = diagonala;
}
Display::~Display()
{
    // Destructor
}
