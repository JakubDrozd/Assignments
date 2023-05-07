//#include <iostream>
//#include <math.h>
//#include <iomanip>
//
//struct koordynaty {
//	double x;
//	double y;
//};
//
//class TrapezRownoramienny
//{
//private:
//	double polozenie_x;
//	double polozenie_y;
//	double podstawa_a;
//	double podstawa_b;
//	double wysokosc;
//public:
//	TrapezRownoramienny(double x = 0, double y = 0, double a = 0, double b = 0, double h = 0) :
//		polozenie_x(x), polozenie_y(y), podstawa_a(a), podstawa_b(b), wysokosc(h) {}
//	void ustaw_wymiary(double x, double y, double a, double b, double h) {
//		polozenie_x = x;
//		polozenie_y = y;
//		if (a <= 0 || b <= 0 || h <= 0)
//		{
//			std::cout << "Niepoprawne wymiary, ustawiam domyslne (1)" << std::endl;
//			podstawa_a = 1;
//			podstawa_b = 0.7;
//			wysokosc = 1;
//		}
//		else
//		{
//			podstawa_a = a;
//			podstawa_b = b;
//			wysokosc = h;
//		}
//	}
//	void odczyt() {
//		koordynaty a;
//		koordynaty b;
//		koordynaty c;
//		koordynaty d;
//
//		a.x = polozenie_x;
//		a.y = polozenie_y;
//
//		b.x = polozenie_x + podstawa_a;
//		b.y = polozenie_y;
//
//		double srodek = (podstawa_a - podstawa_b) / 2;
//		c.x = polozenie_x + srodek;
//		c.y = polozenie_y + wysokosc;
//
//		d.x = polozenie_x + podstawa_b + srodek;
//		d.y = polozenie_y + wysokosc;
//
//		double ramie = sqrt(pow(wysokosc, 2) + pow(srodek, 2));
//
//		std::cout << "Koordynaty wierzcholka a: [" << a.x << "," << a.y << "]" << std::endl;
//		std::cout << "Koordynaty wierzcholka b: [" << b.x << "," << b.y << "]" << std::endl;
//		std::cout << "Koordynaty wierzcholka c: [" << c.x << "," << c.y << "]" << std::endl;
//		std::cout << "Koordynaty wierzcholka d: [" << d.x << "," << d.y << "]" << std::endl;
//		std::cout << "Podstawa A: " << podstawa_a << std::endl;
//		std::cout << "Podstawa B: " << podstawa_b << std::endl;
//		std::cout << "Wysokosc: " << wysokosc << std::endl;
//		std::cout << "Ramie: " << std::fixed << std::setprecision(2) << ramie << std::endl;
//	}
//	void przeksztalcenie(int n) {
//		double nowe_polozenie_x = 0;
//		if ((polozenie_x + podstawa_a) == n)
//		{
//			nowe_polozenie_x = n;
//		}
//		else if (n == polozenie_x + podstawa_a / 2)
//		{
//			return;
//		}
//		else
//		{
//			nowe_polozenie_x = 2.0 * n - polozenie_x - podstawa_a;
//		}
//
//		polozenie_x = nowe_polozenie_x;
//	}
//};
//
//
//int main() {
//	double x;
//	double y;
//	double podstawa_a;
//	double podstawa_b;
//	double wysokosc;
//	int n;
//	TrapezRownoramienny trapez1;
//	std::cout << "Podaj koordynaty [x,y] lewego wierzcholka podstawy A: " << std::endl;
//	std::cin >> x >> y;
//	std::cout << "Podaj Podstawe A: " << std::endl;
//	std::cin >> podstawa_a;
//	std::cout << "Podaj Podstawe B: " << std::endl;
//	std::cin >> podstawa_b;
//	std::cout << "Podaj Wysokosc: " << std::endl;
//	std::cin >> wysokosc;
//	trapez1.ustaw_wymiary(x, y, podstawa_a, podstawa_b, wysokosc);
//	trapez1.odczyt();
//	std::cout << "Podaj wzgledem jakiej osi symetri ma zostac wykonane przeksztalcenie: x = ";
//	std::cin >> n;
//	trapez1.przeksztalcenie(n);
//	trapez1.odczyt();
//	trapez1.przeksztalcenie(n);
//	trapez1.odczyt();
//	return 0;
//}