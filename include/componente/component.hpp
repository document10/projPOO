#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
#include "../produs.hpp"

using namespace std;

class Component : public Produs
{
private:
    int putere;
public:
    Component(string cod, string producator, string denumire, float pret, int stoc, int putere);
    Component(const Component &c);
    Component(string linie);
    string ToString() override;
    string ToFile() override;
    void setVal(int index, string value) override;
    int getTip() override;
    int getPutere();
    void setPutere(int putere);
    ~Component();
};

#endif // COMPONENT_HPP