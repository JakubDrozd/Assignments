/*===========================================================================*/
/*                               ZADANIE 20                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	int liczba1;
//	int liczba2;
//	printf("Podaj liczby calkowite:\n");
//	if (scanf_s("%d", &liczba1) != 1 || scanf_s("%d", &liczba2) != 1) {
//		printf("Bledne dane.");
//		printf("\nKoniec programu.");
//		return 0;
//	}
//	printf("Podales liczby calkowite: %d i %d", liczba1, liczba2);
//	printf("\nKoniec programu.\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 21                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main() {
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
//		printf("Podales: \"%c\"", input);
//		printf("\nKoniec programu.");
//		return 0;
//	}
//}


/*===========================================================================*/
/*                               ZADANIE 26                                  */
/*===========================================================================*/


#include <stdio.h>
#include <math.h>

int main()
{
	const int a = 0;
	const int b = 0;
	int x;
	int y;
	const int promien = 1;
	printf("Program sluzy do sprawdzenia czy podany przez uzytkownika punkt nalezy do okregu o srodku (0,0) i promieniu rownemu 1. \nAutor: Jakub Drozd\n\n");
	printf("Podaj wspolrzedne x i y punktu:\n");
	scanf_s("%d", &x);
	scanf_s("%d", &y);
	if ((pow((x - a), 2) + pow((y - b), 2)) == pow(promien, 2)) {
		printf("Punkt %d, %d nalezy do okregu", x, y);
		printf("\nKoniec programu.");
		return 0;
	}
	else
	{
		printf("Punkt %d, %d nie nalezy do okregu", x, y);
		printf("\nKoniec programu.");
		return 0;
	}
}


/*===========================================================================*/
/*                               ZADANIE 27                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


