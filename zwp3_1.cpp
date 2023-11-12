#include <fstream>
#include <iostream>
#include <exception>
#include <iomanip>
#include <cassert>

using namespace std;

double rand_double(){
	return rand() / (RAND_MAX + 1.0) * 10;
}

template <typename T>
class Element {
public:
	T dane;
	Element* nastepny;
	Element(T dane) {
		this->dane = dane;
		nastepny = nullptr;
	}
	Element() {
		this->dane = NULL;
		this->nastepny = nullptr;
	}
};

template <typename T>
class Kontener {
private:
	Element<T>* pierwszy;
public:
	Kontener() {
		pierwszy = nullptr;
	}
	void push(T dane) {
		Element<T>* nowy_element = new Element<T>(dane);
		if (pierwszy == nullptr)
		{
			pierwszy = nowy_element;
			return;
		}
		else
		{
			Element<T>* aktualny = pierwszy;
			while (aktualny->nastepny != nullptr)
			{
				aktualny = aktualny->nastepny;
			}
			aktualny->nastepny = nowy_element;
		}
	}
	void print_content() {
		if (pierwszy == nullptr)
		{
			cerr << "Lista jest pusta" << endl;
		}
		else
		{
			Element<T>* aktualny = pierwszy;
			int i = 1;
			while (aktualny != nullptr)
			{
				cout << "[" << i << "] " << aktualny->dane << endl;
				aktualny = aktualny->nastepny;
				i++;
			}
		}
	}
	Element<T>* getFirst() {
		return pierwszy;
	}
	class Kontener_Iterator {
	private:
		Kontener<T>& kolekcja;
		Element<T>* kursor;
	public:
		Kontener_Iterator(Element<T>* start, Kontener<T>& kontener) : kursor(start), kolekcja(kontener) {};
		Kontener_Iterator& operator++() {
			if (kursor)
			{
				kursor = kursor->nastepny;
			}
			return *this;
		}
		Kontener_Iterator operator++(int) {
			Kontener_Iterator temp = *this;
			++(*this);
			return temp;
		}
		T& operator*() {
			return kursor->dane;
		}
		bool operator!=(Kontener_Iterator other) {
			return kursor != other.kursor;
		}
		void rewind() {
			kursor = kolekcja.getFirst();
		}
		Kontener_Iterator& operator=(const Kontener_Iterator other) {
			if (this != &other)
			{
				kursor = other.kursor;
			}
			else
			{
				return *this;
			}
		}
		friend ostream& operator<<(ostream& stream, const Kontener_Iterator& iterator) {
			if (iterator.kursor != nullptr) {
				stream << iterator.kursor->dane;
			}
			else {
				stream << "[end]";
			}
			return stream;
		}
	};
	Kontener_Iterator begin() {
		return Kontener_Iterator(pierwszy, *this);
	}
	Kontener_Iterator end() {
		return Kontener_Iterator(nullptr, *this);
	}
};

template <typename T>
void roznicuj1(typename Kontener<T>::Kontener_Iterator& iterator1,typename Kontener<T>::Kontener_Iterator& iterator2,typename Kontener<T>::Kontener_Iterator& iterator3){
	int i = 1;
	while (iterator1 != iterator2)
	{
		*iterator1 = *iterator1 - *iterator3;
		iterator1++;
		iterator3++;
		i++;
	}
	iterator1.rewind();
	iterator3.rewind();
}

template <typename T>
void roznicuj2(typename Kontener<T>::Kontener_Iterator& iterator1,
	typename Kontener<T>::Kontener_Iterator& iterator2, T D) {
	int i = 1;
	while (iterator1 != iterator2)
	{
		*iterator1 = *iterator1 - D;
		iterator1++;
		i++;
	}
	iterator1.rewind();
}

template <typename T>
void do_kwadratu(typename Kontener<T>::Kontener_Iterator& iterator1,
	typename Kontener<T>::Kontener_Iterator& iterator2) {
	int i = 1;
	while (iterator1 != iterator2){
	*iterator1 = *iterator1 * *iterator1;
	iterator1++;
	i++;
	}
	iterator1.rewind();
}

int main() {
	int ile_pacjentow = 10;
	srand(time(NULL));
	Kontener<double> pudelko1;
	Kontener<double> pudelko2;
	for (int i = 0; i < ile_pacjentow; i++)
	{
		pudelko1.push(rand_double());
		pudelko2.push(rand_double());
	}
	auto iterator1 = pudelko1.begin();
	auto iterator2 = pudelko1.end();
	auto iterator3 = pudelko2.begin();
	cout << "Dane_1: " << endl;
	pudelko1.print_content();
	cout << "\nDane_2: " << endl;
	pudelko2.print_content();
	cout << endl;

	cout << "Liczenie wartosci D:" << endl;
	roznicuj1<double>(iterator1, iterator2, iterator3);
	double D = 0.0;
	while (iterator1 != iterator2)
	{
		D += *iterator1;
		iterator1++;
	}
	iterator1.rewind();
	D = (static_cast<double>(1) / ile_pacjentow) * D;
	cout << "D: " << D << endl;
	roznicuj2(iterator1, iterator2, D);
	do_kwadratu<double>(iterator1, iterator2);
	double S = 0.0;
	while (iterator1 != iterator2)
	{
		S += *iterator1;
		iterator1++;
	}
	S = (static_cast<double>(1) / (ile_pacjentow - 1)) * S;
	S = sqrt(S);
	cout << "S: " << S << endl;
	double T = D / (S / sqrt(ile_pacjentow));
	cout << "T = D / (S / sqrt(n)): " << T << endl;


	return 0;
}