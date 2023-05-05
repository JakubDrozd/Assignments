#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;




class MojaKlasa {
    char** email;
    int ile;
public:
    MojaKlasa(int x);
    MojaKlasa(MojaKlasa& mk);	// konstruktor kopiujący

    void setemail(const char* adres, int idx) { 
        strcpy(email[idx], adres); 
    }

    const char* getemail(int idx) {
        if (email[idx] != nullptr)
        {
            return email[idx];
        }
        return "";
    }

    MojaKlasa* nast = nullptr;

    int getCount(){
        return ile;
    }
};
MojaKlasa::MojaKlasa(int x) {
    email = new char* [ile = x];
    for (int i = 0; i < ile; i++) { 
        email[i] = new char[100];
    }
}




MojaKlasa::MojaKlasa(MojaKlasa& mk) {
    email = new char*[mk.ile];
    ile = mk.ile;
    for (int i=0;i<ile;i++) {
        email[i] = new char[100];
        strcpy(email[i],mk.email[i]);
    }
}

class Wykladowca {
private:
    MojaKlasa* pierwszy = nullptr;              //Na początku chcemy aby przy tworzeniu obiektu lista była pusta
public:
    Wykladowca() : pierwszy(nullptr) {};        // To co wyżej
    Wykladowca(const char* nazwa_pliku);        //Konstruktor do tworzenia obiektów z podaniem pliku grupy
    Wykladowca(Wykladowca& wsk_wykl);           //Konstruktor do kopiowania grup innych wykładowców
    ~Wykladowca();
    void dodaj_klase(const char* nazwa_pliku);
    void wypisz();
};

Wykladowca::Wykladowca(const char* nazwa_pliku){
    MojaKlasa* moja_klasa = new MojaKlasa(10);      //Tworze nowy objekt dynamiczny MojaKlasa, ktory bedzie przechowywal email'e uczniow z grupy
    FILE* input;                                    //Liczba w srodku konstruktora to liczba emaili, jaka ma przechowywac, ja przyjalem max 10 maili                                                  na grupe
    fopen_s(&input, nazwa_pliku, "r");
    char email[100];
    int i = 0;
    if (input != 0)
    {
        while (fscanf_s(input, "%s", email, (unsigned)sizeof(email)) == 1)      //Klasyczne wczytywanie danych z pliku do listy dynamicznej
        {
            moja_klasa->setemail(email, i);
            i++;
        }
    }
    if (pierwszy == nullptr)       //Jeżeli to pierwsza grupa wykloadowcy od uruchomienia programu, to ustawiamy jako głowa listy
    {
        pierwszy = moja_klasa;
    }
    else
    {
        MojaKlasa* aktualny = pierwszy;
        while (aktualny->nast != nullptr)           //Jeżeli nie pierwsza grupa, to jedziemy po liście i dodajemy grupę na sam koniec listy
        {
            aktualny = aktualny->nast;
        }
        aktualny->nast = moja_klasa;
    }
    fclose(input);
}

Wykladowca::Wykladowca(Wykladowca& wsk_wykl){
    if (wsk_wykl.pierwszy != nullptr)
    {
        pierwszy = new MojaKlasa(*(wsk_wykl.pierwszy));         //Kopiuje pierwszy element listy dynamicznej z obiektu źródłowego
        MojaKlasa* src = wsk_wykl.pierwszy->nast;
        MojaKlasa* dest = pierwszy;
        while (src != nullptr)
        {
            dest->nast = new MojaKlasa(*src);                   //Kopiuje całą listę dynamiczną z obiektu źródłowego
            dest = dest->nast;
            src = src->nast;
        }
    }
    else
    {
        pierwszy = nullptr;
    }
}

Wykladowca::~Wykladowca(){                      //Dekonstruktor, przed usunieciem obiektu usuwamy po kolei kazdy element zawarty w liscie
    MojaKlasa* aktualny = pierwszy;
    while (aktualny != nullptr)
    {
        MojaKlasa* temp = aktualny;
        aktualny = aktualny->nast;
        delete temp;
    }
    pierwszy = nullptr;                     //Po wyczyscieniu listy ustawiam wskaznik pierwszego elementu na null
}

void Wykladowca::dodaj_klase(const char* nazwa_pliku) {
    MojaKlasa* moja_klasa = new MojaKlasa(30);
    FILE* input;
    fopen_s(&input, nazwa_pliku, "r");
    if (input != 0)
    {
        char email[100];
        int i = 0;
        while (fscanf_s(input, "%s", email, (unsigned)sizeof(email)) == 1)      //Klasyczne wczytywanie danych z pliku
        {
            moja_klasa->setemail(email, i);
            i++;
        }
    }
    if (pierwszy == nullptr)
    {
        pierwszy = moja_klasa;
        return;
    }
    MojaKlasa* aktualny = pierwszy;
    while (aktualny->nast != nullptr)
    {
        aktualny = aktualny->nast;
    }
    aktualny->nast = moja_klasa;
}

void Wykladowca::wypisz() {
    MojaKlasa* aktualny = pierwszy;
    int k = 1;
    while (aktualny != nullptr)                                     //Wypisywanie maili, przesuwanie sie po liscie to przesuwanie sie po grupach
    {
        std::cout << "\nGrupa " << k << ":" << std::endl;
        int ile = aktualny->getCount();
        for (int i = 0; i < ile; i++)                               //Przesuwanie sie po tablicy to przesuwanie sie po mailach uczniow
        {
            const char* email = aktualny->getemail(i);
            size_t length = strlen(email) + 1;
            if (email != nullptr && length < 99)
            {
                std::cout << email << std::endl;
            }
        }
        k++;
        aktualny = aktualny->nast;
    }
    std::cout << "----------------------" << std::endl;
}

int main() {
    std::cout << "\nWykladowca 1: " << std::endl;
    Wykladowca* wykl1 = new Wykladowca();               //Tworzenie wykladowcy 1 z poczatkowa lista pusta
    wykl1->dodaj_klase("grupa1.txt");                   //I dodanie do niego Grupy 1
    wykl1->wypisz();    

    std::cout << "\nWykladowca 2: " << std::endl;
    Wykladowca* wykl2 = new Wykladowca(*wykl1);         //Tworzenie wykladowcy 2 jako kopia wykladowcy 1 + dodanie do niego Grupy 2
    wykl2->dodaj_klase("grupa2.txt");                   //Czyli Wykladowca 2 = Wykladowca 1 + Grupa 2
    wykl2->wypisz();

    std::cout << "\nWykladowca 3: " << std::endl;       //Tworzenie wykladowcy 3 jako kopia wykladowcy 2 (ktory jest kopia wykladowcy 1) + dodanie                                                       Grupy 3
    Wykladowca* wykl3 = new Wykladowca(*wykl2);
    wykl3->dodaj_klase("grupa3.txt");                   //Czyli Wykladowca 3 = Wykladowca 1 + Wykladowca 2 + Grupa 3
    wykl3->wypisz();

    std::cout << "\nWykladowca 4: " << std::endl;        //Tworzenie wykladowcy 4 od razu wczytujac plik z jego Grupą 4
    Wykladowca* wykl4 = new Wykladowca("grupa4.txt");
    wykl4->wypisz();

    delete wykl1;
    delete wykl2;
    delete wykl3;
    delete wykl4;
}