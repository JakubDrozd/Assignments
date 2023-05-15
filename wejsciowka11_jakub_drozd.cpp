//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//#include <iomanip>
//
//class Samochod
//{
//public:
//
//	double cena;
//	char* silnik;
//	Samochod* nast;
//
//	Samochod();
//	Samochod(double cena, const char* silnik);
//	Samochod(Samochod& src);
//	~Samochod();
//	double getCena();
//	const char* getSilnik();
//	void setCena(double cena);
//	void setSilnik(const char* nazwa_silnika);
//	void wypisz();
//
//private:
//
//};
//
//void Samochod::wypisz() {
//	std::cout << "\n----------------------------------------------------" << std::endl;
//	std::cout << "[Samochod]" << std::endl;
//	std::cout << "Cena: " << cena << std::endl;
//	std::cout << "Silnik: " << silnik << std::endl;
//	std::cout << "----------------------------------------------------\n" << std::endl;
//}
//
//Samochod::Samochod(Samochod& src) {
//	cena = src.cena;
//	silnik = new char[strlen(src.silnik) + 1];
//	strcpy(silnik, src.silnik);
//	nast = nullptr;
//}
//
//Samochod::Samochod(double cena, const char* nazwa_silnika) {
//	this->cena = cena;
//	silnik = new char[strlen(nazwa_silnika) + 1];
//	strcpy(silnik, nazwa_silnika);
//	nast = nullptr;
//}
//
//Samochod::Samochod()
//{
//	cena = 0;
//	silnik = new char[7];
//	strcpy(silnik, "Silnik");
//	nast = nullptr;
//}
//
//Samochod::~Samochod()
//{
//	delete nast;
//}
//
//double Samochod::getCena() {
//	return cena;
//}
//
//const char* Samochod::getSilnik() {
//	return silnik;
//}
//
//void Samochod::setCena(double cena) {
//	this->cena = cena;
//}
//
//void Samochod::setSilnik(const char* nazwa_silnika){
//	if (silnik != nullptr)
//	{
//		delete[] silnik;
//	}
//	silnik = new char[strlen(nazwa_silnika) + 1];
//	strcpy(silnik, nazwa_silnika);
//}
//
//
//class Optyka
//{
//public:
//
//	double zoom;
//	double waga;
//	Optyka* nast;
//
//	Optyka();
//	Optyka(Optyka& src);
//	Optyka(double zoom, double waga);
//	~Optyka();
//	double getZoom();
//	double getWaga();
//	void setZoom(double zoom);
//	void setWaga(double waga);
//	void wypisz();
//
//private:
//
//};
//
//Optyka::Optyka(Optyka& src) {
//	this->zoom = src.zoom;
//	this->waga = src.waga;
//	nast = nullptr;
//}
//
//Optyka::Optyka(double zoom, double waga) {
//	this->zoom = zoom;
//	this->waga = waga;
//	nast = nullptr;
//}
//
//void Optyka::wypisz() {
//	std::cout << "\n----------------------------------------------------" << std::endl;
//	std::cout << "[Optyka]" << std::endl;
//	std::cout << "Zoom: " << zoom << std::endl;
//	std::cout << "Waga: " << waga << std::endl;
//	std::cout << "----------------------------------------------------\n" << std::endl;
//}
//
//double Optyka::getZoom() {
//	return zoom;
//}
//
//double Optyka::getWaga() {
//	return waga;
//}
//
//void Optyka::setZoom(double zoom) {
//	this->zoom = zoom;
//}
//
//void Optyka::setWaga(double waga) {
//	this->waga = waga;
//}
//
//Optyka::Optyka()
//{
//	zoom = 1;
//	waga = 1;
//	nast = nullptr;
//}
//
//Optyka::~Optyka()
//{
//	delete nast;
//}
//
//class Osoba
//{
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
//	void wypisz();
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
//void dodaj_samochod(Samochod **pierwszy, Samochod* samochod) {
//	if (*pierwszy == nullptr)
//	{
//		*pierwszy = samochod;
//		return;
//	}
//	Samochod* aktualny = *pierwszy;
//	while (aktualny->nast != nullptr)
//	{
//		aktualny = aktualny->nast;
//	}
//	aktualny->nast = samochod;
//}
//
//void wypisz_samochody(Samochod* pierwszy) {
//	Samochod* aktualny = pierwszy;
//	while (aktualny != nullptr)
//	{
//		aktualny->wypisz();
//		aktualny = aktualny->nast;
//	}
//}
//
//void dodaj_optyke(Optyka** pierwszy, Optyka* optyka) {
//	if (*pierwszy == nullptr)
//	{
//		*pierwszy = optyka;
//		return;
//	}
//	Optyka* aktualny = *pierwszy;
//	while (aktualny->nast != nullptr)
//	{
//		aktualny = aktualny->nast;
//	}
//	aktualny->nast = optyka;
//}
//
//void wypisz_optyke(Optyka* pierwszy) {
//	Optyka* aktualny = pierwszy;
//	while (aktualny != nullptr)
//	{
//		aktualny->wypisz();
//		aktualny = aktualny->nast;
//	}
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
//int main(){
//	Samochod* pierwszy_sam = nullptr;
//	Samochod* s1 = new Samochod(10200, "Mercedes Benz");
//	Samochod* s2 = new Samochod(6700, "Toyota Corolla");
//	Samochod* s3 = new Samochod(12000, "BMW");
//	Samochod* s4 = new Samochod(5700, "Fiat");
//	Samochod* s5 = new Samochod(36000, "Porsche");
//	dodaj_samochod(&pierwszy_sam, s1);
//	dodaj_samochod(&pierwszy_sam, s2);
//	dodaj_samochod(&pierwszy_sam, s3);
//	dodaj_samochod(&pierwszy_sam, s4);
//	dodaj_samochod(&pierwszy_sam, s5);
//	wypisz_samochody(pierwszy_sam);
//
//	Optyka* pierwsza_optyka = nullptr;
//	Optyka* op1 = new Optyka(1.00, 0.2);
//	Optyka* op2 = new Optyka(2.00, 0.25);
//	Optyka* op3 = new Optyka(3.00, 0.75);
//	Optyka* op4 = new Optyka(4.00, 1);
//	Optyka* op5 = new Optyka(8.00, 1.50);
//	dodaj_optyke(&pierwsza_optyka, op1);
//	dodaj_optyke(&pierwsza_optyka, op2);
//	dodaj_optyke(&pierwsza_optyka, op3);
//	dodaj_optyke(&pierwsza_optyka, op4);
//	dodaj_optyke(&pierwsza_optyka, op5);
//	wypisz_optyke(pierwsza_optyka);
//
//	Osoba* pierwsza_osoba = nullptr;
//	Osoba* os1 = new Osoba("Jakub", "Drozd", "kubadrozd@onet.pl");
//	Osoba* os2 = new Osoba("Artur", "Drozd", "arturdrozd@onet.pl");
//	Osoba* os3 = new Osoba("Teresa", "Drozd", "termobik5@gmail.com");
//	Osoba* os4 = new Osoba("Jan", "Kowalski", "jankowalski@wp.pl");
//	Osoba* os5 = new Osoba("Anna", "Nowak", "anowak@gmail.com");
//	dodaj_osobe(&pierwsza_osoba, os1);
//	dodaj_osobe(&pierwsza_osoba, os2);
//	dodaj_osobe(&pierwsza_osoba, os3);
//	dodaj_osobe(&pierwsza_osoba, os4);
//	dodaj_osobe(&pierwsza_osoba, os5);
//	wypisz_osoby(pierwsza_osoba);
//
//	delete pierwszy_sam;
//	delete pierwsza_optyka;
//	delete pierwsza_osoba;
//}