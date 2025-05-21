#ifndef PRODUS_HPP
#define PRODUS_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

class Produs
{
private:
    string cod, producator, denumire;
    float pret;
    int stoc;

public:
    Produs(string cod, string producator, string denumire, float pret, int stoc);
    Produs(const Produs &p);
    Produs(string linie);
    virtual string ToString();
    virtual string ToFile();
    virtual int getTip();
    virtual void setVal(int index,string value);
    string getCod();
    string getProducator();
    string getDenumire();
    float getPret();
    int getStoc();
    void setCod(string cod);
    void setProducator(string producator);
    void setDenumire(string denumire);
    void setPret(float pret);
    void setStoc(int stoc);
    virtual ~Produs();
};
#endif // PRODUS_HPP