#include <iostream>
#include <stdlib.h>
#include <cstring>
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
#include "periferice/mouse.hpp"
#include "periferice/audio.hpp"
#include "periferice/camera.hpp"
#include "periferice/display.hpp"
#include "periferice/portabila.hpp"

#include "exceptie.hpp"

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
            this->Add(p);
        }
        file.close();
    }
    else
        throw Exceptie("Eroare la deschiderea fisierului " + numeFisier, "LinkedList::LoadFromFile", "Eroare fisier");
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
        throw Exceptie("Eroare la deschiderea fisierului " + numeFisier, "LinkedList::SaveToFile", "Eroare fisier");
}

LinkedList::~LinkedList()
{
    
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

    if (current == nullptr)
        return false; // Codul nu a fost gasit

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

Produs *LinkedList::Search(string cod, int criteriu)
{
    LinkedList *current = this;
    string search = "";
    while (current != nullptr)
    {
        switch (criteriu)
        {
        case 0:
            search = current->data->getCod();
            break;
        case 1:
            search = current->data->getProducator();
            break;
        case 2:
            search = current->data->getDenumire();
            break;
        default:
            throw Exceptie("Criteriu de cautare invalid", "LinkedList::Search", "Eroare criteriu");
            break;
        }
        // Convertim ambele stringuri la litere mici pentru comparatie
        for (int i = 0; i < static_cast<int>(search.length()); i++)
        {
            search[i] = tolower(search[i]);
        }
        for (int i = 0; i < static_cast<int>(cod.length()); i++)
            cod[i] = tolower(cod[i]);

        if (strstr(search.c_str(), cod.c_str()) != nullptr || cod == search)
            return current->data;

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

int LinkedList::getMaxLength()
{
    int maxLength = 0;
    LinkedList *current = this;
    while (current != nullptr)
    {
        int length = current->data->ToString().length();
        if (length > maxLength)
            maxLength = length;
        current = current->next;
    }
    return maxLength;
}

LinkedList LinkedList::operator=(const LinkedList &l)
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

Produs *LinkedList::operator[](int index)
{
    LinkedList *current = this;
    for (int i = 0; i < index && current != nullptr; i++)
    {
        current = current->next;
    }
    return &(*current->data);
}

void LinkedList::operator--(void)
{
    if (this->next == nullptr)
        return;
    LinkedList *current = this;
    while (current->next->next != nullptr)
        current = current->next;
    delete current->next;
    current->next = nullptr;
}

Produs *LinkedList::ReadItem(string linie)
{
    int i;
    if (linie.empty())
        return nullptr;
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
    case 11:
        return new Mouse(linie);
        break;
    case 12:
        return new Audio(linie);
        break;
    case 13:
        return new Cam(linie);
        break;
    case 14:
        return new Display(linie);
        break;
    case 15:
        return new Portabila(linie);
        break;
    default:
        return nullptr;
        break;
    }
}
