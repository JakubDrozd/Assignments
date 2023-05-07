//b

#include <iostream>
#include <math.h>
#include <iomanip>

struct koordynaty {
	double x;
	double y;
};


class Prostokat {
private:
	double polozenie_x;
	double polozenie_y;
	double podstawa;
	double wysokosc;
public:
	Prostokat();
	Prostokat(double x, double y, double a, double h);
	Prostokat(Prostokat& src);
	~Prostokat();
	void ustaw_wymiary(double x, double y, double a, double h);
	void odczyt();
	void przeksztalcenie(double n);
	void skalowanie(double k);
	Prostokat* nast;
};

Prostokat::Prostokat() {
	polozenie_x = 0;
	polozenie_y = 0;
	podstawa = 1;
	wysokosc = 1;
	nast = nullptr;
}

Prostokat::Prostokat(double x, double y, double a, double h) {
	polozenie_x = x;
	polozenie_y = y;
	podstawa = a;
	wysokosc = h;
	nast = nullptr;
}

Prostokat::Prostokat(Prostokat& src) {
	polozenie_x = src.polozenie_x;
	polozenie_y = src.polozenie_y;
	podstawa = src.podstawa;
	wysokosc = src.wysokosc;
	nast = src.nast;
}

Prostokat::~Prostokat() {
		delete nast;
}

void Prostokat::ustaw_wymiary(double x, double y, double a, double h) {
	polozenie_x = x;
	polozenie_y = y;
	if (a <= 0 || h <= 0)
	{
		std::cout << "!!!Niepoprawne wymiary, ustawiam domyslne!!!" << std::endl;
		podstawa = 1;
		wysokosc = 1;
	}
	else
	{
		podstawa = a;
		wysokosc = h;
	}
}

void Prostokat::odczyt() {

	double pole = podstawa * wysokosc;

	koordynaty a;
	koordynaty b;
	koordynaty c;
	koordynaty d;

	a.x = polozenie_x;
	a.y = polozenie_y;

	b.x = polozenie_x + podstawa;
	b.y = polozenie_y;

	c.x = polozenie_x;
	c.y = polozenie_y + wysokosc;

	d.x = polozenie_x + podstawa;
	d.y = polozenie_y + wysokosc;

	std::cout << "Koordynaty wierzcholka a: [" << a.x << "," << a.y << "]" << std::endl;
	std::cout << "Koordynaty wierzcholka b: [" << b.x << "," << b.y << "]" << std::endl;
	std::cout << "Koordynaty wierzcholka c: [" << c.x << "," << c.y << "]" << std::endl;
	std::cout << "Koordynaty wierzcholka d: [" << d.x << "," << d.y << "]" << std::endl;
	std::cout << "Podstawa: " << podstawa << std::endl;
	std::cout << "Wysokosc: " << wysokosc << std::endl;
	std::cout << "Pole: " << pole << std::endl;
	printf("\n");
}

void Prostokat::przeksztalcenie(double n){
		double nowe_polozenie_x = 0;
		if ((polozenie_x + podstawa) == n)
		{
			nowe_polozenie_x = n;
		}
		else if (n == polozenie_x + podstawa / 2)
		{
			return;
		}
		else
		{
			nowe_polozenie_x = 2.0 * n - polozenie_x - podstawa;
		}

		polozenie_x = nowe_polozenie_x;
}

void Prostokat::skalowanie(double k) {
	podstawa *= k;
	wysokosc *= k;
}

class TrapezRownoramienny
{
private:
	double polozenie_x;
	double polozenie_y;
	double podstawa_a;
	double podstawa_b;
	double wysokosc;
public:
	TrapezRownoramienny();
	TrapezRownoramienny(double x, double y, double a, double b, double h);
	TrapezRownoramienny(TrapezRownoramienny& src);
	~TrapezRownoramienny();

	void ustaw_wymiary(double x, double y, double a, double b, double h);
	void odczyt();
	void przeksztalcenie(double n);
	TrapezRownoramienny* nast;
};

TrapezRownoramienny::TrapezRownoramienny() {
	polozenie_x = 0;
	polozenie_y = 0;
	podstawa_a = 1;
	podstawa_b = 1;
	wysokosc = 1;
	nast = nullptr;
}

TrapezRownoramienny::TrapezRownoramienny(double x, double y, double a, double b, double h) {
	polozenie_x = x;
	polozenie_y = y;
	podstawa_a = a;
	podstawa_b = b;
	wysokosc = h;
	nast = nullptr;
}

TrapezRownoramienny::TrapezRownoramienny(TrapezRownoramienny& src) {
	polozenie_x = src.polozenie_x;
	polozenie_y = src.polozenie_y;
	podstawa_a = src.podstawa_a;
	podstawa_b = src.podstawa_b;
	wysokosc = src.wysokosc;
	nast = src.nast;
}

TrapezRownoramienny::~TrapezRownoramienny() {
		delete nast;
}

void TrapezRownoramienny::ustaw_wymiary(double x, double y, double a, double b, double h) {
	polozenie_x = x;
	polozenie_y = y;
	if (a <= 0 || b <= 0 || h <= 0)
	{
		std::cout << "Niepoprawne wymiary, ustawiam domyslne (1)" << std::endl;
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

void TrapezRownoramienny::odczyt() {
	koordynaty a;
	koordynaty b;
	koordynaty c;
	koordynaty d;

	double pole = ((podstawa_a + podstawa_b) * wysokosc) / 2;
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
	std::cout << "Pole: " << pole << std::endl;
	std::cout << "Ramie: " << std::fixed << std::setprecision(2) << ramie << std::endl;
	printf("\n");
}

void TrapezRownoramienny::przeksztalcenie(double n) {
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

class blejtram
{
public:
	TrapezRownoramienny* pierw_trap;
	Prostokat* pierw_pros;
	blejtram() {
		pierw_trap = nullptr;
		pierw_pros = nullptr;
	}
	void symetria_osiowa(double n);
	void wypisz(void);
	TrapezRownoramienny* dodaj_trapez(TrapezRownoramienny* trapez) {
		if (pierw_trap == nullptr)
		{
			pierw_trap = trapez;
		}
		else
		{
			TrapezRownoramienny* aktualny = pierw_trap;
			while (aktualny->nast != nullptr)
			{
				aktualny = aktualny->nast;
			}
			aktualny->nast = trapez;
		}
		return trapez;
	}
	Prostokat* dodaj_prostokat(Prostokat* prostokat) {
		if (pierw_pros == nullptr)
		{
			pierw_pros = prostokat;
		}
		else
		{
			Prostokat* aktualny = pierw_pros;
			while (aktualny->nast != nullptr)
			{
				aktualny = aktualny->nast;
			}
			aktualny->nast = prostokat;
		}
		return prostokat;
	}
	~blejtram() {
		delete pierw_trap;
		delete pierw_pros;
	}
private:
};

void blejtram::symetria_osiowa(double n) {
	TrapezRownoramienny* aktualny = pierw_trap;
	while (aktualny != nullptr)
	{
		aktualny->przeksztalcenie(n);
		aktualny = aktualny->nast;
	}

	Prostokat* curr = pierw_pros;
	while (curr != nullptr)
	{
		curr->przeksztalcenie(n);
		curr = curr->nast;
	}
}

void blejtram::wypisz() {
	TrapezRownoramienny* aktualny = pierw_trap;
	while (aktualny != nullptr)
	{
		aktualny->odczyt();
		aktualny = aktualny->nast;
	}

	Prostokat* curr = pierw_pros;
	while (curr != nullptr)
	{
		curr->odczyt();
		curr = curr->nast;
	}
}

int main() {

	Prostokat* pro1 = new Prostokat();
	Prostokat* pro2 = new Prostokat(4, 1, 6, 3);
	Prostokat* pro3 = new Prostokat(1, 1, 3, 2);
	Prostokat* pro4 = new Prostokat(*pro3);

	TrapezRownoramienny* trap1 = new TrapezRownoramienny();
	TrapezRownoramienny* trap2 = new TrapezRownoramienny(-4, 1, 6, 4, 3);
	TrapezRownoramienny* trap3 = new TrapezRownoramienny(*trap2);

	blejtram* blej = new blejtram();
	blej->dodaj_prostokat(pro1);
	blej->dodaj_prostokat(pro2);
	blej->dodaj_prostokat(pro3);
	blej->dodaj_prostokat(pro4);
	blej->dodaj_trapez(trap1);
	blej->dodaj_trapez(trap2);
	blej->dodaj_trapez(trap3);
	blej->wypisz();

	std::cout << "\n\n[Przeksztalcenie] : " << std::endl;
	blej->symetria_osiowa(3);
	blej->wypisz();

	delete blej;

	return 0;
}