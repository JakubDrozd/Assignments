//#include <iostream>
//#include <string>
//#include <fstream>
//#include <iomanip>
//
//using namespace std;
//
//ios_base::fmtflags flagi_domyslne;
//
//ostream& moj_manip(ostream& stream) {
//	flagi_domyslne = stream.flags();
//	stream.fixed;
//	stream.precision(3);
//	return stream;
//}
//
//ostream& normalne(ostream& stream) {
//	stream.flags(flagi_domyslne);
//	return stream;
//}
//
//ostream& scianka(ostream& stream) {
//	return stream << " | ";
//}
//
//class fixw {
//	string linia;
//public:
//	fixw(const string& src, int width) : linia(src, 0, width) {};
//	friend ostream& operator<<(ostream& stream, const fixw& fw);
//};
//
//ostream& operator<<(ostream& stream, const fixw& fw) {
//	stream.fixed;
//	return stream << fw.linia;
//}
//
//
//class format {
//private:
//	string text;
//	double text2;
//public:
//	format(const string& src1, const double& src2) : text(src1), text2(src2) {};
//	friend ostream& operator<<(ostream& stream, const format& element);
//};
//
//ostream& operator<<(ostream& stream, const format& element) {
//	static int i = 1;
//	string zaliczenie_text;
//	if (element.text2 >= 3.01)
//	{
//		zaliczenie_text = "ZALICZA";
//	}
//	else
//	{
//		zaliczenie_text = "NIE ZALICZA";
//	}
//	stream << "[" << i << ". " << setw(6) << setfill('*') << element.text.substr(element.text.length() - 3) << scianka << setprecision(3) << element.text2 << scianka << zaliczenie_text << "]" << endl;
//	i++;
//	return stream;
//}
//
//
//class Uczen {
//public:
//	string imie;
//	string nazwisko;
//	string indeks;
//	double srednia;
//	Uczen* nastepny;
//	virtual void wypisz() {
//		cout << imie << " " << nazwisko << " " << indeks << " " << srednia << endl;
//	}
//	Uczen();
//	Uczen(string imie, string nazwisko, string indeks, double srednia) : imie(imie), nazwisko(nazwisko), indeks(indeks), srednia(srednia), nastepny(nullptr) {};
//	Uczen(Uczen& src);
//};
//
//Uczen::Uczen() {
//	imie = "Jan";
//	nazwisko = "Kowalski";
//	indeks = "000000";
//	srednia = 0.00;
//	nastepny = nullptr;
//}
//
//Uczen::Uczen(Uczen& src) {
//	this->imie = src.imie;
//	this->nazwisko = src.nazwisko;
//	this->indeks = src.indeks;
//	this->srednia = src.srednia;
//	this->nastepny = nullptr;
//}
//
//class Grupa {
//public:
//	Uczen* pierwszy;
//	Grupa() {
//		pierwszy = nullptr;
//	}
//	void wypisz_grupe() {
//		Uczen* aktualny = pierwszy;
//		while (aktualny != nullptr)
//		{
//			aktualny->wypisz();
//			aktualny = aktualny->nastepny;
//		}
//	}
//};
//
//
//void dodaj_ucznia(Uczen **pierwszy, Uczen* nowy_uczen) {
//	nowy_uczen->nastepny = nullptr;
//	if (*pierwszy == nullptr)
//	{
//		*pierwszy = nowy_uczen;
//		return;
//	}
//	else
//	{
//		Uczen* aktualny = *pierwszy;
//		while (aktualny->nastepny != nullptr)
//		{
//			aktualny = aktualny->nastepny;
//		}
//		aktualny->nastepny = nowy_uczen;
//
//	}
//}
//
//int write(string nowy_plik, Uczen* pierwszy) {
//	ofstream file(nowy_plik);
//	if (!file.is_open())
//	{
//		cerr << "Blad zapisywania pliku" << endl;
//		return 1;
//	}
//	else
//	{
//		Uczen* aktualny = pierwszy;
//		while (aktualny != nullptr)
//		{
//			file << format(aktualny->indeks, aktualny->srednia);
//			aktualny = aktualny->nastepny;
//		}
//	}
//	file.close();
//	return 0;
//}
//
//
//int open(string nazwa_pliku) {
//	Grupa* klasa_inf = new Grupa();
//	ifstream plik(nazwa_pliku);
//	if (!plik.is_open())
//	{
//		cerr << "Blad przy otwieraniu pliku zrodlowego" << endl;
//		return 1;
//	}
//	else
//	{
//		Uczen* temp = new Uczen;
//		while (plik >> temp->imie >> temp->nazwisko >> temp->indeks >> temp->srednia)
//		{
//			Uczen *nowy_uczen = new Uczen;
//			nowy_uczen->imie = temp->imie;
//			nowy_uczen->nazwisko = temp->nazwisko;
//			nowy_uczen->srednia = temp->srednia;
//			nowy_uczen->indeks = temp->indeks;
//
//			dodaj_ucznia(&(klasa_inf->pierwszy), nowy_uczen);
//		}
//	}
//	klasa_inf->wypisz_grupe();
//	plik.close();
//	write("raport.txt", klasa_inf->pierwszy);
//	return 0;
//}
//
//ostream& cudzyslow(ostream& stream) {
//	stream << "'";
//	return stream;
//}
//
//template <typename T> 
//class alert {
//	T text;
//public:
//	alert(T message): text(message) {};
//	friend ostream& operator<< <T>(ostream& ostream, const alert<T> arg1);
//};
//
//template <typename T>
//ostream& operator<<(ostream& ostream, const alert<T> arg1) {
//	ostream << "#Alert: " << cudzyslow << arg1.text << cudzyslow << endl;
//	return ostream;
//}
//
//template<>
//class alert<int> {
//	int liczba;
//	string message;
//public:
//	alert(int data, string message) : liczba(data), message(message) {};
//	friend ostream& operator<<(ostream& ostream, const alert<int> arg1);
//};
//
//ostream& operator<<(ostream& ostream, const alert<int> arg1) {
//	ostream << "#Alert ID: " << arg1.liczba << scianka << cudzyslow << arg1.message << cudzyslow << endl;
//	return ostream;
//}
//
//ostream& spacja(ostream& stream) {
//	stream << " ";
//	return stream;
//}
//
//class Uczen_informatyki : public Uczen {
//public:
//	int grupa_zwp;
//	double ocena_z_zwp;
//	void wypisz();
//};
//
//void Uczen_informatyki::wypisz() {
//	cout << imie << spacja << nazwisko << spacja << indeks << spacja << srednia << spacja << grupa_zwp << spacja << ocena_z_zwp << endl;
//}
//
//class Wektor {
//public:
//	int x;
//	int y;
//	Wektor(int x, int y) : x(x), y(y) {};
//	Wektor operator+(const Wektor& other) {
//		return Wektor(x + other.x, y + other.y);
//	}
//	Wektor operator+=(const Wektor& other) {
//		x += other.x;
//		y += other.y;
//		return *this;
//	}
//};
//
//int main() {
//	open("tabelka.txt");
//	
//	cout << alert<string>("Nowa wiadomosc");
//	cout << alert<int>(1, "Nowa wiadomosc");
//
//	Wektor w1(1, 2);
//	Wektor w2(3, 4);
//
//	w1 += w2;
//	cout << w1.x << " " << w1.y << endl;
//	return 0;
//}