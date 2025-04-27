#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>

#include "exceptie.hpp"

using namespace std;

Exceptie::Exceptie(string mesaj, string sursa, string tip)
{
    this->mesaj = mesaj;
    this->sursa = sursa;
    this->tip = tip;
}
Exceptie::Exceptie(const Exceptie &e)
{
    this->mesaj = e.mesaj;
    this->sursa = e.sursa;
    this->tip = e.tip;
}
string Exceptie::getMesaj()
{
    return this->mesaj;
}
string Exceptie::getSursa()
{
    return this->sursa;
}
string Exceptie::getTip()
{
    return this->tip;
}
void Exceptie::setMesaj(string mesaj)
{
    this->mesaj = mesaj;
}
void Exceptie::setSursa(string sursa)
{
    this->sursa = sursa;
}
void Exceptie::setTip(string tip)
{
    this->tip = tip;
}
string Exceptie::ToString()
{
    stringstream ss;
    ss << "Exceptie: " << this->tip << "\n"
       << "Mesaj: " << this->mesaj << "\n"
       << "Sursa: " << this->sursa << endl;
    return ss.str();
}
Exceptie::~Exceptie()
{
    // Destructor
}

ostream &operator<<(ostream &os, const Exceptie &e)
{
    os << "A avut loc o exceptie: " << e.tip << "\n"
       << "Mesaj: " << e.mesaj << "\n"
       << "Sursa: " << e.sursa << endl;
    return os;
}