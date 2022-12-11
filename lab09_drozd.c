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
//		for (int j = 1; j < n; j++)
//		{
//			rysujSpacje(n - j - 1);
//			rysujGwiazdki(2 * j - 1);
//
//		}
//}


/*===========================================================================*/
/*                               ZADANIE 72                                  */
/*===========================================================================*/


//#include <stdio.h>
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
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			printf("%d | %d", j, i*j);
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
//
//}


/*===========================================================================*/
/*                               ZADANIE  74                                 */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


