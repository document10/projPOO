#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <format>

#include "produs.hpp"
#include "exceptie.hpp"

using namespace std;

Produs::Produs(string cod, string producator, string denumire, float pret, int stoc)
{
    this->cod = cod;
    this->producator = producator;
    this->denumire = denumire;
    this->pret = pret;
    this->stoc = stoc;
}
Produs::Produs(const Produs &p)
{
    this->cod = p.cod;
    this->producator = p.producator;
    this->denumire = p.denumire;
    this->pret = p.pret;
    this->stoc = p.stoc;
}
Produs::Produs(string linie)
{
    stringstream s(linie);
    int i;
    s >> i;
    s.ignore(1, '|');
    getline(s, this->cod, '|');
    getline(s, this->producator, '|');
    getline(s, this->denumire, '|');
    s >> this->pret;
    s.ignore(1, '|');
    s >> this->stoc;
}

string Produs::ToString()
{
    stringstream s("");
    s << "(" << this->cod << ") " << this->producator << ", " << this->denumire << ", " << this->pret << " lei, " << this->stoc << " in stoc";
    return s.str();
}

string Produs::ToFile()
{
    stringstream s("");
    s << this->getTip() << "|" << this->cod << "|" << this->producator << "|" << this->denumire << "|" << this->pret << "|" << this->stoc << "\n";
    return s.str();
}

void Produs::setVal(int index, string value)
{
    switch (index)
    {
    case 0:
        this->cod = value;
        break;
    case 1:
        this->producator = value;
        break;
    case 2:
        this->denumire = value;
        break;
    case 3:
        // check if value is a float
        try
        {
            this->pret = stof(value);
        }
        catch (...)
        {
            throw Exceptie("Valoarea introdusa nu este un numar valid!", "Produs::setVal", "Eroare conversie");
        }
        break;
    case 4:
        // check if value is an int
        try
        {
            this->stoc = stoi(value);
        }
        catch (...)
        {
            throw Exceptie("Valoarea introdusa nu este un numar valid!", "Produs::setVal", "Eroare conversie");
        }
        break;
    default:
        throw Exceptie("Proprietatea nu a fost gasita!", "Produs::setVal", "Eroare index");
        break;
    }
}

string Produs::getCod()
{
    return this->cod;
}
string Produs::getProducator()
{
    return this->producator;
}
string Produs::getDenumire()
{
    return this->denumire;
}
float Produs::getPret()
{
    return this->pret;
}
int Produs::getStoc()
{
    return this->stoc;
}
int Produs::getTip()
{
    return 0; // Default implementation, can be overridden in derived classes
}
void Produs::setCod(string cod)
{
    this->cod = cod;
}
void Produs::setProducator(string producator)
{
    this->producator = producator;
}
void Produs::setDenumire(string denumire)
{
    this->denumire = denumire;
}
void Produs::setPret(float pret)
{
    this->pret = pret;
}
void Produs::setStoc(int stoc)
{
    this->stoc = stoc;
}
Produs::~Produs()
{
    // Destructor
}