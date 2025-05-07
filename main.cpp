//baza
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <filesystem>
#include <math.h>
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
    string numeFisier = "produse.txt";
    string statiiDir = "statii/";
    LinkedList *head = new LinkedList(numeFisier);
    head->Remove("0000");
    
    list<Statie> statii;
    for (const auto &entry : filesystem::directory_iterator(statiiDir))
    {
        string path = entry.path().string();
        if (path.find(".txt") != string::npos)
        {
            Statie sn(path);
            statii.push_front(sn);
        }
    }
    int screenWidth = 1500;
    int screenHeight = 750;
    int buttonWidth = head->getMaxLength() * 7;
    int opmode = 0;
    int lookmode = 0;
    int editmode = 0;
    int addmode = 0;
    int searchmode = 0;

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
    char buff0[100]="";
    char buff1[100]="";
    char buff2[100]="";
    char buff3[100]="";
    char buff4[100]="";
    
    bool active = false;
    bool active2 = false;
    bool active3 = false;
    bool active4 = false;
    
    Vector2 vectScroll = { 1000, 1000 };
    
    Rectangle rect = { 0, 0, 1000,static_cast<float>(screenHeight) };
    Rectangle bounds = { 0, 0, 1000, static_cast<float>(screenHeight) };
    Rectangle content = { 10, 10, static_cast<float>(buttonWidth+25), static_cast<float>(head->Size() * 30) };
    string selected = head->Last().getCod();

    InitWindow(screenWidth, screenHeight, "Manager Magazin PC");
    SetTargetFPS(60);
    SetExitKey(0);
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetWindowMinSize(screenWidth, screenHeight);
    GuiLoadStyle("genesis.rgs");
    SetWindowIcon(LoadImage("em1.png"));
    GuiSetStyle(BUTTON, TEXT_ALIGNMENT, 0);
    GuiSetStyle(DEFAULT, TEXT_PADDING, 0);
    GuiSetStyle(BUTTON,BORDER_WIDTH,1);
    GuiSetStyle(DROPDOWNBOX, TEXT_ALIGNMENT, 0);
    Vector2 winsize={static_cast<float>(screenWidth),static_cast<float>(screenHeight)};
    int *sel=new int(1);
    while (!WindowShouldClose())
    {
        winsize = (Vector2){static_cast<float>(GetRenderWidth()),static_cast<float>(GetRenderHeight())};
        BeginDrawing();
            rect.height = winsize.y;
            bounds.height = winsize.y;
            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR))); 
            string text = "#214#Produse in lista: " + to_string(head->Size());
            GuiScrollPanel(bounds, text.c_str(), content,&vectScroll , &rect);
            BeginScissorMode(0, 0, bounds.width-13, bounds.height-13);
                if(opmode==0){
                    optext="#96#Produse";
                    if(head->Size()==0)DrawText("fara produse",vectScroll.x,vectScroll.y+25,30,RED);
                    else for(int i = 0; i < head->Size(); i++)
                    {
                        string text = head->operator[](i)->ToString();
                        if (GuiButton((Rectangle){ vectScroll.x, 25+ vectScroll.y + i * 30, static_cast<float>(text.length()*7), 30 }, text.c_str()))selected = head->operator[](i)->getCod();
                    }
                }
                else {
                    optext = "#181#Statii";
                    int i = 0;
                    for (list<Statie>::iterator it = statii.begin();it!=statii.end();it++)
                    {
                        string txt = it->ToString();
                        DrawText(txt.c_str(),10,25+i*(it->getHead()->Size()+1)*20,10,WHITE);
                        i++;
                    }   
                    
                }
            EndScissorMode();
            if(GuiButton((Rectangle){925,0,75,25},optext.c_str()))opmode=!opmode;
            switch (lookmode)
            {
                case 0:
                    {
                        string text = head->Search(selected)->ToString();
                        replace(text.begin(),text.end(),',','\n');
                        DrawText(text.c_str(), rect.width+10, 50, 20, WHITE);
                        if (GuiButton((Rectangle){rect.width+125, 10, 70, 30 }, "#143#Sterge"))
                        {
                            head->Remove(selected);
                            cout<<"eliminat "<<selected<<"\n";
                            head->SaveToFile(numeFisier);
                            selected = head->Last().getCod();
                        }
                        if (GuiButton((Rectangle){rect.width+200, 10, 70, 30 }, "#22#Editare")){
                            lookmode=3;
                        }
                    }
                    break;
                case 1:
                    GuiTextBox((Rectangle){ rect.width+10, 45, winsize.x-1025, 30 }, buff1, 20, true);
                    if(GuiButton((Rectangle){ rect.width+240, 10, 100, 30 }, "#112#Confirma")&&strlen(buff1)>0)
                    {
                        Produs *p =nullptr;
                        if (buff1[0] != '\0')p = head->Search(string(buff1),searchmode);
                        if(p != nullptr)
                        {
                            selected = p->getCod();
                            cout << "Produs gasit: " << p->getCod() << endl;
                            strcpy(buff1,"");
                            lookmode=0;
                        }
                    }
                    if(GuiDropdownBox((Rectangle){ rect.width+125, 10, 110, 30 }, "#10#Cod\n#141#Producator\n#215#Denumire",&searchmode,active4))active4=!active4;
                break;
                case 2:
                    Produs *p;
                    p=nullptr;
                    GuiTextBox((Rectangle){ rect.width+10, 45, winsize.x-1025, 30 }, buff0, 20, true);
                    if(GuiButton((Rectangle){ rect.width+290, 10, 100, 30 }, "#112#Confirma")&&strlen(buff0)>2)
                    {
                        if(head->Search(string(buff0))==nullptr){
                            stringstream ss("");
                            ss<<addmode;
                            ss<<"|";
                            ss<<string(buff0);
                            ss<<"|0|0|0|0|0|0|0|0|0|0|0|0|0|0";
                            p=head->ReadItem(ss.str());
                            head->Add(p);
                            head->SaveToFile(numeFisier);
                            selected = string(buff0);
                            strcpy(buff0,"");
                            lookmode=3;
                            editmode=1;
                            content.height=static_cast<float>(head->Size() * 30);
                        }
                        else
                        {
                            strcpy(buff0,"#113#Codul exista deja");
                            break;
                        }
                    }
                    GuiLabel((Rectangle){ rect.width+10, 75, 200, 30 }, "#10#Introduceti codul produsului");
                    if(GuiDropdownBox((Rectangle){ rect.width+125, 10, 160, 30 }, "#10#Produs Generic\n#179#Component generic\n#144#Periferic generic\n#206#Procesor\n#207#Memorie\n#203#Stocare\n#194#Placa de baza\n#14#Placa video\n#145#Alimentare\n#102#Carcasa\n#176#Tastatura\n#21#Mouse\n#122#Sistem audio\n#184#Camera\n#181#Display\n#180#Stocare Portabila",&addmode,active3))active3=!active3;
                    break;
                case 3:
                    {
                        p=head->Search(selected);
                        GuiTextBox((Rectangle){ rect.width+10, 45, winsize.x-1025, 30},buff1,20,true);
                        if(GuiButton((Rectangle){ rect.width+280, 10, 100, 30},"#112#Confirma")&&strlen(buff1)>0){
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
                        GuiLabel((Rectangle){ rect.width+10, 70, 200, 30 }, "#23#Se editeaza:");
                        DrawText(text.c_str(), rect.width+10, 100, 20, BLUE);
                        if(GuiDropdownBox((Rectangle){ rect.width+125, 10, 150, 30 },editvals[p->getTip()].c_str(),&editmode,active2))active2=!active2;
                        break;
                    }
                case 4:{
                    GuiLabel((Rectangle){ rect.width+10, 50, 150, 30 }, "#06#Copie de siguranta");
                    GuiTextBox((Rectangle){ rect.width+10, 80, 200, 30 }, buff2, 20, true);
                    if(GuiButton((Rectangle){ rect.width+220, 80, 100, 30 }, "#112#Confirma")&&strlen(buff2)>0)
                    {
                        stringstream ss("");
                        ss<<buff2;
                        ss<<".txt";
                        head->SaveToFile(ss.str());
                        strcpy(buff2,"");
                    }
                    break;
                }
                default:
                    DrawText("Lipseste", rect.width+10, 100, 20, WHITE);
                    break;
            }
            if(GuiDropdownBox((Rectangle){rect.width+10,10,110,30}, "#21#Vizualizare\n#42#Cautare\n#08#Adaugare\n#22#Modificare\n#142#Setari",&lookmode,active)){
                active=!active;
                strcpy(buff0,"");
                strcpy(buff1,"");
            }
            
        EndDrawing();
    }

    CloseWindow();
    head->SaveToFile(numeFisier);
    return 0;
}
