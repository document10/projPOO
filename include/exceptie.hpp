#ifndef EXCEPTIE_HPP
#define EXCEPTIE_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;

class Exceptie
{
private:
    string mesaj,sursa,tip;
public:
    Exceptie(string mesaj,string sursa,string tip);
    Exceptie(const Exceptie &e);
    ~Exceptie();
    string getMesaj();
    string getSursa();
    string getTip();
    void setMesaj(string mesaj);
    void setSursa(string sursa);
    void setTip(string tip);
    string ToString();
    friend ostream& operator<<(ostream& os, const Exceptie& e);
};

#endif //EXCEPTIE_HPP
