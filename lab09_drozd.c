/*===========================================================================*/
/*                               ZADANIE 67                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	printf("Program rysuje w jednej linii tyle gwiazek, ile uzytkonwik zazyczy.\nAutor: Jakub Drozd");
//	printf("\nPodaj ilosc gwiazdek: ");
//	int liczbaGwiazdek;
//	while (scanf_s("%d", &liczbaGwiazdek)!=1 || getchar()!='\n')
//	{
//		printf("Niepoprawne dane, podaj liczbe gwiazdek: ");
//		int c;
//		while((c = getchar())!='\n' && c != EOF)
//		;
//	}
//	for (int i = 0; i < liczbaGwiazdek; i++)
//	{
//		printf("*");
//	}
//	printf("\nKoniec programu\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 68                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	printf("Program rysuje kwadrat o boku rownym liczbie podanej przez uzytkownika.\nAutor: Jakub Drozd");
//	printf("\nPodaj ilosc gwiazdek: ");
//	int liczbaGwiazdek;
//	while (scanf_s("%d", &liczbaGwiazdek) != 1 || getchar() != '\n')
//	{
//		printf("Niepoprawne dane, podaj liczbe gwiazdek: ");
//		int c;
//		while((c = getchar())!='\n' && c != EOF)
//		;
//	}
//	for (int i = 0; i < liczbaGwiazdek; i++)
//	{
//		for (int j = 0; j < liczbaGwiazdek; j++)
//		{
//			if (j == liczbaGwiazdek - 1)
//			{
//				printf("*\n");
//			}
//			else
//			{
//				printf("*");
//			}
//		}
//	}
//	
//	printf("\nKoniec programu\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 69                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	printf("Program rysuje prostokat o szerokosci dwa razy mniejszej od dlugosci, gdzie szerokosc podaje uzytkownik.\nAutor: Jakub Drozd\n");
//	int szerokosc;
//	printf("\nPodaj szerokosc prostokata: ");
//	while (scanf_s("%d", &szerokosc)!=1 || getchar()!='\n')
//	{
//		int c;
//		while((c = getchar())!='\n' && c != EOF)
//		;
//	}
//	int dlugosc = szerokosc * 2;
//	for (int i = 0; i < szerokosc; i++)
//	{
//		for (int j = 0; j < dlugosc; j++)
//		{
//		printf("*");
//		}
//		printf("\n");
//	}
//	printf("\nKoniec programu.\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 70                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	printf("Program rysuje trojkat, o podstawie o dlugosci rownej liczbie podanej przez uzytkownika.\nAutor: Jakub Drozd\n");
//	int dlugosc;
//	printf("Podaj dlugosc podstawy trojkata: ");
//	while (scanf_s("%d", &dlugosc)!=1 || getchar()!='\n')
//	{
//		printf("Niepoprawne dane, podaj dlugosc: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	for (int i = 1; i <= dlugosc ; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	printf("\nKoniec programu\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 71                                  */
/*===========================================================================*/


//rysujSpacje(int liczba) {
//	for (int i = 1; i <= liczba; i++)
//	{
//		printf(" ");
//	}
//}
// rysujGwiazdki(int liczba) {
//	 for (int i = 1; i <= liczba; i++)
//	 {
//		 printf("*");
//	 }
//	 printf("\n");
//}
//
//
//#include <stdio.h>
//
//int main()
//{
//	printf("Program rysuje piramide o podstawie dlugosci rownej liczbie podanej przez uzytkownika.\nAutor:Jakub Drozd\n");
//	printf("Podaj dlugosc podstawy piramidy: ");
//	int n;
//	while (scanf_s("%d", &n)!=1 || getchar()!='\n')
//	{
//		printf("Niepoprawne dane, podaj dlugosc podstawy: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//		for (int i = 1; i < n; i++)
//		{
//			rysujSpacje(n - i - 1);
//			rysujGwiazdki(2 * i - 1);
//
//		}
//		printf("\nKoniec programu.\n");
//		return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 72                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <math.h>
//
//
//int main()
//{
//	printf("Program wypisuje tabliczke mnozenia z zakresu podanego przez uzytkownika.\nAutor: Jakub Drozd\n");
//	int n;
//	printf("Podaj zakres: ");
//	while (scanf_s("%d", &n)!=1 || getchar()!='\n')
//	{
//		printf("Niepoprawne dane, podaj zakres: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	int iloscSpacji = (4 * n) + 3;
//	for (int i = 1; i <= n; i++)
//	{
//		if (i == 1)
//		{
//			printf("%7d", i);
//		}
//		else
//		{
//			printf("%4d", i);
//		}	
//	}
//	for (int i = 1; i <= iloscSpacji; i++)
//	{
//		if (i == 1)
//		{
//			printf("\n-");
//		}
//		else if (i == iloscSpacji)
//		{
//			printf("-\n");
//		}
//		else
//		{
//		printf("-");
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (i > 9)
//		{
//			printf("%d|", i);
//		}
//		else
//		{
//			printf("%d |", i);
//		}
//		for (int j = 1; j <= n; j++)
//		{
//			printf("%4d", i*j);
//		}
//		printf("\n");
//	}
//	printf("\nKoniec programu.\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 73                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	printf("Program wypisuje tabele znakow odpowiadajacym kolejnym kodom ASCII.\Autor: Jakub Drozd\n");
//	printf("kod skrot\n");
//	for (int i = 0; i <= 255; i++)
//	{
//		if (i == 0)
//		{
//			printf("%3d nul\n", 0);
//		}
//		else if (i == 7)
//		{
//			printf("%3d bel\n", 7);
//		}
//		else if (i == 8)
//		{
//			printf("%3d bs\n", 8);
//		}
//		else if (i == 9)
//		{
//			printf("%3d ht\n", 9);
//		}
//		else if (i == 10)
//		{
//			printf("%3d nl\n", 10);
//		}
//		else if (i == 11)
//		{
//			printf("%3d vt\n", 11);
//		}
//		else if (i == 12)
//		{
//			printf("%3d np\n", 12);
//		}
//		else if (i == 13)
//		{
//			printf("%3d cr\n", 13);
//		}
//		else if (i == 26)
//		{
//			printf("%3d eof\n", 26);
//		}
//		else if (i == 27)
//		{
//			printf("%3d esc\n", 27);
//		}
//		else if (i == 127)
//		{
//			printf("%3d %3s\n", 127, "del");
//		}
//		else
//		{
//			printf("%3d %3c\n", i, i);
//		}
//	}
//	printf("\nKoniec programu\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE  74                                 */
/*===========================================================================*/


#include <stdio.h>
#include <string.h>

int main()
{
	printf("Program oblicza pewna sume.\nAutor: Jakub Drozd\n");
	int n;
	int sum = 0;
	printf("Podaj dlugosc sumy (nie wiecej niz 9): ");
	while (scanf_s("%d", &n)!=1 || n < 1 || getchar()!='\n')
	{
		printf("Bledne dane, podaj dlugosc sumy: ");
		int c;
		while ((c = getchar()) != '\n' && c != EOF)
			;
	}
	for (int i = 1; i <= n; ++i)
	{
		int liczba = 0;
		if (i == 1);
		else
		{
			printf(" + ");
		}
		for (int j = 1; j <= i; ++j)
		{
			liczba = liczba * 10 + i;
		}
		printf("%d", liczba);
		sum += liczba;
	}
	printf("\nSuma: %d\n", sum);
	printf("\nKoniec programu.\n");
	return 0;
}
