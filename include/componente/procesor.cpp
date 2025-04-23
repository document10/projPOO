#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "component.hpp"
#include "procesor.hpp"

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
    // char *rez = new char[100];
    // sprintf(rez, "(%s) %s, %s, %.2f lei, %d in stoc, %d W, %.2f GHz, %d nuclee, %.2f GB RAM maxim, %.2f MB Cache", Produs::getCod().c_str(), Produs::getProducator().c_str(), Produs::getDenumire().c_str(), Produs::getPret(), Produs::getStoc(), Component::getPutere(), this->frecventa, this->nuclee, this->maxMem, this->memCache);
    // return string(rez);
    stringstream s("");
    s<<"("<<Produs::getCod()<<") "<<Produs::getProducator()<<", "<<Produs::getDenumire()<<", "<<Produs::getPret()<<" lei, "<<Produs::getStoc()<<" in stoc, "<<Component::getPutere()<<" W, "<<this->frecventa<<" GHz, "<<this->nuclee<<" nuclee,"<<this->maxMem<<" GB RAM maxim,"<<this->memCache<<" MB Cache";
    return s.str();
}

string Procesor::ToFile()
{
    char *rez = new char[100];
    sprintf(rez, "%d|%s|%s|%s|%.2f|%d|%d|%.2f|%d|%.2f|%.2f\n", this->getTip(), Produs::getCod().c_str(), Produs::getProducator().c_str(), Produs::getDenumire().c_str(), Produs::getPret(), Produs::getStoc(), Component::getPutere(), this->frecventa, this->nuclee, this->maxMem, this->memCache);
    return string(rez);
}
int Procesor::getTip()
{
    return 3;
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