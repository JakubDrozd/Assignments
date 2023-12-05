//#include <iostream>
//#include <fstream>
//#include <string>
//#include <exception>
//
//using namespace std;
//
//template <typename T>
//class Element
//{
//public:
//	T dane;
//	Element* nastepny;
//	Element(T dane) : dane(dane), nastepny(nullptr) {};
//};
//
//template <typename T>
//class Stos
//{
//public:
//	Stos() :top(nullptr) {};
//	void push(Element<T> element) {
//		Element<T>* new_element = new Element<T>(element);
//		new_element->nastepny = top;
//		top = new_element;
//	}
//	void pop() {
//		if (top != nullptr)
//		{
//			Element<T>* temp = top;
//			top = top->nastepny;
//			delete temp;
//		}
//	}
//	~Stos() {
//		while (top != nullptr)
//		{
//			pop();
//		}
//	}
//
//private:
//	Element<T>* top;
//};
//
//
//
//
//
//int main() {
//	Stos<string> kolekcja1;
//	
//	for (int i = 0; i < 20; i++)
//	{
//		string temp = "abc" + to_string(i + 1);
//		kolekcja1.push(temp);
//	}
//	
//}