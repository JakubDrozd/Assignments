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


#include <stdio.h>
#include <math.h>

int main()
//Dziedzina to x <0, 1>
{
	int x;
	int y;
	const double e = 2.72;
	printf("Program sluzy do roztrzygniecia gdzie lezy punkt podany przez uzytkownika w stosunku do funkcji:\n");
	printf("f(x) = sqrt(|arccos(x) + e^x/ln(x)|)");
	printf("\nAutor: Jakub Drozd\n");
	printf("Prosze o podanie wspolrzednej x: ");
	if (scanf_s("%d", &x)!=1 || getchar()!='\n')
	{
		printf("Bledne dane.");
		printf("\nKoniec programu.");
		return 0;
	}
	else if (x < 0 || x>1)
	{
		printf("%d nie nale¿y do dziedziny funkcji", x);
		printf("\nKoniec programu.");
		return 0;
	}
	printf("Prosze o podanie wpolrzednej y: ");
	if (scanf_s("%d", &y) != 1 || getchar()!='\n')
	{
		printf("Bledne dane.");
		printf("Koniec programu.");
		return 0;
	}
	x = (double)x;
	y = (double)y;
	double funkcja = fabs(sqrt(acos(x) + (pow(e, x) / log(x))));
	if (y == funkcja)
	{
		printf("%d, %d jest punktem wykresu funkcji f(x)", (int)x, (int)y);
		printf("Koniec programu.");
		return 0;
	}
	else if (true)
	{

	}
}


/*===========================================================================*/
/*                               ZADANIE 32                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 33                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 34                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 35                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


