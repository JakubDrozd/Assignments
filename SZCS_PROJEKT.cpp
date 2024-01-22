#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <random>

class Klient {
public:
    std::string pesel;
    std::string numerTel;
    std::string imie;
    std::string nazwisko;
};

class Zamowienie {
public:
    int numerZamowienia;
    std::string pesel;
    std::string numerCzesci;
    std::string opisZamowienia;
};

class Czesc {
public:
    std::string numerID;
    std::string nazwa;
    std::string opis;
    bool naStanie;
};


class Kontrola {
public:
    static bool sprawdzPesel(const std::string& pesel) {
        return pesel.length() == 11 && std::all_of(pesel.begin(), pesel.end(), ::isdigit);
    }

    static bool sprawdzNumerTelefonu(const std::string& numer) {
        return numer.length() == 9 && std::all_of(numer.begin(), numer.end(), ::isdigit);
    }

    static bool czyZawieraCyfry(const std::string& s) {
        return std::any_of(s.begin(), s.end(), ::isdigit);
    }

    static int sprawdzNumerCzesci(const std::string& s, const std::vector<Czesc>& container) {
        if (!(s.length() == 5 && std::all_of(s.begin(), s.end(), ::isdigit))) {
            return -1;
        }
        auto it = std::find_if(container.begin(), container.end(),
            [&](const Czesc& item) {
                return item.numerID == s;
            });
        return (it != container.end()) ? 0 : -2;
    }

    static void clearScreen() {
        std::system("cls");
    }

    static void generujFakture(const Zamowienie& zamowienie, const Klient& klient, const Czesc& czesc) {
        std::ofstream plik("faktura_" + std::to_string(zamowienie.numerZamowienia) + ".txt");

        if (!plik) {
            std::cerr << "Nie mozna utworzyc pliku faktury.\n";
            return;
        }

        std::time_t teraz = std::time(nullptr);
        char dataWystawienia[20];
        char dataSprzedazy[20];
        std::strftime(dataWystawienia, sizeof(dataWystawienia), "%Y-%m-%d", std::localtime(&teraz));

        std::tm dataDostawyTm = *std::localtime(&teraz);
        dataDostawyTm.tm_mday += czesc.naStanie ? 0 : 7;
        std::mktime(&dataDostawyTm);
        std::strftime(dataSprzedazy, sizeof(dataSprzedazy), "%Y-%m-%d", &dataDostawyTm);

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(150, 1000);
        int losowaCena = distr(gen);

        plik << "Data wystawienia: " << dataWystawienia << "\n";
        plik << "Data sprzedazy: " << dataSprzedazy << "\n\n";
        plik << "Sprzedawca: Sklep z czesciami samochodowymi\n";
        plik << "NIP: 123456789\n";
        plik << "Adres: Kasprzowicza 62 / 11, 01-871 Warszawa\n\n";
        plik << "Nabywca:\n";
        plik << klient.imie << " " << klient.nazwisko << "\n";
        plik << "PESEL: " << klient.pesel << "\n";
        plik << "Telefon: " << klient.numerTel << "\n\n";
        plik << "Faktura nr: " << zamowienie.numerZamowienia << "\n\n";
        plik << "Lp. Nazwa produktu Cena\n";
        plik << "1 " << czesc.nazwa << " " << losowaCena << " PLN\n\n";
        plik << "Sposob platnosci: na miejscu, gotowka\n";
        plik << "Termin platnosci: " << dataSprzedazy << "\n\n";
        plik << "Podpis sprzedajacego\n\n";
        plik << "Podpis kupujacego\n";

        plik.close();
        std::cout << "Faktura zostala wygenerowana jako 'faktura_" << zamowienie.numerZamowienia << ".txt'.\n";
    }
};

class BazaDanych {
public:
    std::vector<Klient> klienci;
    std::vector<Zamowienie> zamowienia;
    std::vector<Czesc> czesci;
    int ostatniNumerZamowienia = 10000;

    BazaDanych() {
        inicjalizujCzesci();
    }

    void dodajKlienta(const Klient& klient) {
        klienci.push_back(klient);
        zapiszKlienta(klient);
    }

    void dodajZamowienie(const Zamowienie& zamowienie) {
        zamowienia.push_back(zamowienie);
        zapiszZamowienie(zamowienie);
    }

    void wczytajDane() {
        wczytajKlientow();
        wczytajZamowienia();
    }

    int generujNumerZamowienia() {
        return ++ostatniNumerZamowienia;
    }

    void wyswietlCzesci() {
        for (const auto& czesc : czesci) {
            std::cout << "[" << czesc.numerID << "]: " << czesc.nazwa << " - \"" << czesc.opis << "\"\n-\n";
        }
    }

    Czesc znajdzCzescPoID(const std::string& s) {
        auto it = czesci.begin();
        it = find_if(czesci.begin(), czesci.end(),
            [&](const Czesc& item) {
                return item.numerID == s;
            });
        if (it != czesci.end())
        {
            return *it;
        }
        else
        {
            std::cerr << "Nie znaleziono czesci o ID: " << s << std::endl;
            return Czesc();
        }
    }

private:
    void zapiszKlienta(const Klient& klient) {
        std::ofstream plik("Klienci.txt", std::ios::app);
        plik << klient.pesel << " " << klient.numerTel << " " << klient.imie << " " << klient.nazwisko << "\n";
        plik.close();
    }

    void zapiszZamowienie(const Zamowienie& zamowienie) {
        std::ofstream plik("Zamowienia.txt", std::ios::app);
        plik << zamowienie.numerZamowienia << " " << zamowienie.pesel << " " << zamowienie.numerCzesci << " " << zamowienie.opisZamowienia << "\n";
        plik.close();
    }

    void wczytajKlientow() {
        std::ifstream plik("Klienci.txt");
        std::string linia;
        while (std::getline(plik, linia)) {
            std::istringstream iss(linia);
            Klient klient;
            iss >> klient.pesel >> klient.numerTel >> klient.imie >> klient.nazwisko;
            klienci.push_back(klient);
        }
        plik.close();
    }

    void wczytajZamowienia() {
        std::ifstream plik("Zamowienia.txt");
        std::string linia;
        while (std::getline(plik, linia)) {
            std::istringstream iss(linia);
            Zamowienie zamowienie;
            iss >> zamowienie.numerZamowienia >> zamowienie.pesel >> zamowienie.numerCzesci;
            iss.ignore();
            std::getline(iss, zamowienie.opisZamowienia);
            if (zamowienie.opisZamowienia == "")
            {
                auto it = find_if(czesci.begin(), czesci.end(), [&](const Czesc& item) {
                    return item.numerID == zamowienie.numerCzesci;
                    });
                zamowienie.opisZamowienia = it->nazwa;
            }
            ostatniNumerZamowienia = zamowienie.numerZamowienia;
            zamowienia.push_back(zamowienie);
        }
        plik.close();
    }

    void inicjalizujCzesci() {
        czesci.push_back({ "10001", "Filtr oleju", "Filtr do silnika benzynowego", true });
        czesci.push_back({ "10002", "Filtr powietrza", "Filtr do silnika diesla", true });
        czesci.push_back({ "10003", "Pasek rozrzadu", "Pasek do silnika 1.9 TDI", false });
        czesci.push_back({ "10004", "Swieca zaplonowa", "Swieca do silnika benzynowego", true });
        czesci.push_back({ "10005", "Amortyzator", "Amortyzator przedni do modelu XYZ", false });
        czesci.push_back({ "10006", "Opona letnia", "Rozmiar 205/55 R16", true });
        czesci.push_back({ "10007", "Lampy przednie", "Halogeny do modelu ABC", false });
        czesci.push_back({ "10008", "Klocki hamulcowe", "Komplet klockow do osi przedniej", false });
        czesci.push_back({ "10009", "Rozrusznik", "Rozrusznik elektryczny 12V", true });
        czesci.push_back({ "10010", "Wycieraczki", "Komplet wycieraczek przednich", true});
        czesci.push_back({ "10011", "Alternator", "Alternator do silnika diesla", false });
        czesci.push_back({ "10012", "Tlumik koncowy", "Tlumik do modelu sportowego", true });
        czesci.push_back({ "10013", "Zbiornik paliwa", "Zbiornik paliwa 60l do modelu sedan", false });
        czesci.push_back({ "10014", "Pompa wody", "Pompa wody do silnika V8", true });
        czesci.push_back({ "10015", "Filtr kabinowy", "Filtr przeciwpylkowy do klimatyzacji", true });
        czesci.push_back({ "10016", "Lozysko kola", "Przednie lozysko kola do SUV", false });
        czesci.push_back({ "10017", "Zestaw sprzegla", "Kompletny zestaw sprzegla do manualnej skrzyni biegow", true });
        czesci.push_back({ "10018", "Radiator chlodnicy", "Radiator do systemu chlodzenia silnika", false });
        czesci.push_back({ "10019", "Pasek klinowy", "Pasek klinowy do alternatora", true });
        czesci.push_back({ "10020", "Wahacz zawieszenia", "Dolny wahacz przedniego zawieszenia", true });


    }
};

void wczytajDaneKlienta(Klient& klient) {
    while (true) {
        std::cout << "Podaj PESEL: ";
        std::cin >> klient.pesel;
        if (!Kontrola::sprawdzPesel(klient.pesel)) {
            std::cout << "Niepoprawny PESEL. Sprobuj ponownie.\n";
            continue;
        }
        break;
    }

    while (true) {
        std::cout << "Podaj numer telefonu: ";
        std::cin >> klient.numerTel;
        if (!Kontrola::sprawdzNumerTelefonu(klient.numerTel)) {
            std::cout << "Niepoprawny numer telefonu. Sprobuj ponownie.\n";
            continue;
        }
        break;
    }

    std::cin.ignore();
    while (true) {
        std::cout << "Podaj imie: ";
        std::getline(std::cin, klient.imie);
        if (Kontrola::czyZawieraCyfry(klient.imie)) {
            std::cout << "Imie nie moze zawierac cyfr. Sprobuj ponownie.\n";
            continue;
        }
        break;
    }

    while (true) {
        std::cout << "Podaj nazwisko: ";
        std::getline(std::cin, klient.nazwisko);
        if (Kontrola::czyZawieraCyfry(klient.nazwisko)) {
            std::cout << "Nazwisko nie moze zawierac cyfr. Sprobuj ponownie.\n";
            continue;
        }
        break;
    }
}

void wczytajDaneZamowienia(Zamowienie& zamowienie, BazaDanych& baza) {
    while (true) {
        std::cout << "Podaj 5-cyfrowy numer czesci: ";
        std::getline(std::cin, zamowienie.numerCzesci);

        int sprawdz = Kontrola::sprawdzNumerCzesci(zamowienie.numerCzesci, baza.czesci);
        if (sprawdz == -1 || sprawdz == -2) {
            std::cout << "Niepoprawny numer czesci. Sprobuj ponownie.\n";
            continue;
        }

        auto czesc = std::find_if(baza.czesci.begin(), baza.czesci.end(), [&](const Czesc& item) {
            return item.numerID == zamowienie.numerCzesci;
            });

        if (!czesc->naStanie) {
            std::cout << "Wybrana czesc nie znajduje sie na stanie magazynu.\n";
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distr(1, 7);
            int dniDoDostawy = distr(gen);

            std::time_t teraz = std::time(0);
            std::tm* dataDostawy = std::localtime(&teraz);
            dataDostawy->tm_mday += dniDoDostawy;
            std::mktime(dataDostawy);

            std::cout << "Przewidywana data dostawy: " << dataDostawy->tm_mday << "-" << dataDostawy->tm_mon + 1 << "-" << dataDostawy->tm_year + 1900 << "\n";
        }

        zamowienie.opisZamowienia = czesc->nazwa;
        break;
    }

    zamowienie.numerZamowienia = baza.generujNumerZamowienia();
}

void wyswietlZamowienia(const BazaDanych& baza) {
    for (const auto& zamowienie : baza.zamowienia) {
        std::cout << "Numer zamowienia: [" << zamowienie.numerZamowienia << "], PESEL: [" << zamowienie.pesel
            << "], Numer czesci: [" << zamowienie.numerCzesci << "], Opis: [" << zamowienie.opisZamowienia << "]\n";
    }
}

int main() {
    BazaDanych baza;
    baza.wczytajDane();
    int wybor;

    do {
       Kontrola::clearScreen();
        std::cout << "Menu glowne\n";
        std::cout << "1. Zamow czesci\n";
        std::cout << "2. Wyswietl zamowienia\n";
        std::cout << "3. Wyswietl dostepne czesci\n";
        std::cout << "4. Wyjdz\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> wybor;

        if (wybor == 1) {
            Kontrola::clearScreen();
            Klient klient;
            Zamowienie zamowienie;
            Czesc czesc;
            wczytajDaneKlienta(klient);
            wczytajDaneZamowienia(zamowienie, baza);

            zamowienie.pesel = klient.pesel;
            czesc = baza.znajdzCzescPoID(zamowienie.numerCzesci);
            baza.dodajKlienta(klient);
            baza.dodajZamowienie(zamowienie);

            char odpowiedz;
            std::cout << "Czy chcesz otrzymac fakture? (t/n): ";
            std::cin >> odpowiedz;
            if (odpowiedz == 't' || odpowiedz == 'T') {
                Kontrola::generujFakture(zamowienie, klient, czesc);
            }
            std::cout << "Nacisnij Enter, aby kontynuowac...";
            std::cin.ignore();
            std::cin.get();
        }
        else if (wybor == 2) {
            Kontrola::clearScreen();
            wyswietlZamowienia(baza);
            std::cout << "Nacisnij dowolny klawisz, aby kontynuowac...\n";
            std::cin.get();
            std::cin.get();
        }
        else if (wybor == 3) {
            Kontrola::clearScreen();
            baza.wyswietlCzesci();
            std::cout << "Nacisnij dowolny klawisz, aby kontynuowac...\n";
            std::cin.get();
            std::cin.get();
        }

    } while (wybor != 4);

    return 0;
}