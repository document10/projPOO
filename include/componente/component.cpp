#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "component.hpp"

using namespace std;

Component::Component(string cod, string producator, string denumire, float pret, int stoc, int putere) : Produs(cod, producator, denumire, pret, stoc)
{
    this->putere = putere;
}

Component::Component(const Component &c) : Produs(c)
{
    this->putere = c.putere;
}

Component::Component(string linie) : Produs(linie)
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
    s >> this->putere;
}

string Component::ToString()
{
    stringstream s("");
    s << "(" << Produs::getCod() << ") " << Produs::getProducator() << ", " << Produs::getDenumire() << ", " << Produs::getPret() << " lei, " << Produs::getStoc() << " in stoc, " << this->putere << " W";
    return s.str();
}

string Component::ToFile()
{
    char *rez = new char[100];
    sprintf(rez, "%d|%s|%s|%s|%.2f|%d|%d\n", this->getTip(), Produs::getCod().c_str(), Produs::getProducator().c_str(), Produs::getDenumire().c_str(), Produs::getPret(), Produs::getStoc(), this->putere);
    return string(rez);
}

int Component::getTip()
{
    return 1;
}

int Component::getPutere()
{
    return this->putere;
}

void Component::setPutere(int putere)
{
    this->putere = putere;
}

Component::~Component()
{
    // Destructor
}