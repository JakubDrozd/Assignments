#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>

struct Klient {
    std::string pesel;
    std::string numerTel;
    std::string imie;
    std::string nazwisko;
};

struct Zamowienie {
    int numerZamowienia;
    std::string pesel;
    std::string numerCzesci;
    std::string opisZamowienia;
};

struct Czesc {
    std::string numerID;
    std::string nazwa;
    std::string opis;
    bool operator==(const Czesc& czesc) {
        return this->numerID == czesc.numerID;
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
            zamowienia.push_back(zamowienie);
        }
        plik.close();
    }

    void inicjalizujCzesci() {
        czesci.push_back({ "10001", "Filtr oleju", "Filtr do silnika benzynowego" });
        czesci.push_back({ "10002", "Filtr powietrza", "Filtr do silnika diesla" });
        czesci.push_back({ "10003", "Pasek rozrzadu", "Pasek do silnika 1.9 TDI" });
        czesci.push_back({ "10004", "Swieca zaplonowa", "Swieca do silnika benzynowego" });
        czesci.push_back({ "10005", "Amortyzator", "Amortyzator przedni do modelu XYZ" });
        czesci.push_back({ "10006", "Opona letnia", "Rozmiar 205/55 R16" });
        czesci.push_back({ "10007", "Lampy przednie", "Halogeny do modelu ABC" });
        czesci.push_back({ "10008", "Klocki hamulcowe", "Komplet klockow do osi przedniej" });
        czesci.push_back({ "10009", "Rozrusznik", "Rozrusznik elektryczny 12V" });
        czesci.push_back({ "10010", "Wycieraczki", "Komplet wycieraczek przednich" });
    }
};
bool sprawdzPesel(const std::string& pesel) {
    return pesel.length() == 11 && std::all_of(pesel.begin(), pesel.end(), ::isdigit);
}

bool sprawdzNumerTelefonu(const std::string& numer) {
    return numer.length() == 9 && std::all_of(numer.begin(), numer.end(), ::isdigit);
}

bool czyZawieraCyfry(const std::string& s) {
    return std::any_of(s.begin(), s.end(), ::isdigit);
}

int sprawdzNumerCzesci(const std::string& s, const std::vector<Czesc>& container) {
    if (!(s.length() == 5 && std::all_of(s.begin(), s.end(), ::isdigit)))
    {
        return -1;
    }
    auto it = container.begin();
    it = std::find_if(container.begin(), container.end(),
        [&](const Czesc& item) {
            return item.numerID == s;
        });
    if (it == container.end())
    {
        return -2;
    }
    return 0;
}

void clearScreen() {
    std::system("cls");
}

void wczytajDaneKlienta(Klient& klient) {
    while (true) {
        std::cout << "Podaj PESEL: ";
        std::cin >> klient.pesel;
        if (!sprawdzPesel(klient.pesel)) {
            std::cout << "Niepoprawny PESEL. Sprobuj ponownie.\n";
            continue;
        }
        break;
    }

    while (true) {
        std::cout << "Podaj numer telefonu: ";
        std::cin >> klient.numerTel;
        if (!sprawdzNumerTelefonu(klient.numerTel)) {
            std::cout << "Niepoprawny numer telefonu. Sprobuj ponownie.\n";
            continue;
        }
        break;
    }

    std::cin.ignore();
    while (true) {
        std::cout << "Podaj imie: ";
        std::getline(std::cin, klient.imie);
        if (czyZawieraCyfry(klient.imie)) {
            std::cout << "Imie nie moze zawierac cyfr. Sprobuj ponownie.\n";
            continue;
        }
        break;
    }

    while (true) {
        std::cout << "Podaj nazwisko: ";
        std::getline(std::cin, klient.nazwisko);
        if (czyZawieraCyfry(klient.nazwisko)) {
            std::cout << "Nazwisko nie moze zawierac cyfr. Sprobuj ponownie.\n";
            continue;
        }
        break;
    }
}

void wczytajDaneZamowienia(Zamowienie& zamowienie, BazaDanych& baza) {
    while (true)
    {
        std::cout << "Podaj 5-cyfrowy numer czesci: ";
        std::getline(std::cin, zamowienie.numerCzesci);
        if (sprawdzNumerCzesci(zamowienie.numerCzesci, baza.czesci) == -1)
        {
            std::cout << "Numer czesci musi byc 5-cyfrowym numerem. Sprobuj ponownie.\n";
            continue;
        }
        if (sprawdzNumerCzesci(zamowienie.numerCzesci, baza.czesci) == -2)
        {
            std::cout << "Czesc o podanym numerze nie istnieje. Sprobuj ponownie.\n";
            continue;
        }
        break;
    }
    std::cout << "Opis zamowienia: ";
    std::getline(std::cin, zamowienie.opisZamowienia);

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
        clearScreen();
        std::cout << "Menu glowne\n";
        std::cout << "1. Zamow czesci\n";
        std::cout << "2. Wyswietl zamowienia\n";
        std::cout << "3. Wyswietl dostepne czesci\n";
        std::cout << "4. Wyjdz\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> wybor;

        if (wybor == 1) {
            Klient klient;
            Zamowienie zamowienie;
            wczytajDaneKlienta(klient);
            wczytajDaneZamowienia(zamowienie, baza);

            zamowienie.pesel = klient.pesel;

            baza.dodajKlienta(klient);
            baza.dodajZamowienie(zamowienie);

            std::cout << "Zamowienie zostalo zlozone. Numer zamowienia: " << zamowienie.numerZamowienia << "\n";
            std::cout << "Nacisnij dowolny klawisz, aby kontynuowac...\n";
            std::cin.get();
            std::cin.get();
        }
        else if (wybor == 2) {
            wyswietlZamowienia(baza);
            std::cout << "Nacisnij dowolny klawisz, aby kontynuowac...\n";
            std::cin.get();
            std::cin.get();
        }
        else if (wybor == 3) {
            clearScreen();
            baza.wyswietlCzesci();
            std::cout << "Nacisnij dowolny klawisz, aby kontynuowac...\n";
            std::cin.get();
            std::cin.get();
        }

    } while (wybor != 4);

    return 0;
}