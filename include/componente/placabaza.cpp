#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <list>
#include "../produs.hpp"
#include "component.hpp"
#include "placabaza.hpp"

using namespace std;

PlacaBaza::PlacaBaza(string cod, string producator, string denumire, float pret, int stoc, int putere, string socket, string chipset, string formFactor, int maxMem, int memSlots,string conectori) : Component(cod, producator, denumire, pret, stoc, putere)
{
    this->socket = socket;
    this->chipset = chipset;
    this->formFactor = formFactor;
    this->maxMem = maxMem;
    this->memSlots = memSlots;
    this->conectori=conectori;
}

PlacaBaza::PlacaBaza(const PlacaBaza &p) : Component(p)
{
    this->socket = p.socket;
    this->chipset = p.chipset;
    this->formFactor = p.formFactor;
    this->maxMem = p.maxMem;
    this->memSlots = p.memSlots;
    this->conectori=p.conectori;
}

PlacaBaza::PlacaBaza(string linie) : Component(linie)
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
    getline(s, this->socket, '|');
    getline(s, this->chipset, '|');
    getline(s, this->formFactor, '|');
    s >> this->maxMem;
    s.ignore(1, '|');
    s >> this->memSlots;
    s.ignore(1,'|');
    getline(s,this->conectori,'|');
}

string PlacaBaza::ToString()
{
    stringstream s("");
    s << "(" << Produs::getCod() << ") " << Produs::getProducator() << ", " << Produs::getDenumire() << ", " << Produs::getPret() << " lei, " << Produs::getStoc() << " in stoc, " << Component::getPutere() << " W, socket: " << this->socket << ", chipset: " << this->chipset << ", form factor: " << this->formFactor << ", max memorie: " << this->maxMem << " GB, sloturi memorie: " << this->memSlots<<", conectori: "<<this->conectori;
    return s.str();
}

string PlacaBaza::ToFile()
{
    stringstream s("");
    s << this->getTip() << "|" << Produs::getCod() << "|" << Produs::getProducator() << "|" << Produs::getDenumire() << "|" << Produs::getPret() << "|" << Produs::getStoc() << "|" << Component::getPutere() << "|" << this->socket << "|" << this->chipset << "|" << this->formFactor << "|" << this->maxMem << "|" << this->memSlots<<"|"<<this->conectori<<"\n";
    return s.str();
}

int PlacaBaza::getTip()
{
    return 6;
}

string PlacaBaza::getSocket()
{
    return this->socket;
}

string PlacaBaza::getChipset()
{
    return this->chipset;
}

string PlacaBaza::getFormFactor()
{
    return this->formFactor;
}

string PlacaBaza::getConectori()
{
    return this->conectori;
}

int PlacaBaza::getMaxMem()
{
    return this->maxMem;
}

int PlacaBaza::getMemSlots()
{
    return this->memSlots;
}

void PlacaBaza::setSocket(string socket)
{
    this->socket = socket;
}

void PlacaBaza::setChipset(string chipset)
{
    this->chipset = chipset;
}

void PlacaBaza::setFormFactor(string formFactor)
{
    this->formFactor = formFactor;
}

void PlacaBaza::setConectori(string conectori)
{
    this->conectori = conectori;
}

void PlacaBaza::setMaxMem(int maxMem)
{
    this->maxMem = maxMem;
}

void PlacaBaza::setMemSlots(int memSlots)
{
    this->memSlots = memSlots;
}

PlacaBaza::~PlacaBaza()
{
    // Destructor
}