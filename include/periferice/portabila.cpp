#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "periferic.hpp"
#include "portabila.hpp"
#include "../exceptie.hpp"

using namespace std;

Portabila::Portabila(string cod, string producator, string denumire, float pret, int stoc, string conexiune, string tehnologie, float capacitate, float readSpeed, float writeSpeed) : Periferic(cod, producator, denumire, pret, stoc, conexiune)
{
    this->tehnologie = tehnologie;
    this->capacitate = capacitate;
    this->readSpeed = readSpeed;
    this->writeSpeed = writeSpeed;
}

Portabila::Portabila(const Portabila &p) : Periferic(p)
{
    this->tehnologie = p.tehnologie;
    this->capacitate = p.capacitate;
    this->readSpeed = p.readSpeed;
    this->writeSpeed = p.writeSpeed;
}

Portabila::Portabila(string linie) : Periferic(linie)
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
    getline(s, tehnologie, '|');
    s >> capacitate;
    s.ignore(1, '|');
    s >> readSpeed;
    s.ignore(1, '|');
    s >> writeSpeed;
}

string Portabila::ToString()
{
    stringstream s;
    s << "(" << Produs::getCod() << ") " << Produs::getProducator() << ", " << Produs::getDenumire() << ", " << Produs::getPret() << " lei, " << Produs::getStoc() << " in stoc, conexiune " << this->getConexiune() << ", tehnologie " << this->tehnologie << ", capacitate " << this->capacitate << " GB " << this->readSpeed << " mbps citire, " << this->writeSpeed << " mbps scriere";
    return s.str();
}

string Portabila::ToFile()
{
    stringstream s;
    s<< this->getTip()<< "|" << Produs::getCod() << "|" << Produs::getProducator() << "|" << Produs::getDenumire() << "|" << Produs::getPret() << "|" << Produs::getStoc() << "|" << this->getConexiune() << "|" << this->tehnologie << "|" << this->capacitate << "|" << this->readSpeed<< "|" << this->writeSpeed<< "\n";
    return s.str();
}

int Portabila::getTip()
{
    return 15;
}

void Portabila::setVal(int index, string value)
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
        //check if value is a float
        try {
            Produs::setPret(stof(value));
        }
        catch (...) {
            throw Exceptie("Pret invalid!", "Portabila::setVal", "Exceptie");
        }
        Produs::setPret(stof(value));
        break;
    case 4:
        //check if value is an int
        try {
            Produs::setStoc(stoi(value));
        }
        catch (...) {
            throw Exceptie("Stoc invalid!", "Portabila::setVal", "Exceptie");
        }
        break;
    case 5:
        Periferic::setConexiune(value);
        break;
    case 6:
        this->tehnologie = value;
        break;
    case 7:
        //check if value is a float
        try {
            this->capacitate = stof(value);
        }
        catch (...) {
            throw Exceptie("Capacitate invalida!", "Portabila::setVal", "Exceptie");
        }
        break;
    case 8:
        //check if value is a float
        try {
            this->readSpeed = stof(value);
        }
        catch (...) {
            throw Exceptie("Read speed invalid!", "Portabila::setVal", "Exceptie");
        }
        break;
    case 9:
        //check if value is a float
        try {
            this->writeSpeed = stof(value);
        }
        catch (...) {
            throw Exceptie("Write speed invalid!", "Portabila::setVal", "Exceptie");
        }
        break;
    default:
        throw Exceptie("Index invalid!", "Portabila::setVal", "Exceptie");
        break;
    }
}

string Portabila::getTehnologie()
{
    return this->tehnologie;
}

float Portabila::getCapacitate()
{
    return this->capacitate;
}

float Portabila::getReadSpeed()
{
    return this->readSpeed;
}

float Portabila::getWriteSpeed()
{
    return this->writeSpeed;
}

void Portabila::setTehnologie(string tehnologie)
{
    this->tehnologie = tehnologie;
}

void Portabila::setCapacitate(float capacitate)
{
    this->capacitate = capacitate;
}

void Portabila::setReadSpeed(float readSpeed)
{
    this->readSpeed = readSpeed;
}

void Portabila::setWriteSpeed(float writeSpeed)
{
    this->writeSpeed = writeSpeed;
}

Portabila::~Portabila()
{
    // Destructor
}