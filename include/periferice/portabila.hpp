#ifndef PORTABILA_HPP
#define PORTABILA_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "periferic.hpp"

using namespace std;

class Portabila : public Periferic
{
private:
    string tehnologie;
    float capacitate, readSpeed, writeSpeed;

public:
    Portabila(string cod, string producator, string denumire, float pret, int stoc, string conexiune, string tehnologie, float capacitate, float readSpeed, float writeSpeed);
    Portabila(const Portabila &p);
    Portabila(string linie);
    string ToString() override;
    string ToFile() override;
    int getTip() override;
    void setVal(int index, string value) override;
    string getTehnologie();
    float getCapacitate();
    float getReadSpeed();
    float getWriteSpeed();
    void setTehnologie(string tehnologie);
    void setCapacitate(float capacitate);
    void setReadSpeed(float readSpeed);
    void setWriteSpeed(float writeSpeed);
    ~Portabila() override;
};

#endif // PORTABILA_HPP
