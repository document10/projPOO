#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "periferic.hpp"

using namespace std;

class Audio : public Periferic
{
private:
    string operare;
    int putere;
    float canale;
public:
    Audio(string cod, string producator, string denumire, float pret, int stoc, string conexiune, string operare, int putere, float canale);
    Audio(const Audio &a);
    Audio(string linie);
    string ToString() override;
    string ToFile() override;
    int getTip() override;
    string getOperare();
    int getPutere();
    float getCanale();
    void setOperare(string operare);
    void setPutere(int putere);
    void setCanale(float canale);
    ~Audio();
};

#endif //AUDIO_HPP
