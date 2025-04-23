#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "component.hpp"
#include "carcasa.hpp"

using namespace std;

Carcasa::Carcasa(string cod, string producator, string denumire, float pret, int stoc, int putere, string marime, string conectori, string dimensiune, string lumini) : Component(cod, producator, denumire, pret, stoc, putere)
{
    this->marime = marime;
    this->conectori = conectori;
    this->dimensiune = dimensiune;
    this->lumini = lumini;
}

Carcasa::Carcasa(const Carcasa &c) : Component(c)
{
    this->marime = c.marime;
    this->conectori = c.conectori;
    this->dimensiune = c.dimensiune;
    this->lumini = c.lumini;
}

Carcasa::Carcasa(string linie) : Component(linie)
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
    getline(s, this->marime, '|');
    getline(s, this->conectori, '|');
    getline(s, this->dimensiune, '|');
    getline(s,this->lumini,'|');
}

string Carcasa::ToString()
{
    stringstream s("");
    s << "(" << Produs::getCod() << ") " << Produs::getProducator() << ", " << Produs::getDenumire() << ", " << Produs::getPret() << " lei, " << Produs::getStoc() << " in stoc, " << Component::getPutere() << " W, marime: " << this->marime << ", conectori: " << this->conectori<<", dimensiune: "<<this->dimensiune<<", lumini: "<<this->lumini;
    return s.str();
}

string Carcasa::ToFile()
{
    stringstream s("");
    s << this->getTip() << "|" << Produs::getCod() << "|" << Produs::getProducator() << "|" << Produs::getDenumire() << "|" << Produs::getPret() << "|" << Produs::getStoc() << "|" << Component::getPutere() << "|" << this->marime << "|" << this->conectori<<"|"<<this->dimensiune<<"|"<<this->lumini<<"\n";
    return s.str();
}

int Carcasa::getTip()
{
    return 9;
}

string Carcasa::getMarime()
{
    return this->marime;
}

string Carcasa::getConectori()
{
    return this->conectori;
}

string Carcasa::getDimensiune()
{
    return this->dimensiune;
}

string Carcasa::getLumini()
{
    return this->lumini;
}

void Carcasa::setMarime(string marime)
{
    this->marime = marime;
}

void Carcasa::setConectori(string conectori)
{
    this->conectori = conectori;
}

void Carcasa::setDimensiune(string dimensiune)
{
    this->dimensiune = dimensiune;
}

void Carcasa::setLumini(string lumini)
{
    this->lumini = lumini;
}

Carcasa::~Carcasa()
{
}