#ifndef TASTATURA_HPP
#define TASTATURA_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "periferic.hpp"

using namespace std;

class Tastatura : public Periferic
{
private:
    string format, taste, iluminare;
public:
    Tastatura(string cod, string producator, string denumire, float pret, int stoc, string conexiune, string format, string taste, string iluminare);
    Tastatura(const Tastatura &t);
    Tastatura(string linie);
    ~Tastatura();
    string ToString();
    string ToFile();
    int getTip();
    string getFormat();
    void setFormat(string format);
    string getTaste();
    void setTaste(string taste);
    string getIluminare();
    void setIluminare(string iluminare);
};

#endif // TASTATURA_HPP
