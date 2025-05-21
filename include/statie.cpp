#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <filesystem>
#include "statie.hpp"

#include "produs.hpp"

#include "linkedlist.hpp"

#include "exceptie.hpp"

using namespace std;

Statie::Statie(string nume, LinkedList *head, string cod)
{
    this->nume = nume;
    this->head = head;
    this->cod = cod;
}

Statie::Statie(string nume, Produs *p)
{
    this->nume = nume;
    this->head = new LinkedList(p);
    this->cod = to_string(nume.size());
}

Statie::Statie(const Statie &s)
{
    this->nume = s.nume;
    this->head = new LinkedList(*s.head);
    this->cod = s.cod;
}

Statie::Statie(string numeFisier)
{
    this->LoadFromFile(numeFisier);
}

void Statie::Add(Produs *p)
{
    p->setStoc(p->getStoc() - 1);
    this->head->Add(p);
}

void Statie::Remove(string cod)
{
    this->head->Remove(cod);
}

float Statie::PretTotal()
{
    float total = 0.0f;
    LinkedList *current = this->head;
    while (current != nullptr)
    {
        total += current->getData()->getPret();
        current = current->getNext();
    }
    return total;
}
string Statie::ToString()
{
    return this->nume + "\n" + this->head->ToString();
}
string Statie::ToFile()
{
    stringstream ss("");
    ss << this->nume << "\n"
       << this->cod << "\n"
       << this->head->ToFile() << endl;
    return ss.str();
}
Statie::~Statie()
{
    // this->head->Clear();
}

string Statie::getNume()
{
    return this->nume;
}

string Statie::getCod()
{
    return this->cod;
}

LinkedList *Statie::getHead()
{
    return this->head;
}

void Statie::setNume(string nume)
{
    this->nume = nume;
}

void Statie::setCod(string cod)
{
    this->cod = cod;
}

void Statie::LoadFromFile(string numeFisier)
{
    this->head = new LinkedList(new Produs("0000", "NECUNOSCUT", "NEDENUMIT", 0.0f, 1));
    ifstream file(numeFisier);
    if (!file.is_open())
        throw Exceptie("Eroare la deschiderea fisierului " + numeFisier, "Statie::LoadFromFile", "Eroare fisier");
    if (file.peek() == file.eof())
    {
        this->nume = "gol";
        this->head = new LinkedList(new Produs("0000", "FARA", "NEDEFINIT", 0.0f, 0));
    }
    else
    {
        string line;
        getline(file, line);
        this->nume = line;
        getline(file, line);
        this->cod=line;
        while (getline(file, line))
        {
            Produs *p = this->head->ReadItem(line);
            if (p != nullptr)
                this->head->Add(p);
        }
        this->head->Remove("0000");
        file.close();
    }
}

void Statie::SaveToFile(string numeFisier)
{
    ofstream file(numeFisier);
    if (file.is_open())
    {
        file << this->ToFile();
        file.close();
    }
    else
        throw Exceptie("Eroare la deschiderea fisierului " + numeFisier, "Statie::SaveToFile", "Eroare fisier");
}

void Statie::operator--(void)
{
    this->head->operator--();
}