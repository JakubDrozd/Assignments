//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//#include <stdexcept>
//#include <ctime>
//#include <cmath>
//#include <iomanip>
//
//using namespace std;
//
//
//static bool czy_pierwsza(int liczba) {
//    for (int i = 2; i <= liczba / 2; i++)
//        if (!(liczba % i))
//            return 0;
//    return 1;
//}
//
//class Przepelnienie : public exception {
//    char opis[100];
//public:
//    Przepelnienie(const char* o) { strcpy_s(opis, o); }
//    const char* what() const throw() { return opis; };
//};
//class BrakDanych : public exception {
//    char opis[100];
//public:
//    BrakDanych(const char* o) { strcpy_s(opis, o); }
//    const char* what() const throw() { return opis; };
//};
//
//class _Bazowe_Cechy {
//public:
//    static const bool _jest_liczba = false;
//    static const bool _nalezy_do_przedzialu = false;
//    static const bool _jest_liczba_calkowita = false;
//    static const bool _jest_liczba_pierwsza = false;
//    static const int _liczby_po_przecinku = 0;
//    static const bool _dazy_do_nieskonczonosci = false;
//};
//
//template<typename T>
//class _Cechy : public _Bazowe_Cechy {
//public:
//    static const T _dolna_granica() { return T(); };
//    static const T _gorna_granica() { return T(); };
//};
//
//template<typename T>
//class Cechy : public _Cechy<T> {
//};
//
//
//class minuta_dnia {
//    int minuta;
//public:
//    minuta_dnia(int minuta = 0) : minuta(minuta) {};
//    int operator()() const { return minuta; };
//    minuta_dnia& operator=(int minuta) { this->minuta = minuta; return *this; };
//    bool operator<(const minuta_dnia& src) const { return (this->minuta < src.minuta); };
//    friend ostream& operator<<(ostream& stream, const minuta_dnia&);
//};
//
//template<>
//class Cechy<minuta_dnia> : public _Cechy<minuta_dnia> {
//public:
//    static const bool _jest_liczba = true;
//    static const bool _nalezy_do_przedzialu = true;
//    static const bool _jest_liczba_calkowita = true;
//    static const minuta_dnia _dolna_granica() { return minuta_dnia(0); };
//    static const minuta_dnia _gorna_granica() { return minuta_dnia(1439); };
//};
//
//ostream& operator<<(ostream& stream, const minuta_dnia& src) {
//    stream.precision(Cechy<minuta_dnia>::_liczby_po_przecinku);
//    return stream << src.minuta;
//};
//
//
//class czasNaWybicie {
//    int godzina;
//public:
//    czasNaWybicie(int godzina = 1) : godzina(godzina) {};
//    int operator()() const { return godzina; };
//    czasNaWybicie& operator=(int num) { godzina = num; return *this; };
//    bool operator<(const czasNaWybicie& src) const { return (godzina < src.godzina); };
//    friend ostream& operator<<(ostream& stream, const czasNaWybicie&);
//};
//
//template<>
//class Cechy<czasNaWybicie> : public _Cechy<czasNaWybicie> {
//public:
//    static const bool _jest_liczba = true;
//    static const bool _nalezy_do_przedzialu = true;
//    static const bool _jest_liczba_calkowita = true;
//    static const czasNaWybicie _dolna_granica() { return czasNaWybicie(1); };
//    static const czasNaWybicie _gorna_granica() { return czasNaWybicie(12); };
//    static const int _liczby_po_przecinku = 2;
//};
//
//ostream& operator<<(ostream& stream, const czasNaWybicie& src) {
//    stream.precision(Cechy<czasNaWybicie>::_liczby_po_przecinku);
//    return stream << src.godzina * 0.8 + (src.godzina - 1) * 1.2;
//};
//
//
//class ilosc_piwa {
//    int litry;
//public:
//    ilosc_piwa(int litry = 1) : litry(litry) {};
//    int operator()() const { return litry; };
//    ilosc_piwa& operator=(int litry) { litry = litry; return *this; };
//    bool operator<(const ilosc_piwa& src) const { return (litry < src.litry); };
//    friend ostream& operator<<(ostream& stream, const ilosc_piwa&);
//};
//
//template<>
//class Cechy<ilosc_piwa> : public _Cechy<ilosc_piwa> {
//public:
//    static const bool _jest_liczba = true;
//    static const bool _nalezy_do_przedzialu = true;
//    static const bool _dazy_do_nieskonczonosci = true;
//    static const bool _jest_liczba_calkowita = true;
//    static const int _liczby_po_przecinku = 2;
//    static const ilosc_piwa _dolna_granica() { return ilosc_piwa(1); };
//};
//
//
//ostream& operator<<(ostream& stream, const ilosc_piwa& src) {
//    stream.precision(Cechy<ilosc_piwa>::_liczby_po_przecinku);
//    return stream << fixed << src.litry * 0.568 << "l";
//};
//
//
//class liczba_pierwsza {
//    int wartosc;
//public:
//    liczba_pierwsza(int wartosc = 2) : wartosc(wartosc) {};
//    int operator()() const { return wartosc; };
//    liczba_pierwsza& operator=(int num) { wartosc = num; return *this; };
//    bool operator<(const liczba_pierwsza& src) const { return (wartosc < src.wartosc); };
//    friend ostream& operator<<(ostream& stream, const liczba_pierwsza& src);
//};
//
//template<>
//class Cechy<liczba_pierwsza> : public _Cechy<liczba_pierwsza> {
//public:
//    static const bool _jest_liczba = true;
//    static const bool _nalezy_do_przedzialu = true;
//    static const bool _dazy_do_nieskonczonosci = true;
//    static const bool _jest_liczba_calkowita = true;
//    static const bool _jest_liczba_pierwsza = true;
//    static const liczba_pierwsza _dolna_granica() { return liczba_pierwsza(2); };
//};
//
//ostream& operator<<(ostream& stream, const liczba_pierwsza& src) {
//    stream.precision(Cechy<liczba_pierwsza>::_liczby_po_przecinku);
//    return stream << src.wartosc;
//};
//
//template<typename T, int rozmiar, typename CechyT = Cechy<T>>
//class SzablonStosu {
//    T stos[rozmiar];
//    int top;
//public:
//    int zajetosc() { return top; };
//    SzablonStosu() : top(0) {}
//    void push(const T& i) {
//        if (top == rozmiar)
//            throw Przepelnienie(typeid(i).name());
//        stos[top++] = i;
//    }
//    void push(int i) {
//        if (top == rozmiar)
//            throw Przepelnienie(typeid(i).name());
//
//        if (CechyT::_jest_liczba && CechyT::_jest_liczba_calkowita) {
//            if (CechyT::_jest_liczba_pierwsza) {
//                if (czy_pierwsza((i))) {
//                    stos[top++] = i;
//                }
//            }
//            else {
//                if (CechyT::_nalezy_do_przedzialu) {
//                    if (CechyT::_dazy_do_nieskonczonosci) {
//                        if (!(T(i) < CechyT::_dolna_granica())) {
//
//                            stos[top++] = i;
//                        }
//                    }
//                    else {
//                        if (!(T(i) < CechyT::_dolna_granica()) && !(CechyT::_gorna_granica() < T(i)))
//                            stos[top++] = i;
//                    }
//                }
//                else
//                    stos[top++] = i;
//            }
//        }
//    }
//    void push(double i) {
//        if (top == rozmiar)
//            throw Przepelnienie(typeid(i).name());
//        if (CechyT::_jest_liczba && !CechyT::_jest_liczba_calkowita) {
//            if (CechyT::_nalezy_do_przedzialu) {
//                if (CechyT::_dazy_do_nieskonczonosci) {
//                    if (!(T(i) < CechyT::_dolna_granica())) {
//
//                        stos[top++] = i;
//                    }
//                }
//                else {
//                    if (!(T(i) < CechyT::_dolna_granica()) && !(CechyT::_gorna_granica() < T(i)))
//                        stos[top++] = i;
//                }
//            }
//            else
//                stos[top++] = i;
//        }
//    }
//    T pop() {
//        if (top == 0)
//            throw BrakDanych(typeid(stos[0]).name());
//
//        return stos[--top];
//    }
//    template<typename U1, int r, typename U2>
//    friend ostream& operator<<(ostream& stream, const SzablonStosu<U1, r, U2>&);
//};
//template<typename U1, int r, typename U2>
//ostream& operator<<(ostream& stream, const SzablonStosu<U1, r, U2>& S)
//{
//    stream << "Zawartosc stosu:" << endl;
//    for (int i = 0; i < S.top; i++) cout << S.stos[i] << endl;
//    return stream << endl;
//};
//
//class Stos2 {
//    static const int rozmiar = 10;
//protected:
//    double stos[rozmiar];
//    int top;
//public:
//    int zajetosc() { return top; };
//    Stos2() : top(0) {};
//    virtual void push(const double& i) {
//        if (top == rozmiar)
//            throw Przepelnienie(typeid(i).name());
//        stos[top++] = i;
//    }
//    virtual double pop() {
//        if (top == 0)
//            throw BrakDanych(typeid(stos[0]).name());
//        return stos[--top];
//    }
//};
//
//template <class T>
//class domieszka1 : public T {
//public:
//    double pop() {
//        if (T::top == 0) {
//            throw BrakDanych(typeid(T::stos[0]).name());
//        }
//        cout << "Ilosc elementow na stosie: " << T::zajetosc() << endl;
//        double temp = T::pop();
//        cout << "Zdejmowana wartosc: " << temp << endl;
//        return temp;
//    }
//};
//
//template<class T>
//class domieszka2 : public T {
//protected:
//    double suma = 0;
//public:
//    void push(const double &i) {
//        T::push(i);
//        suma += i;
//        cout << "Suma stosu = " << suma << endl;
//    }
//    double pop() {
//        double temp = T::pop();
//        suma -= temp;
//        if (suma < 0.00001)
//        {
//            suma = 0.0;
//        }
//        cout << "Suma stosu = " << suma << endl;
//        return temp;
//    }
//};
//
//
//int main() {
//    try {
//        domieszka2<domieszka1<Stos2>> kolekcja;
//        kolekcja.push(1.1);
//        kolekcja.push(1.2);
//        kolekcja.push(1.3);
//        kolekcja.push(1.4);
//        kolekcja.push(1.5);
//        for (int i = 0; i < 5; i++) { kolekcja.pop(); };
//
//    }
//    catch (const std::exception& e) {
//        cerr << e.what() << endl;
//    }
//
//    return 0;
//}
