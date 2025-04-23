#ifndef STOCARE_HPP
#define STOCARE_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "component.hpp"

using namespace std;

class Stocare : public Component
{
private:
    float capacitate, readspeed, writespeed, iops;
    string tehnologie;

public:
    Stocare(string cod, string producator, string denumire, float pret, int stoc, int putere, float capacitate, float readspeed, float writespeed, float iops, string tehnologie);
    Stocare(const Stocare &s);
    Stocare(string linie);
    string ToString() override;
    string ToFile() override;
    int getTip() override;
    float getCapacitate();
    float getReadSpeed();
    float getWriteSpeed();
    float getIOPS();
    string getTehnologie();
    void setCapacitate(float capacitate);
    void setReadSpeed(float readspeed);
    void setWriteSpeed(float writespeed);
    void setIOPS(float iops);
    void setTehnologie(string tehnologie);
    ~Stocare();
};

#endif // STOCARE_HPP
