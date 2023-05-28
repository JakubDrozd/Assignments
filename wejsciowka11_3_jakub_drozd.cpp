//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//#include <iomanip>
//#include <conio.h>
//
//class Osoba {
//public:
//
//	char* imie;
//	char* nazwisko;
//	char* email;
//	Osoba* nast;
//
//	Osoba();
//	Osoba(Osoba& src);
//	Osoba(const char* a_imie, const char* a_nazwisko, const char* a_email);
//	~Osoba();
//	const char* getImie();
//	const char* getNazwisko();
//	const char* getEmail();
//	void setImie(const char* imie);
//	void setNazwisko(const char* nazwisko);
//	void setEmail(const char* email);
//	virtual void wypisz();
//
//private:
//
//};
//
//Osoba::Osoba(const char* a_imie, const char* a_nazwisko, const char* a_email) {
//	imie = new char[strlen(a_imie) + 1];
//	nazwisko = new char[strlen(a_nazwisko) + 1];
//	email = new char[strlen(a_email) + 1];
//	strcpy(imie, a_imie);
//	strcpy(nazwisko, a_nazwisko);
//	strcpy(email, a_email);
//	nast = nullptr;
//}
//
//Osoba::Osoba(Osoba& src) {
//	imie = new char[strlen(src.imie) + 1];
//	nazwisko = new char[strlen(src.nazwisko) + 1];
//	email = new char[strlen(src.email) + 1];
//	strcpy(imie, src.imie);
//	strcpy(nazwisko, src.nazwisko);
//	strcpy(email, src.email);
//	nast = nullptr;
//}
//
//void Osoba::wypisz() {
//	std::cout << "\n----------------------------------------------------" << std::endl;
//	std::cout << "[Osoba]" << std::endl;
//	std::cout << "Imie: " << imie << std::endl;
//	std::cout << "Nazwisko: " << nazwisko << std::endl;
//	std::cout << "E-mail: " << email << std::endl;
//	std::cout << "----------------------------------------------------\n" << std::endl;
//}
//
//Osoba::Osoba()
//{
//	imie = new char[strlen("Jan") + 1];
//	nazwisko = new char[strlen("Kowalski") + 1];
//	email = new char[strlen("jankowalski@gmail.com") + 1];
//	strcpy(imie, "Jan");
//	strcpy(nazwisko, "Kowalski");
//	strcpy(email, "jankowalski@gmail.com");
//	nast = nullptr;
//}
//
//Osoba::~Osoba()
//{
//	delete nast;
//}
//
//const char* Osoba::getImie() {
//	return imie;
//}
//
//const char* Osoba::getNazwisko() {
//	return nazwisko;
//}
//
//const char* Osoba::getEmail() {
//	return email;
//}
//
//void Osoba::setImie(const char* a_imie) {
//	if (imie != nullptr)
//	{
//		delete[] imie;
//	}
//	imie = new char[strlen(a_imie) + 1];
//	strcpy(imie, a_imie);
//}
//
//void Osoba::setNazwisko(const char* a_nazwisko) {
//	if (nazwisko != nullptr)
//	{
//		delete[] nazwisko;
//	}
//	nazwisko = new char[strlen(a_nazwisko) + 1];
//	strcpy(nazwisko, a_nazwisko);
//}
//
//void Osoba::setEmail(const char* a_email) {
//	if (email != nullptr)
//	{
//		delete[] email;
//	}
//	email = new char[strlen(a_email) + 1];
//	strcpy(email, a_email);
//}
//
//void dodaj_osobe(Osoba** pierwszy, Osoba* osoba) {
//	if (*pierwszy == nullptr)
//	{
//		*pierwszy = osoba;
//		return;
//	}
//	Osoba* aktualny = *pierwszy;
//	while (aktualny->nast != nullptr)
//	{
//		aktualny = aktualny->nast;
//	}
//	aktualny->nast = osoba;
//}
//
//void wypisz_osoby(Osoba* pierwszy) {
//	Osoba* aktualny = pierwszy;
//	while (aktualny != nullptr)
//	{
//		aktualny->wypisz();
//		aktualny = aktualny->nast;
//	}
//}
//
//class Student : public Osoba {
//public:
//	int nr_indeksu;
//	int rok_rozpoczecia;
//	int get_Indeks() {
//		return nr_indeksu;
//	}
//	int get_Rozpoczecie() {
//		return rok_rozpoczecia;
//	}
//	void set_Indeks(int indeks) {
//		nr_indeksu = indeks;
//	}
//	void set_Rozpoczecie(int rok) {
//		rok_rozpoczecia = rok;
//	}
//	void wypisz() {
//		std::cout << "\n----------------------------------------------------" << std::endl;
//		std::cout << "[Student]" << std::endl;
//		std::cout << "Imie: " << imie << std::endl;
//		std::cout << "Nazwisko: " << nazwisko << std::endl;
//		std::cout << "Numer indeksu: " << nr_indeksu << std::endl;
//		std::cout << "Rok rozpoczecia: " << rok_rozpoczecia << std::endl;
//		std::cout << "E-mail: " << email << std::endl;
//		std::cout << "----------------------------------------------------\n" << std::endl;
//	}
//	Student() : Osoba(), nr_indeksu(0), rok_rozpoczecia(2000) {};
//	Student(Student& src) : Osoba(src) {
//		nr_indeksu = src.nr_indeksu;
//		rok_rozpoczecia = src.rok_rozpoczecia;
//	}
//	Student(const char* a_imie, const char* a_nazwisko, const char* a_email, int indeks, int rok) : Osoba(a_imie, a_nazwisko, a_email), nr_indeksu(indeks), rok_rozpoczecia(rok) {};
//};
//
//class Pracownik : public Osoba {
//public:
//	int ile_magistrantow;
//	char lista_przedmiotow[10][7];
//
//	Pracownik(const char* a_imie, const char* a_nazwisko, const char* a_email, int magi) : Osoba(a_imie, a_nazwisko, a_email), ile_magistrantow(magi) {
//		memset(lista_przedmiotow, 0, sizeof(lista_przedmiotow));
//	}
//
//	Pracownik() : Osoba(), ile_magistrantow(1) {
//		for (int i = 0; i < 10; i++)
//		{
//			strcpy(lista_przedmiotow[i], "ABCDEF");
//		}
//	};
//
//	Pracownik(Pracownik& src) : Osoba(src) {
//		ile_magistrantow = src.ile_magistrantow;
//		for (int i = 0; i < 10; i++)
//		{
//			strcpy(lista_przedmiotow[i], src.lista_przedmiotow[i]);
//		}
//	};
//
//	void wypisz() {
//		std::cout << "\n----------------------------------------------------" << std::endl;
//		std::cout << "[Pracownik]" << std::endl;
//		std::cout << "Imie: " << imie << std::endl;
//		std::cout << "Nazwisko: " << nazwisko << std::endl;
//		std::cout << "Ile magistrow: " << ile_magistrantow << std::endl;
//		std::cout << "E-mail: " << email << std::endl;
//		std::cout << "Lista przedmiotow:\n";
//		for (int i = 0; i < 10; i++)
//		{
//			std::cout << "[" << i + 1 << "]: ";
//			std::cout << lista_przedmiotow[i] << std::endl;
//		}
//		std::cout << "----------------------------------------------------\n" << std::endl;
//	}
//
//	void set_magi(int magi) {
//		ile_magistrantow = magi;
//	}
//
//	void set_Przedmioty(char tab[10][7]) {
//		for (int i = 0; i < 10; i++)
//		{
//			strcpy(lista_przedmiotow[i], tab[i]);
//		}
//	}
//
//	int get_magi() {
//		return ile_magistrantow;
//	}
//	char* get_Przedmioty() {
//		return *lista_przedmiotow;
//	}
//};
//
//void wczytaj_Tab(char tab[10][7]) {
//	for (int i = 0; i < 10; i++)
//	{
//		std::cout << "[" << i << "]: ";
//		std::cin >> tab[i];
//	}
//}
//
//int main() {
//
//	Osoba* pierwszy = nullptr;
//
//	while (true)
//	{
//		char c;
//		std::cout << "Jaka osobe chcesz utworzyc?" << std::endl;
//		std::cout << "[s] - student  [p] - pracownik  [q] - wyjscie" << std::endl;
//		c = _getch();
//		if (c == 's')
//		{
//			char* imie = new char[16];
//			char* nazwisko = new char[16];
//			char* email = new char[16];
//			int nr_indeksu = 0;
//			int rok_rozpoczecia = 0;
//			std::cout << "Tworzysz studenta: " << std::endl;
//			std::cout << "Podaj imie: ";
//			std::cin >> imie;
//			std::cout << "Podaj nazwisko: ";
//			std::cin >> nazwisko;
//			std::cout << "Podaj email: ";
//			std::cin >> email;
//			std::cout << "Podaj nr indeksu: ";
//			std::cin >> nr_indeksu;
//			std::cout << "Podaj rok rozpoczecia: ";
//			std::cin >> rok_rozpoczecia;
//			if (rok_rozpoczecia < 2000 || rok_rozpoczecia > 2023)
//			{
//				std::cout << "Niepoprawna data, tworzenie studenta domyslnego" << std::endl;
//				Student* student2 = new Student();
//				continue;
//			}
//			Student* student1 = new Student(imie, nazwisko, email, nr_indeksu, rok_rozpoczecia);
//			dodaj_osobe(&pierwszy, student1);
//			std::cout << "\nUtworzono obiekt i dodano do listy\n" << std::endl;
//		}
//		else if (c == 'p')
//		{
//			std::cout << "Tworzysz pracownika" << std::endl;
//			char imie[32];
//			char nazwisko[32];
//			char email[32];
//			int ile_magi;
//			char przedmioty[10][7];
//			std::cout << "Podaj imie: ";
//			std::cin >> imie;
//			std::cout << "Podaj nazwisko: ";
//			std::cin >> nazwisko;
//			std::cout << "Podaj email: ";
//			std::cin >> email;
//			std::cout << "Podaj liczbe magistrantow: ";
//			std::cin >> ile_magi;
//			if (ile_magi < 0 || ile_magi > 8)
//			{
//				std::cout << "Niepoprawna liczba magistrantów, tworzenie pracownika domyslnego" << std::endl;
//				continue;
//			}
//			std::cout << "Podaj przedmioty prowadzone:\n";
//			wczytaj_Tab(przedmioty);
//			Pracownik* p1 = new Pracownik(imie, nazwisko, email, ile_magi);
//			p1->set_Przedmioty(przedmioty);
//			dodaj_osobe(&pierwszy, p1);
//			std::cout << "\nUtworzono obiekt i dodano do listy\n" << std::endl;
//		}
//		else if (c == 'q')
//		{
//			std::cout << "\n[*Zakonczono tworzenie listy*]\n" << std::endl;
//			break;
//		}
//		else
//		{
//			std::cout << "[ERR!] Nieznany typ osoby" << std::endl;
//			continue;
//		}
//	}
//
//	wypisz_osoby(pierwszy);
//
//	printf("\nKoniec programu\n");
//	return 0;
//}
