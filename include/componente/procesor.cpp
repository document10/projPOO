#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "component.hpp"
#include "procesor.hpp"
#include "../exceptie.hpp"

using namespace std;

Procesor::Procesor(string cod, string producator, string denumire, float pret, int stoc, int putere, float frecventa, int nuclee, float maxMem, float memCache) : Component(cod, producator, denumire, pret, stoc, putere)
{
    this->frecventa = frecventa;
    this->nuclee = nuclee;
    this->maxMem = maxMem;
    this->memCache = memCache;
}

Procesor::Procesor(const Procesor &p) : Component(p)
{
    this->frecventa = p.frecventa;
    this->nuclee = p.nuclee;
    this->maxMem = p.maxMem;
    this->memCache = p.memCache;
}

Procesor::Procesor(string linie) : Component(linie)
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
    s >> this->nuclee;
    s.ignore(1, '|');
    s >> this->maxMem;
    s.ignore(1, '|');
    s >> this->memCache;
}

string Procesor::ToString()
{
    stringstream s("");
    s << "(" << Produs::getCod() << ") " << Produs::getProducator() << ", " << Produs::getDenumire() << ", " << Produs::getPret() << " lei, " << Produs::getStoc() << " in stoc, " << Component::getPutere() << " W, " << this->frecventa << " GHz, " << this->nuclee << " nuclee," << this->maxMem << " GB RAM maxim," << this->memCache << " MB Cache";
    return s.str();
}

string Procesor::ToFile()
{
    stringstream s("");
    s << this->getTip() << "|" << Produs::getCod() << "|" << Produs::getProducator() << "|" << Produs::getDenumire() << "|" << Produs::getPret() << "|" << Produs::getStoc() << "|" << Component::getPutere() << "|" << this->frecventa << "|" << this->nuclee << "|" << this->maxMem << "|" << this->memCache << "\n";
    return s.str();
}
int Procesor::getTip()
{
    return 3;
}

void Procesor::setVal(int index, string value)
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
            throw Exceptie("Valoarea introdusa nu este un numar valid!", "Procesor::setVal", "Eroare conversie");
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
            throw Exceptie("Valoarea introdusa nu este un numar valid!", "Procesor::setVal", "Eroare conversie");
        }
        break;
    case 5:
        // check if value is an int
        try
        {
            Component::setPutere(stoi(value));
        }
        catch (...)
        {
            throw Exceptie("Valoarea introdusa nu este un numar valid!", "Procesor::setVal", "Eroare conversie");
        }
        break;
    case 6:
        // check if value is a float
        try
        {
            this->frecventa = stof(value);
        }
        catch (...)
        {
            throw Exceptie("Valoarea introdusa nu este un numar valid!", "Procesor::setVal", "Eroare conversie");
        }
        break;
    case 7:
        // check if value is an int
        try
        {
            this->nuclee = stoi(value);
        }
        catch (...)
        {
            throw Exceptie("Valoarea introdusa nu este un numar valid!", "Procesor::setVal", "Eroare conversie");
        }
        break;
    case 8:
        // check if value is a float
        try
        {
            this->maxMem = stof(value);
        }
        catch (...)
        {
            throw Exceptie("Valoarea introdusa nu este un numar valid!", "Procesor::setVal", "Eroare conversie");
        }
        break;
    case 9:
        // check if value is a float
        try
        {
            this->memCache = stof(value);
        }
        catch (...)
        {
            throw Exceptie("Valoarea introdusa nu este un numar valid!", "Procesor::setVal", "Eroare conversie");
        }
        break;
    default:
        throw Exceptie("Proprietatea nu a fost gasita!", "Procesor::setVal", "Eroare index");
        break;
    }
}

float Procesor::getFrecventa()
{
    return this->frecventa;
}
int Procesor::getNuclee()
{
    return this->nuclee;
}
float Procesor::getMaxMem()
{
    return this->maxMem;
}
float Procesor::getMemCache()
{
    return this->memCache;
}
void Procesor::setFrecventa(float frecventa)
{
    this->frecventa = frecventa;
}
void Procesor::setNuclee(int nuclee)
{
    this->nuclee = nuclee;
}
void Procesor::setMaxMem(float maxMem)
{
    this->maxMem = maxMem;
}
void Procesor::setMemCache(float memCache)
{
    this->memCache = memCache;
}
Procesor::~Procesor()
{
}