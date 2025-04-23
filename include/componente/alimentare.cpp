#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "component.hpp"
#include "alimentare.hpp"

using namespace std;

Alimentare::Alimentare(string cod, string producator, string denumire, float pret, int stoc, int putere, string tip, string conectori,string eficienta) : Component(cod, producator, denumire, pret, stoc, putere)
{
    this->tip = tip;
    this->conectori = conectori;
    this->eficienta=eficienta;
}

Alimentare::Alimentare(const Alimentare &a) : Component(a)
{
    this->tip = a.tip;
    this->conectori = a.conectori;
    this->eficienta=a.eficienta;
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
    getline(s,this->eficienta,'|');
}

string Alimentare::ToString()
{
    stringstream s("");
    s << "(" << Produs::getCod() << ") " << Produs::getProducator() << ", " << Produs::getDenumire() << ", " << Produs::getPret() << " lei, " << Produs::getStoc() << " in stoc, " << Component::getPutere() << " W, tip: " << this->tip << ", conectori: " << this->conectori<<", eficienta: "<<this->eficienta;
    return s.str();
}

string Alimentare::ToFile()
{
    stringstream s("");
    s << this->getTip() << "|" << Produs::getCod() << "|" << Produs::getProducator() << "|" << Produs::getDenumire() << "|" << Produs::getPret() << "|" << Produs::getStoc() << "|" << Component::getPutere() << "|" << this->tip << "|" << this->conectori<<"|"<<this->eficienta<<"\n";
    return s.str();
}

int Alimentare::getTip()
{
    return 8;
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