#ifndef MOUSE_HPP
#define MOUSE_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "periferic.hpp"

using namespace std;

class Mouse : public Periferic
{
private:
    string senzor,iluminare;
    int dpi, butoane;
public:
    Mouse(string cod, string producator, string denumire, float pret, int stoc, string conexiune, string senzor, string iluminare, int dpi, int butoane);
    Mouse(const Mouse &m);
    Mouse(string linie);
    string ToString() override;
    string ToFile() override;
    int getTip() override;
    void setVal(int index, string value) override;
    string getSenzor();
    string getIluminare();
    int getDPI();
    int getButoane();
    void setSenzor(string senzor);
    void setIluminare(string iluminare);
    void setDPI(int dpi);
    void setButoane(int butoane);
    ~Mouse();
};

#endif //MOUSE_HPP
