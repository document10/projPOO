#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "component.hpp"
#include "memorie.hpp"

using namespace std;

Memorie::Memorie(string cod, string producator, string denumire, float pret, int stoc, int putere, float frecventa, float capacitate, string technologie, string conector) : Component(cod, producator, denumire, pret, stoc, putere)
{
    this->frecventa = frecventa;
    this->capacitate = capacitate;
    this->technologie = technologie;
    this->conector = conector;
}

Memorie::Memorie(const Memorie &m) : Component(m)
{
    this->frecventa = m.frecventa;
    this->capacitate = m.capacitate;
    this->technologie = m.technologie;
    this->conector = m.conector;
}

Memorie::Memorie(string linie) : Component(linie)
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
    s >> this->frecventa;
    s.ignore(1, '|');
    s >> this->capacitate;
    s.ignore(1, '|');
    getline(s, this->technologie, '|');
    getline(s, this->conector, '|');
}

string Memorie::ToString()
{
    stringstream s("");
    s << "(" << Produs::getCod() << ") " << Produs::getProducator() << ", " << Produs::getDenumire() << ", " << Produs::getPret() << " lei, " << Produs::getStoc() << " in stoc, " << Component::getPutere() << " W, " << this->frecventa << " MHz, " << this->capacitate << " GB, " << this->technologie << ", conector: " << this->conector;
    return s.str();
}

string Memorie::ToFile()
{
    stringstream s("");
    s << this->getTip() << "|" << Produs::getCod() << "|" << Produs::getProducator() << "|" << Produs::getDenumire() << "|" << Produs::getPret() << "|" << Produs::getStoc() << "|" << Component::getPutere() << "|" << this->frecventa << "|" << this->capacitate << "|" << this->technologie << "|" << this->conector<<"\n";
    return s.str();
}

int Memorie::getTip()
{
    return 4;
}

float Memorie::getFrecventa()
{
    return this->frecventa;
}

float Memorie::getCapacitate()
{
    return this->capacitate;
}

string Memorie::getTechnologie()
{
    return this->technologie;
}

string Memorie::getConector()
{
    return this->conector;
}

void Memorie::setFrecventa(float frecventa)
{
    this->frecventa = frecventa;
}

void Memorie::setCapacitate(float capacitate)
{
    this->capacitate = capacitate;
}

void Memorie::setTechnologie(string technologie)
{
    this->technologie = technologie;
}

void Memorie::setConector(string conector)
{
    this->conector = conector;
}

Memorie::~Memorie()
{
    // Destructor
}