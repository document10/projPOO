#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "periferic.hpp"

using namespace std;

class Camera : public Periferic
{
private:
    string clasa;
    int rezolutie;
    float fps;
public:
    Camera(string cod, string producator, string denumire, float pret, int stoc, string conexiune, string clasa, int rezolutie, float fps);
    Camera(const Camera &c);
    Camera(string linie);
    string ToString() override;
    string ToFile() override;
    int getTip() override;
    string getClasa();
    int getRezolutie();
    float getFPS();
    void setClasa(string clasa);
    void setRezolutie(int rezolutie);
    void setFPS(float fps);
    ~Camera();
};

#endif //CAMERA_HPP
