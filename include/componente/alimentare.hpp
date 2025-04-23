#ifndef ALIMENTARE_HPP
#define ALIMENTARE_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "component.hpp"

using namespace std;

class Alimentare : public Component
{
private:
    string tip, conectori,eficienta;
public:
    Alimentare(string cod, string producator, string denumire, float pret, int stoc, int putere, string tip, string conectori,string eficienta);
    Alimentare(const Alimentare &a);
    Alimentare(string linie);
    string ToString() override;
    string ToFile() override;
    int getTip() override;
    string getTipAlimentare();
    string getConectori();
    string getEficienta();
    void setTipAlimentare(string tip);
    void setConectori(string conectori);
    void setEficienta(string eficienta);
    ~Alimentare();
};


#endif //ALIMENTARE_HPP
