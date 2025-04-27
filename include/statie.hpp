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
    string nume;

public:
    Statie(string nume, LinkedList *head);
    Statie(const Statie &s);
    Statie(string numeFisier);
    void Add(Produs *p);
    void Remove(string cod);
    float PretTotal();
    string ToString();
    string ToFile();
    ~Statie();
    string getNume();
    LinkedList *getHead();
    void setNume(string nume);
    void LoadFromFile(string numeFisier);
    void SaveToFile(string numeFisier);
    static int Import(Statie *s[], string numeFolder);
    static void Export(Statie *s[], int n, string numeFolder);
};

#endif //STATIE_HPP
