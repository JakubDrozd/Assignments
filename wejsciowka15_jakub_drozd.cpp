//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <sstream>
//
//std::ostream& operator<<(std::ostream& os, const std::string& s) {
//	os << s.c_str() << "\n";
//	return os;
//}
//
//class Osoba {
//	public:
//	
//		std::string imie;
//		std::string nazwisko;
//		std::string email;
//		Osoba* nast;
//	
//		Osoba();
//		Osoba(const Osoba& src);
//		Osoba(std::string a_imie, std::string a_nazwisko, std::string a_email);
//		~Osoba();
//		std::string getImie();
//		std::string getNazwisko();
//		std::string getEmail();
//		void setImie(std::string imie);
//		void setNazwisko(std::string nazwisko);
//		void setEmail(std::string email);
//		virtual void wypisz();
//
//		Osoba& operator += (Osoba& src) {
//			this->imie = imie + " " + src.imie;
//			this->nazwisko = nazwisko + " " + src.nazwisko;
//			return *this;
//		}
//	
//		Osoba& operator=(const Osoba& os) {
//			if (this != &os) {
//				this->imie = os.imie;
//				this->nazwisko = os.nazwisko;
//				this->email = os.email;
//			}
//			return *this;
//		}
//	
//	private:
//	
//	};
//	
//	Osoba::Osoba(std::string a_imie, std::string a_nazwisko, std::string a_email) {
//		imie = a_imie;
//		nazwisko = a_nazwisko;
//		email = a_email;
//		nast = nullptr;
//	}
//	
//	Osoba::Osoba(const Osoba& src) {
//		imie = src.imie;
//		nazwisko = src.nazwisko;
//		email = src.email;
//		nast = nullptr;
//	}
//	
//	void Osoba::wypisz() {
//		std::cout << "\n----------------------------------------------------" << std::endl;
//		std::cout << "[Osoba]" << std::endl;
//		std::cout << "Imie: " << imie << std::endl;
//		std::cout << "Nazwisko: " << nazwisko << std::endl;
//		std::cout << "E-mail: " << email << std::endl;
//		std::cout << "----------------------------------------------------\n" << std::endl;
//	}
//	
//	Osoba::Osoba()
//	{
//		imie = "Jan";
//		nazwisko = "Kowalski";
//		email = "jankowalski@gmail.com";
//		nast = nullptr;
//	}
//	
//	Osoba::~Osoba()
//	{
//		delete nast;
//	}
//	
//	std::string Osoba::getImie() {
//		return imie;
//	}
//	
//	std::string Osoba::getNazwisko() {
//		return nazwisko;
//	}
//	
//	std::string Osoba::getEmail() {
//		return email;
//	}
//	
//	void Osoba::setImie(std::string a_imie) {
//		this->imie = a_imie;
//	}
//	
//	void Osoba::setNazwisko(std::string a_nazwisko) {
//		this->nazwisko = a_nazwisko;
//	}
//	
//	void Osoba::setEmail(std::string a_email) {
//		this->email = a_email;
//	}
//	
//	class Pracownik;
//	
//	class Student : public Osoba {
//	public:
//		Student* nast;
//		int nr_indeksu;
//		int rok_rozpoczecia;
//		int get_Indeks() {
//			return nr_indeksu;
//		}
//		int get_Rozpoczecie() {
//			return rok_rozpoczecia;
//		}
//		void set_Indeks(int indeks) {
//			nr_indeksu = indeks;
//		}
//		void set_Rozpoczecie(int rok) {
//			rok_rozpoczecia = rok;
//		}
//		void wypisz() {
//			std::cout << "\n----------------------------------------------------" << std::endl;
//			std::cout << "[Student]" << std::endl;
//			std::cout << "Imie: " << imie << std::endl;
//			std::cout << "Nazwisko: " << nazwisko << std::endl;
//			std::cout << "Numer indeksu: " << nr_indeksu << std::endl;
//			std::cout << "Rok rozpoczecia: " << rok_rozpoczecia << std::endl;
//			std::cout << "E-mail: " << email << std::endl;
//			std::cout << "----------------------------------------------------\n" << std::endl;
//		}
//		Student() : Osoba(), nr_indeksu(0), rok_rozpoczecia(2000), nast(nullptr) {};
//
//		Student(const Student& src) : Osoba(src) {
//			nr_indeksu = src.nr_indeksu;
//			rok_rozpoczecia = src.rok_rozpoczecia;
//			nast = nullptr;
//		}
//
//		Student(std::string a_imie, std::string a_nazwisko, std::string a_email, int indeks, int rok) : Osoba(a_imie, a_nazwisko, a_email), nr_indeksu(indeks), rok_rozpoczecia(rok) {};
//
//		Student& operator = (const Student& src) {
//			Osoba::operator=(src);
//			nr_indeksu = src.nr_indeksu;
//			rok_rozpoczecia = src.rok_rozpoczecia;
//			nast = nullptr;
//			return *this;
//		}
//
//		Student& operator += (const Student& src) {
//			this->imie = imie + " " + src.imie;
//			this->nazwisko = nazwisko + " " + src.nazwisko;
//			this->email = email + " " + src.email;
//			nr_indeksu += src.nr_indeksu;
//			rok_rozpoczecia += src.rok_rozpoczecia;
//			return *this;
//		}
//
//		Student operator+(const Student& src) const {
//			std::string temp_imie = this->imie + " " + src.imie;
//			std::string temp_nazwisko = this->nazwisko + " " + src.nazwisko;
//			std::string temp_email = this->email + " " + src.email;
//			int temp_indeks = this->nr_indeksu + src.nr_indeksu;
//			int temp_rok = this->rok_rozpoczecia + src.rok_rozpoczecia;
//
//			Student result(temp_imie, temp_nazwisko, temp_email, temp_indeks, temp_rok);
//
//			return result;
//		}
//
//		bool operator==(const Student& src) const {
//			bool same_imie = (this->imie == src.imie);
//			bool same_nazwisko = (this->nazwisko == src.nazwisko);
//			bool same_email = (this->email == src.email);
//			bool same_indeks = (nr_indeksu == src.nr_indeksu);
//			bool same_rok = (rok_rozpoczecia == src.rok_rozpoczecia);
//			if (same_imie && same_nazwisko && same_email && same_indeks && same_rok)
//			{
//				return true;
//			}
//			else
//			{
//				return false;
//			}
//		}
//
//		friend std::istream& operator>>(std::istream& wejscie, Student& student) {
//			std::string line;
//			if (std::getline(wejscie, line)) {
//				std::stringstream ss(line);
//				ss >> student.imie >> student.nazwisko >> student.email >> student.nr_indeksu >> student.rok_rozpoczecia;
//			}
//			return wejscie;
//		}
//
//		friend std::ostream& operator<<(std::ostream& wyjscie, const Student& student) {
//			wyjscie << "Imie: " << student.imie;
//			wyjscie << " Nazwisko: " << student.nazwisko;
//			wyjscie << " Email: " << student.email;
//			wyjscie << " Nr indeksu: " << student.nr_indeksu;
//			wyjscie << " Rok rozpoczecia: " << student.rok_rozpoczecia << "\n\n";
//			return wyjscie;
//		}
//	};
//
//template <typename T>
//class Element {
//public:
//	T dane;
//	Element<T>* nast;
//	Element(T dane) {
//		this->dane = dane;
//		this->nast = nullptr;
//	}
//};
//
//
//template <typename T>
//class Kontener {
//public:
//
//	
//	std::string konterer_plik;
//
//	Element<T> *pierwszy;
//
//	Element<T>* wskaznik;
//
//	Kontener() {
//		konterer_plik = "";
//		pierwszy = nullptr;
//		wskaznik = nullptr;
//	}
//
//	Kontener(std::string nazwa_pliku){
//		open(nazwa_pliku);
//	}
//
//	~Kontener() {
//		while (pierwszy)
//		{
//			Element<T> *temp = pierwszy;
//			pierwszy = pierwszy->nast;
//			delete temp;
//		}
//	}
//
//
//	void open(std::string nazwa_pliku) {
//		std::ifstream plik(nazwa_pliku);
//
//		if (!plik)
//		{
//			std::cerr << "Nie udalo sie otworzyc pliku o nazwie: " << nazwa_pliku << std::endl;
//			return;
//		}
//
//		T temp;
//		while (plik >> temp)
//		{
//			Element<T>* nowy = new Element<T>(temp);
//			if (pierwszy == nullptr)
//			{
//				pierwszy = nowy;
//			}
//			else
//			{
//				Element<T>* aktualny = pierwszy;
//				while (aktualny->nast != nullptr)
//				{
//					aktualny = aktualny->nast;
//				}
//				aktualny->nast = nowy;
//			}
//		}
//
//		this->konterer_plik = nazwa_pliku;
//		this->wskaznik = pierwszy;
//
//		plik.close();
//	}
//
//	void save(){
//		if (konterer_plik == "")
//		{
//			return;
//		}
//		else
//		{
//			std::ofstream plik(konterer_plik);
//
//			if (!plik)
//			{
//				std::cerr << "Nie udalo sie otworzyc pliku o nazwie: " << konterer_plik << std::endl;
//				return;
//			}
//			else
//			{
//				Element<T>* aktualny = pierwszy;
//				while (aktualny != nullptr)
//				{
//					plik << aktualny->dane;
//					aktualny = aktualny->nast;
//				}
//
//			}
//
//			plik.close();
//		}
//	}
//
//	void save(std::string nazwa_pliku){
//		std::ofstream plik(nazwa_pliku);
//
//		if (!plik)
//		{
//			std::cerr << "Nie udalo sie otworzyc pliku o nazwie lub plik nie istnieje: " << nazwa_pliku << std::endl;
//		}
//
//			Element<T>* aktualny = pierwszy;
//			while (aktualny != nullptr)
//			{
//				plik << aktualny->dane;
//				aktualny = aktualny->nast;
//			}
//
//
//		plik.close();
//	}
//
//	void wypisz() {
//		Element<T>* aktualny = pierwszy;
//		while (aktualny != nullptr)
//		{
//			std::cout << aktualny->dane << std::endl;
//			aktualny = aktualny->nast;
//		}
//	}
//
//	T& get() {
//		if (wskaznik == nullptr)
//		{
//			std::cout << "Brak elementu pod wskaznikiem" << std::endl;
//		}
//
//		T& wynik = wskaznik->dane;
//
//		if (wskaznik->nast == nullptr)
//		{
//			wskaznik = nullptr;
//		}
//		else
//		{
//			wskaznik = wskaznik->nast;
//		}
//
//		return wynik;
//	}
//
//	void insert(T dane) {
//		if (wskaznik == nullptr)
//		{
//			return;
//		}
//		else
//		{
//			Element<T>* nowy = new Element<T>(dane);
//			nowy->nast = wskaznik->nast;
//			wskaznik->nast = nowy;
//			wskaznik = nowy;
//		}
//	}
//
//	bool end() {
//		if (wskaznik == nullptr)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	void rewind() {
//		if (pierwszy != nullptr)
//		{
//			wskaznik = pierwszy;
//		}
//		else
//		{
//			wskaznik = nullptr;
//		}
//	}
//};
//
//
//int main(){
//
//	Kontener<std::string>* napiski = new Kontener<std::string>("napisy.txt");
//
//	napiski->insert("Napis1");
//	napiski->insert("Napis2");
//	napiski->rewind();
//	napiski->insert("Napis3");
//	napiski->get();
//	napiski->insert("Napis4");
//	napiski->rewind();
//	napiski->get();
//	napiski->insert("Napis5");
//
//	napiski->save();
//
//	delete napiski;
//
//	return 0;
//}