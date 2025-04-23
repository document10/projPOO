#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "periferic.hpp"
#include "audio.hpp"

using namespace std;

Audio::Audio(string cod, string producator, string denumire, float pret, int stoc, string conexiune, string operare, int putere, float canale) : Periferic(cod, producator, denumire, pret, stoc, conexiune)
{
    this->operare = operare;
    this->putere = putere;
    this->canale = canale;
}

Audio::Audio(const Audio &a) : Periferic(a)
{
    this->operare = a.operare;
    this->putere = a.putere;
    this->canale = a.canale;
}

Audio::Audio(string linie) : Periferic(linie)
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
    getline(s, this->operare, '|');
    s >> this->putere;
    s.ignore(1, '|');
    s >> this->canale;
}

string Audio::ToString()
{
    stringstream s("");
    s << "(" << Produs::getCod() << ") " << Produs::getProducator() << ", " << Produs::getDenumire() << ", " << Produs::getPret() << " lei, " << Produs::getStoc() << " in stoc, conexiune " << this->getConexiune() << ", operare " << this->operare << ", putere " << this->putere << "W, canale " << this->canale;
    return s.str();
}

string Audio::ToFile()
{
    stringstream s("");
    s <<this->getTip()<< "|" << Produs::getCod() << "|" << Produs::getProducator() << "|" << Produs::getDenumire() << "|" << Produs::getPret() << "|" << Produs::getStoc() << "|" << this->getConexiune() << "|" << this->operare << "|" << this->putere << "|" << this->canale<< "\n";
    return s.str();
}

int Audio::getTip()
{
    return 12;
}

string Audio::getOperare()
{
    return this->operare;
}

int Audio::getPutere()
{
    return this->putere;
}

float Audio::getCanale()
{
    return this->canale;
}

void Audio::setOperare(string operare)
{
    this->operare = operare;
}

void Audio::setPutere(int putere)
{
    this->putere = putere;
}

void Audio::setCanale(float canale)
{
    this->canale = canale;
}

Audio::~Audio()
{
    // Destructor
}