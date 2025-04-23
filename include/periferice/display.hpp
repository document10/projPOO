#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "periferic.hpp"

using namespace std;

class Display : public Periferic
{
private:
    string tehnologie;
    int rezolutie,diagonala;
    float refreshRate;

public:
    Display(string cod, string producator, string denumire, float pret, int stoc, string conexiune, string tehnologie, int rezolutie, float refreshRate, int diagonala);
    Display(const Display &d);
    Display(string linie);
    string ToString() override;
    string ToFile() override;
    int getTip() override;
    string getTehnologie();
    int getRezolutie();
    float getRefreshRate();
    int getDiagonala();
    void setTehnologie(string tehnologie);
    void setRezolutie(int rezolutie);
    void setRefreshRate(float refreshRate);
    void setDiagonala(int diagonala);
    ~Display();
};

#endif //DISPLAY_HPP
