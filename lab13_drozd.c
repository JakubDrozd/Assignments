/*===========================================================================*/
/*                               ZADANIE 94                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define MAX 25
//
//void info() {
//	printf("Program sprawdza czy w tablicy zdefiniowanej przez uzytkownika, wszystkie jej elementy ponizej przekatnej sa rowne zero.\nAutor: Jakub Drozd\n");
//}
//
//void wpiszTablice(double tab[][MAX], int n, int m){
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			tab[i][j] = wpiszDouble();
//		}
//	}
//}
//
//int wpiszLiczbe() {
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
//int wpiszDouble() {
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
//void sprawdzanie(double tab[][MAX], int n, int m) {
//	int licznik = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (i > j)
//			{
//				if (tab[i][j] != 0)
//				{
//					licznik++;
//				}
//			}
//		}
//	}
//	if (licznik > 0)
//	{
//		printf("Nie wszystkie liczby ponizej przekatnej tablicy sa rowne 0");
//	}
//	else
//	{
//		printf("Wszystkie liczby ponizej przekatnej tablicy sa rowne 0");
//	}
//}
//
//int main()
//{
//	info();
//	double tab[MAX][MAX];
//	printf("Podaj ilosc wierszy: ");
//	int wiersze = wpiszLiczbe();
//	printf("Podaj ilosc kolumn: ");
//	int kolumny = wpiszLiczbe();
//	wpiszTablice(tab, wiersze, kolumny);
//	wypiszTablice(tab, wiersze, kolumny);
//	sprawdzanie(tab, wiersze, kolumny);
//	printf("\n\nKoniec programu.\n\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 95                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define MAX 25
//
//void info() {
//	printf("Program tworzy zdefiniowanja przez uzytkownika tablice dwuwymiarowa i zamienia losowo jego wiersze.\nAutor: Jakub Drozd\n");
//}
//
//void wpiszTablice(double tab[][MAX], int n, int m) {
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
//int wpiszLiczbe() {
//	int liczba;
//	while (scanf_s("%d", &liczba) != 1 || getchar() != '\n')
//	{
//		printf("Bledne dane, podaj liczbe calkowita: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//int wpiszDouble() {
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
//void zamiana(double tab[][MAX], int n, int m, int zamianaPierwszy, int zamianaDrugi) {
//	for (int i = 0; i < n; i++)
//	{
//		double temp;
//		temp = tab[zamianaDrugi][i];
//		tab[zamianaDrugi][i] = tab[zamianaPierwszy][i];
//		tab[zamianaPierwszy][i] = temp;
//	}
//}
//
//int main()
//{
//	info();
//	double tab[MAX][MAX];
//	printf("Podaj ilosc wierszy: ");
//	int wiersze = wpiszLiczbe();
//	printf("Podaj ilosc kolumn: ");
//	int kolumny = wpiszLiczbe();
//	wpiszTablice(tab, wiersze, kolumny);
//	wypiszTablice(tab, wiersze, kolumny);
//	printf("Ktore rzedy chcesz ze soba zamienic? Podaj numer rzedu: [1-%d]: ", wiersze);
//	int zamianaPierwszy = wpiszLiczbe();
//	int zamianaDrugi = wpiszLiczbe();
//	zamiana(tab, wiersze, kolumny, zamianaPierwszy-1, zamianaDrugi-1);
//	wypiszTablice(tab, wiersze, kolumny);
//	printf("\n\nKoniec programu.\n\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 96                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define MAX 25
//
//void info() {
//	printf("Program zamienia s-ty wiersz z s-ta kolumna, gdzie s jest jest numerem wiersza i kolumny przeciecia sie miejsca maksymalnego elementu tablicy.\nAutor: Jakub Drozd.\n");
//}
//
//void znajdzMaxa(double tab[][MAX], int n, int m, int *nrWiersza, int *nrKolumny) {
//	double max = INT_MIN;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (i == j)
//			{
//				if (max < tab[i][j])
//				{
//					max = tab[i][j];
//					*nrWiersza = i;
//					*nrKolumny = j;
//				}
//			}	
//		}
//	}
//}
//
//void stworzTablice(double tab[][MAX], int n, int m) {
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
//void zamiana(double tab[][MAX], int n, int nrWiersza, int nrKolumny){
//	for (int i = 0; i < n; i++)
//	{
//		double temp;
//		temp = tab[i][nrKolumny];
//		tab[i][nrKolumny] = tab[nrWiersza][i];
//		tab[nrWiersza][i] = temp;
//	}
//}
//
//int podajLiczbe() {
//	int liczba;
//	while (scanf_s("%d", &liczba)!=1 || liczba < 0 || getchar()!='\n')
//	{
//		printf("Bledne dane, podaj liczbe calkowita dodatnia: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//int main()
//{
//	int nrWiersza = -1;
//	int nrKolumny = -1;
//	int wiersze;
//	int kolumny;
//	double tab[MAX][MAX];
//	info();
//	printf("Podaj ilosc wierszy: ");
//	wiersze = podajLiczbe();
//	printf("Podaj ilosc kolumn: ");
//	kolumny = podajLiczbe();
//	stworzTablice(tab, wiersze, kolumny);
//	wypiszTablice(tab, wiersze, kolumny);
//	znajdzMaxa(tab, wiersze, kolumny, &nrWiersza, &nrKolumny);
//	printf("\n\n[%d][%d]\n\n", nrWiersza+1, nrKolumny+1);
//	printf("\n\nZAMIANA\n\n");
//	zamiana(tab, wiersze, nrWiersza, nrKolumny);
//	wypiszTablice(tab, wiersze, kolumny);
//	printf("\n\nKoniec programu\n\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 97                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 98                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 99                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 100                                 */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


