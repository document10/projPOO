//librarii de baza
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <filesystem>
#include <math.h>
#include <ctime>

//mecanism stocare produse
#include "include/linkedlist.hpp"

//ierarhie date
#include "include/produs.hpp"

//componente
#include "include/componente/component.hpp"
#include "include/componente/procesor.hpp"
#include "include/componente/memorie.hpp"
#include "include/componente/stocare.hpp"
#include "include/componente/placabaza.hpp"
#include "include/componente/placavideo.hpp"
#include "include/componente/alimentare.hpp"
#include "include/componente/carcasa.hpp"

//periferice
#include "include/periferice/periferic.hpp"
#include "include/periferice/tastatura.hpp"
#include "include/periferice/mouse.hpp"
#include "include/periferice/audio.hpp"
#include "include/periferice/camera.hpp"
#include "include/periferice/display.hpp"
#include "include/periferice/portabila.hpp"

//statii
#include "include/statie.hpp"

//tratare erori
#include "include/exceptie.hpp"

//interfata grafica
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

using namespace std;

int main(int argc, char const *argv[])
{   
    clock_t start = clock();
    string numeFisier = "produse.txt";
    string statiiDir = "statii/";
    if(!filesystem::exists(numeFisier)){
        ofstream file(numeFisier);
        file.close();
    }
    LinkedList *head = new LinkedList(numeFisier);

    vector<Statie> statii;
    if (!filesystem::exists(statiiDir))
    {
        filesystem::create_directory(statiiDir);
    }
    if(!filesystem::is_empty(statiiDir))for (const auto &entry : filesystem::directory_iterator(statiiDir))
    {
        string path = entry.path().string();
        if (path.find(".txt") != string::npos)
        {
            Statie sn(path);
            statii.push_back(sn);
        }
    }
    else cout<<"Nu exista statii in folderul "<<statiiDir<<endl;
    cout<<"Timp incarcare: "<<(clock()-start)/static_cast<float>(CLOCKS_PER_SEC)<<" secunde"<<endl;
    int screenWidth = 1500;
    int screenHeight = 750;
    int buttonWidth = head->getMaxLength() * 7;
    int opmode = 0;
    int lookmode = 0;
    int editmode = 0;
    int addmode = 0;
    int searchmode = 0;
    int stmode = 0;
    int modmode = 0;
    int addst=statii.size();

    string editvals[16]={
        "#216#Cod\n#141#Producator\n#215#Denumire\n#146#Pret\n#96#Stoc",
        "#216#Cod\n#141#Producator\n#215#Denumire\n#146#Pret\n#96#Stoc\n#145#Putere",
        "#216#Cod\n#141#Producator\n#215#Denumire\n#146#Pret\n#96#Stoc\n#144#Conexiune",
        "#216#Cod\n#141#Producator\n#215#Denumire\n#146#Pret\n#96#Stoc\n#145#Putere\nFrecventa\nNuclee\nMaxMem\nMemCache",
        "#216#Cod\n#141#Producator\n#215#Denumire\n#146#Pret\n#96#Stoc\n#145#Putere\nFrecventa\nCapacitate\nTechnologie\nConector",
        "#216#Cod\n#141#Producator\n#215#Denumire\n#146#Pret\n#96#Stoc\n#145#Putere\nFrecventa\nCapacitate\nReadSpeed\nWriteSpeed\nIOPS\nTehnologie",
        "#216#Cod\n#141#Producator\n#215#Denumire\n#146#Pret\n#96#Stoc\n#145#Putere\nSocket\nChipset\nFormFactor\nConectori\nMaxMem\nMemSlots",
        "#216#Cod\n#141#Producator\n#215#Denumire\n#146#Pret\n#96#Stoc\n#145#Putere\nChipset\nConector\nUnits\nTops\nVRAM",
        "#216#Cod\n#141#Producator\n#215#Denumire\n#146#Pret\n#96#Stoc\n#145#Putere\nTip\nConectori\nEficienta",
        "#216#Cod\n#141#Producator\n#215#Denumire\n#146#Pret\n#96#Stoc\n#145#Putere\nMarime\nConectori\nDimensiune\nLumini",
        "#216#Cod\n#141#Producator\n#215#Denumire\n#146#Pret\n#96#Stoc\n#144#Conexiune\nFormat\nTaste\nIluminare",
        "#216#Cod\n#141#Producator\n#215#Denumire\n#146#Pret\n#96#Stoc\n#144#Conexiune\nSenzor\nIluminare\nDPI\nButoane",
        "#216#Cod\n#141#Producator\n#215#Denumire\n#146#Pret\n#96#Stoc\n#144#Conexiune\nOperare\nPutere\nCanale",
        "#216#Cod\n#141#Producator\n#215#Denumire\n#146#Pret\n#96#Stoc\n#144#Conexiune\nClasa\nRezolutie\nFPS",  
        "#216#Cod\n#141#Producator\n#215#Denumire\n#146#Pret\n#96#Stoc\n#144#Conexiune\nTehnologie\nRezolutie\nRefreshRate\nDiagonala",
        "#216#Cod\n#141#Producator\n#215#Denumire\n#146#Pret\n#96#Stoc\n#144#Conexiune\nTehnologie\nCapacitate\nReadSpeed\nWriteSpeed"
    };
    string optext = "";
    string scrolltext = "";
    string selected = head->Last().getCod();

    char buff0[100]="";
    char buff1[100]="";
    char buff2[100]="";
    
    bool active = false;
    bool active2 = false;
    bool active3 = false;
    bool active4 = false;
    bool active5 = false;
    bool active6 = false;
    bool active7 = false;

    Vector2 vectScroll = { 1000, 1000 };
    
    Rectangle rect = { 0, 0, 1000,static_cast<float>(screenHeight) };
    Rectangle bounds = { 0, 0, 1000, static_cast<float>(screenHeight) };
    Rectangle content = { 10, 10, static_cast<float>(buttonWidth), static_cast<float>(head->Size() * 30) };

    Statie selst("GOL",new Produs("0000","NEDEFINIT","NEDEFINIT",0,0));
    if(statii.size()>0)selst=statii.back();

    InitWindow(screenWidth, screenHeight, "Manager Magazin PC");
    SetTargetFPS(60);
    SetExitKey(0);
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetWindowMinSize(screenWidth, screenHeight);
    GuiLoadStyle("genesis.rgs");
    SetWindowIcon(LoadImage("icon.png"));
    GuiSetStyle(BUTTON, TEXT_ALIGNMENT, 0);
    GuiSetStyle(DEFAULT, TEXT_PADDING, 0);
    GuiSetStyle(BUTTON,BORDER_WIDTH,1);
    GuiSetStyle(DROPDOWNBOX, TEXT_ALIGNMENT, 0);
    Vector2 winsize={static_cast<float>(screenWidth),static_cast<float>(screenHeight)};
    cout<<"Timp deschidere: "<<(clock()-start)/static_cast<float>(CLOCKS_PER_SEC)<<" secunde"<<endl;
    while (!WindowShouldClose())
    {
        winsize = (Vector2){static_cast<float>(GetRenderWidth()),static_cast<float>(GetRenderHeight())};
        BeginDrawing();
            rect.height = winsize.y;
            bounds.height = winsize.y;
            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR))); 
            GuiScrollPanel(bounds, scrolltext.c_str(), content,&vectScroll , &rect);
            Vector2 mousePoint = GetMousePosition();
            BeginScissorMode(0, 0, bounds.width-13, bounds.height-13);
            if(!opmode){
                    scrolltext = "#214#Produse in lista: " + to_string(head->Size()-1);
                    content.height=static_cast<float>((head->Size())* 30);
                    optext="#96#Produse";
                    for(int i = 1; i < head->Size(); i++)
                    {
                        string text = head->operator[](i)->ToString();
                        if (selected == head->operator[](i)->getCod())text = "#44#"+text;
                        if (GuiButton((Rectangle){ vectScroll.x, 25+ vectScroll.y + (i-1) * 30, static_cast<float>(buttonWidth), 30 }, text.c_str())&&mousePoint.x<bounds.width)selected = head->operator[](i)->getCod();
                    }
                    if (GuiButton((Rectangle){ vectScroll.x, 25+ vectScroll.y + (head->Size()-1) * 30, static_cast<float>(buttonWidth), 30 }, "#08#Produs nou")&&mousePoint.x<bounds.width)lookmode=2;
                }
                else {
                    content.height=static_cast<float>((statii.size()+1)* 30);
                    optext = "#181#Statii";
                    scrolltext = "#214#Nr statii: " + to_string(statii.size());
                    int i = 0;
                    if(statii.size()==0)GuiLabel((Rectangle){bounds.width+10, 45, 200, 30}, "#113#Nu exista statii");
                    else for (vector<Statie>::iterator it = statii.begin();it!=statii.end();it++)
                    {
                        string txt = it->getNume()+" ("+it->getCod()+") pret total:"+to_string(it->PretTotal())+" lei";
                        if(GuiButton((Rectangle){ vectScroll.x, 25+ vectScroll.y + i * 30, static_cast<float>(buttonWidth), 30 }, txt.c_str())&&mousePoint.x<bounds.width)selst = *it;
                        i++;
                    }   
                    if(GuiButton((Rectangle){ vectScroll.x, 25+ vectScroll.y + i * 30, static_cast<float>(buttonWidth), 30 }, "#08#Adaugare statie")&&mousePoint.x<bounds.width)stmode=1;
                    
                }
            EndScissorMode();
            if(GuiButton((Rectangle){bounds.width-75,0,75,25},optext.c_str()))opmode=!opmode;
            if(!opmode){
                switch (lookmode)
                {
                    case 0:
                        {
                            string text = head->Search(selected)->ToString();
                            replace(text.begin(),text.end(),',','\n');
                            DrawText(text.c_str(), bounds.width+10, 50, 20, WHITE);
                            if (GuiButton((Rectangle){bounds.width+125, 10, 70, 30 }, "#143#Sterge"))
                            {
                                head->Remove(selected);
                                head->SaveToFile(numeFisier);
                                selected = head->Last().getCod();
                            }
                            if (GuiButton((Rectangle){bounds.width+200, 10, 70, 30 }, "#22#Editare")){
                                lookmode=3;
                            }
                        }
                        break;
                    case 1:
                        GuiTextBox((Rectangle){ bounds.width+10, 45, winsize.x-1025, 30 }, buff1, 20, true);
                        if(GuiButton((Rectangle){ bounds.width+240, 10, 100, 30 }, "#112#Confirma")&&strlen(buff1)>0)
                        {
                            Produs *p =nullptr;
                            if (buff1[0] != '\0')p = head->Search(string(buff1),searchmode);
                            if(p != nullptr)
                            {
                                selected = p->getCod();
                                strcpy(buff1,"");
                                lookmode=0;
                            }
                        }
                        if(GuiDropdownBox((Rectangle){ bounds.width+125, 10, 110, 30 }, "#10#Cod\n#141#Producator\n#215#Denumire",&searchmode,active4))active4=!active4;
                    break;
                    case 2:
                        Produs *p;
                        p=nullptr;
                        GuiTextBox((Rectangle){ bounds.width+10, 45, winsize.x-1025, 30 }, buff0, 20, true);
                        if(GuiButton((Rectangle){ bounds.width+290, 10, 100, 30 }, "#112#Confirma")&&strlen(buff0)>2)
                        {
                            if(head->Search(string(buff0))==nullptr){
                                stringstream ss("");
                                ss<<addmode<<"|"<<buff0<<"|0|0|0|0|0|0|0|0|0|0|0|0|0|0";
                                p=head->ReadItem(ss.str());
                                head->Add(p);
                                head->SaveToFile(numeFisier);
                                selected = string(buff0);
                                strcpy(buff0,"");
                                buttonWidth = head->getMaxLength() * 7;
                                content.width = static_cast<float>(buttonWidth);
                                lookmode=3;
                                editmode=1;
                            }
                            else
                            {
                                strcpy(buff0,"#113#Codul exista deja");
                                break;
                            }
                        }
                        GuiLabel((Rectangle){ bounds.width+10, 75, 200, 30 }, "#10#Introduceti codul produsului");
                        if(GuiDropdownBox((Rectangle){ bounds.width+125, 10, 160, 30 }, "#10#Produs Generic\n#179#Component generic\n#144#Periferic generic\n#206#Procesor\n#207#Memorie\n#203#Stocare\n#194#Placa de baza\n#14#Placa video\n#145#Alimentare\n#102#Carcasa\n#176#Tastatura\n#21#Mouse\n#122#Sistem audio\n#184#Camera\n#181#Display\n#180#Stocare Portabila",&addmode,active3))active3=!active3;
                        break;
                    case 3:
                        {
                            p=head->Search(selected);
                            GuiTextBox((Rectangle){ bounds.width+10, 45, winsize.x-1025, 30},buff1,20,true);
                            if(GuiButton((Rectangle){ bounds.width+280, 10, 100, 30},"#112#Confirma")&&strlen(buff1)>0){
                                if(editmode==0)
                                {
                                    if(head->Search(string(buff1))!=nullptr)
                                    {
                                        strcpy(buff1,"#113#Codul exista deja");
                                        break;
                                    }
                                }
                                try
                                {
                                    p->setVal(editmode,string(buff1));
                                    head->SaveToFile(numeFisier);
                                    editmode++;
                                    selected = p->getCod();
                                    strcpy(buff1,"");
                                }
                                catch(Exceptie &e)
                                {
                                    string err = "#113#"+e.getMesaj();
                                    strcpy(buff1,err.c_str());
                                    break;
                                }
                            }
                            string text = head->Search(selected)->ToString();
                            replace(text.begin(),text.end(),',','\n');
                            GuiLabel((Rectangle){ bounds.width+10, 100, 200, 30 }, "#23#Se editeaza:");
                            DrawText(text.c_str(), bounds.width+10, 130, 20, BLUE);
                            if(p->getStoc()>0){
                                GuiLabel((Rectangle){ bounds.width+10, 75, 200, 30 }, "#177#Adauga la statie:");
                                string allst="";
                                for (vector<Statie>::iterator it = statii.begin();it!=statii.end();it++)
                                {
                                    if(it->getHead()->Search(p->getCod())==nullptr)allst+=it->getNume()+" ("+it->getCod()+")\n";
                                }
                                allst+="Anuleaza";
                                if(GuiDropdownBox((Rectangle){ bounds.width+150, 75, 200, 30 },allst.c_str(),&addst,active5)){
                                    active5=!active5;
                                    if(!active5&&addst<static_cast<int>(statii.size())&&statii[addst].getHead()->Search(p->getCod())==nullptr){
                                        statii[addst].Add(p);
                                        statii[addst].SaveToFile(statiiDir+statii[addst].getCod()+".txt");
                                    }
                                }
                            }
                            if(GuiDropdownBox((Rectangle){ bounds.width+125, 10, 150, 30 },editvals[p->getTip()].c_str(),&editmode,active2))active2=!active2;
                            break;
                        }
                    case 4:{
                        GuiLabel((Rectangle){ bounds.width+10, 40, 150, 30 }, "#06#Copie de siguranta");
                        GuiTextBox((Rectangle){ bounds.width+150, 40, 220, 30 }, buff2, 20, true);
                        if(strlen(buff2)!=0){
                            if(GuiButton((Rectangle){ bounds.width+380, 40, 100, 30 }, "#112#Confirma")&&strlen(buff2)>0)
                            {
                                head->SaveToFile(string(buff2)+".txt");
                                strcpy(buff2,"");
                            }
                            if(GuiButton((Rectangle){ bounds.width+380, 80, 100, 30 }, "#189#Ca .csv")){
                                string text = head->ToFile();
                                ofstream file(string(buff2)+".csv");
                                replace(text.begin(),text.end(),',',';');
                                replace(text.begin(),text.end(),'|',',');
                                file<<text;
                                file.close();
                                strcpy(buff2,"");
                            }
                        }
                        break;
                    }
                    default:
                        DrawText("Lipseste", bounds.width+10, 100, 20, WHITE);
                        break;
                }
                if(GuiDropdownBox((Rectangle){bounds.width+10,10,110,30}, "#21#Vizualizare\n#42#Cautare\n#08#Adaugare\n#22#Modificare\n#142#Setari",&lookmode,active)){
                    active=!active;
                    strcpy(buff0,"");
                    strcpy(buff1,"");
                }
            }
            else{
                switch (stmode)
                {
                case 0:
                    if(GuiButton((Rectangle){bounds.width+125, 10, 70, 30 }, "#23#Editare"))stmode=2;
                    for(int i = 0; i < selst.getHead()->Size(); i++)
                    {
                        string text = selst.getHead()->operator[](i)->ToString();
                        DrawText(text.c_str(), bounds.width+10, 50 + i * 30, 20, WHITE);
                    }
                    break;
                case 1:
                    GuiTextBox((Rectangle){ bounds.width+10, 45, winsize.x-1025, 30 }, buff0, 20, true);
                    if(GuiButton((Rectangle){ bounds.width+125, 10, 100, 30 }, "#112#Confirma")&&strlen(buff0)>0)
                    {
                        int ok = 1;
                        for (vector<Statie>::iterator it = statii.begin();it!=statii.end();it++){
                            if(it->getCod()==string(buff0))ok=0;
                        }
                        if(ok){
                            Statie s(buff0, new LinkedList(new Produs("0000","fara","NEDEF",0.0f,0)),string(buff0));
                            statii.push_back(s);
                            selst = s;
                            strcpy(buff0,"");
                            s.SaveToFile(statiiDir+s.getCod()+".txt");
                            stmode=2;
                        }
                        else{
                            strcpy(buff0,"#113#Codul exista deja");
                            break;
                        }
                    }
                    break;
                case 2:
                {

                    GuiTextBox((Rectangle){ bounds.width+10, 45, winsize.x-1025, 30 }, buff0, 20, true);
                    string text = "Se editeaza:"+selst.ToString();
                    DrawText(text.c_str(), bounds.width+10, 75, 20, WHITE);
                    if(GuiButton((Rectangle){ bounds.width+280, 10, 80, 30 }, "#112#Confirma")&&strlen(buff0)>0)
                    {
                        switch (modmode)
                        {
                        case 0:
                        {
                            int index = 0;
                            for (vector<Statie>::iterator it = statii.begin();it!=statii.end();it++){
                                if(it->getCod()==selst.getCod())break;
                                index++;
                            }
                            statii[index].setNume(string(buff0));
                            selst.setNume(string(buff0));
                            statii[index].SaveToFile(statiiDir+selst.getCod()+".txt");
                            strcpy(buff0,"");
                            break;
                        }
                        case 1:
                        {
                            if(selst.getHead()->Size()>1){
                                selst.Remove(string(buff0));
                                selst.SaveToFile(statiiDir+selst.getCod()+".txt");
                                Produs *p = nullptr;
                                p = head->Search(string(buff0));
                                if(p != nullptr)
                                {
                                    p->setStoc(p->getStoc() + 1);
                                    head->SaveToFile(numeFisier);
                                }
                                strcpy(buff0,"");
                            }
                            else{
                                strcpy(buff0,"#113#Nu se poate sterge ultimul produs din statie");
                                break;
                            }
                            break;    
                        }
                        default:
                            break;
                        }
                    }
                    if(GuiDropdownBox((Rectangle){ bounds.width+125, 10, 150, 30 }, "#31#Editare nume\n#143#Stergere dupa cod", &modmode, active7))active7=!active7;
                    break;
                }
                default:
                    break;
                }
                if(GuiDropdownBox((Rectangle){ bounds.width+10, 10, 110, 30 }, "#181#Vizualizare\n#07#Adaugare\n#22#Editare", &stmode, active6)){
                    active6=!active6;
                    strcpy(buff0,"");
                    strcpy(buff1,"");
                }
            }
            
        EndDrawing();
    }
    start = clock();
    CloseWindow();
    
    head->Remove("0000");
    head->SaveToFile(numeFisier);
    for (vector<Statie>::iterator it = statii.begin();it!=statii.end();it++){
        it->SaveToFile(statiiDir+it->getCod()+".txt");
    }
    cout<<"Timp inchidere: "<<(clock()-start)/static_cast<float>(CLOCKS_PER_SEC)<<" secunde"<<endl;
    return 0;
}
