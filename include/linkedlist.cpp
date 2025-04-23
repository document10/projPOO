#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "linkedlist.hpp"

#include "produs.hpp"

#include "componente/component.hpp"
#include "componente/procesor.hpp"
#include "componente/memorie.hpp"
#include "componente/stocare.hpp"
#include "componente/placabaza.hpp"
#include "componente/placavideo.hpp"
#include "componente/alimentare.hpp"
#include "componente/carcasa.hpp"

#include "periferice/periferic.hpp"
#include "periferice/tastatura.hpp"

using namespace std;

LinkedList::LinkedList(Produs *data)
{
    this->data = data;
    this->next = nullptr;
}

LinkedList::LinkedList(const LinkedList &l)
{
    this->data = new Produs(*l.data);
    this->next = l.next ? new LinkedList(*l.next) : nullptr;
}

LinkedList::LinkedList(string numeFisier)
{
    this->data = new Produs("0000", "NECUNOSCUT", "NEDENUMIT", 0.0f, 1);
    this->next = nullptr;
    LoadFromFile(numeFisier);
}
void LinkedList::LoadFromFile(string numeFisier)
{
    ifstream file(numeFisier);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            Produs *p = ReadItem(line);
            // Adaugam produsul in lista
            this->Add(p);
        }
        file.close();
    }
}
void LinkedList::SaveToFile(string numeFisier)
{
    ofstream file(numeFisier);
    if (file.is_open())
    {
        file << ToFile();
        file.close();
    }
    else
    {
        cout << "Eroare la deschiderea fisierului!" << endl;
    }
}

LinkedList::~LinkedList()
{
    //nu dealocam nimic
}

void LinkedList::Add(Produs *data)
{
    LinkedList *newNode = new LinkedList(data);
    LinkedList *current = this;
    
    while (current->next != nullptr)
    {
        current = current->next;
    }
    newNode->next = nullptr;
    current->next = newNode;
}

bool LinkedList::Remove(string cod)
{
    LinkedList *current = this;
    LinkedList *previous = nullptr;
    
    while (current != nullptr && current->data->getCod() != cod)
    {
        previous = current;
        current = current->next;
    }
    
    if (current == nullptr) return false; // Codul nu a fost gasit
    
    if (previous == nullptr)
    {
        // Elementul de sters este primul
        this->data = current->next->data;
        LinkedList *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
    else
    {
        previous->next = current->next;
        delete current;
    }
    return true; // Elementul a fost sters
}

void LinkedList::Clear()
{
    LinkedList *current = this;
    LinkedList *nextNode;
    
    while (current != nullptr)
    {
        nextNode = current->next;
        delete current->data;
        delete current;
        current = nextNode;
    }
}

Produs *LinkedList::Search(string cod)
{
    LinkedList *current = this;
    while (current != nullptr)
    {
        if (current->data->getCod() == cod)
        {
            return current->data;
        }
        current = current->next;
    }
    return nullptr;
}   

string LinkedList::ToString()
{
    string result;
    LinkedList *current = this;
    while (current != nullptr)
    {
        result += current->data->ToString() + "\n";
        current = current->next;
    }
    return result;
}

string LinkedList::ToFile()
{
    string result;
    LinkedList *current = this;
    while (current != nullptr)
    {
        result += current->data->ToFile();
        current = current->next;
    }
    return result;
}

Produs LinkedList::Last()
{
    LinkedList *current = this;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    return *current->data;
}

int LinkedList::Size()
{
    int size = 0;
    LinkedList *current = this;
    while (current != nullptr)
    {
        size++;
        current = current->next;
    }
    return size;
}

LinkedList *LinkedList::getNext()
{
    return this->next;
}

Produs *LinkedList::getData()
{
    return this->data;
}

LinkedList LinkedList::operator =(const LinkedList &l)
{
    if (this != &l)
    {
        delete this->data;
        delete this->next;

        this->data = new Produs(*l.data);
        this->next = l.next ? new LinkedList(*l.next) : nullptr;
    }
    return *this;
}

LinkedList LinkedList::operator [](int index)
{
    LinkedList *current = this;
    for (int i = 0; i < index && current != nullptr; i++)
    {
        current = current->next;
    }
    return *current;
}

Produs *LinkedList::ReadItem(string linie)
{
    int i;
    float pret;
    sscanf(linie.c_str(), "%i|", &i);
    switch (i)
    {
    case 0:
        return new Produs(linie);
        break;
    case 1:
        return new Component(linie);
        break;
    case 2:
        return new Periferic(linie);
        break;
    case 3:
        return new Procesor(linie);
        break;
    case 4:
        return new Memorie(linie);
        break;
    case 5:
        return new Stocare(linie);
        break;
    case 6:
        return new PlacaBaza(linie);
        break;
    case 7:
        return new PlacaVideo(linie);
        break;
    case 8:
        return new Alimentare(linie);
        break;
    case 9:
        return new Carcasa(linie);
        break;
    case 10:
        return new Tastatura(linie);
        break;
    default:
        return nullptr;
        break;
    }
}