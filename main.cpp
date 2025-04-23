#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "include/linkedlist.hpp"

#include "include/produs.hpp"

#include "include/componente/component.hpp"
#include "include/componente/procesor.hpp"
#include "include/componente/memorie.hpp"
#include "include/componente/stocare.hpp"
#include "include/componente/placabaza.hpp"
#include "include/componente/placavideo.hpp"
#include "include/componente/alimentare.hpp"
#include "include/componente/carcasa.hpp"

#include "include/periferice/periferic.hpp"
#include "include/periferice/tastatura.hpp"
#include "include/periferice/mouse.hpp"
#include "include/periferice/audio.hpp"
#include "include/periferice/camera.hpp"
#include "include/periferice/display.hpp"
#include "include/periferice/portabila.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    LinkedList *head = new LinkedList("produse.txt");
    head->Remove("0000");
    // testare adaugare stocare portabila
    // Portabila *p1 = new Portabila("9000", "Samsung", "SSD 970 EVO", 500.0f, 10, "USB", "SSD", 500.0f, 3500.0f, 3000.0f);
    // head->Add(p1);
    cout << "Produse in lista:\n" << head->ToString() << endl;
    // test cautare
    cout << "Cautare produs cu codul:" << endl;
    string cod;
    cin >> cod;
    Produs *p = head->Search(cod);
    if (p != nullptr)
        cout << "Produs gasit: " << p->ToFile() << endl;

    else
        cout << "Produsul nu a fost gasit!" << endl;

    // test modificare
    // Memorie *m = (Memorie*)head->Search("1234");
    // m->setFrecventa(4123.0f);
    // cout << "Produse dupa modificare:" << endl
    //      << head->ToString() << endl;
    // head[0].getData()->setPret(1334.0f);
    // test stergere
    cout << "Stergere produs cu codul:" << endl;
    cin >> cod;
    if (head->Remove(cod))
        cout << "Produsul a fost sters!" << endl;
    else
        cout << "Produsul nu a fost gasit!" << endl;

    cout << "Produse dupa stergere:" << endl
         << head->ToString() << endl;
    cout << "Numar produse in lista: " << head->Size() << endl;
    // testare salvare
    head->SaveToFile("catalog.txt");
    return 0;
}
