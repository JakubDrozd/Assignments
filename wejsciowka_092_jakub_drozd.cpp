#include <iostream>
#include <math.h>
#include <iomanip>
#include <conio.h>

struct koordynaty {
	double x;
	double y;
};

class Kolo {
private:
	double polozenie_x;
	double polozenie_y;
	double promien;
public:
	Kolo(double x = 0, double y= 0, double r = 0): polozenie_x(x), polozenie_y(y), promien(r){}
	void ustaw_wymiary(double x, double y, double r) {
		polozenie_x = x;
		polozenie_y = y;
		if (r < 0)
		{
			std::cout << "!!!Niepoprawne wymiary, ustawiam domyslne!!!" << std::endl;
			promien = 1;
		}
		else
		{
			promien = r;
		}
	}
	void odczyt() {
		std::cout << "Wspolrzedne srodka kola: [" << polozenie_x << "," << polozenie_y << "]" << std::endl;
		std::cout << "Promien kola: " << promien << std::endl;
	}
	void przeksztalcenie(double n){
		if (polozenie_x == n)
		{
			return;
		}
		double odleglosc = fabs(n - polozenie_x);
		double nowe_polozenie_x;
		if (n > polozenie_x)
		{
			nowe_polozenie_x = n + odleglosc;
		}
		else if (n < polozenie_x)
		{
			nowe_polozenie_x = n - odleglosc;
		}
		polozenie_x = nowe_polozenie_x;
	}
	void skalowanie(double k){
		if (k <= 0)
		{
			std::cout << "!!!Skala musi byc wieksza od 0!!!" << std::endl;
			return;
		}
		promien *= k;
	}
};

class TrapezRownoramienny
{
private:
	double polozenie_x;
	double polozenie_y;
	double podstawa_a;
	double podstawa_b;
	double wysokosc;
public:
	TrapezRownoramienny(double x = 0, double y = 0, double a = 0, double b = 0, double h = 0) :
		polozenie_x(x), polozenie_y(y), podstawa_a(a), podstawa_b(b), wysokosc(h) {}
	void ustaw_wymiary(double x, double y, double a, double b, double h) {
		polozenie_x = x;
		polozenie_y = y;
		if (a <= 0 || b <= 0 || h <= 0)
		{
			std::cout << "!!!Niepoprawne wymiary, ustawiam domyslne!!!" << std::endl;
			podstawa_a = 1;
			podstawa_b = 0.7;
			wysokosc = 1;
		}
		else
		{
			podstawa_a = a;
			podstawa_b = b;
			wysokosc = h;
		}
	}
	void odczyt() {
		koordynaty a;
		koordynaty b;
		koordynaty c;
		koordynaty d;

		a.x = polozenie_x;
		a.y = polozenie_y;

		b.x = polozenie_x + podstawa_a;
		b.y = polozenie_y;

		double srodek = (podstawa_a - podstawa_b) / 2;
		c.x = polozenie_x + srodek;
		c.y = polozenie_y + wysokosc;

		d.x = polozenie_x + podstawa_b + srodek;
		d.y = polozenie_y + wysokosc;

		double ramie = sqrt(pow(wysokosc, 2) + pow(srodek, 2));

		std::cout << "Koordynaty wierzcholka a: [" << a.x << "," << a.y << "]" << std::endl;
		std::cout << "Koordynaty wierzcholka b: [" << b.x << "," << b.y << "]" << std::endl;
		std::cout << "Koordynaty wierzcholka c: [" << c.x << "," << c.y << "]" << std::endl;
		std::cout << "Koordynaty wierzcholka d: [" << d.x << "," << d.y << "]" << std::endl;
		std::cout << "Podstawa A: " << podstawa_a << std::endl;
		std::cout << "Podstawa B: " << podstawa_b << std::endl;
		std::cout << "Wysokosc: " << wysokosc << std::endl;
		std::cout << "Ramie: " << std::fixed << std::setprecision(2) << ramie << std::endl;
	}
	void przeksztalcenie(double n) {
		double nowe_polozenie_x = 0;
		if ((polozenie_x + podstawa_a) == n)
		{
			nowe_polozenie_x = n;
		}
		else if (n == polozenie_x + podstawa_a / 2)
		{
			return;
		}
		else
		{
			nowe_polozenie_x = 2.0 * n - polozenie_x - podstawa_a;
		}

		polozenie_x = nowe_polozenie_x;
	}
};


int main() {
	char znak;
	Kolo kolo1;
	Kolo kolo2;
	Kolo kolo3;

	TrapezRownoramienny trapez1;
	TrapezRownoramienny trapez2;
	TrapezRownoramienny trapez3;

	Kolo tablica_kol[3]{ kolo1, kolo2, kolo3 };
	TrapezRownoramienny tablica_trapez[3]{ trapez1, trapez2, trapez3 };

	std::cout << "Wybierz typ figury, ktory chcesz zmodyfikowac:\n[k] - kolo \t [t] - trapez \t [dowolny inny znak] - Koniec programu" << std::endl;
	std::cin >> znak;
	while (true)
	{
		if (znak == 'q')
		{
			std::cout << "Zakonczenie dzialania programu" << std::endl;
			return 0;
		}
		if (znak == 'k')
		{
			int wybor;
			int wybor_modyfikacji;
			std::cout << "[Wybrales kolo]" << std::endl;
			std::cout << "Podaj numer 1-3 aby wybrac kolo: ";
			std::cin >> wybor;
			Kolo& aktualne_kolo = tablica_kol[wybor - 1];
			std::cout << "Wybierz modyfikacje, ktora chcesz przeprowadzic: " << std::endl;
			std::cout << "[1] - Ustawienie wymiarow\t[2] - Przeksztalcenie wzgledem osi x\t[3] - Skalowanie" << std::endl;
			std::cin >> wybor_modyfikacji;
			if (wybor_modyfikacji == 1)
			{
				double polozenie_x;
				double polozenie_y;
				double promien;
				std::cout << "[Ustawianie wymiarow figury nr " << wybor << "]" << std::endl;
				std::cout << "Podaj wspolrzedne srodka kola: ";
				std::cin >> polozenie_x >> polozenie_y;
				std::cout << "Podaj promien kola: ";
				std::cin >> promien;
				aktualne_kolo.ustaw_wymiary(polozenie_x, polozenie_y, promien);
				std::cout << "[Wymiary figury nr " << wybor << "]" << std::endl;
				aktualne_kolo.odczyt();
			}
			else if (wybor_modyfikacji == 2)
			{
				double n;
				std::cout << "[Przeksztalcanie wzgledem osi x]" << std::endl;
				std::cout << "Podaj os wzgledem ktorej ma zostac wykonane przeksztalcenie x = ";
				std::cin >> n;
				aktualne_kolo.przeksztalcenie(n);
				std::cout << "[Po przeksztalceniu]" << std::endl;
				aktualne_kolo.odczyt();
			}
			else if (wybor_modyfikacji == 3)
			{
				double k;
				std::cout << "[Skalowanie figury nr " << wybor << "]" << std::endl;
				std::cout << "Podaj skale k = ";
				std::cin >> k;
				aktualne_kolo.skalowanie(k);
				std::cout << "[Po skalowaniu]" << std::endl;
				aktualne_kolo.odczyt();
			}
			else
			{
				std::cout << "Operacja nieznana, koniec programu" << std::endl;
				return 0;
			}
			std::cout << "Wybierz typ figury, ktory chcesz zmodyfikowac:\n[k] - kolo \t [t] - trapez \t [dowolny inny znak] - Koniec programu" << std::endl;
			std::cin >> znak;
		}
		else if (znak == 't')
		{
			std::cout << "[Wybrales trapez]" << std::endl;
			int wybor;
			int wybor_modyfikacji;
			std::cout << "Podaj numer 1-3 aby wybrac trapez: ";
			std::cin >> wybor;
			TrapezRownoramienny& aktualny_trapez = tablica_trapez[wybor - 1];
			std::cout << "Wybierz modyfikacje, ktora chcesz przeprowadzic: " << std::endl;
			std::cout << "[1] - Ustawienie wymiarow\t[2] - Przeksztalcenie wzgledem osi x" << std::endl;
			std::cin >> wybor_modyfikacji;
			if (wybor_modyfikacji == 1)
			{
				double polozenie_x;
				double polozenie_y;
				double wysokosc;
				double podstawa_a;
				double podstawa_b;
				std::cout << "[Ustawianie wymiarow figury nr " << wybor << "]" << std::endl;
				std::cout << "Podaj wspolrzedne lewego dolnego wierzcholka figury: ";
				std::cin >> polozenie_x >> polozenie_y;
				std::cout << "Podaj rozmiar podstawy dolnej: ";
				std::cin >> podstawa_a;
				std::cout << "Podaj rozmiar podstawy gornej: ";
				std::cin >> podstawa_b;
				std::cout << "Podaj wysokosc: ";
				std::cin >> wysokosc;
				aktualny_trapez.ustaw_wymiary(polozenie_x, polozenie_y, podstawa_a, podstawa_b, wysokosc);
				std::cout << "[Wymiary figury nr " << wybor << "]" << std::endl;
				aktualny_trapez.odczyt();
			}
			else if (wybor_modyfikacji == 2)
			{
				double n;
				std::cout << "[Przeksztalcanie wzgledem osi x]" << std::endl;
				std::cout << "Podaj os wzgledem ktorej ma zostac wykonane przeksztalcenie x = ";
				std::cin >> n;
				aktualny_trapez.przeksztalcenie(n);
				std::cout << "[Po przeksztalceniu]" << std::endl;
				aktualny_trapez.odczyt();
			}
			else
			{
				std::cout << "Operacja nieznana, koniec programu" << std::endl;
				return 0;
			}
			std::cout << "Wybierz typ figury, ktory chcesz zmodyfikowac:\n[k] - kolo \t [t] - trapez \t [dowolny inny znak] - Koniec programu" << std::endl;
			std::cin >> znak;
		}
		else
		{
			std::cout << "Zakonczenie pracy programu" << std::endl;
			return 0;
		}
	}
	return 0;
}