#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include <conio.h>
#include <vector>

#define MAX_PRZEDMIOTOW 10
#define MAX_DLUGOSC 18

using namespace std;

class Osoba {
public:

	char imie[25];
	char nazwisko[25];
	char email[40];
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

	Osoba& operator += (Osoba& src) {
		char* temp = new char[(sizeof(*imie) + sizeof((*src.imie))) + 2];
		strcpy(temp, strcat(imie, " "));
		strcpy(temp, strcat(imie, src.imie));
		strcpy(imie, temp);
		char* temp2 = new char[(sizeof(*nazwisko) + sizeof((*src.imie))) + 2];
		strcpy(temp, strcat(nazwisko, " "));
		strcpy(temp, strcat(nazwisko, src.nazwisko));
		strcpy(nazwisko, temp);
		return *this;
	}
	virtual void inicjaly() = 0;
	virtual void czas_na_uczelni() = 0;

private:

};

Osoba::Osoba(const char* a_imie, const char* a_nazwisko, const char* a_email) {
	strcpy(imie, a_imie);
	strcpy(nazwisko, a_nazwisko);
	strcpy(email, a_email);
	nast = nullptr;
}

Osoba::Osoba(Osoba& src) {
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
	strcpy(imie, a_imie);
}

void Osoba::setNazwisko(const char* a_nazwisko) {
	strcpy(nazwisko, a_nazwisko);
}

void Osoba::setEmail(const char* a_email) {
	strcpy(email, a_email);
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
	Student& operator = (Student& src) {
		strcpy(imie, src.imie);
		strcpy(nazwisko, src.nazwisko);
		strcpy(email, src.email);
		nr_indeksu = src.nr_indeksu;
		rok_rozpoczecia = src.rok_rozpoczecia;
		return *this;
	}
	Student& operator += (Student& src) {
		char* temp = new char[strlen(imie) + strlen(src.imie) + 2];
		strcpy(temp, imie);
		strcat(temp, " ");
		strcat(temp, src.imie);
		strcpy(imie, temp);
		delete[] temp;

		char* temp2 = new char[strlen(nazwisko) + strlen(src.nazwisko) + 2];
		strcpy(temp2, nazwisko);
		strcat(temp2, " ");
		strcat(temp2, src.nazwisko);
		strcpy(nazwisko, temp2);
		delete[] temp2;

		nr_indeksu += src.nr_indeksu;
		rok_rozpoczecia += src.rok_rozpoczecia;

		char* temp3 = new char[strlen(email) + strlen(src.email) + 2];
		strcpy(temp3, email);
		strcat(temp3, " ");
		strcat(temp3, src.email);
		strcpy(email, temp3);
		delete[] temp3;

		return *this;
	}
	void inicjaly() override {
		char fname = this->imie[0];
		char fsur = this->nazwisko[0];
		int number = this->nr_indeksu % 1000;
		cout << "Inicjaly studenta: " << fname << fsur << number << endl;
	}
	void czas_na_uczelni() override {
		std::time_t czas = std::time(nullptr);
		std::tm* teraz = std::localtime(&czas);
		int aktualnyRok = teraz->tm_year + 1900;
		cout << "Ile lat uczy sie na uczelni: " << aktualnyRok - this->rok_rozpoczecia << endl;
	}
};

class Pracownik : public Osoba {
private:
public:
	int ile_magistrantow;
	char lista_przedmiotow[MAX_PRZEDMIOTOW][MAX_DLUGOSC];
	Pracownik* nast;

	Pracownik& operator = (Pracownik& src) {
		strcpy(imie, src.imie);
		strcpy(nazwisko, src.nazwisko);
		strcpy(email, src.email);
		ile_magistrantow = src.ile_magistrantow;
		this->set_Przedmioty(src.lista_przedmiotow);
		return *this;
	}

	Pracownik& operator += (Pracownik& src) {
		char* temp = new char[strlen(imie) + strlen(src.imie) + 2];
		strcpy(temp, imie);
		strcat(temp, " ");
		strcat(temp, src.imie);
		strcpy(imie, temp);
		delete[] temp;

		char* temp2 = new char[strlen(nazwisko) + strlen(src.nazwisko) + 2];
		strcpy(temp2, nazwisko);
		strcat(temp2, " ");
		strcat(temp2, src.nazwisko);
		strcpy(nazwisko, temp2);
		delete[] temp2;

		char* temp3 = new char[strlen(email) + strlen(src.email) + 2];
		strcpy(temp3, email);
		strcat(temp3, " ");
		strcat(temp3, src.email);
		strcpy(email, temp3);
		delete[] temp3;

		for (int i = 0; i < MAX_PRZEDMIOTOW; i++)
		{
			strcpy(lista_przedmiotow[i], strcat(lista_przedmiotow[i], src.lista_przedmiotow[i]));
		}

		ile_magistrantow += src.ile_magistrantow;

		return *this;

	}

	Pracownik(const char* a_imie, const char* a_nazwisko, const char* a_email, int magi, const char tab[MAX_PRZEDMIOTOW][MAX_DLUGOSC]) : Osoba(a_imie, a_nazwisko, a_email), ile_magistrantow(magi) {
		memcpy(lista_przedmiotow, tab, sizeof(lista_przedmiotow));
		nast = nullptr;
	}

	Pracownik() : Osoba(), ile_magistrantow(1) {
		for (int i = 0; i < MAX_PRZEDMIOTOW; i++)
		{
			strcpy(lista_przedmiotow[i], "ABCDEF");
		}
		nast = nullptr;
	};

	Pracownik(Pracownik& src) : Osoba(src) {
		ile_magistrantow = src.ile_magistrantow;
		for (int i = 0; i < MAX_PRZEDMIOTOW; i++)
		{
			strcpy(lista_przedmiotow[i], src.lista_przedmiotow[i]);
		}
		nast = nullptr;
	};

	void wypisz() {
		std::cout << "\n----------------------------------------------------" << std::endl;
		std::cout << "[Pracownik]" << std::endl;
		std::cout << "Imie: " << imie << std::endl;
		std::cout << "Nazwisko: " << nazwisko << std::endl;
		std::cout << "Ile magistrow: " << ile_magistrantow << std::endl;
		std::cout << "E-mail: " << email << std::endl;
		std::cout << "Lista przedmiotow:\n";
		for (int i = 0; i < MAX_PRZEDMIOTOW; i++)
		{
			std::cout << "[" << i + 1 << "]: ";
			std::cout << lista_przedmiotow[i] << std::endl;
		}
		std::cout << "----------------------------------------------------\n" << std::endl;
	}

	void set_magi(int magi) {
		ile_magistrantow = magi;
	}

	void set_Przedmioty(const char tab[MAX_PRZEDMIOTOW][MAX_DLUGOSC]) {
		memcpy(lista_przedmiotow, tab, sizeof(lista_przedmiotow));
	}

	int get_magi() {
		return ile_magistrantow;
	}
	char* get_Przedmioty() {
		return *lista_przedmiotow;
	}
	void inicjaly() override {
		char fname = this->imie[0];
		char fsur = this->nazwisko[0];
		char kody[3] = {};
		for (int i = 0; i < 3; i++)
		{
			kody[i] = this->lista_przedmiotow[i][0];
		}
		cout << "Inicjaly pracownika: " << fname << fsur;
		for (int i = 0; i < 3; i++)
		{
			cout << kody[i];
		}
		printf("\n");
	}

	void czas_na_uczelni() override {
		int ilosc_przedmiotow = 0;
		for (int i = 0; i < MAX_PRZEDMIOTOW; i++)
		{
			if (strlen(lista_przedmiotow[i]) > 0)
			{
				ilosc_przedmiotow++;
			}
		}
		cout << "Ile lat pracuje: " << (0.5 * ile_magistrantow) + ilosc_przedmiotow + 0.5 << endl;
	}
};

void wczytaj_Tab(char tab[MAX_PRZEDMIOTOW][MAX_DLUGOSC]) {
	for (int i = 0; i < MAX_PRZEDMIOTOW; i++)
	{
		std::cout << "[" << i << "]: ";
		std::cin >> tab[i];
	}
}

void dodaj_osobe(Osoba** pierwszy, Osoba* osoba) {
	if (*pierwszy == nullptr)
	{
		*pierwszy = osoba;
	}
	else
	{
		Osoba* aktualny = *pierwszy;
		while (aktualny->nast != nullptr)
		{
			aktualny = aktualny->nast;
		}
		aktualny->nast = osoba;
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

void wypisz_inicjaly_i_czas(Osoba* pierwszy) {
	Osoba* aktualny = pierwszy;
	while (aktualny != nullptr)
	{
		aktualny->inicjaly();
		aktualny->czas_na_uczelni();
		printf("\n");
		aktualny = aktualny->nast;
	}
}

int main() {

	char przedmioty1[MAX_PRZEDMIOTOW][MAX_DLUGOSC] = { {"0"}, {"0"},{"0"}, {"0"}, {"0"}, {"0"}};
	char przedmioty2[MAX_PRZEDMIOTOW][MAX_DLUGOSC] = { {"1"}, {"1"},{"1"}, {"1"}, {"1"}, {"1"}, {"1"}, {"1"}, };
	char przedmioty3[MAX_PRZEDMIOTOW][MAX_DLUGOSC] = { {"2"}, {"2"},{"2"}, {"2"}, {"2"}, {"2"}, {"2"}, {"2"}, {"2"} };

	Osoba* pierwszy = nullptr;

	Student* s1 = new Student("Jakub", "Drozd", "kdrozd@onet.pl", 123479, 2022);
	Student* s2 = new Student("Piotr", "Zeb", "pzeb@wp.pl", 123463, 2021);
	Student* s3 = new Student("Maciek", "Nowakowski", "mnowak123@gmail.com", 123554 ,2019);

	Pracownik* p1 = new Pracownik("Hubert", "Zembrowski", "hzembrowski@uksw.edu.pl", 5, przedmioty1);
	Pracownik* p2 = new Pracownik("Bozena", "Tkacz", "btkacz@uksw.edu.pl", 7, przedmioty2);
	Pracownik* p3 = new Pracownik("Miroslaw", "Zelent", "mzelent@mail.com", 3,  przedmioty3);

	dodaj_osobe(&pierwszy, s1);
	dodaj_osobe(&pierwszy, s2);
	dodaj_osobe(&pierwszy, s3);
	dodaj_osobe(&pierwszy, p1);
	dodaj_osobe(&pierwszy, p2);
	dodaj_osobe(&pierwszy, p3);

	wypisz_inicjaly_i_czas(pierwszy);

	delete pierwszy;

	std::cout << "\nKoniec\n" << std::endl;

	return 0;
}
