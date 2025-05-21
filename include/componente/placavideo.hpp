#ifndef PLACAVIDEO_HPP
#define PLACAVIDEO_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "component.hpp"

using namespace std;

class PlacaVideo : public Component
{
private:
    string chipset, conector;
    int units, tops;
    float vram;
public:
    PlacaVideo(string cod, string producator, string denumire, float pret, int stoc, int putere, string chipset, string conector, int units, int tops, float vram);
    PlacaVideo(const PlacaVideo &p);
    PlacaVideo(string linie);
    string ToString() override;
    string ToFile() override;
    int getTip() override;
    void setVal(int index, string value) override;
    string getChipset();
    string getConector();
    int getUnits();
    int getTops();
    float getVram();
    void setChipset(string chipset);
    void setConector(string conector);
    void setUnits(int units);
    void setTops(int tops);
    void setVram(float vram);
    ~PlacaVideo() override;
};

#endif //PLACAVIDEO_HPP
