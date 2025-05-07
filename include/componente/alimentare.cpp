#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "../exceptie.hpp"
#include "component.hpp"
#include "alimentare.hpp"

using namespace std;

Alimentare::Alimentare(string cod, string producator, string denumire, float pret, int stoc, int putere, string tip, string conectori, string eficienta) : Component(cod, producator, denumire, pret, stoc, putere)
{
    this->tip = tip;
    this->conectori = conectori;
    this->eficienta = eficienta;
}

Alimentare::Alimentare(const Alimentare &a) : Component(a)
{
    this->tip = a.tip;
    this->conectori = a.conectori;
    this->eficienta = a.eficienta;
}

Alimentare::Alimentare(string linie) : Component(linie)
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
    s >> st;
    s.ignore(1, '|');
    getline(s, this->tip, '|');
    getline(s, this->conectori, '|');
    getline(s, this->eficienta, '|');
}

string Alimentare::ToString()
{
    stringstream s("");
    s << "(" << Produs::getCod() << ") " << Produs::getProducator() << ", " << Produs::getDenumire() << ", " << Produs::getPret() << " lei, " << Produs::getStoc() << " in stoc, " << Component::getPutere() << " W, tip: " << this->tip << ", conectori: " << this->conectori << ", eficienta: " << this->eficienta;
    return s.str();
}

string Alimentare::ToFile()
{
    stringstream s("");
    s << this->getTip() << "|" << Produs::getCod() << "|" << Produs::getProducator() << "|" << Produs::getDenumire() << "|" << Produs::getPret() << "|" << Produs::getStoc() << "|" << Component::getPutere() << "|" << this->tip << "|" << this->conectori << "|" << this->eficienta << "\n";
    return s.str();
}

int Alimentare::getTip()
{
    return 8;
}

void Alimentare::setVal(int index, string value)
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
        try
        {
            Produs::setPret(stof(value));
        }
        catch (...)
        {
            throw Exceptie("Valoarea introdusa nu este un numar valid!", "Alimentare::setVal", "Eroare conversie");
        }
        break;
    case 4:
        try
        {
            Produs::setStoc(stoi(value));
        }
        catch (...)
        {
            throw Exceptie("Valoarea introdusa nu este un numar valid!", "Alimentare::setVal", "Eroare conversie");
        }
        break;
    case 5:
        try
        {
            Component::setPutere(stoi(value));
        }
        catch (...)
        {
            throw Exceptie("Valoarea introdusa nu este un numar valid!", "Alimentare::setVal", "Eroare conversie");
        }
        break;
    case 6:
        this->tip = value;
        break;
    case 7:
        this->conectori = value;
        break;
    case 8:
        this->eficienta = value;
        break;
    default:
        throw Exceptie("Proprietatea nu a fost gasita!", "Alimentare::setVal", "Eroare index");
        break;
    }
}

string Alimentare::getTipAlimentare()
{
    return this->tip;
}

string Alimentare::getConectori()
{
    return this->conectori;
}

string Alimentare::getEficienta()
{
    return this->eficienta;
}

void Alimentare::setTipAlimentare(string tip)
{
    this->tip = tip;
}

void Alimentare::setConectori(string conectori)
{
    this->conectori = conectori;
}

void Alimentare::setEficienta(string eficienta)
{
    this->eficienta = eficienta;
}

Alimentare::~Alimentare()
{
}