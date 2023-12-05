//#include <iostream>
//#include <string>
//#include <fstream>
//#include <exception>
//
//using namespace std;
//
//class blad_html : exception {
//private:
//	string alert;
//public:
//	blad_html(const string &message, int numer_linijki) {
//		alert = "Blad w linijce " + to_string(numer_linijki) + ": " + message;
//	}
//
//	const char* what() const noexcept override {
//		return alert.c_str();
//	}
//};
//
//class Stos {
//private:
//    struct Element {
//        string data;
//        Element* nastepny;
//        Element(const string& data, Element* nastepny = nullptr) : data(data), nastepny(nastepny) {}
//    };
//
//    Element* gorny_element;
//
//public:
//    Stos() : gorny_element(nullptr) {}
//
//    ~Stos() {
//        while (gorny_element) {
//            pop();
//        }
//    }
//
//    void push(const string& value) {
//        Element* temp = new Element(value, gorny_element);
//        gorny_element = temp;
//    }
//
//    void pop() {
//        if (gorny_element == nullptr) {
//            throw runtime_error("Stos jest pusty");
//        }
//        Element* temp = gorny_element;
//        gorny_element = gorny_element->nastepny;
//        delete temp;
//    }
//
//    string top() {
//        if (gorny_element == nullptr) {
//            throw runtime_error("Stos jest pusty");
//        }
//        return gorny_element->data;
//    }
//
//    bool empty() const {
//        return gorny_element == nullptr;
//    }
//};
//
//
//void sprawdzanie(istream& input) {
//    string linia_kodu;
//    int numer_linii = 0;
//    Stos stos_tagow;
//
//    while (getline(input, linia_kodu)) {
//        numer_linii++;
//        size_t znaleziono = linia_kodu.find('<');
//        while (znaleziono != string::npos) {
//            size_t znaleziono_koniec = linia_kodu.find('>', znaleziono);
//            if (znaleziono_koniec == string::npos) {
//                throw blad_html("Niedomkniety tag", numer_linii);
//            }
//
//            string tag = linia_kodu.substr(znaleziono + 1, znaleziono_koniec - znaleziono - 1);
//            bool czy_zamykajacy = tag[0] == '/';
//            if (czy_zamykajacy) {
//                tag = tag.substr(1);
//                if (stos_tagow.empty() || stos_tagow.top() != tag) {
//                    throw blad_html("Niesparowany tag zamkniecia: " + tag, numer_linii);
//                }
//                stos_tagow.pop();
//            }
//            else {
//                stos_tagow.push(tag);
//            }
//            znaleziono = linia_kodu.find('<', znaleziono_koniec);
//        }
//    }
//
//    if (!stos_tagow.empty()) {
//        throw blad_html("Nie zamknieto wszystkich tagow", numer_linii);
//    }
//}
//
//
//
//int main() {
//	ifstream plik("bledny_html.txt");
//	if (!plik.is_open())
//	{
//		cerr << "Blad otwierania pliku zrodlowego" << endl;
//		return 1;
//	}
//	try
//	{
//		sprawdzanie(plik);
//		cout << "Plik jest poprawny" << endl;
//	}
//	catch (const blad_html &e)
//	{
//		cerr << e.what() << endl;
//	}
//
//
//
//	return 0;
//}