#include <iostream>
#include <fstream>
#include <string>
#include <exception>
using namespace std;

ostream& spacja(ostream& stream) {
	stream << " ";
	return stream;
}

class Uczen {
public:
	string imie;
	string nazwisko;
	int indeks;

	Uczen(string imie, string nazwisko, int indeks) : imie(imie), nazwisko(nazwisko), indeks(indeks) {};
	Uczen() {
		imie = "UnkownName";
		nazwisko = "UnkownSurname";
		indeks = 0;
	}

	friend ostream& operator<<(ostream& stream, const Uczen src) {
		stream << src.imie << spacja << src.nazwisko << spacja << src.indeks << endl;
		return stream;
	}
};

class BetterFile
{
public:
	BetterFile(string nazwa_pliku);
	~BetterFile();
	void read_file();
	void write_file(string nazwa_pliku);
private:
	fstream file;
};

BetterFile::BetterFile(string nazwa_pliku) : file(nazwa_pliku, ios::in | ios::out | ios::app) {
	if (!file.is_open())
	{
		throw runtime_error("!#!Blad operacji na pliku: " + nazwa_pliku + "!#!");
	}
}

BetterFile::~BetterFile()
{
	file.close();
}

void BetterFile::read_file() {
	string aktualna_linia;
	while (getline(file, aktualna_linia))
	{
		cout << aktualna_linia << endl;
	}
}

void BetterFile::write_file(string data) {
	for (int i = 1; i <= 10; i++)
	{
		this->file << data << " [" << i << "]" << endl;
	}
}

template <typename T, int rozmiar>
class Stos
{
public:
	int top;
	T stos[rozmiar];
	Stos() : top(0) {};
	void push(T& element) {
		stos[top++] = element;
	}
	T pop() {
		return stos[--top];
	}
	void print() {
		for (int i = 0; i < top; i++)
		{
			cout << stos[i] << endl;
		}
	}

	//Iterator klasy

	class iterator
	{
	public:
		iterator(Stos& stos) : kolekcja(stos), wskaznik(0) {};
		iterator(Stos& stos, bool) : kolekcja(stos), wskaznik(kolekcja.top) {};
		T operator++(int) {
			if (wskaznik > kolekcja.top)
			{
				throw runtime_error("Wykroczenie poza kontener");
			}
			return kolekcja.stos[wskaznik++];
		}
		T operator++() {
			if (wskaznik > kolekcja.top)
			{
				throw runtime_error("Wykroczenie poza kontener");
			}
			return kolekcja.stos[++wskaznik];
		}
		bool operator==(const iterator src) {
			return wskaznik == src.wskaznik;
		}
		bool operator!=(const iterator src) {
			return wskaznik != src.wskaznik;
		}
		T operator*() const {
			return kolekcja.stos[wskaznik];
		}
		iterator& operator=(const iterator& src) {
			wskaznik = src.wskaznik;
			return *this;
		}

	private:
		Stos& kolekcja;
		int wskaznik;
	};
	
	iterator begin() {
		return iterator(*this);
	}
	iterator end() {
		return iterator(*this, true);
	}

	friend class iterator;
};

template<typename iter>
void wypisz(iter start, iter end) {
	while (start != end)
	{
		cout << *start << endl;
		start++;
	}
}

void zakonczenie() {
	cout << "Program zostal przerwany" << endl;
	abort();
}

int main() {
	terminate_handler new_handler = set_terminate(zakonczenie);
	try
	{
		BetterFile plik("tabelka.txt");
		plik.read_file();
		BetterFile plik2("tester.txt");
		plik2.write_file("TESTER ");
		Stos<Uczen, 10> kontener;
		for (int i = 0; i < 10; i++)
		{
			string temp_imie = "uczen" + to_string(i);
			string temp_nazwisko = "nazwisko" + to_string(i);
			int temp_indeks = 12347 * 10 + i;
			Uczen uczen(temp_imie, temp_nazwisko, temp_indeks);
			kontener.push(uczen);
		}
		wypisz(kontener.begin(), kontener.end());
		
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
	}
	return 0;
}


