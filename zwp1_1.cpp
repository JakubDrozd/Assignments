//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//#include <iostream>
//#include <string>
//#include <fstream>
//#include <ctime>
//#include <iomanip>
//using namespace std;
//
//struct Dane
//{
//	int id;
//	char nazwa[10];
//	double temp;
//	double pojemn;
//
//	Dane& operator+=(const Dane& other) {
//		this->temp += other.temp;
//		this->pojemn += other.pojemn;
//		return *this;
//	}
//};
//
//ostream& scianka(ostream& stream) {
//	stream << "|";
//	return stream;
//}
//
//ostream& rysuj_linie(ostream& stream) {
//	stream << "+------+" << string(10, '-') << "+-------+" << string(6, '-') << "+" << endl;
//	return stream;
//}
//
//ostream& operator<<(ostream& stream, const Dane& dane) {
//	stream << scianka << setw(6) << setfill('0') << dane.id << scianka;
//	stream << setw(10) << setfill(' ') << left << dane.nazwa << scianka;
//	stream << setw(7) << setfill(' ') << right << fixed << setprecision(1) << dane.temp << scianka;
//	stream << setw(6) << setfill(' ') << right << static_cast<int>(dane.pojemn) << scianka;
//	return stream;
//}
//
//ostream& naglowek(ostream& stream) {
//	time_t aktualny_czas;
//	time(&aktualny_czas);
//	char buffer[26];
//	errno_t err = ctime_s(buffer, sizeof(buffer), &aktualny_czas);
//	if (err) {
//		std::cerr << "Error converting time." << std::endl;
//	}
//	stream << setw(43);
//	stream << right << buffer << endl;
//	stream << getenv("COMPUTERNAME");
//	return stream;
//}
//
//template <typename T, int rozmiar>
//class Tablica {
//	T A[rozmiar];
//public:
//	T& operator[](int index);
//};
//
//template <typename T, int rozmiar>
//T& Tablica<T, rozmiar>::operator[](int index)
//{
//	if (index >= rozmiar || index < 0)
//		return A[0];
//	else
//		return A[index];
//}
//
//ostream& stopka(ostream& stream, Tablica<Dane, rozmiar>& tabelka) {
//	Dane suma = {};
//
//	for (int i = 0; i < rozmiar; i++) {
//		if (tabelka[i].id > 0) {
//			suma.temp += tabelka[i].temp;
//			suma.pojemn += tabelka[i].pojemn;
//		}
//	}
//
//	stream << rysuj_linie;
//	stream << scianka << setw(6) << setfill(' ') << " " << scianka;
//	stream << setw(10) << setfill(' ') << "SUMA" << scianka;
//	stream << setw(7) << setfill(' ') << right << fixed << setprecision(1) << suma.temp << scianka;
//	stream << setw(6) << setfill(' ') << right << static_cast<int>(suma.pojemn) << scianka << endl;
//
//	return stream;
//}
//
//template <typename T, int rozmiar>
//void write(Tablica<T, rozmiar>& tabelka, string nazwa_pliku) {
//	ofstream file(nazwa_pliku);
//	if (!file.is_open())
//	{
//		cerr << "Blad zapisywania pliku" << endl;
//		return;
//	}
//	else
//	{
//		file << naglowek << endl;
//		file << rysuj_linie;
//		for (int i = 0; i < rozmiar; i++)
//		{
//			if (tabelka[i].id > 0)
//			{
//				file << tabelka[i] << endl;
//			}
//		}
//	}
//	file.close();
//	return;
//}
//
//int main() {
//	Tablica<Dane, 10> tabelka;
//	tabelka[0] = { 1, "Nazwa1", 19.97, 301.00 };
//	tabelka[1] = { 2, "Nazwa2", 37.68, 212.02 };
//
//	write(tabelka, "raport.txt");
//	cout << naglowek;
//}