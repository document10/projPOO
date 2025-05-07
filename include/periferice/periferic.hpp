#ifndef PERIFERIC_HPP
#define PERIFERIC_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
#include "../produs.hpp"

using namespace std;

class Periferic : public Produs
{
private:
    string conexiune;
public:
    Periferic(string cod, string producator, string denumire, float pret, int stoc, string conexiune);
    Periferic(const Periferic &p);
    Periferic(string linie);
    string ToString() override;
    string ToFile() override;
    int getTip() override;
    void setVal(int index, string value) override;
    string getConexiune();
    void setConexiune(string conexiune);
    ~Periferic();
};


#endif //PERIFERIC_HPP