#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>


class Samochod
{
public:

	double cena;
	char* silnik;
	Samochod* nast;

	Samochod();
	Samochod(double cena, const char* silnik);
	Samochod(Samochod& src);
	~Samochod();
	double getCena();
	const char* getSilnik();
	void setCena(double cena);
	void setSilnik(const char* nazwa_silnika);
	virtual void wypisz();

private:

};

void Samochod::wypisz() {
	std::cout << "\n----------------------------------------------------" << std::endl;
	std::cout << "[Samochod]" << std::endl;
	std::cout << "Cena: " << cena << std::endl;
	std::cout << "Silnik: " << silnik << std::endl;
	std::cout << "----------------------------------------------------\n" << std::endl;
}

Samochod::Samochod(Samochod& src) {
	cena = src.cena;
	silnik = new char[strlen(src.silnik) + 1];
	strcpy(silnik, src.silnik);
	nast = nullptr;
}

Samochod::Samochod(double cena, const char* nazwa_silnika) {
	this->cena = cena;
	silnik = new char[strlen(nazwa_silnika) + 1];
	strcpy(silnik, nazwa_silnika);
	nast = nullptr;
}

Samochod::Samochod()
{
	cena = 0;
	silnik = new char[7];
	strcpy(silnik, "Silnik");
	nast = nullptr;
}

Samochod::~Samochod()
{
	delete nast;
}

double Samochod::getCena() {
	return cena;
}

const char* Samochod::getSilnik() {
	return silnik;
}

void Samochod::setCena(double cena) {
	this->cena = cena;
}

void Samochod::setSilnik(const char* nazwa_silnika){
	if (silnik != nullptr)
	{
		delete[] silnik;
	}
	silnik = new char[strlen(nazwa_silnika) + 1];
	strcpy(silnik, nazwa_silnika);
}

class Osobowy : public Samochod {
protected:
	double poj_bag;
	char typ_sylwetki;
public:
	Osobowy();
	Osobowy(Osobowy& src);
	Osobowy(double cena, const char* nazwa_silnika, double n, char sylwetka);
	char getSylwetka();
	double getPoj();
	void setSylwetka(char sylwetka);
	void setPoj(double pojemnosc);
	void wypisz();
};

Osobowy::Osobowy() : Samochod(), poj_bag(0), typ_sylwetki('H') {};

Osobowy::Osobowy(Osobowy& src) : Samochod(src), poj_bag(src.poj_bag), typ_sylwetki(src.typ_sylwetki) {};

Osobowy::Osobowy(double cena, const char* nazwa_silnika, double poj, char sylwetka) : Samochod(cena,nazwa_silnika), poj_bag(poj), typ_sylwetki(sylwetka) {};

void Osobowy::wypisz(){
	std::cout << "\n----------------------------------------------------" << std::endl;
	std::cout << "[Samochod (Osobowy)]" << std::endl;
	std::cout << "Cena: " << cena << std::endl;
	std::cout << "Silnik: " << silnik << std::endl;
	std::cout << "Pojemnosc bagaznika: " << poj_bag << std::endl;
	std::cout << "Typ sylwetki: " << (char)typ_sylwetki << std::endl;
	std::cout << "----------------------------------------------------\n" << std::endl;
}

char Osobowy::getSylwetka(){
	return typ_sylwetki;
}

double Osobowy::getPoj() {
	return poj_bag;
}

void Osobowy::setSylwetka(char sylwetka){
	typ_sylwetki = sylwetka;
}

void Osobowy::setPoj(double pojemnosc) {
	poj_bag = pojemnosc;
}

class Ciezarowy : public Samochod {
protected:
	double max_load;
	int liczba_kol;
public:
	Ciezarowy();
	Ciezarowy(Ciezarowy& src);
	Ciezarowy(double cena, const char* nazwa_silnika, double load, int kola);
	double getLoad();
	int getKola();
	void setLoad(double load);
	void setKola(int liczba_kol);
	void wypisz();
};

Ciezarowy::Ciezarowy() : Samochod(), max_load(0), liczba_kol(0) {};

Ciezarowy::Ciezarowy(Ciezarowy& src) : Samochod(src), max_load(src.max_load), liczba_kol(src.liczba_kol) {};

Ciezarowy::Ciezarowy(double cena, const char* nazwa_silnika, double load, int kola) : Samochod(cena, nazwa_silnika), max_load(load), liczba_kol(kola) {};

void Ciezarowy::wypisz() {
	std::cout << "\n----------------------------------------------------" << std::endl;
	std::cout << "[Samochod (Ciezarowy)]" << std::endl;
	std::cout << "Cena: " << cena << std::endl;
	std::cout << "Silnik: " << silnik << std::endl;
	std::cout << "Maks. ladownosc: " << max_load << std::endl;
	std::cout << "Ilosc kol: " << liczba_kol << std::endl;
	std::cout << "----------------------------------------------------\n" << std::endl;
}

double Ciezarowy::getLoad(){
	return max_load;
}

int Ciezarowy::getKola() {
	return liczba_kol;
}

void Ciezarowy::setLoad(double load) {
	max_load = load;
}

void Ciezarowy::setKola(int liczba_kol) {
	this->liczba_kol = liczba_kol;
}

void dodaj_obiekt(Samochod** pierwszy, Samochod* pojazd) {
	if (*pierwszy == nullptr)
	{
		*pierwszy = pojazd;
		return;
	}
	else
	{
		Samochod* aktualny = *pierwszy;
		while (aktualny->nast != nullptr)
		{
			aktualny = aktualny->nast;
		}
		aktualny->nast = pojazd;
	}
}

void wypisz_liste(Samochod* pierwszy) {
	Samochod* aktualny = pierwszy;
	int i = 1;
	while (aktualny != nullptr)
	{
		std::cout << "[" << i << "]" << std::endl;
		aktualny->wypisz();
		aktualny = aktualny->nast;
		i++;
	}
}

int main(){
	Samochod* pierwszy = nullptr;

	while (true)
	{
		char c;
		std::cout << "Jaki samochod chcesz utworzyc?" << std::endl;
		std::cout << "[o] - osobisty  [c] - ciezarowy  [q] - wyjscie" << std::endl;
		c = _getch();
		if (c == 'o')
		{
			double cena;
			char* nazwa_silnika = new char[20];
			double pojemnosc;
			char sylwetka;
			std::cout << "Tworzysz samochod osobowy: " << std::endl;
			std::cout << "Podaj cene samochodu: ";
			std::cin >> cena;
			std::cout << "Podaj pojemnosc bagaznika: ";
			std::cin >> pojemnosc;
			std::cout << "Podaj nazwe silnika: ";
			std::cin >> nazwa_silnika;
			std::cout << "Podaj sylwetke samochodu [\nH - Hatchback,\nS - Sedan,\nK - Kombi,\nV - Van\n]: ";
			std::cin >> sylwetka;
			Osobowy* osobisty = new Osobowy(cena, nazwa_silnika, pojemnosc, sylwetka);
			dodaj_obiekt(&pierwszy, osobisty);
			std::cout << "\nUtworzono obiekt i dodano do listy\n" << std::endl;
			delete[] nazwa_silnika;
		}
		else if (c == 'c')
		{
			std::cout << "Tworzysz samochod ciezarowy" << std::endl;
			double cena;
			char* nazwa_silnika = new char[20];
			double load;
			int kola;
			std::cout << "Podaj cene samochodu: ";
			std::cin >> cena;
			std::cout << "Podaj maks. ladunek: ";
			std::cin >> load;
			std::cout << "Podaj nazwe silnika: ";
			std::cin >> nazwa_silnika;
			std::cout << "Podaj liczbe kol pojazdu: ";
			std::cin >> kola;
			Ciezarowy *ciezarowka = new Ciezarowy(cena, nazwa_silnika, load, kola);
			dodaj_obiekt(&pierwszy, ciezarowka);
			std::cout << "\nUtworzono obiekt i dodano do listy\n" << std::endl;
			delete[] nazwa_silnika;
		}
		else if (c == 'q')
		{
			std::cout << "\n[*Zakonczono tworzenie listy*]\n" << std::endl;
			break;
		}
		else
		{
			std::cout << "[ERR!] Nieznany typ samochodu" << std::endl;
			continue;
		}
	}
	
	wypisz_liste(pierwszy);

	printf("\nKoniec programu\n");
	return 0;
}