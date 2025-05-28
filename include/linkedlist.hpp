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
    LinkedList(Produs *data);
    LinkedList(const LinkedList &l);
    LinkedList(string numeFisier);
    ~LinkedList();
    void Add(Produs *data);
    bool Remove(string cod);
    void Clear();
    void LoadFromFile(string numeFisier);
    void SaveToFile(string numeFisier);
    Produs *Search(string cod,int criteriu=0);
    string ToString();
    string ToFile();
    Produs Last();
    int Size();
    LinkedList *getNext();
    Produs *getData();
    int getMaxLength();
    LinkedList operator=(const LinkedList &l);
    Produs *operator[](int index);
    void operator--(void);
    static Produs* ReadItem(string linie);
};

#endif // LINKEDLIST_HPP