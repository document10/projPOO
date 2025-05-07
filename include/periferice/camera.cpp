#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "periferic.hpp"
#include "camera.hpp"
#include "../exceptie.hpp"

using namespace std;

Cam::Cam(string cod, string producator, string denumire, float pret, int stoc, string conexiune, string clasa, int rezolutie, float fps) : Periferic(cod, producator, denumire, pret, stoc, conexiune)
{
    this->clasa = clasa;
    this->rezolutie = rezolutie;
    this->fps = fps;
}

Cam::Cam(const Cam &c) : Periferic(c)
{
    this->clasa = c.clasa;
    this->rezolutie = c.rezolutie;
    this->fps = c.fps;
}

Cam::Cam(string linie) : Periferic(linie)
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
    getline(s, this->clasa, '|');
    s >> this->rezolutie;
    s.ignore(1, '|');
    s >> this->fps;
}
string Cam::ToString()
{
    stringstream s("");
    s << "(" << Produs::getCod() << ") " << Produs::getProducator() << ", " << Produs::getDenumire() << ", " << Produs::getPret() << " lei, " << Produs::getStoc() << " in stoc, conexiune " << this->getConexiune() << ", clasa " << this->clasa << ", rezolutie " << this->rezolutie << "p, fps " << this->fps;
    return s.str();
}
string Cam::ToFile()
{
    stringstream s("");
    s << this->getTip() << "|" << Produs::getCod() << "|" << Produs::getProducator() << "|" << Produs::getDenumire() << "|" << Produs::getPret() << "|" << Produs::getStoc() << "|" << this->getConexiune() << "|" << this->clasa << "|" << this->rezolutie << "|" << this->fps << "\n";
    return s.str();
}
int Cam::getTip()
{
    return 13;
}

void Cam::setVal(int index, string value)
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
            throw Exceptie("Valoarea introdusa nu este un numar valid!", "Produs::setVal", "Eroare conversie");
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
            throw Exceptie("Valoarea introdusa nu este un numar valid!", "Produs::setVal", "Eroare conversie");
        }
        break;
    case 5:
        Periferic::setConexiune(value);
        break;
    case 6:
        this->clasa = value;
        break;
    case 7:
        // check if value is an int
        try
        {
            this->rezolutie = stoi(value);
        }
        catch (...)
        {
            throw Exceptie("Valoarea introdusa nu este un numar valid!", "Cam::setVal", "Eroare conversie");
        }
        break;
    case 8:
        // check if value is a float
        try
        {
            this->fps = stof(value);
        }
        catch (...)
        {
            throw Exceptie("Valoarea introdusa nu este un numar valid!", "Cam::setVal", "Eroare conversie");
        }
        break;
    default:
        throw Exceptie("Index invalid!", "Cam::setVal", "Exceptie index");
        break;
    }
}

string Cam::getClasa()
{
    return this->clasa;
}

int Cam::getRezolutie()
{
    return this->rezolutie;
}

float Cam::getFPS()
{
    return this->fps;
}

void Cam::setClasa(string clasa)
{
    this->clasa = clasa;
}

void Cam::setRezolutie(int rezolutie)
{
    this->rezolutie = rezolutie;
}

void Cam::setFPS(float fps)
{
    this->fps = fps;
}
Cam::~Cam()
{
    // Destructor
}