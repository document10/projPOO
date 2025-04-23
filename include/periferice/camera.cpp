#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../produs.hpp"
#include "periferic.hpp"
#include "camera.hpp"

using namespace std;

Camera::Camera(string cod, string producator, string denumire, float pret, int stoc, string conexiune, string clasa, int rezolutie, float fps) : Periferic(cod, producator, denumire, pret, stoc, conexiune)
{
    this->clasa = clasa;
    this->rezolutie = rezolutie;
    this->fps = fps;
}

Camera::Camera(const Camera &c) : Periferic(c)
{
    this->clasa = c.clasa;
    this->rezolutie = c.rezolutie;
    this->fps = c.fps;
}

Camera::Camera(string linie) : Periferic(linie)
{
    stringstream s(linie);
    int i, st;
    float pret;
    string temp;
    s >> i;
    s.ignore(1, '|');
    getline(s, temp, '|');
    getline(s, temp, '|');
    getline(s, temp, '|');
    s >> pret;
    s.ignore(1, '|');
    s >> st;
    s.ignore(1, '|');
    getline(s, temp, '|');
    getline(s, this->clasa, '|');
    s >> this->rezolutie;
    s.ignore(1, '|');
    s >> this->fps;
}
string Camera::ToString()
{
    stringstream s("");
    s << "(" << Produs::getCod() << ") " << Produs::getProducator() << ", " << Produs::getDenumire() << ", " << Produs::getPret() << " lei, " << Produs::getStoc() << " in stoc, conexiune " << this->getConexiune() << ", clasa " << this->clasa << ", rezolutie " << this->rezolutie << "p, fps " << this->fps;
    return s.str();
}
string Camera::ToFile()
{
    stringstream s("");
    s << this->getTip() << "|" << Produs::getCod() << "|" << Produs::getProducator() << "|" << Produs::getDenumire() << "|" << Produs::getPret() << "|" << Produs::getStoc() << "|" << this->getConexiune() << "|" << this->clasa << "|" << this->rezolutie << "|" << this->fps<< "\n";
    return s.str();
}
int Camera::getTip()
{
    return 13;
}

string Camera::getClasa()
{
    return this->clasa;
}

int Camera::getRezolutie()
{
    return this->rezolutie;
}

float Camera::getFPS()
{
    return this->fps;
}

void Camera::setClasa(string clasa)
{
    this->clasa = clasa;
}

void Camera::setRezolutie(int rezolutie)
{
    this->rezolutie = rezolutie;
}

void Camera::setFPS(float fps)
{
    this->fps = fps;
}
Camera::~Camera()
{
    // Destructor
}