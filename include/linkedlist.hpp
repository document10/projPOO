#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
#include "produs.hpp"

using namespace std;

class LinkedList
{
private:
    Produs *data;
    LinkedList *next;

public:
    LinkedList(Produs *data = nullptr);
    LinkedList(const LinkedList &l);
    LinkedList(string numeFisier);
    void Add(Produs *data);
    bool Remove(string cod);
    void Clear();
    void LoadFromFile(string numeFisier);
    void SaveToFile(string numeFisier);
    Produs *Search(string cod);
    string ToString();
    string ToFile();
    Produs Last();
    int Size();
    LinkedList *getNext();
    Produs *getData();
    LinkedList operator=(const LinkedList &l);
    LinkedList operator[](int index);
    ~LinkedList();
    static Produs *ReadItem(string linie);
};

#endif // LINKEDLIST_HPP