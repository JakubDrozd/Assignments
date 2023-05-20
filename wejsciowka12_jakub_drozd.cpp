#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include <conio.h>

class Osoba {
public:

	char* imie;
	char* nazwisko;
	char* email;
	Osoba* nast;

	Osoba();
	Osoba(Osoba& src);
	Osoba(const char* a_imie, const char* a_nazwisko, const char* a_email);
	~Osoba();
	const char* getImie();
	const char* getNazwisko();
	const char* getEmail();
	void setImie(const char* imie);
	void setNazwisko(const char* nazwisko);
	void setEmail(const char* email);
	virtual void wypisz();
	void operator += (Osoba& src) {
		char* temp = new char[(sizeof(*imie) + sizeof((*src.imie))) + 2];
		strcpy(temp, strcat(imie, " "));
		strcpy(temp, strcat(imie, src.imie));
		strcpy(imie, temp);
		char* temp2 = new char[(sizeof(*nazwisko) + sizeof((*src.imie))) + 2];
		strcpy(temp, strcat(nazwisko, " "));
		strcpy(temp, strcat(nazwisko, src.nazwisko));
		strcpy(nazwisko, temp);
	}

private:

};

Osoba::Osoba(const char* a_imie, const char* a_nazwisko, const char* a_email) {
	imie = new char[strlen(a_imie) + 1];
	nazwisko = new char[strlen(a_nazwisko) + 1];
	email = new char[strlen(a_email) + 1];
	strcpy(imie, a_imie);
	strcpy(nazwisko, a_nazwisko);
	strcpy(email, a_email);
	nast = nullptr;
}

Osoba::Osoba(Osoba& src) {
	imie = new char[strlen(src.imie) + 1];
	nazwisko = new char[strlen(src.nazwisko) + 1];
	email = new char[strlen(src.email) + 1];
	strcpy(imie, src.imie);
	strcpy(nazwisko, src.nazwisko);
	strcpy(email, src.email);
	nast = nullptr;
}

void Osoba::wypisz() {
	std::cout << "\n----------------------------------------------------" << std::endl;
	std::cout << "[Osoba]" << std::endl;
	std::cout << "Imie: " << imie << std::endl;
	std::cout << "Nazwisko: " << nazwisko << std::endl;
	std::cout << "E-mail: " << email << std::endl;
	std::cout << "----------------------------------------------------\n" << std::endl;
}

Osoba::Osoba()
{
	imie = new char[strlen("Jan") + 1];
	nazwisko = new char[strlen("Kowalski") + 1];
	email = new char[strlen("jankowalski@gmail.com") + 1];
	strcpy(imie, "Jan");
	strcpy(nazwisko, "Kowalski");
	strcpy(email, "jankowalski@gmail.com");
	nast = nullptr;
}

Osoba::~Osoba()
{
	delete nast;
}

const char* Osoba::getImie() {
	return imie;
}

const char* Osoba::getNazwisko() {
	return nazwisko;
}

const char* Osoba::getEmail() {
	return email;
}

void Osoba::setImie(const char* a_imie) {
	if (imie != nullptr)
	{
		delete[] imie;
	}
	imie = new char[strlen(a_imie) + 1];
	strcpy(imie, a_imie);
}

void Osoba::setNazwisko(const char* a_nazwisko) {
	if (nazwisko != nullptr)
	{
		delete[] nazwisko;
	}
	nazwisko = new char[strlen(a_nazwisko) + 1];
	strcpy(nazwisko, a_nazwisko);
}

void Osoba::setEmail(const char* a_email) {
	if (email != nullptr)
	{
		delete[] email;
	}
	email = new char[strlen(a_email) + 1];
	strcpy(email, a_email);
}

void dodaj_osobe(Osoba** pierwszy, Osoba* osoba) {
	if (*pierwszy == nullptr)
	{
		*pierwszy = osoba;
		return;
	}
	Osoba* aktualny = *pierwszy;
	while (aktualny->nast != nullptr)
	{
		aktualny = aktualny->nast;
	}
	aktualny->nast = osoba;
}

void wypisz_osoby(Osoba* pierwszy) {
	Osoba* aktualny = pierwszy;
	while (aktualny != nullptr)
	{
		aktualny->wypisz();
		aktualny = aktualny->nast;
	}
}

class Student : public Osoba {
public:
	int nr_indeksu;
	int rok_rozpoczecia;
	int get_Indeks() {
		return nr_indeksu;
	}
	int get_Rozpoczecie() {
		return rok_rozpoczecia;
	}
	void set_Indeks(int indeks) {
		nr_indeksu = indeks;
	}
	void set_Rozpoczecie(int rok) {
		rok_rozpoczecia = rok;
	}
	void wypisz() {
		std::cout << "\n----------------------------------------------------" << std::endl;
		std::cout << "[Student]" << std::endl;
		std::cout << "Imie: " << imie << std::endl;
		std::cout << "Nazwisko: " << nazwisko << std::endl;
		std::cout << "Numer indeksu: " << nr_indeksu << std::endl;
		std::cout << "Rok rozpoczecia: " << rok_rozpoczecia << std::endl;
		std::cout << "E-mail: " << email << std::endl;
		std::cout << "----------------------------------------------------\n" << std::endl;
	}
	Student() : Osoba(), nr_indeksu(0), rok_rozpoczecia(2000) {};
	Student(Student& src) : Osoba(src) {
		nr_indeksu = src.nr_indeksu;
		rok_rozpoczecia = src.rok_rozpoczecia;
	}
	Student(const char* a_imie, const char* a_nazwisko, const char* a_email, int indeks, int rok) : Osoba(a_imie, a_nazwisko, a_email), nr_indeksu(indeks), rok_rozpoczecia(rok) {};
};

class Pracownik : public Osoba {
public:
	int ile_magistrantow;
	char lista_przedmiotow[10][7];

	Pracownik(const char* a_imie, const char* a_nazwisko, const char* a_email, int magi) : Osoba(a_imie, a_nazwisko, a_email), ile_magistrantow(magi) {
		memset(lista_przedmiotow, 0, sizeof(lista_przedmiotow));
	}

	Pracownik() : Osoba(), ile_magistrantow(1) {
		for (int i = 0; i < 10; i++)
		{
			strcpy(lista_przedmiotow[i], "ABCDEF");
		}
	};

	Pracownik(Pracownik& src) : Osoba(src) {
		ile_magistrantow = src.ile_magistrantow;
		for (int i = 0; i < 10; i++)
		{
			strcpy(lista_przedmiotow[i], src.lista_przedmiotow[i]);
		}
	};

	void wypisz() {
		std::cout << "\n----------------------------------------------------" << std::endl;
		std::cout << "[Pracownik]" << std::endl;
		std::cout << "Imie: " << imie << std::endl;
		std::cout << "Nazwisko: " << nazwisko << std::endl;
		std::cout << "Ile magistrow: " << ile_magistrantow << std::endl;
		std::cout << "E-mail: " << email << std::endl;
		std::cout << "Lista przedmiotow:\n";
		for (int i = 0; i < 10; i++)
		{
			std::cout << "[" << i + 1 << "]: ";
			std::cout << lista_przedmiotow[i] << std::endl;
		}
		std::cout << "----------------------------------------------------\n" << std::endl;
	}

	void set_magi(int magi) {
		ile_magistrantow = magi;
	}

	void set_Przedmioty(char tab[10][7]) {
		for (int i = 0; i < 10; i++)
		{
			strcpy(lista_przedmiotow[i], tab[i]);
		}
	}

	int get_magi() {
		return ile_magistrantow;
	}
	char* get_Przedmioty() {
		return *lista_przedmiotow;
	}
};

void wczytaj_Tab(char tab[10][7]) {
	for (int i = 0; i < 10; i++)
	{
		std::cout << "[" << i << "]: ";
		std::cin >> tab[i];
	}
}

void lista_dodaj(Osoba** pierwsza, Osoba  *osoba) {
	if (*pierwsza == nullptr)
	{
		*pierwsza = osoba;
		return;
	}
	else
	{
		Osoba* aktualna = *pierwsza;
		while (aktualna->nast != nullptr)
		{
			aktualna = aktualna->nast;
		}
		aktualna->nast = osoba;
	}
}

void wypisz_liste(Osoba* pierwszy) {
	Osoba* aktualny = pierwszy;
	while (aktualny != nullptr)
	{
		aktualny->wypisz();
		aktualny = aktualny->nast;
	}
}

void sumuj_liste(Osoba **pierwszy){
	Osoba* aktualny = (*pierwszy)->nast;
	while (aktualny != nullptr)
	{
		**pierwszy += *aktualny;
		aktualny = aktualny->nast;
	}
}

int main() {

	Osoba* pierwszy = nullptr;

	Osoba* o1 = new Osoba("Jakub", "Drozd", "kubadrozd@onet.pl");
	Osoba* o2 = new Osoba();
	Osoba* o3 = new Osoba(*o1);
	o3->setImie("Artur");
	Osoba* o4 = new Osoba("Anna", "Nowak", "anowak@gmail.com");
	Osoba* o5 = new Osoba("Wojciech", "Buryn", "wojburyn@wp.pl");


	lista_dodaj(&pierwszy, o1);
	lista_dodaj(&pierwszy, o2);
	lista_dodaj(&pierwszy, o3);
	lista_dodaj(&pierwszy, o4);
	lista_dodaj(&pierwszy, o5);

	sumuj_liste(&pierwszy);

	o1->wypisz();

	std::cout << "Koniec" << std::endl;

	return 0;
}
