#ifndef CAM_HPP
#define CAM_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "periferic.hpp"

using namespace std;

class Cam : public Periferic
{
private:
    string clasa;
    int rezolutie;
    float fps;
public:
    Cam(string cod, string producator, string denumire, float pret, int stoc, string conexiune, string clasa, int rezolutie, float fps);
    Cam(const Cam &c);
    Cam(string linie);
    string ToString() override;
    string ToFile() override;
    int getTip() override;
    void setVal(int index, string value) override;
    string getClasa();
    int getRezolutie();
    float getFPS();
    void setClasa(string clasa);
    void setRezolutie(int rezolutie);
    void setFPS(float fps);
    ~Cam() override;
};

#endif //CAM_HPP
