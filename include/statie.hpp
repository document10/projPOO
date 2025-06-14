#ifndef STATIE_HPP
#define STATIE_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "produs.hpp"
#include "linkedlist.hpp"

using namespace std;

class Statie {
private:
    LinkedList *head;
    string nume,cod;

public:
    Statie(string nume, LinkedList *head,string cod);
    Statie(string nume, Produs *p);
    Statie(const Statie &s);
    Statie(string numeFisier);
    ~Statie();
    void Add(Produs *p);
    void Remove(string cod);
    float PretTotal();
    string ToString();
    string ToFile();
    string getNume();
    string getCod();
    LinkedList *getHead();
    void setNume(string nume);
    void setCod(string cod);
    void LoadFromFile(string numeFisier);
    void SaveToFile(string numeFisier);
    void operator--(void);
};

#endif //STATIE_HPP
