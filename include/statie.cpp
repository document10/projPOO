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

Statie::Statie(string nume, LinkedList *head)
{
    this->nume = nume;
    this->head = head;
}

Statie::Statie(const Statie &s)
{
    this->nume = s.nume;
    this->head = new LinkedList(*s.head);
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
    return this->head->ToString();
}
string Statie::ToFile()
{
    stringstream ss("");
    ss << this->nume << "\n" << this->head->ToFile() << endl;
    return ss.str();
}
Statie::~Statie()
{
    delete this->head;
}

string Statie::getNume()
{
    return this->nume;
}

LinkedList *Statie::getHead()
{
    return this->head;
}

void Statie::setNume(string nume)
{
    this->nume = nume;
}

void Statie::LoadFromFile(string numeFisier)
{
    this->head = new LinkedList(new Produs("0000", "NECUNOSCUT", "NEDENUMIT", 0.0f, 1));
    ifstream file(numeFisier);
    if (!file.is_open())
        throw Exceptie("Eroare la deschiderea fisierului " + numeFisier, "Statie::LoadFromFile", "Eroare fisier");
    string line;
    getline(file, line);
    this->nume = line;
    while(getline(file, line)){
        Produs *p = this->head->ReadItem(line);
        if (p != nullptr)
            this->head->Add(p);
    }
    this->head->Remove("0000");
    file.close();
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

int Statie::Import(Statie *s[], string numeFolder)
{
    // Verificam daca folderul exista
    if (!filesystem::exists(numeFolder))
        throw Exceptie("Folderul " + numeFolder + " nu exista!", "Statie::Import", "Eroare folder");
    
    // Verificam daca este un folder
    if (!filesystem::is_directory(numeFolder))
        throw Exceptie("Calea " + numeFolder + " nu este un folder!", "Statie::Import", "Eroare folder");
    // Verificam daca folderul este gol
    if (filesystem::is_empty(numeFolder))
        throw Exceptie("Folderul " + numeFolder + " este gol!", "Statie::Import", "Eroare folder");
    
    int i=0;
    for (const auto &entry : filesystem::directory_iterator(numeFolder))
    {
        string path = entry.path().string();
        if (path.find(".txt") != string::npos)
        {
            s[i] = new Statie(path);
            i++;
        }
    }
    return i;
}

void Statie::Export(Statie *s[], int n, string numeFolder)
{
    // Verificam daca folderul exista
    if (!filesystem::exists(numeFolder))
        throw Exceptie("Folderul " + numeFolder + " nu exista!", "Statie::Export", "Eroare folder");
    
    // Verificam daca este un folder
    if (!filesystem::is_directory(numeFolder))
        throw Exceptie("Calea " + numeFolder + " nu este un folder!", "Statie::Export", "Eroare folder");
    
    for (int i = 0; i < n; i++)
    {
        string path = numeFolder + "/" + s[i]->getNume() + ".txt";
        s[i]->SaveToFile(path);
    }
}