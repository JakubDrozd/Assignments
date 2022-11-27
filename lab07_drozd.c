/*===========================================================================*/
/*                               ZADANIE 52                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	printf("Program wypisuje tekst podany przez uzytkownika przy czym usuwa zbedne spacje.\nAutor: Jakub Drozd\n");
//	char znak;
//	int czyBialo;
//	printf("Podaj tekst:\n");
//	while ((znak = getchar()) != '\n' )
//	{
//		if (znak == ' ' && czyBialo)
//		{
//			continue;
//		}
//		if (znak == ' ' && !czyBialo)
//		{
//			czyBialo = 1;
//			putchar(znak);
//		}
//		else
//		{
//		putchar(znak);
//		czyBialo = 0;
//		}
//	}
//	printf("\nKoniec programu\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 53                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	printf("Program wypisuje liczbe naturalna podana przez uzytkownika.\nAutor: Jakub Drozd\n");
//	int liczba;
//	printf("Podaj dowolna liczbe naturalna: ");
//	while (scanf_s("%d", &liczba)!=1 || liczba <= 0 || getchar()!='\n')
//	{
//		printf("Bledne dane, popraw: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF);
//	}
//	printf("Podales liczbe: %d", liczba);
//	printf("\nKoniec programu\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 54                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	printf("Program prosi o podanie literki 't' i wypisuje komunikat dla uzytkownika\nAutor: Jakub Drozd\n");
//	char znak;
//	printf("\nPodaj literke 't': ");
//	while (scanf_s("%c", &znak) != 1 || znak != 't' || getchar() != '\n')
//	{
//		printf("Bledne dane, popraw: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	printf("Wpisales literke 't'");
//	printf("\nKoniec programu\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 55                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <limits.h>
//
//int main()
//{
//	printf("Program wyznacza minimum z podanych liczb\nAutor: Jakub Drozd\n");
//	printf("Podaj liczby naturalne, aby zakonczyc wpisz 0\n");
//	int liczba = 1;
//	int min = INT_MAX;
//	while (liczba != 0)
//	{
//		printf("Podaj liczbe: ");
//		while (scanf_s("%d", &liczba)!=1 || liczba < 0 || getchar()!='\n')
//		{
//			printf("Bledne dane, popraw: ");
//			int c;
//			while ((c = getchar()) != '\n' && c != EOF)
//				;
//		}
//		if (liczba != 0 && liczba < min)
//		{
//			min = liczba;
//		}
//	}
//	printf("Najmniejsza z podanych liczb to: %d", min);
//	printf("\nKoniec programu\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 56                                  */
/*===========================================================================*/


#include <stdio.h>

int main()
{
	int ilosc = 1;
	double liczba;
	double suma = 0;
	printf("Program oblicza srednia dla podanych liczb zmiennopozycyjnych.\nAutor: Jakub Drozd\n");
	printf("Podaj 10 liczb zmiennopozycyjnych:\n");
	while (ilosc <= 10)
	{
		printf("%d. ", ilosc);
		while (scanf_s("%lf", &liczba)!=1 || getchar()!='\n')
		{
			printf("Bledne dane, popraw: ");
			int c;
			while ((c = getchar()) != '\n' && c != EOF)
				;
		}
		suma += liczba;
		ilosc++;
	}
	double srednia = suma / 10;
	printf("Srednia arytmetyczna podanych liczb wynosi: %lf", srednia);
	printf("\nKoniec programu\n");
	return 0;
}


/*===========================================================================*/
/*                               ZADANIE 57                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 58                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 59                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


