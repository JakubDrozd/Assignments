/*===========================================================================*/
/*                               ZADANIE 20                                  */
/*===========================================================================*/


#include <stdio.h>

int main()
{
	printf("Program sluzy do wypisywania liczb calkowitych podanych przez uzytkownika.\nAutor: Jakub Drozd\n\n");
	int liczba1;
	int liczba2;
	printf("Podaj liczby calkowite:\n");
	if (scanf_s("%d", &liczba1) != 1 || scanf_s("%d", &liczba2) != 1) {
		printf("Bledne dane.");
		printf("\nKoniec programu.");
		return 0;
	}
	printf("Podales liczby calkowite: %d i %d", liczba1, liczba2);
	printf("\nKoniec programu.\n");
	return 0;
}


/*===========================================================================*/
/*                               ZADANIE 21                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main() {
//	printf("Program sluzy do konwersji wprowadzonej przez uzytkownika liczby calkowitej nieujemnej z systemu szesnastkowego na \ndziesetny.\nAutor: Jakub Drozd\n\n");
//	int liczba;
//	int liczbaNaDziesietny;
//	printf("Podaj liczbe calkowita w systemie szesnastkowym:\n");
//	if (scanf_s("%x", &liczba) != 1) {
//		printf("Bledne dane.");
//		printf("\nKoniec programu.");
//		return 0;
//	}
//	int liczbaNaDziesetny = (int)liczba;
//	printf("Podales liczbe %x w systemie szesnastkowym.", liczba);
//	printf("\nPodana liczba %x w systemie szesnastkowym to %d w systemie dziesetnym.", liczba, liczbaNaDziesetny);
//	printf("\nKoniec programu.");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 22                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//int liczba;
//printf("Program sluzy do konwersji wprowadzonej przez uzytkownika liczby calkowitej z systemu dziesietnego na szesnatkowy.\nAutor: Jakub Drozd\n\n");
//	printf("Podaj liczbe calkowita w systemie dziesetnym:\n");
//	if (scanf_s("%d", &liczba)!=1) {
//	printf("Bledne dane.");
//		printf("Koniec programu.");
//		return 0;
//	}
//	printf("Podales liczbe %d w systemie dziesietnym, ktora jest %x w systemie szesnatkowym.", liczba, liczba);
//	printf("\nKoniec programu.");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 23                                  */
/*===========================================================================*/


//#include <stdio.h>	
//	int main()
//	{
//		printf("Program sluzy do konwersji wprowadzonej przez uzytkownika liczby calkowitej nieujemnej z systemu dziesietnego na szesnatkowy.\nAutor: Jakub Drozd\n\n");
//		int liczba;
//		printf("Podaj liczbe calkowita nieujemna w systemie dziesetnym:\n");
//		if (scanf_s("%d", &liczba) != 1 || liczba <= 0) {
//			printf("Bledne dane.");
//			printf("Koniec programu.");
//			return 0;
//		}
//		printf("Podales liczbe %d w systemie dziesietnym, ktora jest %x w systemie szesnatkowym.", liczba, liczba);
//		printf("\nKoniec programu.");
//		return 0;
//	}


/*===========================================================================*/
/*                               ZADANIE 24                                   */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	printf("Program sluzy do sprawdzenia czy podana przez uzytkownika liczba calkowita jest dodatnia czy ujemna.\nAutor: Jakub Drozd\n\n");
//	int liczba;
//	printf("Podaj liczbe calkowita:\n");
//	if (scanf_s("%d", &liczba) != 1) {
//		printf("Bledne dane.");
//		printf("\nKoniec programu.\n");
//	}
//	else if (liczba > 0) {
//		printf("Podana liczba %d jest dodatnia.\n", liczba);
//		printf("\Koniec programu.\n");
//		return 0;
//	}
//	else {
//		printf("Podana liczba %d jest ujemna.\n", liczba);
//		printf("\Koniec programu.\n");
//		return 0;
//	}
//}


/*===========================================================================*/
/*                               ZADANIE 25                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main() {
//	char input;
//	char nextchar;
//	printf("Program sluzy do sprawdzenia czy uzytkownik wpisuje litere \"t\" lub litere \"T\".\nAutor: Jakub Drozd\n\n");
//	printf("Prosze wpisac duza lub mala litere \"t\":\n");
//	input = getchar();
//	nextchar = getchar();
//	if (input != 't' && input !='T' || nextchar != '\n')
//	{
//		printf("Bledne dane");
//		printf("\nKoniec programu");
//		return 0;
//	}
//	else {
//		printf("Podales litere: \"%c\"", input);
//		printf("\nKoniec programu.");
//		return 0;
//	}
//}


/*===========================================================================*/
/*                               ZADANIE 26                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	const double a = 0.0;
//	const double b = 0.0;
//	double x;
//	double y;
//	const double promien = 1.0;
//	printf("Program sluzy do sprawdzenia czy podany przez uzytkownika punkt nalezy do okregu o srodku (0,0) i promieniu rownemu 1. \nAutor: Jakub Drozd\n\n");
//	printf("Podaj wspolrzedne x i y punktu:\n");
//	if (scanf_s("%lf", &x)!=1 || scanf_s("%lf", &y)!=1)
//	{
//		printf("Bledne dane");
//		printf("\nKoniec programu.");
//		return 0;
//	}
//	else if ((pow((x - a), 2.0) + pow((y - b), 2.0)) == pow(promien, 2.0)) {
//		printf("Punkt %lf, %lf nalezy do okregu", x, y);
//		printf("\nKoniec programu.");
//		return 0;
//	}
//	else
//	{
//		printf("Punkt %lf, %lf nie nalezy do okregu", x, y);
//		printf("\nKoniec programu.");
//		return 0;
//	}
//}


/*===========================================================================*/
/*                               ZADANIE 27                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	double srodek1 = 0.0;
//	double srodek2 = 0.0;
//	double promien = 1.0;
//	double x;
//	double y;
//	double odleglosc;
//	printf("Program sluzy do sprawdzenia gdzie punkt wyznaczony przez uzytkownika znajduje sie w stosunku do okregu o srodku (0,0) i promieniu 1.\nAutor: Jakub Drozd\n\n");
//	printf("Podaj wspolrzedne x i y punktu:\n");
//	if (scanf_s("%lf", &x)!=1.0 || scanf_s("%lf", &y)!=1.0)
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.");
//		return 0;
//	}
//	odleglosc = sqrt(pow((x - srodek1), 2.0) + pow((y - srodek2), 2.0));
//	if (odleglosc == promien)
//	{
//		printf("Punkt (%lf, %lf) lezy na okregu", x, y);
//		printf("\nKoniec programu.");
//		return 0;
//	} else if(odleglosc > promien){
//		printf("Punkt (%lf, %lf) lezy na zewnatrz okregu", x, y);
//		printf("\nKoniec programu.");
//		return 0;
//	}
//	else
//	{
//		printf("Punkt (%lf, %lf) lezy wewnatrz okregu", x, y);
//		printf("\nKoniec programu.");
//		return 0;
//	}
//}


