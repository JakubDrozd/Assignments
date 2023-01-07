/*===========================================================================*/
/*                               ZADANIE 87                                  */
/*===========================================================================*/


#include <stdio.h>
#define MAX 25

void info() {
	printf("Program wczytuje i wypisuje elementy tabeli dwuwymiarowej.\nAutor: Jakub Drozd\n");
}

int wczytajLiczbe() {
	int liczba;
	while (scanf_s("%d", &liczba)!=1 || liczba < 0 || getchar()!='\n')
	{
		printf("Bledne dane, podaj liczbe calkowita wieksza od zera: ");
		int c;
		while ((c = getchar())!='\n' && c!=EOF)
			;
	}
	return liczba;
}

double wczytajDouble() {
	double liczba;
	while (scanf_s("%lf", &liczba) != 1 || getchar() != '\n')
	{
		printf("Bledne dane, podaj liczbe zmiennopozycyjna: ");
		int c;
		while ((c = getchar()) != '\n' && c != EOF)
			;
	}
	return liczba;
}

void wczytajDoTablicy(double tab[][MAX], int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Podaj nastepny element tablicy [%d][%d]: ", i+1, j+1);
			tab[i][j] = wczytajDouble();
		}
	}
}

void wypiszTablice(double tab[][MAX], int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%.1lf ", tab[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	info();
	double tab[MAX][MAX];
	printf("Podaj liczbe wierszy tablicy: ");
	int wiersze = wczytajLiczbe();
	printf("Podaj liczbe kolumn tablicy: ");
	int kolumny = wczytajLiczbe();
	printf("Wiersze: %d\nKolumny: %d\n", wiersze, kolumny);
	wczytajDoTablicy(tab, wiersze, kolumny);
	wypiszTablice(tab, wiersze, kolumny);
	printf("\n\nKoniec programu.\n\n");
	return 0;
}


/*===========================================================================*/
/*                               ZADANIE 88                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 89                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 90                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 91                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 92                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 93                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


