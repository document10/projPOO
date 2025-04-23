#ifndef MEMORIE_HPP
#define MEMORIE_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "component.hpp"

using namespace std;

class Memorie : public Component
{
    private:
    float frecventa, capacitate;
    string technologie, conector;
    
    public:
    Memorie(string cod, string producator, string denumire, float pret, int stoc, int putere, float frecventa, float capacitate, string technologie, string conector);
    Memorie(const Memorie &m);
    Memorie(string linie);
    string ToString() override;
    string ToFile() override;
    int getTip() override;
    float getFrecventa();
    float getCapacitate();
    string getTechnologie();
    string getConector();
    void setFrecventa(float frecventa);
    void setCapacitate(float capacitate);
    void setTechnologie(string technologie);
    void setConector(string conector);
    ~Memorie();
};

#endif //MEMORIE_HPP