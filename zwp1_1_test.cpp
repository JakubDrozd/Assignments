#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

struct Dane
{
	int ID;
	char nick[10];
	unsigned level;
	double pkt;

	bool operator>(const Dane& src) {
		return this->level > src.level;
	}
};

ostream& scianka(ostream& stream) {
	stream << "|";
	return stream;
}

ostream& rysuj_linie(ostream& stream) {
	stream << "+------+" << string(10, '-') << "+-------+" << string(6, '-') << "+" << endl;
	return stream;
}

ostream& operator<<(ostream& stream, const Dane& dane) {
	stream << scianka << setw(6) << setfill('0') << dane.ID << scianka;
	stream << setw(10) << setfill(' ') << left << dane.nick << scianka;
	stream << setw(7) << setfill(' ') << right << dane.level << scianka;
	stream << setw(6) << setfill(' ') << right << fixed << setprecision(1) << dane.pkt << scianka;
	return stream;
}

ostream& glowny_header(ostream& stream) {
	stream << scianka << setw(6) << setfill('0') << "ID" << scianka;
	stream << setw(10) << setfill(' ') << left << "nick" << scianka;
	stream << setw(7) << setfill(' ') << right << fixed << setprecision(1) << "level" << scianka;
	stream << setw(6) << setfill(' ') << right << "pkt" << scianka;
	return stream;
}

ostream& naglowek(ostream& stream) {
	time_t aktualny_czas;
	time(&aktualny_czas);
	char buffer[26];
	errno_t err = ctime_s(buffer, sizeof(buffer), &aktualny_czas);
	stream << setw(35);
	stream << right << buffer << endl;
	stream << getenv("COMPUTERNAME");
	return stream;
}

template <typename T, int rozmiar>
class Tablica {
	T A[rozmiar];
public:
	T& operator[](int index);
};

template <typename T, int rozmiar>
T& Tablica<T, rozmiar>::operator[](int index)
{
	if (index >= rozmiar || index < 0)
		return A[0];
	else
		return A[index];
}

template <typename T, int rozmiar>
ostream& stopka(ostream& stream, Tablica<T, rozmiar>& tabelka) {
	Dane maxLevelDane = tabelka[0];

	for (int i = 1; i < rozmiar; i++) {
		if (tabelka[i].ID >= 0)
		{
			if (tabelka[i] > maxLevelDane) {
				maxLevelDane = tabelka[i];
			}
		}
	}

	stream << rysuj_linie;
	stream << scianka << setw(6) << setfill('0') << 0 << scianka;
	stream << setw(10) << setfill(' ') << " " << scianka;
	stream << setw(7) << setfill(' ') << right << maxLevelDane.level << scianka;
	stream << setw(6) << setfill(' ') << right << fixed << setprecision(1) << maxLevelDane.pkt << scianka << endl;


	return stream;
}

template <typename T, int rozmiar>
void write(Tablica<T, rozmiar>& tabelka, const string& nazwa_pliku) {
	ofstream file(nazwa_pliku);
	if (!file.is_open())
	{
		cerr << "Blad zapisywania pliku" << endl;
		return;
	}
	else
	{
		file << naglowek << endl;
		file << rysuj_linie;
		file << glowny_header << endl;
		file << rysuj_linie;
		for (int i = 0; i < rozmiar; i++)
		{
			if (tabelka[i].ID >= 0)
			{
				file << tabelka[i] << endl;
			}
		}
		stopka(file, tabelka);
		file << rysuj_linie;

	}
	file.close();
	return;
}

int main() {
	Tablica<Dane, 10> tabelka;
	tabelka[0] = { 1, "nick1", 57, 301.00 };
	tabelka[1] = { 2, "nick2", 34, 212.02 };
	tabelka[2] = { 3, "nick3", 22, 181.19 };
	tabelka[3] = { 4, "nick4", 11, 97.38 };
	tabelka[4] = { 5, "nick5", 98, 13.38 };
	string nazwa_pliku;

	cout << "Podaj nazwe pliku do zapisu: ";
	cin >> nazwa_pliku;
	nazwa_pliku += ".txt";
	write(tabelka, nazwa_pliku);
	cout << (tabelka[0] > tabelka[1]) << endl;
	system(("start " + nazwa_pliku).c_str());
}