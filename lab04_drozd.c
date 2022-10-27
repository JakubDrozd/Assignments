/*===========================================================================*/
/*                               ZADANIE 28                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	int x;
//	int y;
//	printf("Program sluzy do wyznaczenia czy punkt podany przez uzytkownika lezy na pierwszej cwiartce ukladu wspolrzednych\nAutor: Jakub Drozd\n");
//	printf("Prosze podac wpolrzedna \"x\": ");
//	if (scanf_s("%d", &x) != 1) {
//		scanf_s("%d", &x);
//	}
//	printf("Prosze podac wpolrzedna \"y\": ");
//	if (scanf_s("%d", &y) != 1) {
//		scanf_s("%d", &y);
//	}
//	if (x <= 0 || y <= 0)
//	{
//		printf("Punkt o podanych wspolrzednych x=%d i y=%d NIE nalezy do pierwszej cwiartki ukladu wspolrzednych", x, y);
//		printf("\nKoniec programu.");
//		return 0;
//	}
//	else
//	{
//		printf("Punkt o podanych wspolrzednych x=%d i y=%d NALEZY do pierwszej cwiartki ukladu wspolrzednych", x, y);
//		printf("\nKoniec programu.");
//		return 0;
//	}
//}


/*===========================================================================*/
/*                               ZADANIE 29                                 */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	int x;
//	int y;
//	printf("Program sluzy do wyznaczenia na ktorej cwiartce ukladu wspolrzednych lezy punkt podany przez uzytkownika\nAutor: Jakub Drozd\n");
//	printf("Prosze podac wpolrzedna \"x\": ");
//	if (scanf_s("%d", &x) != 1) {
//		printf("Bledne dane.");
//		printf("\nKoniec programu.");
//		return 0;
//	}
//	printf("Prosze podac wpolrzedna \"y\": ");
//	if (scanf_s("%d", &y) != 1) {
//		printf("Bledne dane.");
//		printf("\nKoniec programu.");
//		return 0;
//	}
//	if (x > 0)
//	{
//		if (y > 0)
//		{
//			printf("Punkt nalezy do I cwiartki ukladu wspolrzednych");
//			printf("\nKoniec programu");
//			return 0;
//		}
//		else if (y < 0)
//		{
//			printf("Punkt nalezy do IV cwiartki ukladu wspolrzednych");
//			printf("\nKoniec programu");
//			return 0;
//		}
//		else
//		{
//			printf("Punkt lezy na osi Y");
//			printf("\nKoniec programu");
//			return 0;
//		}
//	}
//	else
//	{
//		if (y > 0)
//		{
//			printf("Punkt nalezy do II cwiartki ukladu wspolrzednych");
//			printf("\nKoniec programu");
//			return 0;
//		}
//		else if (y < 0)
//		{
//			printf("Punkt nalezy do III cwiartki ukladu wspolrzednych");
//			printf("\nKoniec programu");
//			return 0;
//		}
//		else
//		{
//			printf("Punkt lezy na osi Y");
//			printf("\nKoniec programu");
//			return 0;
//		}
//	}
//}


/*===========================================================================*/
/*                               ZADANIE 30                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	double liczba;
//	printf("Program sluzy do zaokraglania liczb wymiernych z rozszerzeniem dziesietnym do liczb calkowitych\nAutor: Jakub Drozd\n");
//	printf("Podaj liczbe niecalkowita w rozszerzeniu dziesietnym: ");
//	if (scanf_s("%lf", &liczba)!=1 || getchar()!='\n')
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.\n");
//		return 0;
//	}
//	int zaokr = (int)liczba;
//	if (liczba == zaokr)
//	{
//		printf("Podana liczba %lf jest calkowita", liczba);
//		printf("\nKoniec programu.\n");
//		return 0;
//	}
//	else
//	{
//		printf("Podana liczba %.2lf nie jest calkowita i zostala zaokraglona do %d", liczba, zaokr);
//		printf("\nKoniec programu.\n");
//		return 0;
//	}
//}


/*===========================================================================*/
/*                               ZADANIE 31                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <math.h>
//
//int main()
////Dziedzina to x <0, 1>
//{
//	double x;
//	double y;
//	const double e = 2.72;
//	printf("Program sluzy do roztrzygniecia gdzie lezy punkt podany przez uzytkownika w stosunku do funkcji:\n");
//	printf("f(x) = sqrt(|arccos(x) + e^x/ln(x)|)");
//	printf("\nAutor: Jakub Drozd\n");
//	printf("Prosze o podanie wspolrzednej x: ");
//	if (scanf_s("%lf", &x)!=1 || getchar()!='\n')
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.");
//		return 0;
//	}
//	else if (x < 0 || x>1)
//	{
//		printf("%.3lf nie nalezy do dziedziny funkcji", x);
//		printf("\nKoniec programu.");
//		return 0;
//	}
//	printf("Prosze o podanie wpolrzednej y: ");
//	if (scanf_s("%lf", &y) != 1 || getchar()!='\n')
//	{
//		printf("Bledne dane.");
//		printf("Koniec programu.");
//		return 0;
//	}
//	double funkcja = fabs(sqrt(acos(x) + (pow(e, x) / log(x))));
//	if (y == funkcja)
//	{
//		printf("%.3lf, %.3lf jest punktem wykresu funkcji f(x)", x, y);
//		printf("\nKoniec programu.");
//		return 0;
//	}
//	else if (y > funkcja)
//	{
//		printf("%.3lf, %.3lf jest nad wykresem funkcji f(x)", x, y);
//		printf("\nKoniec programu.");
//		return 0;
//	}
//	else if (y < funkcja)
//	{
//		printf("%.3lf, %.3lf jest pod wykresem funkcji f(x)", x, y);
//		printf("\nKoniec programu.");
//		return 0;
//	}
//}


/*===========================================================================*/
/*                               ZADANIE 32                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	int x = 0;
//	printf("Testowanie instr. przypisania.\n\n");
//	x+=2;
//	printf("Po x+=2; wart. x jest: %d\n", x);
//	x *= (x + 1);
//	printf("Po x *= x + 1 wart. x jest: %d\n", x);
//	x+=1;
//	printf("Po x+=1 wart. x jest: %d\n", x);
//	x -= 3 / 4;
//	printf("Po x -= 3 / 4 wart. x jest: %d\n", x);
//	x /= x + 1;
//	printf("Po x /= x + 1 wart. x jest: %d\n", x);
//	x-=1;
//	printf("Po x-=1 wart. x jest: %d\n", x);
//	printf("\n\nKoniec programu. \n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 33                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	int x = 0;
//	int y;
//	y = x + 7; /*1*/
//	printf("\ny = (x++) + 7 = %d", y);
//	x += 1;
//	y = (x+1) + 7; /*2*/
//	printf("\ny = (x+1) + 7 = %d", y);
//	y = 7 + x; /*3*/
//	printf("\ny = 7 + (x++) = %d", y);
//	x += 1;
//	y = 7 + (x+1); /*4*/
//	printf("\ny = 7 + (++x) = %d", y);
//	y = 7 + (x + 1); /*5*/
//	printf("\ny = 7 + (x + 1) = %d", y);
//}


/*===========================================================================*/
/*                               ZADANIE 34                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	printf("Program oblicza wartosc funkcji\n");
//	printf("f(x)=sqrt(x^2+1)+ln(x^2+1)/(5 + sin(x^2+1))-e^sin(x^2+1)");
//	printf(" dla x podanego przez uzytkownika\n");
//	printf("Autor: Jakub Drozd\n");
//	printf("Prosze podac liczbe aby obliczyc wartosc funkcji: ");
//	double x;
//	const double e = 2.72;
//	if (scanf_s("%lf", &x)!= 1 || getchar()!='\n')
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.");
//		return 0;
//	}
//	double pom1;
//	double pom2;
//	pom1 = pow(x, 2) + 1;
//	pom2 = sin(pom1);
//	double y = sqrt(pom1) + ((log(pom1)) / (5 + pom2)) - (pow(e, pom2));
//	printf("f(%.3lf) = %.3lf", x, y);
//	printf("\nKoniec programu.");
//	return 0;
//
//}


/*===========================================================================*/
/*                               ZADANIE 35                                  */
/*===========================================================================*/


#include <stdio.h>
#include <math.h>

int main()
{

	double liczba;
	printf("Program oblicza wartosc x^8, gdzie x jest liczba podana przez uzytkownika\n");
	printf("Autor: Jakub Drozd\n");
	printf("Prosze podaj x: ");
	if (scanf_s("%lf", &liczba)!=1 || getchar()!='\n')
	{
		printf("Bledne dane.");
		printf("\nKoniec programu.");
		return 0;
	}
	liczba = liczba * liczba;
	liczba = liczba * liczba;
	liczba = liczba * liczba;
	printf("\nRecznie = %lf", liczba);
	return 0;
}