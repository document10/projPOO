#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "component.hpp"
#include "stocare.hpp"

using namespace std;

Stocare::Stocare(string cod, string producator, string denumire, float pret, int stoc, int putere, float capacitate, float readspeed, float writespeed, float iops, string tehnologie) : Component(cod, producator, denumire, pret, stoc, putere)
{
    this->capacitate = capacitate;
    this->readspeed = readspeed;
    this->writespeed = writespeed;
    this->iops = iops;
    this->tehnologie = tehnologie;
}

Stocare::Stocare(const Stocare &s) : Component(s)
{
    this->capacitate = s.capacitate;
    this->readspeed = s.readspeed;
    this->writespeed = s.writespeed;
    this->iops = s.iops;
    this->tehnologie = s.tehnologie;
}

Stocare::Stocare(string linie) : Component(linie)
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
    s >> this->capacitate;
    s.ignore(1, '|');
    s >> this->readspeed;
    s.ignore(1, '|');
    s >> this->writespeed;
    s.ignore(1, '|');
    s >> this->iops;
    s.ignore(1, '|');
    getline(s, this->tehnologie, '|');
}

string Stocare::ToString()
{
    stringstream s("");
    s << "(" << Produs::getCod() << ") " << Produs::getProducator() << ", " << Produs::getDenumire() << ", " << Produs::getPret() << " lei, " << Produs::getStoc() << " in stoc, " << Component::getPutere() << " W, " << this->capacitate << " GB, " << this->readspeed << " MB/s citire, " << this->writespeed << " MB/s, scriere" << this->iops << " IOPS, tehnologie: " << this->tehnologie<<"\n";
    return s.str();
}

string Stocare::ToFile()
{
    stringstream s("");
    s << this->getTip() << "|" << Produs::getCod() << "|" << Produs::getProducator() << "|" << Produs::getDenumire() << "|" << Produs::getPret() << "|" << Produs::getStoc() << "|" << Component::getPutere() << "|" << this->capacitate << "|" << this->readspeed << "|" << this->writespeed << "|" << this->iops << "|" << this->tehnologie<<"\n";
    return s.str();
}

int Stocare::getTip()
{
    return 5;
}

float Stocare::getCapacitate()
{
    return this->capacitate;
}

float Stocare::getReadSpeed()
{
    return this->readspeed;
}

float Stocare::getWriteSpeed()
{
    return this->writespeed;
}

float Stocare::getIOPS()
{
    return this->iops;
}

string Stocare::getTehnologie()
{
    return this->tehnologie;
}

void Stocare::setCapacitate(float capacitate)
{
    this->capacitate = capacitate;
}

void Stocare::setReadSpeed(float readspeed)
{
    this->readspeed = readspeed;
}

void Stocare::setWriteSpeed(float writespeed)
{
    this->writespeed = writespeed;
}

void Stocare::setIOPS(float iops)
{
    this->iops = iops;
}

void Stocare::setTehnologie(string tehnologie)
{
    this->tehnologie = tehnologie;
}

Stocare::~Stocare()
{
    // Destructor
}