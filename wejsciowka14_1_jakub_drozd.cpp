//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//#include <iomanip>
//#include <conio.h>
//
//#define MAX_PRZEDMIOTOW 10
//#define MAX_DLUGOSC 100
//
//
//
//class Osoba {
//public:
//
//	char imie[50];
//	char nazwisko[50];
//	char email[100];
//	Osoba* nast;
//
//	Osoba();
//	Osoba(const Osoba& src);
//	Osoba(const char* a_imie, const char* a_nazwisko, const char* a_email);
//	~Osoba();
//	const char* getImie();
//	const char* getNazwisko();
//	const char* getEmail();
//	void setImie(const char* imie);
//	void setNazwisko(const char* nazwisko);
//	void setEmail(const char* email);
//	virtual void wypisz();
//	Osoba& operator += (Osoba& src) {
//		char* temp = new char[(sizeof(*imie) + sizeof((*src.imie))) + 2];
//		strcpy(temp, strcat(imie, " "));
//		strcpy(temp, strcat(imie, src.imie));
//		strcpy(imie, temp);
//		char* temp2 = new char[(sizeof(*nazwisko) + sizeof((*src.imie))) + 2];
//		strcpy(temp, strcat(nazwisko, " "));
//		strcpy(temp, strcat(nazwisko, src.nazwisko));
//		strcpy(nazwisko, temp);
//		return *this;
//	}
//
//	Osoba& operator=(const Osoba& os) {
//		if (this != &os) {
//			strcpy(imie, os.imie);
//			strcpy(nazwisko, os.nazwisko);
//			strcpy(email, os.email);
//		}
//		return *this;
//	}
//
//private:
//
//};
//
//Osoba::Osoba(const char* a_imie, const char* a_nazwisko, const char* a_email) {
//	strcpy(imie, a_imie);
//	strcpy(nazwisko, a_nazwisko);
//	strcpy(email, a_email);
//	nast = nullptr;
//}
//
//Osoba::Osoba(const Osoba& src) {
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
//	strcpy(imie, a_imie);
//}
//
//void Osoba::setNazwisko(const char* a_nazwisko) {
//	strcpy(nazwisko, a_nazwisko);
//}
//
//void Osoba::setEmail(const char* a_email) {
//	strcpy(email, a_email);
//}
//
//class Pracownik;
//
//class Student : public Osoba {
//public:
//	Student* nast;
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
//
//	Student(const Student& src) : Osoba(src) {
//		nr_indeksu = src.nr_indeksu;
//		rok_rozpoczecia = src.rok_rozpoczecia;
//	}
//
//	Student(const char* a_imie, const char* a_nazwisko, const char* a_email, int indeks, int rok) : Osoba(a_imie, a_nazwisko, a_email), nr_indeksu(indeks), rok_rozpoczecia(rok) {};
//
//	Student& operator = (const Student& src) {
//		Osoba::operator=(src);
//		nr_indeksu = src.nr_indeksu;
//		rok_rozpoczecia = src.rok_rozpoczecia;
//		return *this;
//	}
//
//	Student& operator += (const Student& src) {
//		char* temp = new char[strlen(imie) + strlen(src.imie) + 2];
//		strcpy(temp, imie);
//		strcat(temp, " ");
//		strcat(temp, src.imie);
//		strcpy(imie, temp);
//		delete[] temp;
//
//
//		char* temp2 = new char[strlen(nazwisko) + strlen(src.nazwisko) + 2];
//		strcpy(temp2, nazwisko);
//		strcat(temp2, " ");
//		strcat(temp2, src.nazwisko);
//		strcpy(nazwisko, temp2);
//		delete[] temp2;
//
//		nr_indeksu += src.nr_indeksu;
//		rok_rozpoczecia += src.rok_rozpoczecia;
//
//		char* temp3 = new char[strlen(email) + strlen(src.email) + 2];
//		strcpy(temp3, email);
//		strcat(temp3, " ");
//		strcat(temp3, src.email);
//		strcpy(email, temp3);
//		delete[] temp3;
//
//		return *this;
//	}
//
//	Student operator+(const Student& src) const {
//		char* temp_imie = new char[strlen(imie) + strlen(src.imie) + 2];
//		strcpy(temp_imie, imie);
//		strcat(temp_imie, " ");
//		strcat(temp_imie, src.imie);
//
//		char* temp_nazwisko = new char[strlen(nazwisko) + strlen(src.nazwisko) + 2];
//		strcpy(temp_nazwisko, nazwisko);
//		strcat(temp_nazwisko, " ");
//		strcat(temp_nazwisko, src.nazwisko);
//
//		char* temp_email = new char[strlen(email) + strlen(src.email) + 2];
//		strcpy(temp_email, email);
//		strcat(temp_email, " ");
//		strcat(temp_email, src.email);
//
//		int temp_indeks = this->nr_indeksu + src.nr_indeksu;
//		int temp_rok = this->rok_rozpoczecia + src.rok_rozpoczecia;
//
//		Student result(temp_imie, temp_nazwisko, temp_email, temp_indeks, temp_rok);
//
//		delete[] temp_imie;
//		delete[] temp_nazwisko;
//
//		return result;
//	}
//
//	bool operator==(const Student& src) const {
//		bool same_imie = (strcmp(imie, src.imie) == 0);
//		bool same_nazwisko = (strcmp(nazwisko, src.nazwisko) == 0);
//		bool same_email = (strcmp(email, src.email) == 0);
//		bool same_indeks = (nr_indeksu == src.nr_indeksu);
//		bool same_rok = (rok_rozpoczecia == src.rok_rozpoczecia);
//		if (same_imie && same_nazwisko && same_email && same_indeks && same_rok)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	operator Pracownik();
//};
//
//class Pracownik : public Osoba {
//private:
//public:
//	int ile_magistrantow;
//	char lista_przedmiotow[MAX_PRZEDMIOTOW][MAX_DLUGOSC];
//	Pracownik* nast;
//
//	Pracownik& operator = (const Pracownik& src) {
//		strcpy(imie, src.imie);
//		strcpy(nazwisko, src.nazwisko);
//		strcpy(email, src.email);
//		ile_magistrantow = src.ile_magistrantow;
//		this->set_Przedmioty(src.lista_przedmiotow);
//		return *this;
//	}
//
//	Pracownik& operator += (Pracownik& src) {
//		char* temp = new char[strlen(imie) + strlen(src.imie) + 2];
//		strcpy(temp, imie);
//		strcat(temp, " ");
//		strcat(temp, src.imie);
//		strcpy(imie, temp);
//		delete[] temp;
//
//		char* temp2 = new char[strlen(nazwisko) + strlen(src.nazwisko) + 2];
//		strcpy(temp2, nazwisko);
//		strcat(temp2, " ");
//		strcat(temp2, src.nazwisko);
//		strcpy(nazwisko, temp2);
//		delete[] temp2;
//
//		char* temp3 = new char[strlen(email) + strlen(src.email) + 2];
//		strcpy(temp3, email);
//		strcat(temp3, " ");
//		strcat(temp3, src.email);
//		strcpy(email, temp3);
//		delete[] temp3;
//
//		for (int i = 0; i < MAX_PRZEDMIOTOW; i++)
//		{
//			strcpy(lista_przedmiotow[i], strcat(lista_przedmiotow[i], src.lista_przedmiotow[i]));
//		}
//
//		ile_magistrantow += src.ile_magistrantow;
//
//		return *this;
//
//	}
//
//	Pracownik operator+(const Pracownik& src) {
//		char* temp_imie = new char[strlen(imie) + strlen(src.imie) + 2];
//		strcpy(temp_imie, imie);
//		strcat(temp_imie, " ");
//		strcat(temp_imie, src.imie);
//
//		char* temp_nazwisko = new char[strlen(nazwisko) + strlen(src.nazwisko) + 2];
//		strcpy(temp_nazwisko, nazwisko);
//		strcat(temp_nazwisko, " ");
//		strcat(temp_nazwisko, src.nazwisko);
//
//		char* temp_email = new char[strlen(email) + strlen(src.email) + 2];
//		strcpy(temp_email, email);
//		strcat(temp_email, " ");
//		strcat(temp_email, src.email);
//
//		int temp_magi = ile_magistrantow + src.ile_magistrantow;
//		
//		char temp_array[MAX_PRZEDMIOTOW][MAX_DLUGOSC];
//
//		for (int i = 0; i < MAX_PRZEDMIOTOW; i++)
//		{
//			strcpy(temp_array[i], strcat(lista_przedmiotow[i], src.lista_przedmiotow[i]));
//		}
//
//		Pracownik result(temp_imie, temp_nazwisko, temp_email, temp_magi, temp_array);
//
//		delete[] temp_imie;
//		delete[] temp_nazwisko;
//		delete[] temp_email;
//
//		return result;
//	}
//
//
//	Pracownik(const char* a_imie, const char* a_nazwisko, const char* a_email, int magi, const char tab[MAX_PRZEDMIOTOW][MAX_DLUGOSC]) : Osoba(a_imie, a_nazwisko, a_email), ile_magistrantow(magi) {
//		memcpy(lista_przedmiotow, tab, sizeof(lista_przedmiotow));
//		nast = nullptr;
//	}
//
//	Pracownik() : Osoba(), ile_magistrantow(1) {
//		for (int i = 0; i < MAX_PRZEDMIOTOW; i++)
//		{
//			strcpy(lista_przedmiotow[i], "ABCDEF");
//		}
//		nast = nullptr;
//	};
//
//	Pracownik(const Pracownik& src) : Osoba(src) {
//		ile_magistrantow = src.ile_magistrantow;
//		for (int i = 0; i < MAX_PRZEDMIOTOW; i++)
//		{
//			strcpy(lista_przedmiotow[i], src.lista_przedmiotow[i]);
//		}
//		nast = nullptr;
//	};
//
//	operator Student();
//
//	void wypisz() {
//		std::cout << "\n----------------------------------------------------" << std::endl;
//		std::cout << "[Pracownik]" << std::endl;
//		std::cout << "Imie: " << imie << std::endl;
//		std::cout << "Nazwisko: " << nazwisko << std::endl;
//		std::cout << "Ile magistrow: " << ile_magistrantow << std::endl;
//		std::cout << "E-mail: " << email << std::endl;
//		std::cout << "Lista przedmiotow:\n";
//		for (int i = 0; i < MAX_PRZEDMIOTOW; i++)
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
//	void set_Przedmioty(const char tab[MAX_PRZEDMIOTOW][MAX_DLUGOSC]) {
//		memcpy(lista_przedmiotow, tab, sizeof(lista_przedmiotow));
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
//void wczytaj_Tab(char tab[MAX_PRZEDMIOTOW][MAX_DLUGOSC]) {
//	for (int i = 0; i < MAX_PRZEDMIOTOW; i++)
//	{
//		std::cout << "[" << i << "]: ";
//		std::cin >> tab[i];
//	}
//}
//
//
//Student::operator Pracownik()	//Student -> Pracownik
//{
//	char temp_przedmioty[MAX_PRZEDMIOTOW][MAX_DLUGOSC] = { {"POKONW"},{"POKONW"}, {"POKONW"}, {"POKONW"}, {"POKONW"}, {"POKONW"}, {"POKONW"}, {"POKONW"}, {"POKONW"}, {"POKONW"} };
//	Pracownik* temp = new Pracownik(this->imie, this->nazwisko, this->email, 1, temp_przedmioty);
//	return *temp;
//}
//
//
//Pracownik::operator Student() {	//Pracownik -> Student
//	Student* temp = new Student(this->imie, this->nazwisko, this->email, 999999, 2023);
//	return *temp;
//}
//
//
//class Kolejka {
//private:
//	Student* pierwszy;
//public:
//	Kolejka();
//	~Kolejka();
//	void put(Student* student);
//	void get(int nr_index);
//	void purge();
//	void show();
//};
//
//Kolejka::Kolejka() {
//	pierwszy = nullptr;
//}
//
//Kolejka::~Kolejka() {
//	while (pierwszy != nullptr)
//	{
//		Student* aktualny = pierwszy;
//		pierwszy = aktualny->nast;
//		delete aktualny;
//	}
//}
//
//void Kolejka::put(Student* student) {
//	if (this->pierwszy == nullptr)
//	{
//		pierwszy = student;
//		return;
//	}
//	else
//	{
//		Student* aktualny = pierwszy;
//		while (aktualny->nast != nullptr)
//		{
//			aktualny = aktualny->nast;
//		}
//		aktualny->nast = student;
//	}
//}
//
//void Kolejka::get(int nr_index) {
//	Student* aktualny = pierwszy;
//	Student* poprz = nullptr;
//
//	while (aktualny != nullptr)
//	{
//		if (aktualny->nr_indeksu == nr_index)
//		{
//			Student* temp = aktualny;
//			aktualny = aktualny->nast;
//
//			if (temp == pierwszy)
//			{
//				pierwszy = aktualny;
//			}
//			else
//			{
//				poprz->nast = aktualny;
//			}
//		}
//		else
//		{
//			poprz = aktualny;
//			aktualny = aktualny->nast;
//		}
//	}
//}
//
//void Kolejka::purge(){
//	Student* aktualny = pierwszy;
//	while (aktualny != nullptr && aktualny->nast != nullptr)
//	{
//		if (*aktualny == *(aktualny->nast))
//		{
//			Student* temp = aktualny->nast;
//			aktualny->nast = aktualny->nast->nast;
//			delete temp;
//		}
//		else
//		{
//			aktualny = aktualny->nast;
//		}
//	}
//}
//
//void Kolejka::show() {
//	Student* aktualny = pierwszy;
//	while (aktualny != nullptr)
//	{
//		aktualny->wypisz();
//		aktualny = aktualny->nast;
//	}
//}
//
//int main() {
//
//	Student* s1 = new Student("Jakub", "Drozd", "kubadrozd@onet.pl", 123479, 2022);
//	Student* s2 = new Student("Jakub", "Drozd", "kubadrozd@onet.pl", 123479, 2022);
//	Student* s3 = new Student("Jan", "Kowalski", "jkowalski@wp.pl", 123478, 2019);
//	Student* s4 = new Student("Anna", "Nowak", "anowak@gmail.com", 123476, 2022);
//	Student* s5 = new Student("Jakub", "Drozd", "kubadrozd@onet.pl", 123479, 2022);
//
//	Kolejka* kolejeczka = new Kolejka();
//	kolejeczka->put(s1);
//	kolejeczka->put(s2);
//	kolejeczka->put(s3);
//	kolejeczka->put(s4);
//	kolejeczka->put(s5);
//
//	std::cout << "Przed:" << std::endl;
//	kolejeczka->show();
//
//	kolejeczka->purge();
//
//	std::cout << "Po: " << std::endl;
//	kolejeczka->show();
//
//	delete kolejeczka;
//
//	return 0;
//}
//
//
