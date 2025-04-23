#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "component.hpp"
#include "placavideo.hpp"

using namespace std;

PlacaVideo::PlacaVideo(string cod, string producator, string denumire, float pret, int stoc, int putere, string chipset, string conector, int units, int tops, float vram):Component(cod, producator, denumire, pret, stoc, putere){
    this->chipset = chipset;
    this->conector = conector;
    this->units = units;
    this->tops = tops;
    this->vram = vram;
}

PlacaVideo::PlacaVideo(const PlacaVideo &p) : Component(p)
{
    this->chipset = p.chipset;
    this->conector = p.conector;
    this->units = p.units;
    this->tops = p.tops;
    this->vram = p.vram;
}

PlacaVideo::PlacaVideo(string linie) : Component(linie)
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
    getline(s, this->chipset, '|');
    getline(s, this->conector, '|');
    s >> this->units;
    s.ignore(1, '|');
    s >> this->tops;
    s.ignore(1, '|');
    s >> this->vram;
}
string PlacaVideo::ToString()
{
    stringstream s("");
    s << "(" << Produs::getCod() << ") " << Produs::getProducator() << ", " << Produs::getDenumire() << ", " << Produs::getPret() << " lei, " << Produs::getStoc() << " in stoc, " << Component::getPutere() << " W, chipset: " << this->chipset << ", conector: " << this->conector << ", units: " << this->units << ", TOPS: " << this->tops<<", : "<<this->vram << " GB VRAM";
    return s.str();
}

string PlacaVideo::ToFile()
{
    stringstream s("");
    s << this->getTip() << "|" << Produs::getCod() << "|" << Produs::getProducator() << "|" << Produs::getDenumire() << "|" << Produs::getPret() << "|" << Produs::getStoc() << "|" << Component::getPutere() << "|" << this->chipset << "|" << this->conector << "|" << this->units << "|" << this->tops<<"|"<<this->vram<<"\n";
    return s.str();
}

int PlacaVideo::getTip()
{
    return 7;
}

int PlacaVideo::getUnits()
{
    return this->units;
}

int PlacaVideo::getTops()
{
    return this->tops;
}

float PlacaVideo::getVram()
{
    return this->vram;
}

string PlacaVideo::getChipset()
{
    return this->chipset;
}

string PlacaVideo::getConector()
{
    return this->conector;
}

void PlacaVideo::setChipset(string chipset)
{
    this->chipset = chipset;
}

void PlacaVideo::setConector(string conector)
{
    this->conector = conector;
}

void PlacaVideo::setUnits(int units)
{
    this->units = units;
}

void PlacaVideo::setTops(int tops)
{
    this->tops = tops;
}

void PlacaVideo::setVram(float vram)
{
    this->vram = vram;
}

PlacaVideo::~PlacaVideo()
{
    
}
