//#include <iostream>
//#include <fstream>
//#include <exception>
//#include <iomanip>
//#include <ctime>
//
//using namespace std;
//
//double rand_double() {
//	return rand() / (RAND_MAX + 1.0);
//}
//
//template <typename T>
//class Element {
//private:
//	T dane;
//	Element* nastepny;
//public:
//	Element(T dane) : dane(dane), nastepny(nullptr) {};
//	Element() : dane(T()), nastepny(nullptr) {};
//	Element* get_Next() { return nastepny; };
//	T& get_Dane() { return dane; };
//	void set_Next(Element* new_next) { nastepny = new_next; };
//
//};
//
//
//template <typename T>
//class Kontener {
//private:
//	Element<T>* pierwszy;
//public:
//	Kontener() : pierwszy(nullptr) {};
//	void push(T dane);
//	void print();
//	Element<T>* get_First() { return pierwszy; };
//	~Kontener();
//	class Iterator {
//	private:
//		Kontener<T>& kolekcja;
//		Element<T>* kursor;
//		bool is_End;
//	public:
//		Iterator(Kontener<T>& kontener) : kolekcja(kontener), kursor(kolekcja.pierwszy), is_End(false) {};
//		Iterator(Kontener<T>& kontener, bool koniec) :kolekcja(kontener), kursor(nullptr), is_End(koniec) {};
//		T& operator*() { return kursor->get_Dane(); };
//		Element<T>* operator++() {
//			kursor = kursor->get_Next();
//			return kursor;
//		}
//		Element<T>* operator++(int) {
//			Element<T>* temp = kursor;
//			++(*this);
//			return temp;
//		}
//		void operator=(const Iterator &other) {
//			this->kursor = other.kursor;
//		}
//		void rewind() {
//			kursor = kolekcja.pierwszy;
//		}
//		bool operator!=(const Iterator &other) {
//			return kursor != other.kursor;
//		}
//	};
//	Iterator begin() {
//		return Iterator(*this);
//	}
//	Iterator end() {
//		return Iterator(*this, true);
//	}
//};
//
//
//
//template <typename T>
//void Kontener<T>::push(T dane) {
//	Element<T>* new_element = new Element<T>(dane);
//	if (pierwszy == nullptr)
//	{
//		pierwszy = new_element;
//		return;
//	}
//	else
//	{
//		Element<T>* aktualny = pierwszy;
//		while (aktualny->get_Next() != nullptr)
//		{
//			aktualny = aktualny->get_Next();
//		}
//		aktualny->set_Next(new_element);
//	}
//}
//
//template <typename T>
//Kontener<T>::~Kontener() {
//	Element<T>* aktualny = pierwszy;
//	while (aktualny != nullptr)
//	{
//		Element<T>* temp = aktualny;
//		aktualny = aktualny->get_Next();
//		delete temp;
//	}
//}
//
//template <typename T>
//void Kontener<T>::print() {
//	Element<T>* aktualny = pierwszy;
//	while (aktualny != nullptr)
//	{
//		cout << aktualny->get_Dane() << endl;
//		aktualny = aktualny->get_Next();
//	}
//}
//
//
//
//
//
//int main() {
//	srand((unsigned int)time(NULL));
//	Kontener<double> kontener1;
//	Kontener<double> kontener2;
//	for (int i = 0; i < 10; i++)
//	{
//		kontener1.push(rand_double());
//		kontener2.push(rand_double());
//	}
//
//	auto iterator1 = kontener1.begin();
//	auto iterator2 = kontener1.end();
//	
//
//	while (iterator1 != iterator2)
//	{
//		cout << *iterator1 << endl;
//		iterator1++;
//	}
//
//	
//
//	return 0;
//}