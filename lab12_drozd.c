/*===========================================================================*/
/*                               ZADANIE 87                                  */
/*===========================================================================*/


//#include <stdio.h>
//#define MAX 25
//
//void info() {
//	printf("Program wczytuje i wypisuje elementy tabeli dwuwymiarowej.\nAutor: Jakub Drozd\n");
//}
//
//int wczytajLiczbe() {
//	int liczba;
//	while (scanf_s("%d", &liczba)!=1 || liczba < 0 || getchar()!='\n')
//	{
//		printf("Bledne dane, podaj liczbe calkowita wieksza od zera: ");
//		int c;
//		while ((c = getchar())!='\n' && c!=EOF)
//			;
//	}
//	return liczba;
//}
//
//double wczytajDouble() {
//	double liczba;
//	while (scanf_s("%lf", &liczba) != 1 || getchar() != '\n')
//	{
//		printf("Bledne dane, podaj liczbe zmiennopozycyjna: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//void wczytajDoTablicy(double tab[][MAX], int m, int n) {
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("Podaj nastepny element tablicy [%d][%d]: ", i+1, j+1);
//			tab[i][j] = wczytajDouble();
//		}
//	}
//}
//
//void wypiszTablice(double tab[][MAX], int m, int n) {
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%.1lf ", tab[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//
//int main()
//{
//	info();
//	double tab[MAX][MAX];
//	printf("Podaj liczbe wierszy tablicy: ");
//	int wiersze = wczytajLiczbe();
//	printf("Podaj liczbe kolumn tablicy: ");
//	int kolumny = wczytajLiczbe();
//	printf("Wiersze: %d\nKolumny: %d\n", wiersze, kolumny);
//	wczytajDoTablicy(tab, wiersze, kolumny);
//	wypiszTablice(tab, wiersze, kolumny);
//	printf("\n\nKoniec programu.\n\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 88                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define MAX 25
//
//void info() {
//	printf("Program tworzy losowa tablice dwuwymiarowa i zamienia jej wiersze z kolumnami.\nAutor: Jakub Drozd\n");
//}
//
//
//void wczytajDoTablicy(double tab[][MAX], int m, int n) {
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			tab[i][j] = rand() % (8 + 1 + 8) - 8;
//		}
//	}
//}
//
//void wypiszTablice(double tab[][MAX], int m, int n) {
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%4.1lf ", tab[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void transponowanie(double tab[][MAX], int m, int n) {
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			printf("%4.1lf ", tab[j][i]);
//		}
//		printf("\n");
//	}
//}
//
//
//int main()
//{
//	info();
//	double tab[MAX][MAX];
//	printf("Wiersze: %d\nKolumny: %d\n", 3, 2);
//	wczytajDoTablicy(tab, 3, 2);
//	printf("Tablica:\n");
//	wypiszTablice(tab, 3, 2);
//	printf("Tablica (po transponowaniu):\n");
//	transponowanie(tab, 3, 2);
//	printf("\n\nKoniec programu.\n\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 89                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define MAX 25
//
//void info() {
//	printf("Program znajduje maksymalny element w tablicy zdefiniowanej przez uzytkownika.\nAutor: Jakub Drozd\n");
//}
//
//void wczytajDoTablicy(double tab[][MAX], int n, int m) {
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			tab[i][j] = rand() % (8 + 1 + 8) - 8;
//		}
//	}
//}
//
//int wczytajLiczbe() {
//	int liczba;
//	printf("Podaj liczbe: ");
//	while (scanf_s("%d", &liczba)!=1 || getchar()!='\n')
//	{
//		printf("Bledne dane, podaj liczbe: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//void wypiszTablice(double tab[][MAX], int n, int m) {
//	for (int i = 0; i < n; i++)
//	{
//		printf("[");
//		for (int j = 0; j < m; j++)
//		{
//			printf("%4.1lf ", tab[i][j]);
//		}
//		printf("]");
//		printf("\n");
//	}
//}
//
//
//double znajdzNajwieksza(double tab[][MAX], int n, int m) {
//	double najwieksza = tab[0][0];
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (najwieksza < tab[i][j])
//			{
//				najwieksza = tab[i][j];
//			}
//		}
//	}
//	return najwieksza;
//}
//
//int main()
//{
//	info();
//	double tab[MAX][MAX];
//	int wiersze = 0;
//	int kolumny = 0;
//	printf("Podaj ilosc wierszy\n");
//	wiersze = wczytajLiczbe();
//	printf("Podaj ilosc kolumn\n");
//	kolumny = wczytajLiczbe();
//	wczytajDoTablicy(tab, wiersze, kolumny);
//	wypiszTablice(tab, wiersze, kolumny);
//	znajdzNajwieksza(tab, wiersze, kolumny);
//	printf("Najwieksza liczba w tablicy jest: %.1lf", znajdzNajwieksza(tab, wiersze, kolumny));
// 	printf("\n\nKoniec programu\n\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 90                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define MAX 25
//
//void info() {
//	printf("Program sprawdza czy w zdefiniowanej przez uzytkownika tablicy, skladajacej sie z zer i jedynek, kazdy rzad  i kazda kolumna ma dokladnie jedna jedynke.\nAutor: Jakub Drozd\n");
//}
//
//void wczytajTablice(int tab[][MAX], int n, int m) {
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			tab[i][j] = wczytajLiczbe();
//		}
//	}
//}
//
//void wypiszTablice(int tab[][MAX], int n, int m) {
//	for (int i = 0; i < n; i++)
//	{
//		printf("[");
//		for (int j = 0; j < m; j++)
//		{
//			printf("%d ", tab[i][j]);
//		}
//		printf("]");
//		printf("\n");
//	}
//}
//
//int wczytajLiczbe() {
//	int liczba;
//	while (scanf_s("%d", &liczba)!=1 || getchar()!='\n')
//	{
//		printf("Bledne dane, podaj liczbe calkowita: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//void warunek(int tab[][MAX], int n, int m) {
//	int oneCountRow = 0;
//	int oneCountColumn = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (tab[i][j] == 1)
//			{
//				oneCountColumn++;
//			}
//		}
//	}
//}
//
//int main()
//{
//	info();
//	int tab[MAX][MAX];
//	printf("Podaj liczbe wierszy: ");
//	int wiersze = wczytajLiczbe();
//	printf("Podaj liczbe kolumn: ");
//	int kolumny = wczytajLiczbe();
//	wczytajTablice(tab, wiersze, kolumny);
//	wypiszTablice(tab, wiersze, kolumny);
//	warunek(tab, wiersze, kolumny);
//	printf("\n\nKoniec programu\n\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 91                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define MAX 25
//
//void info() {
//	printf("Program sumuje wszystkie elementy tablicy zdefiniowanej przez uzytkownika.\nAutor: Jakub Drozd\n");
//}
//
//void wczytajTablice(double tab[][MAX], int n, int m) {
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			tab[i][j] = rand() % (8 + 1 + 8) - 8;
//		}
//	}
//}
//
//double sumaZElementow(double tab[][MAX], int n, int m) {
//	double suma = 0.0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			suma += tab[i][j];
//		}
//	}
//	return suma;
//}
//
//void wypiszTablice(double tab[][MAX], int n, int m) {
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			printf("%4.1lf ", tab[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int wczytajLiczbe() {
//	int liczba;
//	while (scanf_s("%d", &liczba)!=1 || getchar()!='\n')
//	{
//		printf("Bledne dane, podaj liczbe: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//int main()
//{
//	info();
//	double tab[MAX][MAX];
//	printf("Podaj liczbe wierszy: ");
//	int wiersze = wczytajLiczbe();
//	printf("Podaj liczbe kolumn: ");
//	int kolumny = wczytajLiczbe();
//	wczytajTablice(tab, wiersze, kolumny);
//	wypiszTablice(tab, wiersze, kolumny);
//	printf("Suma elementow tablicy jest rowna: %.1lf", sumaZElementow(tab, wiersze, kolumny));
//	printf("\n\nKoniec programu\n\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 92                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define MAX 25
//
//void info() {
//	printf("Program sumuje elementy lezace na przekatnej tablicy zdefiniowanej przez uzytkownika.\nAutor: Jakub Drozd\n");
//}
//
//void wczytajTablice(double tab[][MAX], int n, int m) {
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			tab[i][j] = rand() % (8 + 1 + 8) - 8;
//		}
//	}
//}
//
//double sumaZElementow(double tab[][MAX], int n, int m) {
//	double suma = 0.0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (i == j)
//			{
//				suma += tab[i][j];
//			}
//		}
//	}
//	return suma;
//}
//
//void wypiszTablice(double tab[][MAX], int n, int m) {
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			printf("%4.1lf ", tab[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int wczytajLiczbe() {
//	int liczba;
//	while (scanf_s("%d", &liczba) != 1 || getchar() != '\n')
//	{
//		printf("Bledne dane, podaj liczbe: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//int main()
//{
//	info();
//	double tab[MAX][MAX];
//	printf("Podaj liczbe wierszy: ");
//	int wiersze = wczytajLiczbe();
//	printf("Podaj liczbe kolumn: ");
//	int kolumny = wczytajLiczbe();
//	wczytajTablice(tab, wiersze, kolumny);
//	wypiszTablice(tab, wiersze, kolumny);
//	printf("Suma elementow tablicy jest rowna: %.1lf", sumaZElementow(tab, wiersze, kolumny));
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


