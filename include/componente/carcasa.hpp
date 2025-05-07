#ifndef CARCASA_HPP
#define CARCASA_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "component.hpp"

using namespace std;

class Carcasa : public Component
{
private:
    string marime, conectori, dimensiune, lumini;

public:
    Carcasa(string cod, string producator, string denumire, float pret, int stoc, int putere, string marime, string conectori, string dimensiune, string lumini);
    Carcasa(const Carcasa &c);
    Carcasa(string linie);
    string ToString() override;
    string ToFile() override;
    int getTip() override;
    void setVal(int index, string value) override;
    string getMarime();
    string getConectori();
    string getDimensiune();
    string getLumini();
    void setMarime(string marime);
    void setConectori(string conectori);
    void setDimensiune(string dimensiune);
    void setLumini(string lumini);
    ~Carcasa();
};

#endif //CARCASA_HPP
