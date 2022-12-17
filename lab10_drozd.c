/*===========================================================================*/
/*                               ZADANIE 75                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//#define ILE 10 // ilosc pobranych liczb
//
//void info() {	//Wypisuje funkcje programu
//	printf("Program wczytuje do tablicy liczby i wypisuje ja na dwa sposoby.\nAutor: Jakub Drozd\n");
//}
//
//int wczytaj_int(void) {	//Wczytuje liczbe z bufora klawiatury
//	int liczba;
//	while (scanf_s("%d", &liczba)!=1 || getchar()!='\n')
//	{
//		printf("Bledne dane, popraw:\t\t");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//void wczytaj_int_1W(int tab[], int n) {	//Wczytuje liczbe z bufora klawiatury do tablicy
//	for (int i = 0; i < n; i++)
//	{
//		printf("Liczba %d: ", i + 1);
//		tab[i] = wczytaj_int();
//	}
//}
//
//void wypisz_liczby(int tab[], int n) {	//Wypisuje zawartosc tablicy w domyslnej i odwroconej kolejnosci
//	printf("Podane liczby: [");
//	for (int i = 0; i < n; i++)
//	{
//		if (i == n-1)
//		{
//			printf("%d", tab[i]);
//		}
//		else
//		{
//		printf("%d, ", tab[i]);
//
//		}
//	}
//	printf("]\n");
//	printf("Podane liczby (odwrocone): [");
//	for (int i = n-1; i >=0; --i)
//	{
//		if (i == 0)
//		{
//			printf("%d", tab[i]);
//		}
//		else
//		{
//			printf("%d, ", tab[i]);
//		}
//	}
//	printf("]");
//}
//
//int main()
//{
//	info();
//	int liczby[ILE] = {0};
//	wczytaj_int_1W(liczby, ILE);
//	wypisz_liczby(liczby, ILE);
//	printf("\n\nKoniec programu.\n\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 76                                  */
/*===========================================================================*/

//#include <stdio.h>
//
//void info() {
//	printf("Program wyznacza iloczyn oraz sume elementow ciagu n-elementowego, ciag podaje uzytkownik.\nAutor: Jakub Drozd\n");
//}
//
//int wczytajLiczbe(void) {		//Wczytuje dowolna liczbe calkowita
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
//int wczytajLiczbeZPrzedzialu(void) {	//Wczytuje liczbe calkowita z przedzialu [1,100]
//	int liczba;
//	while (scanf_s("%d", &liczba) != 1 || liczba < 1 || liczba > 100 || getchar() != '\n')
//	{
//		printf("Bledne dane, podaj liczbe calkowita z przedzialu [1, 100]: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//void wczytajDoTablicy(int tab[], int n) {	//Wczytuje do tablicy liczby calkowite podane przez uzytkownika
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d. ", i + 1);
//		tab[i] = wczytajLiczbe();
//	}
//}
//
//int sumaZTablicy(int tab[], int n) {	//Oblicza sume liczb z tablicy
//	int suma = 0;
//	for (int i = 0; i < n; i++)
//	{
//		suma += tab[i];
//	}
//	return suma;
//}
//
//int iloczynZTablicy(int tab[], int n) {	//Oblicza iloczyn liczb z tablicy
//	int iloczyn = 1;
//	for (int i = 0; i < n; i++)
//	{
//		iloczyn *= tab[i];
//	}
//	return iloczyn;
//}
//
//#define MAX 100

//int main() {
//	info();
//	int tab[MAX];
//	printf("Ile liczb chcesz podac ");
//	printf("(nie wiecej niz %d): ", MAX);
//	int n = wczytajLiczbeZPrzedzialu();
//	wczytajDoTablicy(tab, n);
//	printf("Suma (z tablicy): %d\n", sumaZTablicy(tab, n));
//	printf("Iloczyn (z tablicy): %d", iloczynZTablicy(tab, n));
//	printf("\n\nKoniec programu.\n\n");
//	return 0;
//}
//
//int main() {
//	info();
//	printf("Ile liczb chcesz podac ");
//	printf("(nie wiecej niz %d): ", MAX);
//	int n = wczytajLiczbeZPrzedzialu();
//	int liczba;
//	int suma = 0;
//	int iloczyn = 1;
//	for (int i = 0; i < n; i++)
//	{
//		while (scanf_s("%d", &liczba)!=1 || getchar()!='\n')
//		{
//			printf("Bledne dane, podal liczbe calkowita: ");
//			int c;
//			while ((c = getchar()) != '\n' && c != EOF)
//				;
//		}
//		suma += liczba;
//		iloczyn *= liczba;
//	}
//	printf("Suma (z petli): %d", suma);
//	printf("\nIloczyn (z petli): %d", iloczyn);
//	printf("\n\nKoniec programu.\n\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 77                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//void info() {
//	printf("Program wypisuje trzycyfrowe liczby, ktore sa rowne sumie szescianow swoich cyfr.\nAutor: Jakub Drozd\n");
//}
//
//int main()
//{
//	info();
//}


/*===========================================================================*/
/*                               ZADANIE 78                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//void info() {
//	printf("Program oblicza n wyrazow ciagu Fibbonacciego i wypisuje je od najwiekszej do najmniejszej, n podaje uzytkownik.\nAutor: Jakub Drozd\n");
//}
//
//int wczytajLiczbe(void) {
//	int liczba;
//	while (scanf_s("%d", &liczba)!=1 || liczba < 0 || liczba > 20 || getchar()!='\n')
//	{
//		printf("Podaj liczbe calkowita z przedzialu [0,20]: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//int fibbonacci(int n) {
//	if (n <= 1)
//	{
//		return n;
//	}
//	return fibbonacci(n - 1) + fibbonacci(n - 2);
//}
//
//void wpiszDoTablicy(int tab[], int n) {
//	for (int i = 0; i < n; i++)
//	{
//		tab[i] = fibbonacci(i);
//	}
//}
//
//void sortowanie(int tab[], int rozmiar) {
//	for (int i = 0; i < rozmiar - 1; i++)
//	{
//		for (int j = 0; j < rozmiar - i - 1; j++)
//		{
//			if (tab[j] < tab[j+1])
//			{
//				int temp = tab[j];
//				tab[j] = tab[j + 1];
//				tab[j + 1] = temp;
//			}
//		}
//	}
//
//
//}
//
//
//void wypiszTablice(int tab[], int n) {
//	printf("[");
//	for (int i = 0; i < n; i++)
//	{
//		if (i == n-1)
//		{
//			printf("%d", tab[i]);
//		}
//		else
//		{
//		printf("%d, ", tab[i]);
//
//		}
//	}
//	printf("]");
//}
//
//#define MAX 20
//
//int main()
//{
//	info();
//	int tab[MAX];
//	int n = wczytajLiczbe();
//	wpiszDoTablicy(tab, n);
//	sortowanie(tab, n);
//	wypiszTablice(tab, n);
//}


/*===========================================================================*/
/*                               ZADANIE 79                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//void info() {
//	printf("Program wczytuje 10 liczb calkowitych i wypisuje je rosnaco.\nAutor: Jakub Drozd\n");
//}
//
//void sortujTablice(int tab[], int rozmiar) {
//	for (int i = 0; i < rozmiar - 1; i++)
//	{
//		for (int j = 0; j < rozmiar - i - 1; j++)
//		{
//			if (tab[j] > tab[j+1])
//			{
//				int temp = tab[j];
//				tab[j] = tab[j+1];
//				tab[j+1] = temp;
//			}
//		}
//	}
//}
//
//int wczytajLiczbe(void) {
//	int liczba = 0;
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
//void wczytajTablice(int tab[], int rozmiar){
//	for (int i = 0; i < rozmiar; i++)
//	{
//		tab[i] = wczytajLiczbe();
//	}
//}
//
//void wypiszTablice(int tab[], int rozmiar) {
//	printf("[");
//	for (int i = 0; i < rozmiar; i++)
//	{
//		if (i == rozmiar - 1)
//		{
//			printf("%d", tab[i]);
//		}
//		else
//		{
//			printf("%d, ", tab[i]);
//		}
//	}
//	printf("]");
//}
//
//#define ILE 10
//
//int main()
//{
//	info();
//	int tab[ILE];
//	wczytajTablice(tab, ILE);
//	sortujTablice(tab, ILE);
//	wypiszTablice(tab, ILE);
//	printf("\n\nKoniec programu.\n\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 80                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//void info() {
//	printf("Program losowo generuje 10 liczb calkowitych nieujemnych i wypisuje je od najmniejszej do najwiekszej.\nAutor:Jakub Drozd.\n\n");
//}
//
//
//void wczytajLiczbe(int tab[], int n) {
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		tab[i] = rand();
//	}
//}
//
//void wypiszTab(int tab[], int n) {
//	for (int i = 0; i < n; i++)
//	{
//		printf("[%d] = %d\n", i+1, tab[i]);
//	}
//}
//
//void sortowanie(int tab[], int n) {
//	for (int i = 0; i < n -1; i++)
//	{
//		for (int j = 0; j < n - i - 1; j++)
//		{
//			if (tab[j] > tab[j+1])
//			{
//				int temp = tab[j];
//				tab[j] = tab[j + 1];
//				tab[j + 1] = temp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	info();
//	int tab[10] = { 0 };
//	wczytajLiczbe(tab, 10);
//	sortowanie(tab, 10);
//	wypiszTab(tab, 10);
//	printf("\n\nKoniec programu.\n\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 81                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//#include <limits.h>
//
//void info() {
//	printf("Program wypisuje 10 liczby z przedzalu [1,2] i wypisuje je od najmniejszej do najwiekszej.\nAutor: Jakub Drozd\n");
//}
//
//void wczytajLiczby(double tab[], int n) {
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		tab[i] = rand() / (double)RAND_MAX + 1;
//	}
//}
//
//void wypiszLiczby(double tab[], int n) {
//	for (int i = 0; i < n; i++)
//	{
//		printf("[%2d] = %f\n", i + 1, tab[i]);
//	}
//}
//
//void sortowanie(double tab[], int n) {
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < n - i - 1; j++)
//		{
//			if (tab[j] > tab[j+1])
//			{
//				double temp = tab[j];
//				tab[j] = tab[j + 1];
//				tab[j + 1] = temp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	info();
//	double tab[10];
//	wczytajLiczby(tab, 10);
//	sortowanie(tab, 10);
//	wypiszLiczby(tab, 10);
//}


