#ifndef PROCESOR_HPP
#define PROCESOR_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "component.hpp"

using namespace std;

class Procesor : public Component
{
private:
    float frecventa, maxMem, memCache;
    int nuclee;

public:
    Procesor(string cod, string producator, string denumire, float pret, int stoc, int putere, float frecventa, int nuclee, float maxMem, float memCache);
    Procesor(const Procesor &p);
    Procesor(string linie);
    string ToString() override;
    string ToFile() override;
    void setVal(int index, string value) override;
    int getTip() override;
    float getFrecventa();
    int getNuclee();
    float getMaxMem();
    float getMemCache();
    void setFrecventa(float frecventa);
    void setNuclee(int nuclee);
    void setMaxMem(float maxMem);
    void setMemCache(float memCache);
    ~Procesor() override;
};

#endif // PROCESOR_HPP