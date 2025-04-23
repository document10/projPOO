#ifndef PLACABAZA_HPP
#define PLACABAZA_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <list>
#include "../produs.hpp"
#include "component.hpp"

using namespace std;

class PlacaBaza : public Component
{
private:
    string socket, chipset, formFactor,conectori;
    int maxMem, memSlots;
public:
    PlacaBaza(string cod, string producator, string denumire, float pret, int stoc, int putere, string socket, string chipset, string formFactor, int maxMem, int memSlots,string conectori);
    PlacaBaza(const PlacaBaza &p);
    PlacaBaza(string linie);
    string ToString() override;
    string ToFile() override;
    int getTip() override;
    string getSocket();
    string getChipset();
    string getFormFactor();
    string getConectori();
    int getMaxMem();
    int getMemSlots();
    void setSocket(string socket);
    void setChipset(string chipset);
    void setFormFactor(string formFactor);
    void setConectori(string conectori);
    void setMaxMem(int maxMem);
    void setMemSlots(int memSlots);
    ~PlacaBaza();
};

#endif // PLACABAZA_HPP
