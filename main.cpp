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

#include "include/statie.hpp"

#include "include/exceptie.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    LinkedList *head = new LinkedList("produse.txt");
    head->Remove("0000");
    cout << "Produse in lista:\n" << head->ToString() << endl;
    cout << "Numar produse in lista: " << head->Size() << endl;
    Statie *s[1000];
    int n;
    if(argc < 3) {
        cerr << "Argumente insuficiente!" << endl;
        return 1;
    }
    //testare import
    try
    {
        n = Statie::Import(s, argv[1]);
    }
    catch(const Exceptie &e)
    {
        cerr << e << '\n';
        exit(1);
    }
    catch (const exception &e)
    {
        cerr << "Standard exception: " << e.what() << '\n';
        exit(1);
    }
    catch (...)
    {
        cerr << "Unknown exception occurred." << '\n';
        exit(1);
    }
    cout << "Numar statii importate: " << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Statie " << i + 1 << ": " << s[i]->getNume() << endl;
        cout << "Produse in statie:\n" << s[i]->ToString() << endl;
        cout << "Numar produse in lista: " << s[i]->getHead()->Size() << endl;
        cout << "Pret total: " << s[i]->PretTotal() << endl;
    }

    // testare export
    try{
        Statie::Export(s, n, argv[2]);
    }
    catch(const Exceptie &e)
    {
        cerr << e << '\n';
        exit(1);
    }
    catch (const exception &e)
    {
        cerr << "Standard exception: " << e.what() << '\n';
        exit(1);
    }
    catch (...)
    {
        cerr << "Unknown exception occurred." << '\n';
        exit(1);
    }
    return 0;
}
